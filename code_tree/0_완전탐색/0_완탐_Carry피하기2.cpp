#include <iostream>
#define MAX_N 20
// 9:18 ~ 9:30 (12분)

using namespace std;

int n;
int arr[MAX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int result = -1;    // 모든 짝에서 발생할 경우, -1이 반환**
    // 캐리가 나는 상황을 어떻게 표현할 것인가...
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                // 몫 - 나머지 스킬을 이용하면 될 것 같아요
                // 1~1만까지의 숫자네요, 최대 5자리라는 얘기네요
                // 각 숫자의 자릿수를 모두 내놓고, 해당 자릿수를 더했을 때 캐리 여부를 판단
                // 사실 만의 자리는 판단할 필요가 없다. 1 1 1 캐리나올 수 없음
                // 천의 자리
                int a_2 = (arr[i] % 10000) / 1000;
                int b_2 = (arr[j] % 10000) / 1000;
                int c_2 = (arr[k] % 10000) / 1000;
                if(a_2 + b_2 + c_2 >= 10) continue;
                
                // 백의 자리
                int a_3 = (arr[i] % 1000) / 100;
                int b_3 = (arr[j] % 1000) / 100;
                int c_3 = (arr[k] % 1000) / 100;
                if(a_3 + b_3 + c_3 >= 10) continue;

                // 십의 자리
                int a_4 = (arr[i] % 100) / 10;
                int b_4 = (arr[j] % 100) / 10;
                int c_4 = (arr[k] % 100) / 10;
                if(a_4 + b_4 + c_4 >= 10) continue;

                // 일의 자리
                int a_5 = (arr[i] % 10);
                int b_5 = (arr[j] % 10);
                int c_5 = (arr[k] % 10);
                if(a_5 + b_5 + c_5 >= 10) continue;
                
                // 자릿수별로 계산했으면 좀 더 빨랐을 것 같아서 개선함

                result = max(arr[i] + arr[j] + arr[k], result);
            }
        }
    }
    cout << result;

    return 0;
}