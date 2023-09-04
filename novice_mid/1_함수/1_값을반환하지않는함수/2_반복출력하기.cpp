#include <iostream>

using namespace std;

int n;  // 1~100

void PrintNString(int n) {
    for(int i = 0; i < n; i++)
        cout << "12345^&*()_\n";
    return;
}

int main() {
    cin >> n;
    PrintNString(n);
    return 0;
}