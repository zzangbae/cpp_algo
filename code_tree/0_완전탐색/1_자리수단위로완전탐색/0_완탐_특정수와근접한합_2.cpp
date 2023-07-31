#include <iostream>
#include <climits>

using namespace std;

#define MAX_N 100

int n, s;
int arr[MAX_N];
int array_sum;
int ans = INT_MAX;

int main() {
    // 입력
    cin >> n >> s;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 배열의 값들의 총합을 미리 구해둡니다.
    for(int i = 0; i < n; i++)
        array_sum += arr[i];
    
    // 모든 쌍을 다 잡아봅니다.
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            // i번과 j번 수를 제외할 경우 남은 숫자들의 총합은 다음과 같습니다.
            int new_sum = array_sum - arr[i] - arr[j];

            int diff = abs(new_sum - s);
            ans = min(ans, diff);
        }
    
    // 정답을 출력합니다.
    cout << ans;
    return 0;
}