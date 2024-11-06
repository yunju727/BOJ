#include <string>
#include <vector>
#include <algorithm>

/*
1번 수포자 : 1 2 3 4 5 1 2 3 4 5 -> 계속 1 2 3 4 5 반복 / 5개마다 반복
2번 수포자 : 2 1 2 3 2 4 2 5 / 2 1 2 3 2 4 2 5 / 8개마다 반복
3번 수포자 : 3 3 1 1 2 2 4 4 5 5 반복 / 10개마다 반복

하는 방법. for문 순회하면서 돈다.ㅇㅇ 
*/

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> students = {0, 0, 0};
    
    vector<int> st1_ans = {1,2,3,4,5};
    vector<int> st2_ans = {2,1,2,3,2,4,2,5};
    vector<int> st3_ans = {3,3,1,1,2,2,4,4,5,5};
    
    int ite1 = st1_ans.size();
    int ite2 = st2_ans.size();
    int ite3 = st3_ans.size();
    
    int pos1, pos2, pos3;
    
    for(int i = 0; i < answers.size(); i++){
        pos1 = i%ite1;
        pos2 = i%ite2;
        pos3 = i%ite3;
        
        if(answers[i] == st1_ans[pos1])
            students[0]++;
        if(answers[i] == st2_ans[pos2])
            students[1]++;
        if(answers[i] == st3_ans[pos3])
            students[2]++;
    }
    int max_score = *max_element(students.begin(),students.end());
    
    vector<int> answer;
    
    for(int j = 0; j<3; j++){
        if(max_score == students[j])
            answer.push_back(j+1);
    }
    
    
    
    return answer;
}