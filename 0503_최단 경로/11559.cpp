//
// Created by kjy82 on 2022-05-10.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
//행과 열을 바꿔줄 것이므로 ROW를 6으로 설정
const int ROW = 6; //행의 수 6
const int COL = 12; //열의 수 12
//계산을 편하기 하기 위해 12*6을 6*12로 바꿈

bool bfs(int r, int c, vector<vector<char>> &board) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    queue<ci> q; //행,열 값 저장할 큐
    queue<ci> puyo; //포함된 좌표 저장할 큐
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false)); //ROW*COL 크기의 이중벡터 visited 선언 및 false로 값 초기화

    //시작 초기화
    q.push({r, c}); //q에 r(행 값), c(열 값) 저장
    puyo.push({r, c}); // puyo에 r(행 값), c(열 값) 저장
    visited[r][c] = true; //visited[r][c] true로 (방문한 것으로) 전환
    int cnt = 1; //모여있는 뿌요의 개수
    while (!q.empty()) { //q가 빈 큐가 아닐 때 반복
        int cr = q.front().first; //cr: 현재 행 값
        int cc = q.front().second; //cc: 현재 열 값
        q.pop(); //q에서 front 원소 삭제

        for (int i = 0; i < 4; i++) { //4번 반복
            int nr = cr + dr[i]; //nr: 탐색할 행 -> 현재 행 + dr[i] (dr[i] -1 이면 이전 행, 1이면 다음 행, 0이면 같은 행)
            int nc = cc + dc[i]; //nc: 탐색할 열 -> 현재 열 + dc[i] (dc[i] -1 이면 이전 열, 1이면 다음 열, 0이면 같은 열)
            if (nr < 0 || nr >= ROW || nc < 0 || nc >= COL || visited[nr][nc]) {
            //탐색할 행이 0미만 이거나 전체 행의 수 이상이거나 탐색할 열이 전체 열의 수 이상이거나 탐색할 좌표가 방문한 좌표일 때
                continue; //연산 건너 뛰고 반복문 계속 진행
            }
            if (board[nr][nc] == board[cr][cc]) { //현재 좌표와 이후 탐색한 좌표에 같은 색의 뿌요 있을 때
                q.push({nr, nc}); //q에 탐색한 행, 열 값 저장
                puyo.push({nr, nc}); //puyo에 탐색한 행, 열 값 저장
                visited[nr][nc] = true; //탐색한 좌표 방문한 것으로(true로) 전환
                cnt++; //cnt값 1 증가
            }
        }
    }
    if (cnt < 4) { //뿌요 안터짐
        return false; //false 반환
    }
    //뿌요가 터지는 경우
    while (!puyo.empty()) { //puyo가 빈 큐가 아닐동안 반복
        int cr = puyo.front().first; //cr: 뿌요의 행 값
        int cc = puyo.front().second; //cc: 뿌요의 열 값
        puyo.pop(); //puyo의 front 원소 삭제

        board[cr][cc] = '.'; //뿌요 터졌으니 board[cr][cc] 값을 .으로 전환
    }
    return true; //true 반환
}

//뿌요를 터뜨린 이후의 새 필드를 작성하는 함수
vector<vector<char>> makeNewBoard(vector<vector<char>> &board) {
    vector<vector<char>> new_board(ROW, vector<char>(COL, '.')); //ROW*COL의 이중벡터 new_board 생성 및 값 .으로 초기화
    for (int i = 0; i < ROW; i++) { //행의 수만큼 반복
        queue<char> temp; //남아있는 뿌요 모으는 큐
        for (int j = 0; j < COL; j++) { //열의 수만큼 반복
            if (board[i][j] != '.') { //뿌요 존재하면
                temp.push(board[i][j]); //board[i][j] (뿌요의 색) temp에 저장
            }
        }
        int index = 0; //인덱스 선언 및 0으로 초기화
        while (!temp.empty()) { //temp에 값 존재하면
            new_board[i][index++] = temp.front(); //temp의 front 원소를 new_board[i][index++]에 저장
            temp.pop(); //temp의 front 원소 삭제
        }
    }
    return new_board; //새로 만든 board 반환
}

int simulation(vector<vector<char>> &board) {
    int answer = 0; //정답을 저장할 변수 answer
    while (true) { //반복문
        bool flag = false; //뿌요가 터졌는지 확인
        for (int i = 0; i < ROW; i++) { //행의 수만큼 반복
            for (int j = 0; j < COL; j++) { //열의 수만큼 반복
                if (board[i][j] == '.') { //뿌요 없는 빈 공간이면
                    continue; //반복문 계속 진행
                }
                if (bfs(i, j, board)) { //한 번이라도 뿌요 터졌다면
                    flag = true; //flat를 true로 바꿈
                }
            }
        }
        if (!flag) { //flag가 false면 (뿌요 한 번도 안 터졌으면)
            break; //반복문 빠져나오기
        }
        board = makeNewBoard(board); //뿌요 터뜨린 후의 board를 다시 작성
        answer++; //정답값 1 증가
    }
    return answer; //정답 반환
}

/**
 * [Puyo Puyo] - bfs, 시뮬레이션 문제
 *
 * 1. bfs 탐색을 통해 4개 이상의 뿌요가 모였는지 확인
 * 2. 4개 이상의 뿌요가 모였다면, 해당되는 영역을 '.'으로 바꾸어 비워줌
 * 3. 전체 필드에 대해 1~2를 다 수행한 후, 뿌요를 떨어뜨림
 *    - 바닥부터 시작해서 남아있는 뿌요들을 모으고, 남은 부분은 '.'으로 채우는 방식
 * 4. 터뜨릴 수 없을 때까지 반복
 *
 * 여기서, 3번 과정을 편하게 하기 위해 12*6으로 들어오는 입력을 6*12로 바꾸어준다.
 * 같은 열에 있는 데이터를 다루는 것보다 같은 행에 있는 데이터를 다루는 것이 편하기 때문이다.
 */

int main() {
    //입력
    char input; //입력 문자
    vector<vector<char>> board(ROW, vector<char>(COL)); //ROW*COL의 이중 벡터 board 선언
    for (int i = 0; i < COL; i++) { //열의 수만큼 반복
        for (int j = 0; j < ROW; j++) { //행의 수만큼 반복
            cin >> input; //문자 입력 받음
            board[j][COL - i - 1] = input; //j행 COL-i-1열에 입력문자 저장
        }
    }

    //연산 & 출력
    cout << simulation(board); //연산
    return 0; //프로그램 종료
}