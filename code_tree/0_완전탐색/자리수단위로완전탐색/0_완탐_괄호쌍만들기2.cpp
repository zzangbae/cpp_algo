#include <iostream>
#include <string>
// 3 : 43 ~ 3 : 58
using namespace std;

// 3번과 다른 점은 두 개씩 짝을 지어주어야 한다. + 연속한**이것때문에 오래걸림

string s;

int main() {
    cin >> s;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ')' || s[i + 1] == ')') continue;
        for(int j = i + 2; j < s.size() - 1; j++) {
            if(s[j] == '(' || s[j + 1] == '(') continue;
            cnt++;
        }
    }
    cout << cnt;    
    return 0;
}