#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n, k;
int arr[MAX_N];

int main() {
    // 입력
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 모든 구간의 시작점을 잡아봅니다.
    int max_sum = 0;
    for(int i = 0; i <= n - k; i++) {
        // 해당 구간 내 원소의 합을 구합니다.
        int sum = 0;
        for(int j = i; j < i + k; j++)
            sum += arr[j];
        
        // 최댓값을 구합니다.
        max_sum = max(max_sum, sum);
    }
                        
    cout << max_sum;
    return 0;
}