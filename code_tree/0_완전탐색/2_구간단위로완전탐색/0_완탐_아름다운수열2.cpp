// 9:30~10:15(45분소요. 27분과 18분 차이)
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 100
#define MAX_M 100
using namespace std;

int n, m;
int nrr[MAX_N];
int mrr[MAX_M];
int wrr[MAX_M];
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> nrr[i];
    for(int i = 0; i < m; i++)
        cin >> mrr[i];

    // 입력까진 잘들어온다.

    int cnt = 0;
    // 구간단위로 진행하며 포함된 모든 수가 
    for(int i = 0; i <= n - m; i++) {
        // 비교 초기화
        for(int w = 0; w < m; w++)
            wrr[w] = mrr[w];

        int cc = 0; // cc가 m이 되어야함
        for(int j = i; j < i + m; j++) {
            for(int k = 0; k < m; k++) {
                if(nrr[j] == wrr[k]) {  // 변수명 조심하자!
                    wrr[k] = -1;
                    cc++;
                    break;
                }
            }
        }
        if(cc == m) cnt++;
    }
    cout << cnt;
    return 0;
}