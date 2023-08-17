## 출력 - 문제풀이 시 사용

#### cout

* C++ 표준 출력 스트림을 나타내는 객체

#### 객체 출력 형식 제어

`fixed`

* 부동 소수점 숫자를 고정된 소수점 형식으로 출력하도록 지정하는 매니퓰레이터(manipulator)
* 모든 부동 소수점 숫자가 고정된 소수점 형식으로 출력되게 된다.

```CPP
#include <iostream>

using namespace std;

int main()
{
    double num1 = 123.456789;
    double num2 = 123.444;
    cout << "fixed전 출력: " << num1 << "\n";
    cout << "fixed전 출력: " << num2 << "\n";
    
    cout << fixed;
    cout << "fixed후 출력: " << num1 << "\n";
    cout << "fixed후 출력: " << num2 << "\n";
    return 0;
}
/**
	fixed전 출력: 123.457
    fixed전 출력: 123.444
    fixed후 출력: 123.456789
    fixed후 출력: 123.444000
    fixed전에는 소수점 이하 3자리까지, 후에는 default값으로 6자리까지 출력된다.
    123.444의 경우 나머지 자리는 000으로 채워짐을 확인할 수 있다.
*/
```

`precision()`

* 출력되는 부동 소수점 숫자의 소수점 이하 자릿수를 설정한다.
* 이를 설정하지 않았기 때문에 기본적으로 6자리의 소수점 이하 숫자가 출력된 것이다.(위의 예제)
* precision 매니퓰레이터를 사용하여 출력할 소수점 이하 자릿수를 설정할 수 있다.

```CPP
#include <iostream>

using namespace std;

int main()
{
    double num1 = 123.456789;
    double num2 = 123.444;
    cout << "fixed전 출력: " << num1 << "\n";
    cout << "fixed전 출력: " << num2 << "\n";
    
    cout << fixed;
    cout.precision(4);
    cout << "fixed후 출력: " << num1 << "\n";
    cout << "fixed후 출력: " << num2 << "\n";
    return 0;
}

/**
	fixed전 출력: 123.457
    fixed전 출력: 123.444
    fixed후 출력: 123.4568
    fixed후 출력: 123.4440
    -> 소수점 아래 4자리임을 확인할 수 있다.
    -> 123.456789의 경우, 반올림을 통해서 123.4568이 됨을 확인할 수 있다.
*/
```

