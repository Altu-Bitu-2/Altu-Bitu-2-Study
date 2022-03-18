//
// Created by kjy82 on 2022-03-17.
//

#include <iostream>
#include <map>


using namespace std;


//팰린드롬 생성 함수
string palindrome(string &s, map<char, int>& m) {
    int index = 0;
    for (auto iter : m) {
        for (int i = 0; i < iter.second / 2; i++) {
            s[index] = s[s.length() - 1 - index] = iter.first;
            index++;
        }
        if (iter.second % 2 == 1) {
            s[s.length() / 2] = iter.first;
        }
    }
    return s;
}


int main() {
    string s;
    map<char, int> m;
    int count = 0;

    //입력
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        m[s[i]]++;
    }

    //팰린드롬 생성이 불가능한 경우 판별
    if (s.length() % 2 == 0) {
        for (auto iter : m) {
            if (iter.second % 2 == 1) {
                cout << "I'm Sorry Hansoo" << '\n';
                return 0;
            }
        }
    }
    else {
        for (auto iter : m) {
            if (iter.second % 2 == 1) {
                count++;
                if (count == 2) {
                    cout << "I'm Sorry Hansoo" << '\n';
                    return 0;
                }
            }
        }
    }

    s = palindrome(s, m);

    //출력
    cout << s << '\n';

    return 0;
}