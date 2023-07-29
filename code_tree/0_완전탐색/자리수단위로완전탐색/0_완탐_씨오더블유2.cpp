#include <iostream>
#include <string>
// 9:00~9:06

using namespace std;

int n;
string s;

int main() {
    cin >> n;
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] != 'C') continue;
        for(int j = i + 1; j < s.size(); j++) {
            if(s[j] != 'O') continue;
            for(int k = j + 1; k < s.size(); k++) {
                if(s[k] != 'W') continue;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}