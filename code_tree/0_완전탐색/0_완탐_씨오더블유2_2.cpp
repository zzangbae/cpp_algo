#include <iostream>
#include <string>

using namespace std;

int n;
string str;

int main() {
    // 입력
    cin >> n;
    cin >> str;
    
    // 모든 쌍을 다 잡아봅니다.
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++)
                if(str[i] == 'C' && str[j] == 'O' && str[k] == 'W')
                    cnt++;
    
    cout << cnt;
    return 0;
}