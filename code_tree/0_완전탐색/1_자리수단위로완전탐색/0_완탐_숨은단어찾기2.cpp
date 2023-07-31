// 6:01~6:13
#include <iostream>
#include <string>
#define MAX_N 50

using namespace std;
int n, m;
string arr[MAX_N];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 'L') {
                for(int k = 0; k < 8; k++) {
                    // 다다음 점이 범위 내인지를 확인
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    int nnx = i + dx[k] * 2;
                    int nny = j + dy[k] * 2;
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(nnx < 0 || nnx >= n || nny < 0 || nny >= m) continue;
                    if(arr[nx][ny] == 'E' && arr[nnx][nny] == 'E') cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}