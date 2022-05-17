//
// Created by kjy82 on 2022-05-17.
//

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;    //판의 크기 19*19

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>> &board) {
    return r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == stone;
    //행의 범위 확인 (0~18), 열의 범위 확인(0~18), 돌의 종류가 같은지 확인
}

//연속된 돌이 5개 있는지 확인하는 함수
bool validDir(int r, int c, int d, int stone, vector<vector<int>> &board) {
    //가로, 세로, 우하향 대각선, 우상향 대각선
    int dr[4] = {0, 1, 1, -1}; //각 방향에 대한 행 변화값
    int dc[4] = {1, 0, 1, 1}; //각 방향에 대한 열 변환값

    //(r, c) 이전에 위치한 이어지는 돌이 있나?
    if (promising(r - dr[d], c - dc[d], stone, board)) { //반대 방향으로 같은 돌이 있을때
        return false; //false 반환
    }
    int cnt = 0; //cnt: 연속된 돌의 개수
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++; //cnt 1 증가
        r += dr[d]; //행 값에 dr[d] 더한다 (-> 이어지는 방향 계속 확인)
        c += dc[d]; //열 값에 dc[d] 더한다
    }
    return cnt == 5; //연속된 돌의 개수가 5개면 true 반환
}

//승부 결과 확인하는 함수 (이긴 돌 있으면 true 반환)
bool isEnd(int r, int c, vector<vector<int>> &board) {
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board)) { //연속된 돌 확인
            return true; //true 반환
        }
    }
    return false; //false 반환
}

/**
 * [오목]
 *
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. (주의) 육목이상이 되는지 확인해야 함
 *
 */

int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); //이중벡터 board 선언 및 초기화

    //입력
    for (int i = 0; i < SIZE; i++) { //판의 행 수(19)만큼 반복
        for (int j = 0; j < SIZE; j++) { //판의 열 수(19)만큼 반복
            cin >> board[i][j]; //보드 한 칸의 상태 입력 받는다
        }
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) { //판의 행 수(19)만큼 반복
        for (int j = 0; j < SIZE; j++) { //판의 열 수(19)만큼 반복
            if (!board[i][j]) { //돌이 없음
                continue; //연산 건너뛰고 반복문 계속한다
            }
            if (isEnd(i, j, board)) { //누군가 이겼나?
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1; //이긴 돌과 위치 출력
                return 0; //프로그램 종료
            }
        }
    }
    cout << 0;  //무승부 -> 0 출력
    return 0;   //프로그램 종료
}