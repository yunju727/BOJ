#include <string>
#include <vector>

using namespace std;
bool in_range(int x, int y, int n){
    return x >= 0 && x < n && y >=0 && y <n;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n,vector<int>(n,0));
    int start = 1;
    int visited[n][n];
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
    for(int i =0 ; i< n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    //BFS 할 때처럼 초기화
    answer[0][0] = start;
    visited[0][0] = 1;
    int x = 0, y = 0;
    int dir = 0;
    
    while(start <n*n){
        start ++;
        int tx = x + dx[dir]; int ty = y + dy[dir];
        if(in_range(tx, ty, n) && !visited[tx][ty]){
            answer[tx][ty] = start;
            visited[tx][ty] = 1;
        }
        else{
            if(dir == 0)ty-=1;
            else if(dir == 1) tx-=1;
            else if (dir == 2) ty+=1;
            else if (dir == 3) tx+=1;
            dir = (dir+1)%4;
            tx += dx[dir]; ty += dy[dir];
            if(in_range(tx, ty, n) && !visited[tx][ty]){
                answer[tx][ty] = start;
                visited[tx][ty] = 1;
            }
        }
        x = tx;y = ty;
    }
    
    return answer;
}