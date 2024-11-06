#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int garo = -1;
    int sero = -1;
    /*
    1. 첫 for문에서는 가로와 세로중 큰값을 가로 리스트에 오도록 변경한다.
    2. 그 뒤 두번째 for문에서는 가로와 세로의 최대값을 각각 찾음
    */
    for(int i = 0; i < sizes.size(); i++){
        //더 큰 값이 0번째에 오도록 조정
        if(sizes[i][0] < sizes[i][1]){
            int temp = sizes[i][1];
            sizes[i][1] = sizes[i][0];
            sizes[i][0] = temp;
        }
    }
    
    
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] > garo){
            garo = sizes[i][0];
        }
        if(sizes[i][1] > sero){
            sero = sizes[i][1];
        }
    }
    answer = garo * sero;
    return answer;
}