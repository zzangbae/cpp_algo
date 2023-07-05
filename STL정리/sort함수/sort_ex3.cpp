#include <algorithm>
#include <iostream>
#include <vector>

// 2차원 벡터에서 첫번째요소는 내림차순, 두번째 요소는 오름차순으로 정렬
// 1. 비교함수 활용
bool compare(const std::vector<int>& a, const std::vector<int>& b) {
    // 첫번째 요소를 내림차순으로 정렬
    if (a[0] > b[0])
        return true;
    else if (a[0] < b[0])
        return false;
    
    // 첫번째 요소가 같은 경우 두번째 요소를 오름차순으로 정렬
    return a[1] < b[1]; // 만약 두 요소가 다 같을 경우, false가 나와서 자리가 유지된다.
}

int main() {
    std::vector<std::vector<int>> arr = {{1, 2}, {2, 3, 1}, {2, 2}, {3,2}, {4, 5}, {2, 3, 2}};

    std::sort(arr.begin(), arr.end(), compare);

    for (const auto& vec : arr) {
        if(vec.size() == 3) {
            std::cout << "[" << vec[0] << ", " << vec[1] << ", " << vec[2] << "] ";
        } else {
            std::cout << "[" << vec[0] << ", " << vec[1] << "] ";
        }
    }
    return 0;
}