#include <string>
#include <vector>

using namespace std;
int visited[200];
int network = 0;

void dfs(int idx, vector<vector<int>> computers){
    //바로 해당 노드 방문 처리
    visited[idx] = 1;
    for(int i = 0; i < computers.size(); i ++){
        if(!visited[i] && computers[idx][i] == 1){
            visited[i] = 1;
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n ; i++){
        visited[i] = 0;
    }
    for(int i = 0; i < n; i++){
        //만약 방문하지 않은 노드라면
        if(!visited[i]){
            dfs(i, computers);
            answer++;
        }
    }
    return answer;
}