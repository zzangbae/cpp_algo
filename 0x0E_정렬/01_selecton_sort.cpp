#include<iostream>
using namespace std;

/**
 * 선택 정렬
 * 시간 복잡도 : O(N^2)
 * 배열을 정렬시킬 때, 배열 내에서 가장 큰 것부터 혹은 가장 작은 것부터 찾아서 끝으로 보내며 정렬하는 정렬
 * 즉, 가장 큰 것이나 가장 작은 것을 '선택' 한다는 의미로 선택정렬이라고 부른다.
 * 따로 tmp 배열을 만들지 않기 때문에, inplace sort의 일종이다.
*/

int a[1000005];  // 정렬할 배열, 최대 100만까지 정렬시킨다고 하자
int n;  // 배열의 길이

// 오름차순으로 정렬하는 선택정렬 함수
void selection_sort(int arr[], int n) {
    for(int i = n - 1; i > 0; i--) {
        int mxidx = 0;
        for(int j = 1; j <= i; j++) {
            if(arr[mxidx] < arr[j]) mxidx = j;
        }
        swap(arr[mxidx], arr[i]);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    selection_sort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}