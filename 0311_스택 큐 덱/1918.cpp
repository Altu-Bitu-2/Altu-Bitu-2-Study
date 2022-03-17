//
// Created by kjy82 on 2022-03-17.
//

#include <iostream>
#include <stack>


using namespace std;


// (,) 와 +,-와 *,/의 우선순위 설정
// 왜? -> *(/)는 +(-)보다 먼저 계산해야 함
int priority(char ch) {
    switch (ch) {
        case '(': case ')':
            return 0;
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
    }
}


// 중위 표기식을 후위 표기식으로 고치는 함수
void infix_to_postfix(string& s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            // 문자열에 연산부호가 오면 스택에 push
            // 스택에 *(/), 문자열에 +(-)가 오면 *(/)를 출력하고 +(-)를 push
            case '+': case '-': case '*': case '/':
                while (!st.empty() && (priority(s[i]) <= priority(st.top()))) {
                    cout << st.top();
                    st.pop();
                }
                st.push(s[i]);
                break;
                // 문자열에 '('가 오면 스택에 push
            case '(':
                st.push(s[i]);
                break;
                // 문자열에 ')'가 오면 스택에서 이와 짝이 되는 '('를 만날때까지 스택의 원소들을 출력
            case ')':
                while (st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
                break;
                // 알파벳은 스택에 push하지 않고 바로 출력
            default:
                cout << s[i];
                break;
        }
    } //for문 끝
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }
}


int main() {
    string s;

    //입력
    cin >> s;

    //변환 및 출력
    infix_to_postfix(s);

    return 0;
}