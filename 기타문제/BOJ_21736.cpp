#include <iostream>
#include <string>
#include <queue>

using namespace std;

/**
 * 21736 - 헌내기는 친구가 필요해
 * 캠퍼스의 크기 N x M
 * 이동 - 벽이 아닌 상하좌우
 * 캠퍼스 밖으로 이동 X
 * 만날 수 있는 사람의 수를 출력하는 프로그램
*/

/**
 * 입력 O : 빈공간
 * X : 벽
 * P : 사람
 * I : 도연이(1번만 주어진다.)
*/

int n, m;
int arr[605][605];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int answer;

int main() {
    cin >> n >> m;
    string s;
    queue<pair<int, int>> q;
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'O') arr[i][j] = 0;
            else if(s[j] == 'P') arr[i][j] = 1;
            else if(s[j] == 'X') arr[i][j] = -1;
            else {
                arr[i][j] = 2;
                q.push({i, j});
            }
        }
    }
    // 도연이가 지나간 곳은 2로 바뀔 것이다.
    while(q.size()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 벽이거나 들렸던 점이면 가지 않는다.
            if(arr[nx][ny] == -1 || arr[nx][ny] == 2) continue;
            if(arr[nx][ny] == 0) {
                q.push({nx, ny});   // 다음점을 큐에 넣어주기
                arr[nx][ny] = 2;
                continue;
            }
            if(arr[nx][ny] == 1) {
                q.push({nx, ny});
                arr[nx][ny] = 2;
                answer++;
            }
        }
    }

    if(answer == 0) cout << "TT";
    else cout << answer;
    return 0;
}