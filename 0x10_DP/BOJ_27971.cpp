#include<iostream>

using namespace std;

/**
 * N : 2 ~ 10만
 * M : 1 ~ 100, 닫힌 구간
 * A, B
*/

// 점화식 : dp[i] = min(dp[i - a] + 1, dp[i - b] + 1);
// 문제 다른 점: 조건 나눠서 하기

int n, m, a, b;
int dp[100005];
int l, r;

int main() {
    cin >> n >> m >> a >> b;
    dp[a] = 1;
    dp[b] = 1;
    int min_ab = min(a, b);
    int max_ab = max(a, b);
    for(int i = 0; i < m; i++) {
        cin >> l >> r;
        for(int j = l; j <= r; j++) {
            dp[j] = -1;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(dp[i] == -1) {
            continue; // 애초에 -1이면 스킵
        }
        // i가 a미만인 경우 -> -1
        if(i < min_ab) {
            dp[i] = -1;
        }
        else if(i == min_ab) {
            continue;
        }
        // i가 a초과, b미만 인 경우
        else if(min_ab < i && i < max_ab) {
            if(i - min_ab >= min_ab && dp[i - min_ab] > 0) {
                dp[i] = dp[i - min_ab] + 1;
            } else {
                dp[i] = -1;
            }
        }
        else if(i == max_ab) continue;
        // i가 a, b 중 큰 값보다 큰 경우
        else {
            if(dp[i - min_ab] <= 0 && dp[i - max_ab] <= 0) {
                dp[i] = -1;
            }
            else if(dp[i - min_ab] > 0 && dp[i - max_ab] <= 0) {
                dp[i] = dp[i - min_ab] + 1;
            }
            else if(dp[i - min_ab] <= 0 && dp[i - max_ab] > 0) {
                dp[i] = dp[i - max_ab] + 1;
            }
            else {
                dp[i] = min(dp[i - min_ab] + 1, dp[i - max_ab] + 1);
            }
        }
    }

    cout << dp[n];
    return 0;
}