//
// Created by kjy82 on 2022-05-31.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix;

int n, ans = 0; //n: 보드의 크기, ans: 답

int getMaxBlock(matrix &board) {
    int max_block = 0; //max_block:얻을 수 있는 가장 큰 블록
    for (int i = 0; i < n; i++) { //n번 반복 (행)
        for (int j = 0; j < n; j++) { //n번 반복 (열)
            max_block = max(max_block, board[i][j]); //연산
        }
    }
    return max_block; //max_block 리턴
}

matrix transposeMatrix(matrix &board) {
    matrix board_t(n, vector<int>(n, 0)); //transpose matrix인 board_t 선언 및 초기화
    for (int i = 0; i < n; i++) { //n번 반복 (행)
        for (int j = 0; j < n; j++) { //n번 반복 (열)
            board_t[i][j] = board[j][i]; //전치한 값 board_t에 저장
        }
    }
    return board_t; //board_t 리턴
}

/**
 * 상으로 이동하는 함수
 * - 한 열씩 검사하면서 위의 행부터 2개씩 같은 거 있다면 합치기
 * - 이때 블록 없는 부분은 넘어가고, 블록이 존재했던 값을 저장해서 비교하는 것이 중요!
 */
matrix upMove(matrix board) {
    matrix temp(n, vector<int>(n, 0)); //새롭게 블록 저장할 배열
    for (int j = 0; j < n; j++) { //n번 반복
        int idx = 0; //idx: 현재 좌표
        int prev = 0; //prev:이전 블록의 번호
        for (int i = 0; i < n; i++) { //n번 반복
            if (!board[i][j]) { //빈칸이면
                continue; //연산 건너뛰고 반복문 계속하기
            }
            if (board[i][j] == prev) { //이전 블록과 값 같으면
                temp[idx - 1][j] *= 2; //2 곱한 값 temp에 저장
                prev = 0; //prev 0으로 초기화
            } else {
                temp[idx++][j] = board[i][j]; //블록이 존재했던 값 저장
                prev = board[i][j]; //prev에 블록 값 저장
            }
        }
    }
    return temp; //temp 리턴
}

//백트래킹 탐색
void backtracking(int cnt, matrix board) {
    if (cnt == 5) { //5번 이동했으면
        ans = max(ans, getMaxBlock(board)); //얻을 수 있는 가장 큰 블록 ans에 저장
        return; //리턴
    }
    //Transpose matrix 구하기 (상->좌)
    matrix board_t = transposeMatrix(board);
    //상
    backtracking(cnt + 1, upMove(board));
    //하
    reverse(board.begin(), board.end()); //보드 돌리기
    backtracking(cnt + 1, upMove(board));
    //좌
    backtracking(cnt + 1, upMove(board_t));
    //우
    reverse(board_t.begin(), board_t.end()); //보드 돌리기
    backtracking(cnt + 1, upMove(board_t));
}

/**
 * [2048 (Easy)]
 *
 * - 상, 하, 좌, 우로 이동하는 경우에 대해 최대 5번 이동시키는 모든 경우를 구한 후, 가장 큰 블록 찾는 문제 - 백트래킹
 * - 움직이는 함수는 하나만 짜고, 보드를 돌려가면서 상, 하, 좌, 우 모든 방향의 움직임을 만듦
 *
 * - 상 <-> 하: 행 순서를 뒤집어서 해결
 * - 상/하 <-> 좌/우: Transpose Matrix 활용
 *
 * - ex. 2 2 1 를 상, 하, 좌, 우로 이동하는 경우 구하는 법
 *       2 2 2
 *       4 4 4
 *  -상: 원래 배열에서 상으로 움직이는 함수 실행
 *       2 2 1    4 4 1
 *       2 2 2 -> 4 4 2
 *       4 4 4    0 0 4
 *  -하: 원래 배열의 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    4 4 4    4 4 4
 *       2 2 2 -> 2 2 2 -> 4 4 2
 *       4 4 4    2 2 1    0 0 1
 *  -좌: 원래 배열의 전치 행렬을 구한 후, 상으로 움직이는 함수 실행
 *       2 2 1    2 2 4    4 4 8
 *       2 2 2 -> 2 2 4 -> 1 2 4
 *       4 4 4    1 2 4    0 0 0
 *  -우: 원래 배열의 전치 행렬에서 행 순서를 뒤집은 후, 상으로 움직이는 함수 실행
 *       2 2 1    1 2 4    1 4 8
 *       2 2 2 -> 2 2 4 -> 4 2 4
 *       4 4 4    2 2 4    0 0 0
 */

int main() {
    //입력
    cin >> n; //n 입력받기
    matrix board(n, vector<int>(n, 0)); //배열 board 선언 및 초기화
    for (int i = 0; i < n; i++) { //n번 반복 (행)
        for (int j = 0; j < n; j++) { //n번 반복 (열)
            cin >> board[i][j]; //게임판의 초기 상태 입력받기
        }
    }

    //연산
    backtracking(0, board); //백트래킹 연산

    //출력
    cout << ans; //ans 출력
    return 0; //프로그램 종료
}