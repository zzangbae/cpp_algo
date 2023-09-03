#include <iostream>

using namespace std;

int n;
int result;

int sum(int n) {
    if(n == 1) return 1;
    else {
        return n + sum(n - 1);
    }
}

int main() {
    cin >> n;
    
    // 재귀적으로 더하기
    result = sum(n);
    cout << "result : " << result; 

    cout << "\n";
    
    // 반복문으로 더하기
    int result2 = 0;
    for(int i = 1; i <= n; i++)
        result2 += i;

    cout << "result2 : " << result2;
    return 0;
}