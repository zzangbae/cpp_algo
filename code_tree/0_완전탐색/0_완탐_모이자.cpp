#include <iostream>
#include <algorithm>
#include <climits>  // climits 라이브러리를 통해서 INT_MAX, INT_MIN값을 받아올 수 있음

using namespace std;

int n;
int arr[101];

int main() {
    // 가능한 이동 거리의 합 중 최솟값
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];  // 각각 살고 있는 숫자

    int min_sum = INT_MAX;
    for(int i = 0; i < n; i++) {
        int a = i;  // 모일 집
        int sum_diff = 0;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            sum_diff += arr[j] * abs(j - i);    // 명수 * 거리
        }
        min_sum = min(min_sum, sum_diff);
    }

    cout << min_sum;
    return 0;
}