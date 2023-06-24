#include<iostream>
using namespace std;

/**
 * Merge sort(병합정렬)
 * 시간복잡도 : O(NlogN)
 * 중간에 있는 값을 중심으로, 왼쪽에는 중간에 있는 값보다 작은 값들, 오른쪽에는 중간에 있는 값보다 큰 값들을 모은다. 그리고 그 왼쪽, 오른쪽에 있는 값들을 정렬시킨다. 단, 재귀적으로 파고 들어가서 배열을 쪼개고 쪼개서 정렬시키고 붙이는 식으로 진행한다.
 * 즉, 배열을 작은 배열들로 나누고, 그들을 정렬시키고 붙이는 '병합'의 방법을 활용하는 정렬이다.
 * divide and conquer을 이용한 사례이다.
 * tmp 배열을 활용하기 때문에 stable sort의 일종이다.
*/

int a[1000005]; // 정렬할 배열, 최대 100만
int n;  // 배열의 길이
int tmp[1000005];   // 정렬된 배열을 임의로 담는 배열

// 이 함수는 11728 배열합치기를 공부하면 이해가 가능한 함수
void merge(int st, int en) {
    int mid = (st + en) / 2;
    int lidx = st;
    int ridx = mid;
    for(int i = st; i < en; i++) {
        // 오른쪽 배열의 인덱스가 끝나버림
        if(ridx == en) tmp[i] = a[lidx++];
        // 왼쪽 배열의 인덱스가 끝나버림
        else if(lidx == mid) tmp[i] = a[ridx++];
        // 왼쪽 배열의 갱신 최솟값이 더 작음
        else if(a[lidx] <= a[ridx]) tmp[i] = a[lidx++];
        else tmp[i] = a[ridx++]; 
    }
    for(int i = st; i < en; i++) a[i] = tmp[i];
}

void merge_sort(int st, int en) {
    if(en == st + 1) return;
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st, en);
}

int main() {
    // 입력 빠르게 하기
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge_sort(0, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}