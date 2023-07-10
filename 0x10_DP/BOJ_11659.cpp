#include<iostream>

using namespace std;

/**
 * N이 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램
 * M은 합을 구해야하는 횟수
 * N는 1~10만(각 수는 1000보다 작거나 같은 자연수)
 * M은 1~10만
 * => 매번 더해서 구하는 방식 O(NM)의 방식으로는 문제를 해결할 수 없다.
*/

// 누적합을 저장해놓고 특정 인덱스에서 다른 인덱스를 빼는게 좋을 것 같다.

int n, m;
int arr[100005];
int dp[100005]; // dp1. i번째 수까지 더한 누적합

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int x = 1; x <= n; x++) {
        cin >> arr[x];
        dp[x] = dp[x - 1] + arr[x];
    }
    for(int tc = 0; tc < m; tc++) {
        int i, j;
        cin >> i >> j;
        cout << dp[j] - dp[i - 1] << "\n";
    }
    return 0;
}