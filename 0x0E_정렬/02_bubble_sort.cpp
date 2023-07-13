#include<iostream>
using namespace std;

/**
 * 버블 정렬
 * 시간복잡도 : O(N^2)
 * 배열을 정렬시킬 때(오름차순 기준), 맨 오른쪽 칸으로 가장 큰 값이 이동 되도록 하는 정렬
 * 값 비교후 정렬되는 모습이 거품모양이라서 '버블' 정렬이라고 부른다.
 * 따로 tmp 배열을 만들지 않기 때문에, inplace sort의 일종이다.
*/

int a[1000005]; // 정렬할 배열, 최대 100만까지 정렬시킨다고 하자
int n;  // 배열의 길이

// 오름차순으로 정렬하는 버블정렬 함수
void bubble_sort(int arr[], int n) {
    for(int i = n - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bubble_sort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}