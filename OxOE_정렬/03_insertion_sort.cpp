#include<iostream>
using namespace std;

/**
 * 삽입 정렬
 * 시간 복잡도 : O(N^2)
 * 최선의 경우, 이동없이 비교만 이루어지게 되어 O(N)으로 끝
 * 배열을 정렬 시킬 때, 배열의 두번째 자료부터 참고하여, 왼쪽의 값과 비교하며, 해당 값과 같거나 작은 값이 나올 때까지 나머지 카드를 오른쪽으로 이동시키는 것이다.
 * 즉, 이동시키고자 하는 자료를 어디에 '삽입'할 것인지 찾는 정렬이다.
*/

int a[1000005]; // 정렬할 배열, 최대 100만까지 정렬시킨다고 하자
int n;  // 배열의 길이

// 오름차순으로 정렬하는 삽입정렬 함수
void insertion_sort(int arr[], int n) {
    int key = 0;
    int j;
    for(int i = 1; i < n; i++) {
        key = arr[i];   // 삽입될 자리를 찾는 값
        for(j = i - 1; j >= 0 && arr[j] > key; j--) {
            arr[j + 1] = arr[j];    // 오른쪽으로 값을 이동시킴
        }
        arr[j + 1] = key;   // 더이상 이동 못한다면 j+1이 key가 들어갈 자리가 된다.
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    insertion_sort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}