// 7:53~8:35(42분/35분) 챗쥐피티 도움받음
#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 100000

using namespace std;

int n;  // 1~10만
vector<int> v;

int min_sum_of_pairs(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> min_heap;  // 최소 힙 선언
    for (int num : nums) {
        min_heap.push(num);  // 숫자들을 최소 힙에 추가
    }

    int total_sum = 0;
    while (min_heap.size() > 1) {
        int min1 = min_heap.top(); min_heap.pop();  // 가장 작은 숫자
        int min2 = min_heap.top(); min_heap.pop();  // 그 다음으로 작은 숫자
        
        int pair_sum = min1 + min2;
        total_sum += pair_sum;

        min_heap.push(pair_sum);  // 새로운 합을 힙에 추가
    }

    return total_sum;
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int result = min_sum_of_pairs(v);
    cout << result;
    return 0;
}

/**
priority_queue를 이용하는 문제 - 최소힙
*/