// 10:32~11:09(37분, 22분 초과)
#include <iostream>
#include <algorithm>
#define MAX_P 10001
using namespace std;

int n, k;   // n:1~100, k:1~1만, 위치:1~1만
int place[MAX_P];
int main() {
    cin >> n >> k;
    int p;
    char c;
    int max_p = 0;
    for(int i = 0; i < n; i++) {
        cin >> p >> c;
        if(c == 'G') place[p] = 1;
        else if(c == 'H') place[p] = 2;
        max_p = max(max_p, p);  // 제일 오른쪽의 값
    }
    // 입력은 잘들어온다.

    int max_sum = 0;
    int tmp_sum = 0;
    for(int i = 1; i + k <= max_p; i++) {
        tmp_sum = 0;
        for(int j = i; j <= i + k; j++) {
            tmp_sum += place[j];
        }
        max_sum = max(max_sum, tmp_sum);
    }
    // k가 제일 큰 범위를 넘어서는 경우 -> 이게 엣지 케이스였음
    if(k >= max_p) {
        for(int i = 1; i <= max_p; i++) {
            max_sum += place[i];
        }
    }
    cout << max_sum;
    // 해설 풀이를 보면 i = 0 ~ MAX_NUM - k를 범위로 잡는다. 즉 전 범위에 대해서 계산한다.
    // 나의 경우, 전 범위 계산을 하지 않고, 특정 범위만 추려내기 위한 최적화 과정에서 엣지 케이스가 발견되었다.
    return 0;
}