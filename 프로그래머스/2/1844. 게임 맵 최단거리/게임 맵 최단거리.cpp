#include<vector>
#include <queue>
using namespace std;
int result = 26;
int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
int n, m;
bool is_limit(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < m;
}
/*
void search_way(vector<vector<int>> maps, int x, int y, int c){
    if(x == n-1 && y == m-1){
        result = result > c ? c : result;
        return;
    }
    
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(is_limit(nx, ny) && maps[nx][ny] != 0){
            maps[nx][ny] = 0; // 다시 못 돌아가게 하기 위함
            search_way(maps, nx, ny, c+1);
            maps[nx][ny] = 1; // 다시 설정해줘야함
        }
    }
}
*/
int solution(vector<vector<int> > maps)
{
    n = maps.size();
    m = maps[0].size();
    int answer = 0;
    queue<vector<int>> q;
    q.push({0,0,1});
    maps[0][0] = 0;
    while(!q.empty()){
        int x = q.front()[0], y = q.front()[1], d = q.front()[2];
        if(x == n-1 && y == m-1)answer = d;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(is_limit(nx, ny) && maps[nx][ny] != 0){
                q.push({nx, ny, d+1});
                maps[nx][ny] = 0;
            }
        }
    }
    
    if(answer == 0)answer = -1;
    return answer;
}