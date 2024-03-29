//
// Created by kjy82 on 2022-04-06.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, total, input;	//N: 행(열)의 수, total: 표의 원소 개수, input: 표의 원소 값
    priority_queue<int, vector<int>, greater<>> num;

    //입력
    cin >> N;

    /*
    N번째 큰 수 찾기
    1. N개의 수 우선순위 큐에 내림차순 연산 활용해 입력받는다
    2. 나머지 수 탐색해 큐의 top(큐 내 최솟값)보다 값이 클때만 우선순위 큐에 삽입한다
    */

    total = N * N - N;	//N개의 수 먼저 큐에 입력받을거라 N*N에서 N 뺀 값 저장

    while (N--) {
        cin >> input;
        num.push(input);
    }

    while (total--) {
        cin >> input;
        if (input > num.top()) {
            num.pop();
            num.push(input);
        }
    }

    //출력
    cout << num.top() << '\n';

    return 0;
}