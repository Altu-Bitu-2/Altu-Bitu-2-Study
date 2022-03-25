//
// Created by kjy82 on 2022-03-25.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//prev_permutation()을 활용한 조합을 이용한 풀이
int blackJackC(int n, int m, vector<int> &card) {
    int ans = 0; //정답

    vector<bool> is_selected(n, false); //고른 카드가 true
    for (int i = 0; i < 3; i++) { //3장 카드 고른 것으로 초기화
        is_selected[i] = true; //3장의 카드 고른 것(true)로
    }

    do {
        int sum = 0; //고른 3장의 카드 합 저장
        for (int i = 0; i < n; i++) { //n개의 카드 탐색
            if (is_selected[i]) { //고른 카드라면
                sum += card[i]; //그 카드의 수 sum에다 더한다
            }
        }
        //m과 가장 가까운 카드 구하기
        if (sum <= m) { //sum이 m 이하일때
            ans = max(ans, sum); //ans, sum 중 큰 값 ans에 넣는다
        }
    } while (prev_permutation(is_selected.begin(), is_selected.end())); //구할 수 있는 조합 다 구할때까지 반복
    return ans; //정답 리턴
}

//3중 for문 풀이
int blackJackFor(int n, int m, vector<int> &card) {
    int ans = 0; //정답

    for (int i = 0; i < n; i++) { // i: 0 ~ n-1
        for (int j = i + 1; j < n; j++) { // j: i+1 ~ n
            for (int k = j + 1; k < n; k++) { // k: j+1 ~ n
                int sum = card[i] + card[j] + card[k]; // 카드 세 장에 적힌 숫자의 합 sum에 저장
                if (sum > m) { //m을 넘었다면
                    break; //(생각해보세요) 바로 return ans; 를 하면 어떻게 될까요?
                    /**
                     * ex. card의 값: 1 2 3 7 9 10, m = 11
                     * 1) return ans;를 할 경우 -> 1+2+9=12 > 11. 1+3+7=11로 11에 더 가까운 답 존재하지만 확인 못함
                     * 2) break; -> k반복문 빠져나감. j반복문은 다시 돈다. 즉, 더 가까운 답이 있는지 계속 검사 가능
                     */
                }
                ans = max(ans, sum); //ans와 sum 중 더 큰 값을 ans에 넣는다
            }
        }
    }
    return ans; //정답 리턴
}

/**
 * [ 블랙잭 ] - 단순 구현
 * 카드가 최대 100장이므로,
 * C(100, 3) < 100*100*100 = 1,000,000 -> 브루트포스 충분히 가능
 *
 * ver1. 3중 for문 이용해서 구현
 * +) 코드의 효율성을 높이기 위해, 카드를 사전에 정렬하여 M을 넘어가는 순간 반복 종료 (이때, 한 반복만 빠져나오는 것 주의!)
 *
 * ver2. prev_permutation()을 활용하여 모든 조합을 구해서 구현
 */

int main() {
    int n, m; //카드 수 n과 딜러가 외치는 숫자 m 저장할 변수 선언

    //입력
    cin >> n >> m; //n,m 입력 받음
    vector<int> card(n, 0); //크기 n, 값이 0으로 초기화된 벡터 card 생성
    for (int i = 0; i < n; i++) { //n번 반복
        cin >> card[i]; //카드에 적힌 수 입력 받음
    }

    //연산
    //조합 풀이
    int ans = blackJackC(n, m, card);

    //3중 for 문 풀이
    //sort(card.begin(), card.end()); //card의 값들 오름차순 정렬
    //int ans = blackJackFor(n, m, card);

    //출력
    cout << ans; //답 출력
    return 0; //프로그램 종료
}