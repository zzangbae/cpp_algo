// 21:20~21:30(10분/121분) in time
#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_N 100000

using namespace std;

int n;
int arr[MAX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    int m = arr[0]; // 최소가격
    int result = INT_MIN;   // 최대이익
    for(int i = 1; i < n; i++) {
        m = min(m, arr[i]);
        result = max(result, arr[i] - m);
    }
    if(result <= 0) {
        cout << 0;
    } else {
        cout << result;
    }
    return 0;
}