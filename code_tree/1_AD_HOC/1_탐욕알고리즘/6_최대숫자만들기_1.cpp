// 1:46~1:54(8분) / 2:35~2:43(8분) (16분/11분) over time
#include <iostream>
#include <string>
#include <algorithm>
#define MAX_N 50000

using namespace std;

int n;  // 1~5만
long long arr[MAX_N];

bool sort_logic(long long a, long long b) {
    string ab = to_string(a) + to_string(b); 
    string ba = to_string(b) + to_string(b);
    int size_min = min(ab.size(), ba.size());
    string ab_ = "";
    string ba_ = "";
    // 같은 길이에서 비교
    for(int i = 0; i < size_min; i++) {
        ab_ += ab[i];
        ba_ += ba[i];
    }
    if(stol(ab_) > stol(ba_)) {
        return true;
    } else return false;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n, sort_logic);

    for(int i = 0; i < n; i++)
        cout << arr[i];
    
    return 0;
}

/**
    나는 너무 복잡하게 풀었다.
    그냥 a + b를 내림차순해서 정렬시켜주면 되는 문제다.
*/