//
// Created by kjy82 on 2022-05-17.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 401; //상수 INF 401로 선언
typedef pair<int, int> ci; //int, int 쌍을 ci로 정의

pair<int, ci> nextPos(int n, int shark_size, ci &shark, vector<vector<int>> &board) {
    //상, 하, 좌, 우
    int dr[4] = {-1, 1, 0, 0}; //각 방향에 대한 행 변화값
    int dc[4] = {0, 0, -1, 1}; //각 방향에 대한 열 변환값

    int min_dist = INF; //최소 거리 INF 로 초기화
    queue<ci> q; //상어가 갈 수 있는 곳
    vector<vector<int>> dist(n, vector<int>(n, 0)); //상어의 방문 여부 + 거리
    vector<ci> list; //상어가 먹을 수 있는 물고기들의 위치

    dist[shark.first][shark.second] = 1; //상어의 위치 방문한 것으로(1) 바꾼다
    q.push(shark); //q에 상어의 위치 값들 넣는다
    while (!q.empty()) { //q가 비어있지 않을 동안 반복
        int row = q.front().first; //row: 상어가 갈 곳의 행 값
        int col = q.front().second; //col: 상어가 갈 곳의 열 값
        q.pop(); //q의 top 원소 빼낸다

        if (dist[row][col] >= min_dist) { //최단거리 이상은 탐색할 필요 없음
            continue; //이후 연산 건너뛰고 반복문 계속한다
        }
        for (int i = 0; i < 4; i++) { //4번 반복(상, 하, 좌, 우)
            int nr = row + dr[i]; //nr: 상어가 이동한다면 그 후 상어 위치의 행 값
            int nc = col + dc[i]; //nc: 상어가 이동한다면 그 후 상어 위치의 열 값
            //만약 상어가 이동할 수 없는 곳으로 이동해야 된다면
            if (nr < 0 || nr >= n || nc < 0 || nc >= n || dist[nr][nc] || board[nr][nc] > shark_size) {
                continue; //연산 건너뛰고 반복문 계속한다
            }

            dist[nr][nc] = dist[row][col] + 1; //상어가 다음 칸으로 이동하면 이전에 있던 곳보다 거리 + 1
            if (board[nr][nc] && board[nr][nc] < shark_size) { //먹을 수 있는 물고기 발견
                list.emplace_back(nr, nc); //list에 물고기의 위치 nr, nc 삽입
                min_dist = dist[nr][nc]; //min_dist에 dist[nr][nc] 저장
                continue; //반복문 계속한다
            }
            q.push({nr, nc}); //q에 nr, nc 삽입
        }
    }

    if (list.empty()) { //상어가 갈 수 있는 곳이 없음
        return {min_dist, {-1, -1}}; //INF, -1, -1 리턴
    }

    sort(list.begin(), list.end(), [](const ci &p1, const ci &p2) { //정렬 (compare 함수를 정의하지 않아도 됨)
        if (p1.first != p2.first) { //물고기 위치의 행 값 다르면
            return p1.first < p2.first; //위에 있는 물고기 선택
        }
        return p1.second < p2.second; //왼쪽에 있는 물고기 선택
    });
    return {min_dist - 1, list[0]}; //최소 거리와 물고기 위치 리턴
}

int simulation(int n, pair<int, int> &shark, vector<vector<int>> &board) {
    int ans = 0, size = 2, cnt = 0; //ans: 상어가 엄마의 도움 없이 물고기 먹을 수 있는 시간, size: 상어의 크기, cnt: 먹은 물고기의 수
    while (true) { //반복
        pair<int, ci> result = nextPos(n, size, shark, board); //result에 최소 거리와 상어 위치 저장
        if (result.first == INF) { //더 이상 먹을 수 있는 물고기가 공간에 없음
            break; //반복문 빠져나간다
        }
        ans += result.first; //ans에 최소 거리 더함 (1초에 한 칸씩 움직이니 거리 = 시간)
        cnt++; //cnt 1 증가
        if (cnt == size) { //상어 크기 증가
            cnt = 0; //cnt 다시 0으로 초기화
            size++; //상어 크기 1 증가
        }

        //상어 이동
        board[shark.first][shark.second] = 0; //물고기 먹었으니 보드 값 0으로
        shark = result.second; //shark에 위치 저장해준다
    }
    return ans; //ans 반환
}

/**
 * [아기 상어]
 *
 * 1. 상어로부터 가장 가까운 거리에 있는 모든 물고기 탐색 (BFS)
 * 2. 우선순위 조건에 맞추어 먹으러 갈 물고기 확정
 *    탐색하는 방향에 우선순위를 두는 걸로 해결되지 않음! (예제 입력 4) 정렬 필요
 * 3. 상어가 이동할 수 있는 곳이 없을 때까지 BFS 탐색 반복
 *
 * 입력 범위가 작기 때문에 매번 BFS 탐색을 반복해도 시간 초과 X
 * 가능한 물고기의 최대 마리 수 : 399마리
 * 최대 BFS 탐색 횟수 : 399회, 1회 탐색마다 while 문은 최대 400회 미만으로 순회
 * 총 연산 횟수 약 160000번으로 충분히 가능
 *
 * 해설 : https://myunji.tistory.com/378
 * *글 자체는 별로 도움이 안되고...그냥 리팩토링하면 코드가 이렇게 되는구나 정도만 봐주세요
 */

int main() {
    int n; //n: 공간의 크기
    pair<int, int> shark_pos; //shark_pos: 상어의 위치

    //입력
    cin >> n; //n 입력받는다
    vector<vector<int>> board(n, vector<int>(n)); //이중벡터 board 선언 및 초기화
    for (int i = 0; i < n; i++) { //공간의 행의 수(n번) 반복
        for (int j = 0; j < n; j++) { //공간의 열의 수(n번) 반복
            cin >> board[i][j]; //보드 한 칸의 상태 입력받는다
            if (board[i][j] == 9) { //상어의 초기 위치
                shark_pos = make_pair(i, j); //상어 위치의 행, 열 값 shark_pos에 저장
            }
        }
    }

    //연산 & 출력
    cout << simulation(n, shark_pos, board);
    return 0; //프로그램 종료
}