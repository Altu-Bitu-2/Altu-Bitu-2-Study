//
// Created by kjy82 on 2022-04-15.
//

#include <iostream>
#include <map>

using namespace std;

/**
 * [IF문 좀 대신 써줘]
 *
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power;  //n: 칭호의 개수, m: 캐릭터들의 수, power: 전투력 상한값
    string name;  //칭호 이름

    //입력
    cin >> n >> m;
    while (n--) {   //n번 반복
        cin >> name >> power;   //칭호의 이름과 전투력 상한값 입력받음
        if (title[power].empty()) { //해당 전투력 상한값에 대한 칭호가 title에 저장되어 있지 않다면
            title[power] = name;    //칭호 저장
        }
    }

    //출력
    while (m--) {   //m번 반복
        cin >> power;   //캐릭터들의 전투력 입력받음
        cout << title.lower_bound(power)->second << '\n';   //해당되는 칭호 출력
        //title.lower_bound(power): power이상의 값 중 가장 작은 값
    }
}