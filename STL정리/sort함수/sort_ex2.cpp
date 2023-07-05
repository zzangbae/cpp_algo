#include <iostream>
#include <algorithm>

int main() {
    // 숫자 배열
    int arr[] = {5, 2, 9, 1, 3};

    // 내림차순
    std::sort(std::begin(arr), std::end(arr), std::greater<>());
    for(int i = 0; i < 5; i++)
        std::cout << arr[i] << " ";

    std::cout << "\n";

    // 문자 배열
    char arr2[] = {'z', 'a', 'd', 'b', 'c'};

    // 오름차순(기본)
    std::sort(std::begin(arr2), std::end(arr2));
    for(int i = 0; i < 5; i++)
        std::cout << arr2[i] << " ";

    std::cout << "\n";

    // 내림차순(greate<>())을 활용
    std::sort(std::begin(arr2), std::end(arr2), std::greater<>());
    for(int i = 0; i < 5; i++)
        std::cout << arr2[i] << " ";
}