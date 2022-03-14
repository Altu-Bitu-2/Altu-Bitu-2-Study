//
// Created by kjy82 on 2022-03-14.
//

#include <iostream>
#include <unordered_set>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N, M, input;
    unordered_set<int> note1;

    //입력
    cin >> T; //테스트케이스의 개수
    while (T--) {
        //수첩 1
        cin >> N;
        while (N--) {
            cin >> input;
            note1.insert(input);
        }
        //수첩 2
        cin >> M;
        while (M--) {
            cin >> input;
            if (note1.find(input) == note1.end()) //수첩2의 숫자가 수첩 1에 없는 경우
                cout << 0 << '\n';
            else
                cout << 1 << '\n';
        }
    }
    return 0;
}