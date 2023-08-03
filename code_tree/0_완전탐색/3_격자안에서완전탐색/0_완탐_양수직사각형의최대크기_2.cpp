#include<iostream>
#include<algorithm>
#include<climits>
#define MAX_NUM 20
using namespace std;

int n, m;
int grid[MAX_NUM][MAX_NUM];
int down_max[MAX_NUM][MAX_NUM];

void PreProcessing() {
    // 마지막 행
    for(int j = 0; j < m; j++)
        if(grid[n - 1][j] > 0) 
            down_max[n - 1][j] = 1;
    
    // 아래서 부터 시작하면 저의에 맞지 않음
    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] > 0)
                down_max[i][j] = down_max[i + 1][j] + 1;
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    // down_max를 계산
    PreProcessing();

    int ans = INT_MIN;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            int best_height = INT_MAX;
            for(int l = j; l < m; l++) {
                best_height = min(best_height, down_max[i][l]);

                // 넓이를 계산하여 갱신
                ans = max(ans, (best_height) * (l - j + 1));
            }
        }

    if(ans <= 0)
        ans = -1;
    
    cout << ans;
    return 0;
}