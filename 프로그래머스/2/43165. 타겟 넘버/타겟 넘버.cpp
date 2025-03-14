#include <string>
#include <vector>

using namespace std;

int result = 0;

void dfs(int depth, int tmp, vector<int>numbers, int target){
    // 종료 조건
    if(depth == numbers.size()){
        if(tmp == target){
            result ++;
            return;
        }
        return;
    }
    dfs(depth+1, tmp+numbers[depth],numbers, target);
    dfs(depth+1, tmp-numbers[depth], numbers, target);
    
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(0, 0, numbers, target);
    answer = result;
    return answer;
}