#include <iostream>
#include <algorithm>
#include <string>

#define MAX_N 50000

using namespace std;

int n;
int arr[MAX_N];

// true면 a, b순서를 유지한다는 것.
// string은 길이에 순서상관없이 사전식 순서를 고수한다
bool cmp(int a, int b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n, cmp);

    for(int i = 0; i < n; i++)
        cout << arr[i];
    
    return 0;
}