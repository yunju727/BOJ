#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    vector<char> r;
    for(int i = 0; i < number.size(); i++){
        //비어 있는 경우
        if(r.empty()){
            r.push_back(number[i]);
        }
        else{
            if(r.back() >= number[i])r.push_back(number[i]);
            //큰 경우
            else{
                while(true){
                    if(r.empty() || k == 0 || r.back() >= number[i])break;
                    if(r.back() < number[i]){
                        r.pop_back();
                        k--;
                    }
                }
                r.push_back(number[i]);
            }
        }
    }
    while(k > 0){
        r.pop_back();
        k--;
    }
    for(int i = 0; i < r.size(); i++){
        answer += r[i];
    }
    return answer;
}