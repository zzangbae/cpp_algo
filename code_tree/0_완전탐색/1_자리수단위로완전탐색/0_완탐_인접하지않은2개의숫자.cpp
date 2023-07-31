#include <iostream>
#include <climits>
#include <algorithm>
#define MAX_N 100

// 8:55 ~ 8:59
// 조건, 인접하지 않는
using namespace std;

int n;
int arr[MAX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int result = INT_MIN;
    int res_tmp = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 2; j < n; j++) {    // 인접하지 않다는 것을 구현하기 위해서 j + 2로 표현
            res_tmp = 0;
            res_tmp += arr[i] + arr[j];
            result = max(result, res_tmp);
        }
    }

    cout << result;
    return 0;
}