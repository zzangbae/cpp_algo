#include <iostream>

#define MAX_N 100   // 이와같이 상수를 선언할 수 있음

using namespace std;

int n;
int arr[101];   // int arr[MAX_N];  -> 이렇게 선언한 상수를 이용해서 나타낼 수도 있음

int main() {
    // 0. 입력
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    // 1. 조합 돌리기
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++)
                if(arr[i] <= arr[j] && arr[j] <= arr[k]) cnt++;
    
    cout << cnt;

    return 0;
}