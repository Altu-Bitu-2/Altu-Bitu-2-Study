//
// Created by kjy82 on 2022-04-15.
//

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, char> ci; //ci: int와 char 쌍

//특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int arrow_point, int n, vector<char> &wheel) {
    string ans = "";    //정답
    int start = arrow_point;    //idx를 start에 저장
    do {    //반복문 실행
        ans += wheel[arrow_point];  //정답에 wheel[arrow_point]를 추가
        arrow_point = (arrow_point + 1) % n;  //(arrow_point+1) % n, 즉 다음 idx값을 arrow_point에 저장
    } while (arrow_point != start); //arrow_point가 다시 처음 idx값으로 돌아오기 전까지 (한 바퀴 다 돌때까지) 반복
    return ans; //정답 반환
}

//행운의 바퀴 구하는 함수
string makeWheel(int n, vector<ci> &record) {
    vector<char> wheel(n, '?'); //바퀴의 상태
    vector<bool> is_available(26, false); //알파벳 중복 체크

    int idx = 0; //화살표가 가리키는 인덱스
    for (int i = 0; i < record.size(); i++) {   //record의 size(k)만큼 반복
        int rot = record[i].first;  //rot: 바퀴를 회전시켰을때 가리키는 글자가 몇 번 바뀌었는지
        char alpha = record[i].second;  //alpha: 회전 멈췄을때 가리켜진 글자
        idx = (idx - rot % n + n) % n;
        if (wheel[idx] == alpha) {  //wheel[idx]와 alpha 같을때 (이미 wheel[idx]에 접근해본 케이스)
            continue;   //다음 반복문 실행
        }
        if (wheel[idx] != '?' || is_available[alpha - 'A']) {
        /*
         * 이전 if문에서 wheel[idx] == alpha인 경우는 다뤄졌음!
         * 1. wheel[idx] != '?'
         * wheel[idx]에 alpha와 다른 글자가 저장되어있다 -> 한 칸에 두 글자 (모순)
         * 2. is_available[alpha - 'A']
         * 해당 글자의 is_available값이 이미 true -> 글자 중복이 있다 (모순)
         * */
            return "!"; //해당하는 바퀴 존재하지 않음. ! 출력
        }
        wheel[idx] = alpha; //가리킨 글자 wheel[idx]에 저장
        is_available[alpha - 'A'] = true;   //가리켜진 문자에 대해 is_available을 true로 바꿈
    }
    return arrowStartWheel(idx, n, wheel);  //바퀴에 존재하는 글자들을 문자열로 반환
}

/**
 * [행운의 바퀴]
 *
 * 바퀴가 돌아갈 필요 X
 * 화살표가 가르키는 인덱스를 회전 정보에 따라 바꿔줌
 *
 * 1. 화살표가 가르키는 칸이 결정되지 않았으면 알파벳을 바퀴에 적는다.
 * 2. 이미 알파벳이 써 있는 경우, 같은 알파벳이 아닌 경우 조건에 해당하는 바퀴 만들 수 없다.
 * 3. 바퀴에 쓰여있는 알파벳은 중복되지 않으므로 동일한 알파벳이 여러 자리에 있을 수 없다.
 */

int main() {
    int n, k;   //n: 바퀴의 칸 수, k: 바퀴를 돌리는 횟수

    //입력
    cin >> n >> k;
    vector<ci> record(k, {0, 0}); //바퀴 회전 기록
    for (int i = 0; i < k; i++) {   //k번 반복
        cin >> record[i].first >> record[i].second; //글자가 몇 번 바뀌었는지 + 가리킨 글자 입력받음
    }

    //연산 & 출력
    cout << makeWheel(n, record);
    return 0;   //프로그램 종료
}