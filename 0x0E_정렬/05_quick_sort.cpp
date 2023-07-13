#include<iostream>
using namespace std;

/**
 * Quick sort(퀵 정렬)
 * 시간복잡도 : O(NlogN), 최악 O(N^2)
 * 머지 소트와 마찬가지로 '재귀적으로' 구현
 * pivot을 제 자리 값으로 보내는 정렬이다.
 * 퀵 소트의 장점은, 추가적인 공간을 필요로 하지 않는다는 것이다. 따라서 cache hit rate가 높아서 merge sort에 비해서 빠를 때가 있다.
 * => 따라서 inplace sort의 일종이다.
 * 단, 머지 소트와 다르게 stable sort는 아니다.
*/

int n;
int arr[1000005];

void quick_sort(int st, int en) {
    if(en <= st + 1) return;
    int pivot = arr[st];
    int l = st + 1;
    int r = en - 1;
    while(l) {
        while(l <= r && arr[l] <= pivot) l++;
        while(l <= r && arr[r] >= pivot) r--;
        if(l > r) break;
        swap(arr[l], arr[r]);
    }
    swap(arr[st], arr[r]);
    quick_sort(st, r);
    quick_sort(r + 1, en);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    quick_sort(0, n);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}