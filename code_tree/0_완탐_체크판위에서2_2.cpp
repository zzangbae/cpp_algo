#include <iostream>

#define MAX_N 15

using namespace std;

int n, m;
char grid[MAX_N][MAX_N];

int main() {
    // 입력
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    // 이동 시에 행과 열이 전부 증가하도록
    // 모든 쌍을 다 잡아봅니다.
    int cnt = 0;
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            for(int k = i + 1; k < n - 1; k++)
                for(int l = j + 1; l < m - 1; l++)
                    // 그 중 색깔이 전부 달라지는 경우에만 개수를 세줍니다.
                    if(grid[0][0] != grid[i][j] && 
                       grid[i][j] != grid[k][l] &&
                       grid[k][l] != grid[n - 1][m - 1])
                        cnt++;
                        
    cout << cnt;
    return 0;
}