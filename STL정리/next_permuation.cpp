#include<iostream>
#include<algorithm>
// 순열 조합을 깔끔하게 해결
using namespace std;

int main() {
    // 1. 순열로 활용하기
    int a[3] = {1, 2, 3};
    do{
        for(int i = 0; i < 3; i++)
            cout << a[i];
        cout << "\n";
    } while(next_permutation(a, a + 3));

    cout << "-----------------\n";
    // 2. 조합으로 활용하기
    int b[4] = {0, 0, 1, 1};
    do{
        for(int i = 0; i < 4; i++) {
            if(b[i] == 0)
                cout << i + 1;
        }
        cout << "\n";
    } while(next_permutation(b, b + 4));
}