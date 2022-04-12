//
// Created by kjy82 on 2022-04-12.
//

#include <iostream>
#include <string>
#include <deque>

using namespace std;

//k개의 수 지워서 큰 수 만드는 함수
string findMaxNumber(string number, int l, int k) {
    deque<char> dq; //연산에 사용할 덱

    int cnt = 0; //삭제된 숫자의 개수
    for (int i = 0; i < l; i++) {   //l번(n번) 반복
        //cnt < k일때 & dq가 비어 있지 않을때 & dq의 back보다 입력받은 숫자가 커질때
        while (cnt < k && !dq.empty() && dq.back() < number[i]) {
            dq.pop_back();  //dq의 rear에 있는 원소 pop
            cnt++;  //cnt 증가
        }
        dq.push_back(number[i]); //이번 입력 삽입
    }

    string answer = ""; //정답
    for (int i = 0; i < l - k; i++) { //l-k 자릿수
        answer += dq[i];   //dq에 저장된 숫자들 ans에 저장
    }
    return answer;  //정답 반환
}

/**
 * [크게 만들기]
 *
 * 어차피 남는 수는 n-k자리 수!
 * 가능한 앞자리에 큰 수를 배치하는 것이 유리하다.
 * 수의 앞자리부터 탐색하며, 덱에 차례대로 저장
 * 직전 자리보다 큰 수가 나오면 덱의 back이 자신보다 크거나 같아질 때까지 pop_back한 뒤에 추가
 *
 * ex) 1924 에서 2개를 지워서 큰 수를 만들어야 한다면
 *    deque: []           이번 숫자 '1' -> deque: ['1']
 *    deque: ['1']        이번 숫자 '9' -> deque: ['9']
 *    deque: ['9']        이번 숫자 '2' -> deque: ['9', '2']
 *    deque: ['9', '2']   이번 숫자 '4' -> deque: ['9', '4']
 *
 *    답: 94
 *
 * 이러한 그리디적 풀이가 가능한 이유 -> number의 순서가 고정되어 있기 때문!
 *
 * 정확히 k개의 수를 지워야 함을 유의
 */

int main() {
    int n, k;   //n: 입력받을 숫자의 자릿수, k: 삭제할 숫자의 개수
    string number;  //입력받을 숫자

    //입력
    cin >> n >> k >> number;

    //연산 & 출력
    cout << findMaxNumber(number, number.length(), k);
    return 0;   //프로그램 종료
}