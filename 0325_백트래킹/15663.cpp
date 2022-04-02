//
// Created by kjy82 on 2022-04-01.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SIZE = 8; //배열 크기

int n, m;   //n: 주어지는 자연수의 개수, m: 수열의 길이
vector<int> num(SIZE);  //입력받을 n개의 수를 저장할 벡터
vector<int> ans(SIZE);  //정답을 저장할 벡터
vector<bool> check(SIZE);   //사용된 숫자인지 확인하기 위한 벡터

//백트래킹 함수
void backtracking(int cnt) {
    if (cnt == m) { //길이 m 이라면 (기저조건)
        for (int i = 0; i < m; i++) {   //m번 도는 반복문
            cout << ans[i] << ' ';  //ans 벡터의 원소들 출력
        }
        cout << '\n'; //줄바꿈 출력
        return; //기저조건 만족했으므로 함수 리턴
    }
    int prev = 0; //이전에 선택한 값
    for (int i = 0; i < n; i++) {   //n번 도는 반복문
        if (!check[i] && prev != num[i]) { //수 위치 중복 체크 && 이전에 탐색한 값이 아니라면
            prev = num[i];          //prev에 현재 숫자 사용했으니 저장해놓는다
            ans[cnt] = num[i];      //ans벡터(정답 벡터)에 현재 숫자 저장
            check[i] = true;        //num벡터의 i번째 숫자 사용했으니 check벡터의 i번째 원소 true로
            backtracking(cnt + 1);  //백트래킹 다시 부른다
            //다시 돌아왔을 때
            check[i] = false;       //check벡터의 i번째 원소 다시 false로 바꾼다
        }
    }
}

/**
 * 1. 우선 수열을 사전 순으로 증가하는 순서로 출력해야 하므로 주어진 수열을 오름차순 정렬
 * 2. 이 상태에서 우선, 같은 위치의 수를 또 선택하지 않도록 중복제거 (check 배열 사용)를 해줌
 * 3. 그 후, 중복되는 "수열"을 거르는 방법은 이전에 선택한 값을 변수에 저장해서, 수열을 만들다 다시 루트 노드로 돌아왔을 때
 *    이전에 선택한 값과 같은 값이면 넘어가면 됨! -> 어차피 같은 수이므로 같은 과정 반복해서 똑같은 수열이 나올 것
 */

int main() {
    //입력
    cin >> n >> m;  //n과 m 입력받는다
    for (int i = 0; i < n; i++) {   //n번 도는 반복문
        cin >> num[i];  //num 벡터에 n개의 숫자들 입력받는다
    }

    //연산
    sort(num.begin(), num.begin() + n); //오름차순 정렬

    //백트래킹 & 출력
    backtracking(0);    //백트래킹 연산
    return 0;   //프로그램 종료
}