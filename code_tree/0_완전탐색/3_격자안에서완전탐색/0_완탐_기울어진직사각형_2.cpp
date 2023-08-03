// 해설 풀이
#include<iostream>
#include<algorithm>
#define MAX_N 20
#define DIR_NUM 4   // 방향 가짓수

using namespace std;

int n;
int grid[MAX_N][MAX_N];

// 특정 점이 범위 안에 있는지 확인
bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// (x, y) 점을 시작으로 하여 width k, height = l일 떄의 값
int GetScore(int x, int y, int k, int l) {
    int dx[DIR_NUM] = {-1, -1, 1, 1};   // 1, 2, 3, 4 방향
    int dy[DIR_NUM] = {1, -1, -1, 1};  // 1, 2, 3, 4 방향
    int move_num[DIR_NUM] = {k, l, k, l};
    
    int sum_of_number = 0;
    
    for(int d = 0; d < DIR_NUM; d++) {
        for(int q = 0; q < move_num[d]; q++) {
            x += dx[d];
            y += dy[d];
            
            // 만약 다음 점이 범위를 넘어가게 된다면 직사각형이 안만들어지므로 갱신이 안되도록 0을 리턴한다.
            if(!InRange(x, y))
                return 0;

            sum_of_number += grid[x][y];
        }
    }

    return sum_of_number;
}


int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 1; k < n; k++) {
                for(int l = 1; l < n; l++) {
                    ans = max(ans, GetScore(i, j, k, l));
                }
            }
        }
    }
    cout << ans;
    return 0;
}