//
// Created by kjy82 on 2022-03-24.
//

#include <iostream>
#include <vector>


using namespace std;


//칠해야 하는 정사각형 개수를 구하는 함수 (첫 칸이 검정일 때 기준)
int countPaint(int m, int n, vector<vector<char>> v) {
    int count = 0; //칠해야 하는 사각형 수

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0 && v[m + i][n + j] != 'B')
                count++;
            else if ((i + j) % 2 == 1 && v[m + i][n + j] != 'W') {
                count++;
            }
        }
    }

    if (count > 32) {
        return 64 - count;
    }
    return count;
}


int main() {
    int m, n, answer = 64, tmp = 0;
    vector<vector<char>> v;

    //입력
    cin >> m >> n;
    v.assign(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    //가능한 8*8 체스판에 대해 칠해야 하는 사각형 수 구하기
    for (int i = 0; i <= m - 8; i++) {
        for (int j = 0; j <= n - 8; j++) {
            tmp = countPaint(i, j, v);
            if (tmp < answer) {
                answer = tmp;
            }
        }
    }

    //출력
    cout << answer << '\n';

    return 0;
}