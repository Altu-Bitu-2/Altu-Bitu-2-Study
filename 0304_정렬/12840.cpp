//
// Created by kjy82 on 2022-03-10.
//

#include <iostream>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int h, m, s, q, T, c;

    //입력
    cin >> h >> m >> s >> q;
    int time = h * 3600 + m * 60 + s;
    for (int i = 0; i < q; i++) {
        cin >> T;
        if (T == 1) {
            cin >> c;
            time = (time + c) % 86400;
        }
        else if (T == 2) {
            cin >> c;
            time = (time - c) % 86400;
            if(time < 0) {
                time += 86400;
            }
        }
        else {
            //출력
            cout << (time / 3600) % 24  << ' ' << (time / 60) % 60 << ' ' << time % 60 << '\n';
        }
    }
    return 0;
}