// 6:29~6:34
#include <iostream>
#include <algorithm>

using namespace std;

int x, y;   // 1~1만

int main() {
    cin >> x >> y;
    int result = 0;
    for(int i = x; i <= y; i++) {
        int a = i / 10000;              // 만의자리
        int b = (i % 10000) / 1000;     // 천의자리
        int c = (i % 1000) / 100;       // 백의자리
        int d = (i % 100) / 10;         // 십의자리
        int e = i % 10;                 // 일의자리
        result = max(result, a + b + c + d + e);
    }

    cout << result;
    
    return 0;
}
/**
 - 해설의 재귀적인 표현에 유의하자
*/