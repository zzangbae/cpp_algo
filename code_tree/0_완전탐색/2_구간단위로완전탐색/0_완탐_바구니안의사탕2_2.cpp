#include <iostream>
#include <algorithm>

#define MAX_NUM 100

using namespace std;

int n, k;
int arr[MAX_NUM + 1];

int main() {
    // 입력
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        int x, a;
        cin >> a >> x;
        
        arr[x] += a;
    }
    
    // 모든 구간의 시작점을 잡아봅니다.
    int max_sum = 0;
    for(int i = 0; i <= MAX_NUM; i++) {
        // 해당 구간 내 원소의 합을 구합니다.
        int sum = 0;
        for(int j = i - k; j <= i + k; j++)
            if(j >= 0 && j <= MAX_NUM)
                sum += arr[j];
        
        // 최댓값을 구합니다.
        max_sum = max(max_sum, sum);
    }
                        
    cout << max_sum;
    return 0;
}
/**
 * 해설에서 배워야할 점
 * 바구니 위치는 0~100인 반면, 범위 k는 바구니의 범위보다 더 클 수 있다.
 * -> 중심점을 모든 점으로 잡고
 * -> c-k ~ c+k 범위의 값을 모두 더하되,
 * -> 범위의 값이 바구니의 범위 안에 있을 때에만 값을 더할 수 있도록 한다.
 * **이렇게 하면 범위를 잡는 게 한층 쉬워진다.
*/