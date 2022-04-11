//
// Created by kjy82 on 2022-04-11.
//

#include <iostream>
#include <vector>

using namespace std;

void changeVal(int i, int j, vector<vector<char>>& matrix_a) {
    for (int s = i; s < i + 3; s++) {
        for (int t = j; t < j + 3; t++) {
            if(matrix_a[s][t] == '1')
                matrix_a[s][t] = '0';
            else
                matrix_a[s][t] = '1';
        }
    }
}

int main() {
    int n, m, count = 0;
    vector<vector<char>> matrix_a;
    vector<vector<char>> matrix_b;

    //입력
    cin >> n >> m;
    matrix_a.assign(n, vector<char>(m));
    matrix_b.assign(n, vector<char>(m));

    for (int i = 0; i < n; i++) {	//행렬 A 입력 받기
        for (int j = 0; j < m; j++) {
            cin >> matrix_a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {	//행렬 B 입력 받기
        for (int j = 0; j < m; j++) {
            cin >> matrix_b[i][j];
        }
    }

    //행렬 A, B의 문자 다를때 3x3 크기의 부분 행렬 원소 값 뒤집기
    for (int i = 0; i <= n - 3; i++) {
        for (int j = 0; j <= m - 3; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) {
                changeVal(i, j, matrix_a);
                count++;
            }
        }
    }

    //행렬 A를 B로 못 바꿀 때 -1 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    //출력
    cout << count << '\n';

    return 0;
}