#include<iostream>
#include<queue>

using namespace std;

/**
 * 4179
 * 지훈이가 불에 타기전에 탈출할 수 있는지 여부
 * 얼마나 빨리 탈출할 수 있는지
 * 불은 네 방향 확산
 * 지훈이는 가장자리에 접한 공간에서 탈출
 * 지훈, 불은 벽이 있는 공간을 통과하지 못함
 * 지훈 : 하나
 * 불 : 여러개 존재할 수 있음
*/

int r, c;
char arr[1005][1005];
queue<pair<int, int>> fq;   // 불들의 위치(여러개 가능함)
queue<pair<int, int>> jq;   // 지훈 위치
int f_arr[1005][1005];  // fire bfs
int j_arr[1005][1005];  // 지훈 bfs
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    // 1. 입력값 받기
    cin >> r >> c;  // 1000까지
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            char c = '!';   // !는 임의값
            cin >> c;
            arr[i][j] = c;
            if(c == 'J') {
                jq.push({i, j});
                j_arr[i][j] = 1;    // 지훈이의 시작점은 1
            }
            else if(c == 'F') {
                fq.push({i, j});
                f_arr[i][j] = 1;    // 불의 시작점은 1
            }
        }
    }

    // 2. 불에 대해서 BFS 돌리기
    while(fq.size()) {
        int x = fq.front().first;
        int y = fq.front().second;
        fq.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 범위 넘어선 경우
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            // 벽에 걸린 경우
            if(arr[nx][ny] == '#') continue;
            // 이미 불이 지나간 경우
            if(f_arr[nx][ny] != 0) continue;
            f_arr[nx][ny] = f_arr[x][y] + 1;
            fq.push({nx, ny});
        }
    }

    // 2+. 불이 다 돌았는데 안 닿는 부분(벽에 막히거나 하는 식으로)은 큰 수 집어넣기
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(arr[i][j] == '#') continue;
            if(f_arr[i][j] == 0) f_arr[i][j] = 987654321;
        }
    }

    // 3. 지훈이에 대해서 BFS 돌리기
    while(jq.size()) {
        int x = jq.front().first;
        int y = jq.front().second;
        jq.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if(arr[nx][ny] == '#') continue;
            if(j_arr[nx][ny] != 0) continue;
            j_arr[nx][ny] = j_arr[x][y] + 1;
            jq.push({nx, ny});
        }
    }
    
    // cout << "--------f------" << "\n";
    // for(int i = 0; i < r; i++) {
    //     for(int j = 0; j < c; j++) {
    //         cout << f_arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "------j--------" << "\n";
    // for(int i = 0; i < r; i++) {
    //     for(int j = 0; j < c; j++) {
    //         cout << j_arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }


    // 4. 지훈 배열과 불 배열의 가장자리 체크하기, 애초에 가장 큰 값을 대입해놔야한다...j_arr, f_arr에
    int answer = 987654321;
    // 4-1. 왼쪽 한 줄 비교
    for(int i = 0; i < r; i++) {
        if(j_arr[i][0] != 0 && j_arr[i][0] < f_arr[i][0] && j_arr[i][0] < answer) answer = j_arr[i][0];
    }
    // 4-2. 오른쪽 한 줄 비교
    for(int i = 0; i < r; i++) {
        if(j_arr[i][c - 1] != 0 && j_arr[i][c - 1] < f_arr[i][c - 1] && j_arr[i][c - 1] < answer) answer = j_arr[i][c - 1];
    }
    // 4-3. 위쪽 한 줄 비교
    for(int i = 0; i < c; i++) {
        if(j_arr[0][i] != 0 && j_arr[0][i] < f_arr[0][i] && j_arr[0][i] < answer) answer = j_arr[0][i];
    }
    // 4-4. 아래쪽 한 줄 비교
    for(int i = 0; i < c; i++) {
        if(j_arr[r - 1][i] != 0 && j_arr[r - 1][i] < f_arr[r - 1][i] && j_arr[r - 1][i] < answer) answer = j_arr[r - 1][i];
    }
    // 

    // 5. answer 판단
    if(answer == 987654321) {
        cout << "IMPOSSIBLE";
    } else {
        cout << answer;
    }
}