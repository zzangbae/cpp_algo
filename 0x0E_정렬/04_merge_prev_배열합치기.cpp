#include<iostream>
using namespace std;

/**
 * 병합 정렬에 이용될 내용을 공부해보자
 * 먼저 '(오름차순)정렬된' 두 배열을 더해서 새로운 오름차순 정렬 배열을 만드는 문제를 생각해보자.
*/

// 백준문제 11728 : 배열 합치기
int n, m;
int a[1000005], b[1000005], c[2000005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];
    int aidx = 0, bidx = 0; // 배열 내의 최소값의 인덱스
    for(int i = 0; i < n + m; i++) {
        // b배열의 값이 이미 다 쓰인 경우
        if(bidx == m) c[i] = a[aidx++];
        // a배열의 값이 이미 다 쓰인 경우
        else if(aidx == n) c[i] = b[bidx++];
        // a배열의 갱신된 최소값이 b배열의 갱신된 최소값보다 작거나 같은 경우 -> stable sort
        else if(a[aidx] <= b[bidx]) c[i] = a[aidx++];
        // b배열의 갱신된 최솟값이 더 작은 경우
        else c[i] = b[bidx++];
    }
    for(int i = 0; i < n + m; i++) cout << c[i];
}