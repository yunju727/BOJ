#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(string begin, string target, vector<string> words) {
    vector<int> visited;
    int answer;
    int word_size = begin.size();
    for(int i = 0; i < words.size(); i++){
        visited.push_back(0);
    }
    queue<pair<int,int>> q;
    for(auto& w: words){
        int diff = 0;
        for(int i = 0; i < word_size; i++){
            if(w[i] != begin[i]) diff++;
        }
        if(diff == 1){
            int idx = find(words.begin(),words.end(),w) - words.begin();
            q.push({idx,1});
            visited[idx] = 1;
        }
    }
    bool is_end = false;
    while(!q.empty()){
        int d = q.front().second;
        begin = words[q.front().first];
        if(begin == target){
            is_end = true;
            answer = d;
            break;
        }
        q.pop();
        
        for(auto& w: words){
            int idx = find(words.begin(),words.end(),w) - words.begin();
            int diff = 0;
            //방문 여부를 먼저 찾자
            if(visited[idx] != 1){
                for(int i = 0; i < word_size; i++){
                    if(w[i] != begin[i]) diff++;
                }
                if(diff == 1){
                    q.push({idx, d+1});
                    visited[idx] = 1;
                }
            }
        }
    }
    if(!is_end) answer = 0;
    return answer;
}