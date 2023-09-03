#include <iostream>

using namespace std;

int sum2n(int n) {
    // 재귀 종료조건
    if(n == 1)
        return 1;
    return n + sum2n(n - 1);
}

int main() {
    int n = 0;
    cin >> n;
    
    // for문을 통해서 구현
    int result = 0;
    for(int i = 1; i <= n; i++) {
        result += i;
    }
    cout << "result: " << result << "\n";

    // 재귀를 통해서 구현
    int result2 = 0;
    result2 = sum2n(n);
    cout << "result2: " << result2 << "\n";

    return 0;
}