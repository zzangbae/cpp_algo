#include<iostream>
#include<queue>
using namespace std;

int board[502][502];
bool vis[502][502];
int n, m;   // 입력값으로 주어짐 - 일반적으로 r, c
int dx[4] = {-1, 0, 1, 0};  // 상하좌우
int dy[4] = {0, 1, 0, -1};  // 상하좌우

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // 입력으로 그리드 환경이 주어짐
    queue<pair<int, int>> q;
    vis[0][0] = 1;  // 시작점 방문처리 ** 중요 **
    q.push({0, 0});
    while(!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();    // cur : 현재점
        int x = cur.first;
        int y = cur.second;
        // 상 하 좌 우 판단 - 다음점
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            // 범위 체크
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            // 방문 체크, 1은 예시 - 벽
            if(vis[nx][ny] || board[nx][ny] != 1) continue;
            vis[nx][ny] = 1;    // 다음 점 방문체크 ** 중요 **
            q.push({nx, ny});   // 큐에 넣기
        }
    }
}