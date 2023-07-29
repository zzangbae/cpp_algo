#include <iostream>
#include <string>

using namespace std;

string str;

int main() {
    // 입력
    cin >> str;
    int n = (int) str.size();
    
    // 모든 쌍을 다 잡아봅니다.
    int cnt = 0;
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n - 1; j++)
            if(str[i] == '(' && str[i + 1] == '(' && str[j] == ')' && str[j + 1] == ')')
                cnt++;
    
    cout << cnt;
    return 0;
}