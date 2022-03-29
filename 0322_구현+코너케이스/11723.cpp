//
// Created by kjy82 on 2022-03-28.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<bool> S(21, false);
//있는지 없는지 확인만 하기 위해 bool형 배열 만든다
//있으면 true, 없으면 false

void addX(int x) { //S에 x를 추가
    S[x] = true;
}

void removeX(int x) { //S에서 x를 제거
    S[x] = false;
}

int checkX(int x) { //S에 x가 있는지 확인
    return S[x];
}

void toggleX(int x) { //S에 x가 있으면 제거, 없으면 추가
    if (S[x] == true) {
        S[x] = false;
        return;
    }
    S[x] = true;
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
        if (calculation == "all") {
            S.assign(21, true); //S에 1~20 모두 추가 (모두 true)
            continue;
        }
        else if (calculation == "empty") {
            S.assign(21, false); //S의 모든 원소 삭제 (모두 false)
            continue;
        }

        cin >> num;
        if (calculation == "add") {
            addX(num);
        }
        else if (calculation == "remove") {
            removeX(num);
        }
        else if (calculation == "check") {
            cout << checkX(num) << '\n';
        }
        else if (calculation == "toggle") {
            toggleX(num);
        }
    }

    return 0;
}