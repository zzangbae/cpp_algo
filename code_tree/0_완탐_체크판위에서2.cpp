#include <iostream>
using namespace std;

int r, c;
char arr[16][16];

int main() {
    cin >> r >> c;
    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++)
            cin >> arr[i][j];

    int cnt = 0;
    // 첫번째 색 받기
    char fc = arr[0][0];    // W or B
    char lc = arr[r - 1][c - 1];
    for(int i = 1; i < r - 2; i++) {
        for(int j = 1; j < c - 2; j++) {
            if(arr[i][j] == fc) continue;   // 처음 것과 달라야함
            for(int k = i + 1; k < r - 1; k++) {
                for(int l = j + 1; l < c - 1; l++) {
                    if(arr[k][l] == arr[i][j]) continue;   // 전 것과 달라야함
                    if(arr[k][l] == lc) continue;   // 마지막 것과 달라야함
                    cnt++;
                }
            }
        }
    }
    
    /**
        해설풀이와 다른점은 미리 19줄 if문을 통해서 필요없는 반복문을 빠지게 함
    */
    cout << cnt;
    return 0;
}