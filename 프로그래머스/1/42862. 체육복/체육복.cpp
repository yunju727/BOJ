#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> realLost, realReserve;
    
    for(auto& l:lost){
        if(find(reserve.begin(),reserve.end(),l) == reserve.end()){
            realLost.push_back(l);
        }
    }
    for(auto& r:reserve){
        if(find(lost.begin(),lost.end(),r) == lost.end()){
            realReserve.push_back(r);
        }
    }
    
    
    vector<int> r;
    for(int i = 0; i< realReserve.size(); i++){
        r.push_back(1);
    }

    sort(realLost.begin(), realLost.end());
    sort(realReserve.begin(), realReserve.end());
    
    answer = n - realLost.size();
    
    for(int i = 0; i < realLost.size(); i++){
        for(int j = 0; j < realReserve.size(); j++){
            if(realLost[i] == realReserve[j]-1 && r[j] == 1){
                r[j] = 0;
                answer++;
                break;
            }
            else if(realLost[i] == realReserve[j]+1 && r[j] == 1){
                r[j] = 0;
                answer++;
                break;
            }
        }
    }
    return answer;
}