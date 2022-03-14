//
// Created by kjy82 on 2022-03-14.
//

#include <iostream>
#include <set>


using namespace std;


int main() {
    string S;
    set<string> part;

    //입력
    cin >> S;
    for (int i = 0; i < S.length(); i++) {
        for (int j = 1; j < S.length() + 1; j++) {
            part.insert(S.substr(i, j));
        }
    }

    //출력
    cout << part.size() << '\n';

    return 0;
}