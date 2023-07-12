#include<iostream>
#include<queue>
#include<map>
#include<vector>

using namespace std;

int arr[101][101];
bool visited[101][101] = {false};
int n, m;
int x, y, a, b;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
map<pair<int, int>, vector<pair<int, int>>> light;

int main() { 
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        if(light.find({x, y}) == light.end()) light[{x, y}] = {{a, b}}; // 벡터 추가
        else light[{x, y}].push_back({a, b});
    }

    arr[1][1] = 1;
    queue<pair<int, int>> q;
    q.push({1, 1});
    visited[1][1] = true;
    
    while(!q.empty()) {
        int sx = q.front().first;
        int sy = q.front().second;
        q.pop();
        // 불켤 수 있는 곳 켜주기
        if(light.find({sx, sy}) != light.end()) {
            for(pair<int, int> ll : light[{sx, sy}]) {
                int lx = ll.first;
                int ly = ll.second;
                if(arr[lx][ly] != 1) {
                    // 불켜기
                    arr[lx][ly] = 1;
                    // 새로 불 켠 곳 4방향 중 방문한 적이 있다면 재탐색
                    for(int i = 0; i < 4; i++) {
                        int nlx = lx + dx[i];
                        int nly = ly + dy[i];
                        if(nlx > n || nlx < 1 || nly > n || nly < 1) continue;
                        if(visited[nlx][nly]) q.push({nlx, nly});
                    }
                }
            }
        }
        // 불을 켠 방 기준으로 4방향에 불켜지고 방문한적 없으면 재탐색
        for(int i = 0; i < 4; i ++) { 
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            if(nx > n || nx < 1 || ny > n || ny < 1) continue;
            if(visited[nx][ny]) continue;
            if(arr[nx][ny] == 0) continue;
            q.push({nx, ny});
            visited[nx][ny] = true;
        }
    }

    int answer = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] == 1) answer++;
        }
    }
    cout << answer;
    return 0;
}