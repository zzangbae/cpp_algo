#include<iostream>
#include<vector>
#include<map>
#include<queue>

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
        // 기존의 값이 없다면 추가하기
        if(light.find({x, y}) == light.end()) {
            light[{x, y}] = {{a, b}};
        }
        else {
            light[{x, y}].push_back({a, b});
        }
    }

    // (1, 1)은 불을 킬 수 있다.
    arr[1][1] = 1;  // 1은 불을 켰다는 것을 의미한다.
    // bfs를 돌려보자
    queue<pair<int, int>> q;
    q.push({1, 1});
    while(q.size()) {
        int sx = q.front().first;
        int sy = q.front().second;
        visited[sx][sy] = true; // 현재점 방문처리
        q.pop();
        // 스위치가 있다면 불을 켜자
        if(light.find({sx, sy}) != light.end()) {
            for(pair<int, int> ll : light[{sx, sy}]) {
                int llx = ll.first;
                int lly = ll.second;
                // 새로불을 켠 곳 4방향 중 방문한 적이 있다면 재탐색 대상
                // 예시에서 (2, 1) 켰을 때, (1, 1)은 들린 상황
                if(arr[llx][lly] != 1) {
                    arr[llx][lly] = 1;
                    for(int i = 0; i < 4; i++) {
                        int nllx = llx + dx[i];
                        int nlly = lly + dy[i];
                        if(nllx > n || nllx < 1 || nlly > n || nlly < 1) continue;
                        if(visited[nllx][nlly]) q.push({nllx, nlly});
                    }
                } 
            }
        }
        // 불을 켠 방 기준으로 4방향 불 켜진 곳이 있는데 방문한 적이 없다면 재탐색 대상
        for(int i = 0; i < 4; i++) {
            int nx = sx + dx[i];
            int ny = sy + dy[i];
            // 다음 점이 범위를 넘어간 경우
            if(nx > n || nx < 1 || ny > n || ny < 1) continue;
            // 불이 꺼져있는 경우, 넘어가기
            if(arr[nx][ny] == 0) continue;
            if(visited[nx][ny]) continue;
            q.push({nx, ny});   // 방문X이고, 불이 켜진곳은 재탐색 대상
        }
    }
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= n; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int answer = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(arr[i][j] == 1) answer++;
        }
    }
    cout << answer;
}