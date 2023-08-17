## tuple

#include \<tuple> 라이브러리 불러와야함

#### tuple

* **사물의 유한한 순서**를 뜻함
* 두 개 이상의 순서대로 정렬된 서로 다른 값들의 모임(데이터형이 다를 때 활용)

#### 선언

```CPP
std::tuple<int, char, string> t(10, 'x', "smart");
```

#### 관련 함수

`make_tuple` : 튜플을 만드는 함수

`get` : 튜플로부터 값을 가져오는 함수

`swap` : 튜플을 다른 튜플과 값을 바꾸는 함수(연산자 튜플의 값을 다른 변수에 전달)

`tie` : 튜플의 값들을 다른 변수에 전달

```CPP
// make_tuple
auto t = std::make_tuple(10, 'x', 'smart');

// get
std::get<2>(t);	// 인덱스로 접근: smart를 가져오게 된다.

// swap : 조건이 있다. 두개의 튜플이 서로 같은 형의 데이터를 같은 순서로 저장해야함
std::swap(t1, t2);

// tie
int x;
char y;
string z;
std::tie(x, y, z) = t;
```

#### 테스트 코드

```CPP
#include <iostream>
#include <tuple>

int main()
{
    auto t1 = std::make_tuple(10, 'x', "string");
    std::cout << "t의 3번째 원소: " << std::get<2>(t1) << "\n";
    
    auto t2 = std::make_tuple(20, 'y', "smart");
    std::cout << "t2의 3번째 원소: " << std::get<2>(t2) << "\n";
    
    std::swap(t1, t2);
    std::cout << "t1과 t2 바꿈" << "\n";
    
    std::cout << "t의 3번째 원소: " << std::get<2>(t1) << "\n";
    std::cout << "t2의 3번째 원소: " << std::get<2>(t2) << "\n";
    
    int x;
    char y;
    std::string z;
    std::tie(x, y, z) = t1;
    std::cout << "x : " << x << "\n";
    std::cout << "y : " << y << "\n";
    std::cout << "z : " << z << "\n";
    return 0;
}
/** 결과
	t의 3번째 원소: string
    t2의 3번째 원소: smart
    t1과 t2 바꿈
    t의 3번째 원소: smart
    t2의 3번째 원소: string
    x : 20
    y : y
    z : smart
*/
```





