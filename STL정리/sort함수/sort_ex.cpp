#include <algorithm>
#include <iostream>

int main() {
    int arr[] = {5, 2, 9, 1, 3};
    int arr2[] = {5, 2, 9, 1, 3};

    std::sort(arr, arr + 5);
    std::sort(std::begin(arr2), std::end(arr2));

    for(int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    for(int i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";
    }

    return 0;
}