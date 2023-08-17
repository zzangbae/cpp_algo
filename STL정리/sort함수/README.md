## STL - Sort 활용

* C++에서 `sort`함수는 정렬 알고리즘을 사용하여 배열 또는 벡터의 요소들을 정렬하는 데에 사용

* <algorithm\> 헤더 파일에 정의되어 있음

* `begin()` ,`end()` 멤버 함수를 통해서 얻은 반복자를 사용한다.
* 기본값은 오름차순이다.
  * 즉, 작은 값이 앞으로 오도록 하는 것이 기본값이다.
  * 작은 것이 앞으로 올 때, true가 나오도록 bool함수가 비교함수로 설정되어있다.
    * 따라서 큰 값이 앞으로 오도록 하기위해선, 첫번째 요소(a)와 두번째 요소(b)를 비교하여 `a > b`일 때 true값이 반환되도록 하는 비교함수를 활용하면 된다.
* `sort(첫번째 매개변수, 두번째 매개변수, 비교함수 or 비교 연산자)`
  * 3번째 매개변수값이 false일 때, 자리바꿈이 일어난다.
  * 3번째 매개변수에 `std::less<>()` 혹은 `<`이 들어가면 오름차순으로 정렬하게 된다.(기본값)
  * 3번째 매개변수에 `std::greater<>()` 혹은 `>`이 들어가면 내림차순으로 정렬하게 된다.

#### 예시

```cpp
#include <iostream>
#include <algorithm>

int main() {
    int arr[] = {5, 2, 9, 1, 3};
    int arr2[] = {5, 2, 9, 1, 3};

    std::sort(arr, arr + 5);	// 이렇게 포인터를 활용할 수 있고
    std::sort(std::begin(arr2), std::end(arr2));	// 이렇게 반복자로 바로 할 수 도 있다.

    for(int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";		// 1 2 3 5 9
    }
    std::cout << "\n";

    for(int i = 0; i < 5; i++) {
        std::cout << arr2[i] << " ";	// 1 2 3 5 9
    }

    return 0;
}
```

#### 예시2(내림차순)

* `std::greater<>()` 을 활용

```cpp
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
```

#### 비교함수를 활용

* `compare` 함수를 활용
* 2차원 벡터에서 첫번째 요소는 내림차순, 두번째 요소는 오름차순으로 정렬

```cpp
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
  	// return a[1] < b[1] || a[1] == b[1]; // 이 경우, 기존의 자리가 바뀌게 된다.
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
// 결과
// [4, 5] [3, 2] [2, 2] [2, 3, 1] [2, 3, 2] [1, 2]
// [2, 3, 1]과 [2, 3, 2] 첫번째, 두번째 요소가 같은 경우를 확인하기 위함
```

#### 람다함수를 활용

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<std::vector<int>> arr = {{1, 2}, {2, 3}, {2, 2}, {3, 2}, {4, 5}};
		
  	// [] : 람다함수 활용
    std::sort(arr.begin(), arr.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
        if(a[0] > b[0])
            return true;
        else if (a[0] < b[0])
            return false;
        return a[1] < b[1];
    });

    for(int i = 0; i < arr.size(); i++) {
        std::cout << "[" << arr[i][0] << ", " << arr[i][1] << "] "; 
    }
}
```

#### cf)

* 람다함수에서 `const` 한정자를 사용한 이유

  * 람다 함수가 매개변수를 수정하지 않음을 나타냄 --> 매개변수를 읽기전용으로 강제

  * 람다 함수의 명시적 표현

  * 성능개선의 측면에서 컴파일러가 해당 매개변수를 변경할 필요가 없음을 알게됨

    --> 불필요한 복사 작업을 피하거나 최적화할 수 있는 여러 가지 기회를 제공

  * 안정성, 최적화

* 람다함수에서 `&` 를 사용하여 전달하는 이유

  * 레퍼런스(참조) 전달 : 원본 데이터를 참조함으로써 복사 비용을 줄일 수 있음. + 원본데이터에 대한 변경을 수행할 수도 있기는 하나, 위 사례는 const를 통해서 변경 수행을 막음
  * 가변 매개변수 : 람다함수에서 매개변수를  `const` 로 받으면 읽기 전용으로 제한됨. `&` 를 사용하면 매개변수를 읽고 쓸 수 있음. 따라서, 정렬 조건을 구현하는 람다 함수에서 매개변수 값을 변경해야 할 경우 `&` 를 사용하여 가변 매개변수를 선언할 수 있음 
