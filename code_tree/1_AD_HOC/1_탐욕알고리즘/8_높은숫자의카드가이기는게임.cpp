#include <iostream>
#include <unordered_set>
#include <algorithm>

#define MAX_N 50000

using namespace std;

/**
    Intuition
    A의 카드 중 작은 숫자부터 순서대로 보며 남아있는 B의 숫자보다 더 큰 경우 바로 매칭을 진행하는 것이 항상 유리함
    5만 -> 시간복잡도 O(NlogN)까지 가능하다
*/

int n;
int a_cards[MAX_N];
int b_cards[MAX_N];

unordered_set<int> b_set;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> b_cards[i];
        b_set.insert(b_cards[i]);
    }

    // a카드 완성
    int card_idx = 0;
    for(int i = 1; i <= 2 * n; i++)
        if(b_set.find(i) == b_set.end())
            a_cards[card_idx++] = i;
    
    // 오름차순 정렬 -> O(NlogN)
    sort(a_cards, a_cards + n);
    sort(b_cards, b_cards + n);
    
    int ans = 0;
    int b_idx = 0;
    for(int a_idx = 0; a_idx < n; a_idx++) {
        // a가 현재 b카드보다 우세하면
        // 둘을 매칭해주는게 항상 유리하다
        if(b_idx < n && a_cards[a_idx] > b_cards[b_idx]) {
            ans++;
            b_idx++;
        }
    }

    cout << ans;

    return 0;
}