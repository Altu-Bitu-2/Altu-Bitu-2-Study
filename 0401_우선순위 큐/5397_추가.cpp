//
// Created by kjy82 on 2022-04-08.
//

#include <iostream>
#include <deque>

using namespace std;

//dq로부터 문자열 얻어내는 함수
string dqToString(deque<char> &dq) {
    string ans = "";    //강산이의 비밀번호
    while (!dq.empty()) {   //dq가 비어있지 않을동안
        ans += dq.front();  //ans에 dq 맨 앞의 원소 더한 후
        dq.pop_front();     //dq 맨 앞의 원소 삭제
    }
    return ans;     //강산이의 비밀번호 반환
}

//강산이의 비밀번호를 찾아내는 함수
string findPass(string s) {
    deque<char> dq_left;  //커서 이전 내용을 저장
    deque<char> dq_right; //커서 이후 내용을 저장

    for (int i = 0; i < s.length(); i++) {  //문자열의 길이만큼 반복
        switch (s[i]) { //문자에 따라 케이스 나눔
            case '-': //현재 커서 앞에 있는 글자를 지운다.
                if (!dq_left.empty()) { //dq_left에(커서 앞에) 글자가 있다면
                    dq_left.pop_back(); //dq_left의 마지막 원소 삭제
                }
                break;  //케이스 빠져나오기
            case '<': //커서를 왼쪽으로 이동 -> dq_left 의 마지막 원소를 dq_right 앞에 삽입
                if (!dq_left.empty()) { //dq_left에 글자가 있다면
                    dq_right.push_front(dq_left.back());    //dq_left의 마지막 원소 dq_right의 맨 앞에 삽입
                    dq_left.pop_back(); //dq_left의 마지맛 원소 삭제 (dq_right에 넣었으니까)
                }
                break;  //케이스 빠져나오기
            case '>': //커서를 오른쪽으로 이동 -> dq_right 의 처음 원소를 dq_left 의 마지막에 삽입
                if (!dq_right.empty()) {    //dq_right에 글자 있다면
                    dq_left.push_back(dq_right.front());    //dq_right의 맨 앞의 원소 dq_left의 마지막에 삽입
                    dq_right.pop_front();   //dq_right 맨 앞의 원소 삭제(dq_left에 넣었으니까)
                }
                break;  //케이스 빠져나오기
            default: //문자인 경우, 입력을 하면 커서보다 왼쪽에 위치하므로 dq_left에 삽입
                dq_left.push_back(s[i]);    //dq_left에 문자 삽입
                break;  //케이스 빠져나오기
        }
    }

    string pass = dqToString(dq_left);  //커서 앞의 문자들 pass에 저장
    pass += dqToString(dq_right);   //커서 뒤의 문자들 마저 pass에 추가
    return pass;    //정답 비밀번호 반환
}

/**
 * [키로거]
 *
 * 해당 풀이는, 글자 삽입 삭제 시 이동시키는 과정에서 생기는 코너케이스를 해결하기 위해 커서를 기준으로 왼쪽, 오른쪽으로 나눠서 값을 저장함
 *
 * 1. 커서 앞의 글자를 지울 때, 글자가 없는 경우 주의
 * 2. 커서를 왼쪽으로 이동할 때, 이미 가장 왼쪽에 커서가 있는 경우 주의
 * 3. 커서를 오른쪽으로 이동할 때, 이미 가장 오른쪽에 커서가 있는 경우 주의
 */

int main() {
    int t;  //테스트케이스의 수
    string s;   //강산이가 입력한 문자열

    //입력
    cin >> t;   //t 입력받음
    while (t--) {   //테스트케이스의 수만큼 과정 반복
        cin >> s;   //문자열 입력받음

        //연산 & 출력
        cout << findPass(s) << '\n';
    }
    return 0;   //프로그램 종료
}