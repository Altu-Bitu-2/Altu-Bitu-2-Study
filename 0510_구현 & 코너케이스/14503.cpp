//
// Created by kjy82 on 2022-05-17.
//

#include <iostream>
#include <vector>

using namespace std;

int cntCleanRobot(int r, int c, int d, vector<vector<int>> &board) {
    //상, 우, 하, 좌
    int dr[4] = {-1, 0, 1, 0}; //각 방향에 대한 행 변화값/
    int dc[4] = {0, 1, 0, -1}; //각 방향에 대한 열 변환값

    int step = 0, ans = 0; //step: 2a번 단계가 실행된 수,ans: 로봇 청소기가 청소하는 칸의 개수
    while (true) { //반복
        if (board[r][c] == 0) { //보드칸이 빈 칸이면
            board[r][c] = 2; //보드칸 상태 2로 바꾼다 (청소함)
            ans++; //ans 값 1 증가
        }

        if (step == 4) { //2a번 단계가 연속으로 네 번 실행되었을 경우
            if (board[r - dr[d]][c - dc[d]] == 1) { //뒤쪽이 벽이면
                return ans; //ans 반환 (작동 멈춤)
            }
            r -= dr[d]; //바로 뒤쪽으로 (행)
            c -= dc[d]; //바로 뒤쪽으로 (열)
            step = 0; //step 0으로 다시 초기화
        } else { //2a번 단계가 4번 미만 실행되었을 때
            d = (d + 3) % 4; //바라보는 방향 왼쪽으로 회전
            if (board[r + dr[d]][c + dc[d]]) { //바로 왼쪽에 빈 공간 없을 때
                step++; //step 값 1 증가
                continue; //반복문 계속한다
            }
            r += dr[d]; //한 칸 전진 (행)
            c += dc[d]; //한 칸 전진 (열)
            step = 0; //step 0으로 초기화
        }
    }
}

/**
 * [로봇 청소기]
 *
 * board 정보 -> 0: 빈 칸, 1: 벽, 2: 청소한 공간
 * step: 회전 카운트. 4가 되면 한 바퀴 돌아 다시 제자리로 돌아왔음을 의미
 *
 * 항상 첫 행, 마지막 행, 첫 열, 마지막 열은 벽이라고 문제에서 주어졌으므로 범위 검사를 할 필요가 없음
 */

int main() {
    int n, m, r, c, d;
    //n: 세로 크기, m: 가로 크기, r, c: 로봇 청소기의 좌료, d: 로봇 청소기가 바라보는 방향

    //입력
    cin >> n >> m >> r >> c >> d;
    vector<vector<int>> board(n, vector<int>(m, 0)); //이중벡터 board 선언 및 초기화
    for (int i = 0; i < n; i++) { //n번 반복
        for (int j = 0; j < m; j++) { //m번 반복
            cin >> board[i][j]; //보드 한 칸의 상태 입력 받는다
        }
    }

    //연산 & 출력
    cout << cntCleanRobot(r, c, d, board);
    return 0; //프로그램 종료
}