#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// 10:24~
// 동적 계획
int n;
int arr[1005][3];

int main() {
    int cost[3];
    arr[0][0] = 0;
    arr[0][1] = 0;
    arr[0][2] = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> cost[0] >> cost[1] >> cost[2];
        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + cost[0];
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + cost[1];
        arr[i][2] = min(arr[i - 1][1], arr[i - 1][0]) + cost[2];
    }
    cout << min(arr[n][2], min(arr[n][0], arr[n][1]));
}