#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 100000

using namespace std;

int n;
int a[MAX_N + 1]


int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    
    int ans = INT_MIN;
    int sum = 0;
    for(int i = 0; i <= n; i++) {
        if(sum < 0) // 이전까지의 합이 0보다 작다면, i부터 다시시작
            sum = a[i];
        else
            sum += a[i];
        
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}