#include <iostream>
#include <string>

using namespace std;

int room[50][50];
int N, M;
int d;
int rx;
int ry;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool location_check(int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < M) {
        return true;
    }
    else {
        return false;
    }
}

int rotation(int direction) {
    direction--;
    if (direction < 0) {
        direction += 4;
    }
    return direction;
}

int main() {
    cin >> N >> M;
    // 로봇의 위치
    cin >> rx >> ry >> d;
    // 방 정보
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> room[i][j];
        }
    }

    int result = 0;

    // 로봇의 위치가 벽이 아니면 while문 계속 실행
    while (location_check(rx, ry) && room[rx][ry] != 1) {
        // 현재 칸이 청소가 안되어 있다면 청소
        if (room[rx][ry] == 0) {
            room[rx][ry] = -1;
            result += 1;
        }
        bool is_trash = false;
        // 로봇 위치 인접 4칸에 쓰레기가 있는지를 검사하는 반복문
        // 해당 반복문이 끝나면, 로봇이 90도로 회전할 지, 아니면 후진할 지 결정난다.
        for (int i = 0; i < 4; i++) {
            int tmp_x = rx + dx[i];
            int tmp_y = ry + dy[i];

            //해당 위치가 유효한 위치라면 청소가 되어 있는지 검사(1개라도 있으면 됨)
            if (location_check(tmp_x, tmp_y)) {
                if (room[tmp_x][tmp_y] == 0) {
                    is_trash = true;
                    break;
                }
            }
        }

        // 로봇의 인접 4칸에 쓰레기가 있는경우 90도 회전
        if (is_trash) {
            // 90도 회전
            d = rotation(d);
            int tmp_x = rx + dx[d];
            int tmp_y = ry + dy[d];
            // 바로 앞칸이 청소가 안되어 있다면 전진한다.
            if (location_check(tmp_x, tmp_y)) {
                if (room[tmp_x][tmp_y] == 0) {
                    rx = tmp_x;
                    ry = tmp_y;
                }
            }
        }
        // 그렇지 않은 경우 후진한다.
        else {
            rx = rx - dx[d];
            ry = ry - dy[d];
        }

    }
    cout << result;
}
