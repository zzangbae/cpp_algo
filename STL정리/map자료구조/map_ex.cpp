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