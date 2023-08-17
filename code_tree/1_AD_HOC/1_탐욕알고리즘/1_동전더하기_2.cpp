#include <iostream>
#define MAX_N 10

using namespace std;

int n, k;
int coins[MAX_N];

int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> coins[i];

    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        ans += k / coins[i];
        k %= k % coins[i];
    }
    cout << ans;
    return 0;
}