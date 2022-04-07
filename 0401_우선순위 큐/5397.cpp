//
// Created by kjy82 on 2022-04-07.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, cur = 0;	  //T: 테스트케이스 개수, cur: 현재 커서의 위치
    string input;	  //입력으로 들어오는 문자열
    vector<char> answer(1);

    //입력
    cin >> T;
    while (T--) {
        cin >> input;
        for (int i = 0; i < input.size(); i++) {
            switch (input[i]) {
                case '<':
                    if (cur > 0) {
                        cur--;
                    }
                    else {
                        cur = 0;
                    }
                    break;
                case '>':
                    cur++;
                    break;
                case '-':
                    cur--;
                    answer.erase(answer.begin() + cur);
                    break;
                default:
                    answer.insert(answer.begin() + cur, input[i]);
                    cur++;
                    break;
            }
        }
        //출력
        for (int i = 0; i < answer.size(); i++) {
            cout << answer[i];
        }
        cout << '\n';
        answer.clear();
        cur = 0;
    }

    return 0;
}