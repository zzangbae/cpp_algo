#include <iostream>
#include <vector>
#include <string>

using namespace std;

string a;
vector<int> open;
vector<int> close;
int main() {
    cin >> a;
    for(int i = 0; i < a.length(); i++) {
        if(a[i] == '(') open.push_back(i);
        else if(a[i] == ')') close.push_back(i);
    }
    int result = 0;
    // 여는 괄호가 먼저 나와야 한다...
    for(int op : open) {
        for(int cl : close) {
            if(op < cl) result++; 
        }
    }
    cout << result;
    
    return 0;
}