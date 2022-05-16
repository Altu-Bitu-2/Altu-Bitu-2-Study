//
// Created by kjy82 on 2022-05-16.
//

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;
int dr[4] = { 0, 1, 1, -1 };
int dc[4] = { 1, 0, 1, 1 };

//연속된 바둑알의 개수를 확인하는 함수
int checkContinuity(int i, int j, int k, vector<vector<int>>& board) {
    int cnt = 1;
    if (j > board.size() - 5) {
        return 0;
    }
    if (k == 2) {
        if (i > board.size() - 5) {
            return 0;
        }
    }
    else if (k == 3) {
        if (i < 4) {
            return 0;
        }
    }

    for (int n = 0; n < 6; n++) { //최대 6개까지 연속된 바둑알 수 센다
        if (i + (n + 1) * dr[k] > board.size() - 1 || i + (n + 1) * dr[k] < 0 || j + (n + 1) * dc[k] > board.size() - 1)
            break;
        if (board[i + n * dr[k]][j + n * dc[k]] == board[i + (n + 1) * dr[k]][j + (n + 1) * dc[k]]) {
            cnt++;
        }
        else
            break;
    }

    if (cnt == 5) {
        //반대 방향에 같은 색의 바둑알 있는 경우
        if (i - dr[k] > 0 && i - dr[k] < board.size() && j - dr[k] > 0 && j - dr[k] < board.size() && board[i][j] == board[i - dr[k]][j - dr[k]]) {
            return 0;
        }
        return board[i][j];
    }
    return 0;
}

//승부 결과를 확인하는 함수
pair<int, ci> findWinner(vector<vector<int>>& board) {
    int result = 0, location_x = -1, location_y = -1;

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board.size(); j++) {
            if (board[i][j] == 0)
                continue;

            for (int k = 0; k < 4; k++) {
                result = checkContinuity(i, j, k, board);
                if (result != 0) {
                    location_x = i + 1;
                    location_y = j + 1;
                    return { result, {location_x, location_y} };
                }
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
    answer = findWinner(board);

    //출력
    cout << answer.first << '\n';
    if (answer.second.first != -1) {
        cout << answer.second.first << ' ' << answer.second.second;
    }

    return 0;
}