//
// Created by kjy82 on 2022-03-28.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

set<int> S;

void addX(int x) { //S에 x를 추가
    S.insert(x);
}

void removeX(int x) { //S에서 x를 제거
    if(S.find(x) != S.end())
        S.erase(x);
}

int checkX(int x) { //S에 x가 있는지 확인
    if (S.find(x) != S.end())
        return 1; //있으면 1 리턴
    return 0;
}

void toggleX(int x) { //S에 x가 있으면 제거, 없으면 추가
    if (S.find(x) != S.end()) {
        S.erase(x);
        return;
    }
    S.insert(x);
}

void all() { //S를 {1, 2, ..., 20}으로 바꾼다
    S.clear();
    for (int i = 0; i < 20; i++) {
        S.insert(i + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, num;		//M: 연산의 수, num: 연산할 숫자
    string calculation;

    //입력
    cin >> M;
    while (M--) {
        cin >> calculation;
        if (calculation == "add") {
            cin >> num;
            addX(num);
        }
        else if (calculation == "remove") {
            cin >> num;
            removeX(num);
        }
        else if (calculation == "check") {
            cin >> num;
            cout << checkX(num) << '\n';
        }
        else if (calculation == "toggle") {
            cin >> num;
            toggleX(num);
        }
        else if (calculation == "all") {
            all();
        }
        else
            S.clear(); //S를 공집합으로
    }

    return 0;
}