#include <iostream>
#include <algorithm>

using namespace std;

int n;
int grid[21][21];

int main() {
    // 1. 입력
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    int max_coin = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j + 2 < n; j++)
            max_coin = max(max_coin, grid[i][j] + grid[i][j + 1] + grid[i][j + 2]);
    
    cout << max_coin;
    return 0;
}