//
// Created by kjy82 on 2022-04-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int score, player; //score: 점수, player: 몇번째 선수인지
vector<int> entry = {0, 1, 2, 3, 4, 5, 6, 7, 8}; //선수 순서
vector<vector<int>> board; //이차원 벡터 board 선언

/**
 * 주자들 진루처리
 *
 * 1110 : 1, 2, 3루에 주자 존재
 * 0100 : 2루에 주자 존재
 * 1010 : 1, 3루에 주자 존재
 */
void running(int &run, int num) {
    run |= (1 << 0); //0번 플레이트에 타자 표시
    for (int i = (4 - num); i < 4; i++) { //홈까지 진루할 수 있는 주자들
        if (run & (1 << i)) { //주자가 있다면
            run &= ~(1 << i); //주자가 홈인 했기 때문에 플레이트를 비워줌
            score++; //score 증가
        }
    }
    run = run << num; //주자들 이동
}

//idx 이닝 플레이
void playGame(int idx) {
    int out = 0, run = 0; //아웃카운트, 진루 상태
    while (out != 3) { //out이 3미만일때만 반복
        int hit = board[idx][entry[player]]; //이번 주자의 결과
        if (!hit) { //아웃
            out++; //out값 증가
        }
        else { //존재하는 모든 주자 진루
            running(run, hit);
        }
        player = (player + 1) % 9; //다음 선수
    }
}

/**
 * 순열, 비트마스킹 풀이
 * 1. 순열로 가능한 모든 타순을 구한다. (순열)
 *    4번 타자는 항상 1번 선수여야 하기 때문에 2번 ~ 9번 선수에 대해서만 순열을 돌린다.
 * 2. 엔트리에 대한 점수를 계산한다. 1~3루와 홈베이스 총 4개의 플레이트에 대해 선수의 존재여부를 비트로 표현한다.
 *
 * 해설 : https://myunji.tistory.com/439?category=1154147
 */

int main() {
    int n, ans = 0; //n: 이닝 수, ans: 얻을 수 있는 최대 점수

    //입력
    cin >> n;
    board.assign(n, vector<int>(9)); //board의 크기 지정
    for (int i = 0; i < n; i++) { //n번 반복
        for (int j = 0; j < 9; j++) { //9번 반복
            cin >> board[i][j]; //선수가 각 이닝에서 얻는 결과 입력받음
        }
    }

    //연산
    do {
        swap(entry[0], entry[3]); //1번 선수 4번 타자 되도록
        score = player = 0; //초기화
        for (int i = 0; i < n; i++) { //각 이닝 플레이
            playGame(i); //i번째 이닝 플레이
        }
        ans = max(ans, score); //ans와 score 중 큰 값 ans에 저장
        swap(entry[3], entry[0]); //원래대로 복구
    } while (next_permutation(entry.begin() + 1, entry.end())); //1번 선수 제외 나머지 선수들에 대해 반복

    //출력
    cout << ans; //정답 출력
    return 0; //프로그램 종료
}