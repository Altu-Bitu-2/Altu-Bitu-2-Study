//
// Created by kjy82 on 2022-05-16.
//

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

//가로로 같은 색의 바둑알이 5개 놓인 경우 확인
int horizontal(int i, int j, vector<vector<int>>& board) {
    if (j > board.size() - 5) {
        return 0;
    }
    for (int y = j + 1; y < j + 5; y++) {
        if (board[i][y] != board[i][y - 1]) {
            return 0;
        }
    }
    return 1;
}

//세로로 같은 색의 바둑알이 5개 놓인 경우 확인
int vertical(int i, int j, vector<vector<int>>& board) {
    if (i > board.size() - 5) {
        return 0;
    }
    for (int x = i + 1; x < i + 5; x++) {
        if (board[x][j] != board[x - 1][j]) {
            return 0;
        }
    }
    return 1;
}

//오른쪽 아래 대각선으로 같은 색의 바둑알이 5개 놓인 경우 확인
int diagonal_right(int i, int j, vector<vector<int>>& board) {
    if (i > board.size() - 5  || j > board.size() - 5) {
        return 0;
    }
    for (int x = i + 1, y = j + 1; x < i + 5 && y < j + 5; x++, y++) {
        if (board[x][y] != board[x - 1][y - 1]) {
            return 0;
        }
    }
    return 1;
}

//오른쪽 아래 대각선으로 같은 색의 바둑알이 5개 놓인 경우 확인
int diagonal_left(int i, int j, vector<vector<int>>& board) {
    if (i > board.size() - 5 || j < 4) {
        return 0;
    }
    for (int x = i + 1, y = j - 1; x < i + 5 && y > j - 5; x++, y--) {
        if (board[x][y] != board[x - 1][y + 1]) {
            return 0;
        }
    }
    return 1;
}

//승부 결과를 확인하는 함수
pair<int, ci> checkWinner(vector<vector<int>>& board) {
    int result = 0, location_x = -1, location_y = -1;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == 0)
                continue;

            //가로, 세로, 대각선 오른쪽 아래, 대각선 왼쪽 아래로 같은 색의 바둑알이 5개 연속 놓인 경우가 있을 때
            if (horizontal(i, j, board) || vertical(i, j, board) || diagonal_right(i, j, board)) {
                result = board[i][j];
                location_x = i + 1;
                location_y = j + 1;
                return { result, {location_x, location_y} };
            }
            //대각선 왼쪽 아래로 같은 색의 바둑알이 5개 연속 놓인 경우가 있을 때
            if (diagonal_left(i, j, board)) {
                result = board[i][j];
                location_x = i + 5;
                location_y = j - 3;
                return { result, {location_x, location_y} };
            }
        }
    }

    return { result, {location_x, location_y} };
}

int main() {
    int N = 19;
    vector<vector<int>> board(N, vector<int>(N));
    pair<int, ci> answer;

    //입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    //연산
    answer = checkWinner(board);

    //출력
    cout << answer.first << '\n';
    if (answer.second.first != -1) {
        cout << answer.second.first << ' ' << answer.second.second;
    }

    return 0;
}