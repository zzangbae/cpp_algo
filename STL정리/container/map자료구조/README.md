## STL 컨테이너 - map 자료구조

* STL 컨테이너의 일종
* '키'와 '값'의 쌍으로 이루어진 제네릭 컨테이너
  * 내부 구현 : 검색, 삽입, 삭제 O(logN)인 레드블랙트리로 구성되어 있음
* 기본 형태 : `map<key, value> m`
* MAP 정렬
  * 자료를 저장할 때, 내부적으로 자동으로 정렬
  * key를 기준으로 정렬하며 오름차순으로 정렬
  * 내림차순 정렬을 원하면 `map<int, int, greater> m` 이렇게 하면됨
* `#include<map>` 처리 해야함

#### 예시

```cpp
#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    // 1. map 선언 : map<key type, vale type> 이름
    map<string, int> m;

    // 2. find메서드 : 찾고자하는 데이터 있는지 확인(iterator 사용)
    // 없을 경우, 맵의 끝을 가리키는 참조 리턴한다.
    if(m.find("Alice") != m.end()) {
        cout << "find" << "\n";
    } else {
        cout << "not find" << "\n";
    }
    // 결과 : not find

    // 3. insert메서드 : 삽입
    m.insert({"zzangbae", 1});
    // 3-1.아래와 같이 원소를 저장할 수 있음
    m["changbae"] = 2;

    // 4. 키로 값 알아내기
    cout << m["changbae"] << "\n";  // 2

    // 5. 반복문 데이터 접근(first, second)
    // 5-1. 인덱스 기반
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << " " << iter->second << "\n";
    }
    cout << "\n";
    /**
     * changbae 2
      zzangbae 1
      - key값을 기준을 정렬되었음을 확인할 수 있다.
    */

    // 5-2. 범위기반 반복문 활용
    for(auto iter: m) {
        cout << iter.first << " " << iter.second << "\n";
    }

    // 6. 삭제(erase, clear)
    // 6-1. 특정 위치 요소 삭제
    m.erase(m.begin());

    for(auto iter: m) cout << iter.first << " " << iter.second << "\n"; // changbae, 1 은 삭제되었음을 확인할 수 있다.

    // 6-2. 키값을 기준으로 삭제
    m.erase("zzangbae");

    for(auto iter: m) cout << iter.first << " " << iter.second << "\n"; // 아무것도 나오지 않는다.


    // 6-3. 모든 요소 제거
    m.clear();

    return 0;
}
```

#### 정리

* map 선언 : `map<key type, value type> 이름`

* map 삽입

  * 선언 : `map<string, int> m;`
  * insert활용 ; `m.insert({"zzangbae", 1});`
  * key, value : `m["changbae"] = 2;`

* map에 키값으로 value 찾기

  * 키값으로 value 찾기
  * `cout << m["zzangbae"] << "\n";` --> 2출력됨

* map에 해당 키값이 있음을 확인하기(find메서드)

  * `m.find("Alice")` -> 있을 경우, 있는 곳의 오퍼레이터가 반환
  * 없을 경우, m.end()가 반환
  * 따라서 있음 여부는 위의 예제처럼 m.end()와 비교해서 찾는다.

* map 삭제

  * 전체 삭제 : `m.clear();`
  * 특정 인덱스 삭제 : `m.erase(m.begin() + 2);`
  * 특정 부분 삭제 : `m.erase(m.begin(), m.begin() + 2);`
  * 키값 기준 삭제 : `m.erase("zzangbae");`

* map을 이용한 데이터 조회

  * 인덱스 기반

    ```cpp
    for(auto iter = m.begin(); iter != m.end()l iter++) {
      cout << iter->first << " " << iter->second << "\n";
    }
    ```

    

  * 범위 기반

    ```cpp
    for(auto iter : m) {
      cout << iter.first << " " << iter.second << "\n";
    }
    ```

    

  