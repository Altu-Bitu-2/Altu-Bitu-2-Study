//
// Created by kjy82 on 2022-03-25.
//

#include <iostream>
#include <stack>

using namespace std;

//A + B 함수, 일의 자릿수부터 더함
stack<int> calcPlus(string &a, string &b) {
    //결과값 담을 스택 st 선언
    stack<int> st;
    int p1 = a.length() - 1; //a의 일의 자릿수 인덱스
    int p2 = b.length() - 1; //b의 일의 자릿수 인덱스
    bool carry = false; //올림 체크 변수

    while (p1 >= 0 && p2 >= 0) { //자릿수 더하기
        int num = (a[p1--] - '0') + (b[p2--] - '0'); //a와 b의 각 자릿수 값 더하기
        num += carry; //carry 있으면 num에 더해준다
        carry = num / 10;  //자릿수 더한 값이 10을 넘으면 올림변수 체크
        st.push(num % 10); //올림값 제외한 값만 스택에 저장
    }
    while (p1 >= 0) { //a에서 남은 숫자 반영
        int num = (a[p1--] - '0'); //a의 해당 자릿수 값
        num += carry; //carry 있으면 num에 더한다
        carry = num / 10;
        st.push(num % 10);
    }
    if (carry) { //마지막 올림 확인
        st.push(1);
    }

    //결과값 반환
    return st;
}

/**
 * 1. 한 자릿수씩 더해서 스택(혹은 배열)에 저장
 * 2. 한 자릿수씩 더할 때, 값이 10을 넘어가는 경우 고려 -> 자릿수 올림
 * 3. A와 B의 길이가 같지만, 둘의 합의 길이는 다른 경우 고려 -> 마지막 자리에서 올림
 * 4. A와 B의 길이가 다른 경우 고려 -> 더 긴 길이 처리 주의,
 *                                코드 중복을 피하기 위해 A가 B보다 길도록 먼저 처리하고 시작
 *
 * 본 풀이에서 더한 결과값을 스택에 넣는 이유는 일의자릿수부터 더하기 때문
 * 배열을 사용할 경우 마지막 인덱스부터 출력하면 됨
 */

int main() {
    string a, b; //입력 수가 매우 크므로 string 으로 입력
    stack<int> st; //더한 결과값 저장할 스택

    //입력
    cin >> a >> b;

    //연산
    if (a.length() < b.length()) { //b가 더 길다면
        //a가 더 길도록 a와 b swap
        swap(a, b);
    }
    //결과값 st에 저장
    st = calcPlus(a, b);

    //출력
    //st이 빌때까지
    while (!st.empty()) {
        //top에 있는 원소 출력
        cout << st.top();
        //top에 있는 원소 pop(조건: st이 빌때까지니 pop 안하면 무한루프)
        st.pop();
    }
    //엔터 출력
    cout << '\n';

    //main함수 종료
    return 0;
}