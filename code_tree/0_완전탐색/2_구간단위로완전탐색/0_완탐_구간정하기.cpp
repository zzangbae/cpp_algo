// 11:18~11:42(24분, 10분초과 -> 인덱스, 문제 float변경 등의 놓친 부분 있었음)
#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 100
// 특정 구간을 잡았을 때, 구간안에
using namespace std;

int n;
int arr[MAX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int result = 0;
    int sum_interval = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            sum_interval = 0;
            int cnt = 0; // 범위 안의 원소의 갯수
            for(int k = i; k <= j; k++) {
                sum_interval += arr[k]; // 인덱스 실수 -> 시간 엄청씀
                cnt++;
            }
            
            float avg_v = (float)sum_interval / cnt;   // int형으로 할 경우 에러가 난다... 소숫점으로 출력되도록 해야한다.
            for(int k = i; k <= j; k++) {
                if(arr[k] == avg_v) {
                    result++;
                    break;  // 구간 당 하나의 숫자만
                }
            }
        }
    }
    cout << result;
        
    return 0;
}