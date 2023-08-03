// 9:00~9:07(7분/정해지지않음)
#include <iostream>
#include <algorithm>
#define MAX_N 20
#define MAX_M 20
using namespace std;
 
int n, m;   // 1~20
int grid[MAX_N][MAX_M];

// (x1, y1) ~ (x2, y2) 직사각형 넓이를 구하기 - 만약 음수가 포함되어 있다면 -1을 리턴하기
int BoxSize(int x1, int y1, int x2, int y2) {
    for(int i = x1; i <= x2; i++)
        for(int j = y1; j <= y2; j++)
            if(grid[i][j] <= 0) return -1;
    
    return (x2 - x1 + 1) * (y2 - y1 + 1);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];
    
    int ans = -1;
    // 직사각형 : 시작점, 끝점
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            for(int k = i; k < n; k++)
                for(int l = j; l < m; l++)
                    ans = max(ans, BoxSize(i, j, k, l));
    
    cout << ans;
    return 0;
}

/**
-직사각형 다룰 때 기억할점 : 직사각형은 왼쪽위의 점과 오른쪽 아래의 점으로 표현할 수 있다.
*/