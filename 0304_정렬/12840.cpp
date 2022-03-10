//
// Created by kjy82 on 2022-03-10.
//

#include <iostream>

using namespace std;

int main() {
    int h, m, s, q, T, c;

    //입력
    cin >> h >> m >> s >> q;
    int time = h * 3600 + m * 60 + s;
    for (int i = 0; i < q; i++) {
        cin >> T;
        if (T == 1) {
            cin >> c;
            time += c;
        }
        else if (T == 2) {
            cin >> c;
            time -= c;
        }
        else {
            //출력
            cout << (time / 3600) % 24  << ' ' << (time % 3600) / 60 << ' ' << (time % 3600) % 60 << '\n';
        }
    }
    return 0;
}