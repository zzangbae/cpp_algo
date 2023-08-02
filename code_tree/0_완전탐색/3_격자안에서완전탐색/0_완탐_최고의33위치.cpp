// 9:36~9:42(6분/16분) - on time
#include <iostream>
#include <climits>
#include <algorithm>
#define MAX_N 20
using namespace std;

int n;  // 3~20 O(N^2) 400
int arr[MAX_N][MAX_N];
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    
    int max_coin = INT_MIN;
    int tmp_coin = 0;
    // 3 * 3 격자의 제일 왼쪽 위 (i, j)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            tmp_coin = 0;
            if(i + 2 >= n || j + 2 >= n) continue;
            for(int k = i; k <= i + 2; k++) {
                for(int l = j; l <= j + 2; l++) {
                    tmp_coin += arr[k][l];
                }
            }
            max_coin = max(max_coin, tmp_coin);
        }
    }
    cout << max_coin;
    return 0;
}

/**
 * 해셜의 경우, 조건에 만족하는 끝범위(가장자리)를 가져와서
 * 해당 가장자리 안에 포함되는 금 개수를 계산하고, 최댓값을 갱신하는 식으로 진행
*/