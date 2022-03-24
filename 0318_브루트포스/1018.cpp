//
// Created by kjy82 on 2022-03-24.
//

#include <iostream>
#include <vector>


using namespace std;


//칠해야 하는 정사각형 개수를 구하는 함수
int countPaint(int m, int n, vector<vector<string>> v) {
    int count = 0; //칠해야 하는 사각현 수
    string first_block = v[m][n];
    for (int i = m; i < m + 8; i++) {
        if (m % 2 == 0) {
            for (int j = n; j < n + 8; j += 2) {
                if (v[i][j] != first_block || v[i][j + 1] == first_block) {
                    count++;
                }
            }
        }
        for (int j = n; j < n + 8; j += 2) {
            if (v[i][j] == first_block || v[i][j + 1] != first_block) {
                count++;
            }
        }
    }
    return count;
}


int main() {
    int m, n, answer = 64, tmp = 0;
    int a, b;
    vector<vector<string>> v;

    //입력
    cin >> m >> n;
    v.assign(m, vector<string>(n, ""));
    a = m - 8;
    b = n - 8;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    //가능한 8*8 체스판에 대해 칠해야 하는 사각형 수 구하기
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
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