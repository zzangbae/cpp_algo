// 10:49~11:04(15분/10분) over time
#include <iostream>
#define MAX_N 100000

using namespace std;

int n;  // 1~~10만개
int a[MAX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    int result = a[0];    // 맨 앞의 값이 초기값(n = 1)
    int sum = 0;
    for(int i = 1; i < n; i++) {
        sum += a[i];
        result = max(result, sum);
        if(sum < 0) sum = 0;
    }
    cout << result;
    return 0;
}

// 1번째 실수 : 음수고려 안함
// 풀이 : 그림 보고 해결