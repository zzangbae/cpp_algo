#include<iostream>

using namespace std;

/**
 * 로봇 청소기
 * N x M 직사각형 : 벽 or 칸
 * 1. 현재칸이 청소되지 않은 경우, 청소한다
 * 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
 *      1) 바라보는 방향을 유지한채로 한칸 후진 후 1번
 *      2) 바라보는 방향의 뒤쪽 칸이 벽이라 후진 못하면 작동 멈춤
 * 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈칸이 있는 경우,
 *      1) 반시계 방향으로 90도 회전
 *      2) 바라보는 방향을 기준으로 앞쪽 칸이 총소되지 않은 빈칸 인 경우 한칸 전진
 *      3) 1번으로 돌아감
 * -> 구 : 멈출 때까지 총소하는 칸의 개수
*/

int n, m;   // 3~50
int arr[55][55];    // 0 : 청소X, 1 : 벽, 2 : 청소됨
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    cin >> n >> m;
    int x, y, d;    // x, y: 현재좌표, d: 방향
    cin >> x >> y >> d;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    while(true) {
        // 1. 현재칸이 청소되지 않은 경우, 청소하기
        if(arr[x][y] != 2) arr[x][y] = 2;
        // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        // 즉, 4칸 모두 청소되거나 벽이어야 한다.
        bool cleaned = true;
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 청소 안된 곳을 발견 -> clean : false 하고 넘어감
            if(arr[nx][ny] == 0) {
                cleaned = false;
                break;
            }
        }
        // 2-cleaned:true - 4칸 모두 청소되어있음
        if(cleaned) {
            // 2-1. 바라보는 방향 유지한채 한칸 후진 하고 1번-continue;
            // 2-2. 바라보는 방향의 뒤쪽 칸이 벽이라면 작동 멈춤
            if(d == 0) {    // 북을 바라보기 때문에 뒤쪽 칸은 남쪽
                if(arr[x + 1][y] == 1) break;
                else {
                    x++;
                    continue;
                }
            } else if(d == 1) {     // 동을 바라보기 때문에 뒤쪽칸은 서쪽
                if(arr[x][y - 1] == 1) break;
                else {
                    y--;
                    continue;
                }
            } else if(d == 2) {     // 남을 바로보며 뒤쪽칸 북쪽
                if(arr[x - 1][y] == 1) break;
                else {
                    x--;
                    continue;
                }
            } else if(d == 3) {     // 서를 바라보며 뒤쪽칸은 동쪽
                if(arr[x][y + 1] == 1) break;
                else {
                    y++;
                    continue;
                }
            }

        } else {    // 3-청소되어있지 않은 방향이 존재
            // 3-1, 3-2. 바라보는 방향이 청소되지 않은 칸이 될 때까지 회전
            while(true) {
                d = (d + 3) % 4;
                if(d == 0) {
                    if(arr[x - 1][y] == 0) {
                        x--;
                        break;
                    }
                }
                else if(d == 1) {
                    if(arr[x][y + 1] == 0) {
                        y++;
                        break;
                    }
                }
                else if(d == 2) {
                    if(arr[x + 1][y] == 0) {
                        x++;
                        break;
                    }
                }
                else if(d == 3) {
                    if(arr[x][y - 1] == 0) {
                        y--;
                        break;
                    }
                }
            }
            // 3-3. 1번으로 돌아가기 -> 자동으로 1번으로 가게 됨
        }
    }

    int answer = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 2) answer++;
        }
    }
    cout << answer;
    return 0;
}