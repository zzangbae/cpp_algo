#include<iostream>
#include<queue>
using namespace std;

/**
 * 7576 토마토
 * 하루마다 인접한 토마토 익힌다
 * 혼자 저절로 익는 경우는 없음
 * 며칠이 지나면 다 익는지, 중간에 막히는 경우도 있음(빈칸)
*/

int n, m;
int arr[1005][1005];
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int answer;

int main() {
    // 입력값 받기
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int a = 0;
            cin >> a;
            arr[i][j] = a;
            // 토마토의 유치를 큐에 집어넣기
            if(a == 1) {
                q.push({i, j});
            }
        }
    }

    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 범위를 넘어선 경우
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 0이 아닌 경우 
            if(arr[nx][ny] != 0) continue;
            // 0인 경우, 더하기 1씩 해서 넓혀가기
            arr[nx][ny] = arr[x][y] + 1;
            q.push({nx, ny});
        }
    }

    // 0이 있으면 -1을 내놓도록 한다.
    // 아닌 경우 최댓값을 찾아 answer에 넣기
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                answer = -1;
                break;
            }
            if(arr[i][j] > answer) {
                answer = arr[i][j];
            }
        }
        if(answer == -1) break;
    }
    if(answer == -1) cout << -1;
    else cout << answer - 1;
}