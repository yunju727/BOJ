#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    vector<int> boat;
    //내림차순 정렬 방법 -> 이거 말고 방법 더 많음. 람다함수 사용 등
    sort(people.rbegin(), people.rend());
    for(int i = 0; i < people.size(); i++){
        boat.push_back(people[i]);
        if(boat.size() >= 2 && (boat[boat.size()-1] + boat[boat.size()-2]) <= limit){
            answer += 1;
            boat.pop_back();boat.pop_back();
        }
    }
    answer += boat.size();
    return answer;
}