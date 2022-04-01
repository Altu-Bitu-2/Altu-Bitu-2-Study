//
// Created by kjy82 on 2022-04-01.
//

#include <iostream>
#include <vector>

using namespace std;

//태수의 등수를 찾는 함수
int findRanking(int n, int new_score, int p, vector<int> &ranking) {
    int idx = 1;    //n개의 점수 중 idx번째 점수와 태수의 점수를 비교
    int ans = 1;    //태수의 등수
    //새로운 점수를 어느 위치에 넣을지 탐색
    while (idx <= n) {  //최대 n번 도는 반복문
        if (new_score > ranking[idx]) { //태수의 점수가 idx번째 랭킹점수보다 높은 경우
            break;  //반복문 빠져 나온다
        }
        if (new_score < ranking[idx]) { //태수의 점수가 idx번째 랭킹점수보다 낮은 경우
            ans = idx + 1;  //태수의 등수 = idx + 1
        }
        idx++;  //한 등수 낮은 점수와 태수의 점수를 비교
    }
    if (idx == p + 1) { //랭킹 리스트에 들어가지 못하는 경우
        return -1;  //-1 반환
    }
    return ans; //정답 반환
}

/**
 * [등수 구하기]
 *
 * 1. n = 0일 때, 고려
 * 2. 등수는 p보다 작지만, 점수가 더 좋을 때만 랭킹이 갱신되므로 랭킹 리스트에 들어가지 못하는 경우 고려 (동점)
 *
 * 현재 랭킹에 올라간 n까지 등수와 새로운 점수를 비교하며 새로운 점수 몇 등인지 계산
 * 새로운 점수가 현재 탐색 등수의 점수보다 작다면 -> 현재 탐색 등수 + 1
 * 동점일 경우 -> 그 전 등수 그대로 사용 -> 아무 처리도 하지 않음!
 */

int main() {
    int n, new_score, p;    //n:랭킹에 있는 점수의 개수, new_score: 태수의 점수, p:랭킹에 올라갈 수 있는 점수의 개수

    //입력
    cin >> n >> new_score >> p;
    vector<int> ranking(p + 1, 0);
    for (int i = 1; i <= n; i++) {  //n번 도는 반복문
        cin >> ranking[i];  //ranking 벡터에 현재 랭킹에 있는 점수들 입력받는다
    }

    //연산 & 출력
    cout << findRanking(n, new_score, p, ranking);  //정답 출력
    return 0;   //프로그램 종료
}