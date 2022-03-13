//
// Created by kjy82 on 2022-03-13.
//

#include <iostream>
#include <set>


using namespace std;


void search_num(set<int> s, int i) {
    for (auto iter : s) {
        if (iter == i) { //수첩 2에 적힌 숫자가 수첩 1에 있을 때
            cout << 1 << '\n';
            return;
        }
    }
    cout << 0 << '\n'; //없을 때
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M, input;
    set<int> note1;

    //입력
    cin >> T; //테스트케이스의 개수
    for (int i = 0; i < T; i++) {
        //수첩 1
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> input;
            cout << input << ' ';
            note1.insert(input);
        }
        //수첩 2
        cin >> M;
        for (int k = 0; k < M; k++) {
            cin >> input;
            search_num(note1, input);
        }
    }
    return 0;
}