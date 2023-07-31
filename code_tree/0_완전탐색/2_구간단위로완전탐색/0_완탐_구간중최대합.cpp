// 10:27~10:31
#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 100

using namespace std;

int n, k;   // K <= n: 1~100
int arr[MAX_N];
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int max_sum = INT_MIN;
    int tmp_sum = 0;
    for(int i = 0; i <= n - k; i++) {
        tmp_sum = 0;    // 초기화 필수
        for(int j = i; j < i + k; j++) {
            tmp_sum += arr[j];
        }
        max_sum = max(max_sum, tmp_sum);
    }
    cout << max_sum;
    return 0;
}