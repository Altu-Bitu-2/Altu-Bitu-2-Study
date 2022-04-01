//
// Created by kjy82 on 2022-04-01.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF_MAX = 1e9;    //1e9 = 1 * 10^9
const int SIZE = 11;        //주어지는 수의 최대 개수: 11

int n;  //자연수의 개수
vector<int> num(SIZE + 1);  //n개의 자연수 입력받을 벡터
vector<int> expression(4); //0: +, 1: -, 2: *, 3: /
int max_value = -INF_MAX, min_value = INF_MAX;  //얻을 수 있는 결과값의 최댓값과 최솟값

void backtracking(int cnt, int sum) { //cnt: 수 인덱스, sum: 연산 결과
    if (cnt == n - 1) { //연산 모두 완료했다면 (기저조건)
        max_value = max(max_value, sum);    //max_value, sum 중 큰 값 max_value에 저장
        min_value = min(min_value, sum);    //min_value, sum 중 작은 값 min_value에 저장
        return; //기저조건 만족했으므로 함수 리턴
    }
    for (int i = 0; i < 4; i++) { //연산자 검사
        if (expression[i]) {    //해당 연산자 입력으로 주어졌을 때
            expression[i]--;    //연산자 사용했으니 개수 하나 감소
            int new_sum = 0;    //연산 결과값 담을 변수
            switch (i) { //연산자 종류에 따라
                case 0: //+인 경우
                    new_sum = sum + num[cnt + 1];   //덧셈 수행
                    break;  //switch문 빠져나감
                case 1: //-인 경우
                    new_sum = sum - num[cnt + 1];   //뺄셈 수행
                    break;  //switch문 빠져나감
                case 2: //*인 경우
                    new_sum = sum * num[cnt + 1];   //곱셈 수행
                    break;  //switch문 빠져나감
                case 3: //나누기인 경우
                    new_sum = sum / num[cnt + 1];   //나눗셈 수행
                    break;  //switch문 빠져나감
            }
            backtracking(cnt + 1, new_sum); //증가시킨 cnt값과 현재까지의 연산 결과 매개변수로 backtracking함수 다시 수행
            //다시 돌아왔을때
            expression[i]++;    //연산자 개수 다시 증가
        }
    }
}

/**
 * 연산자 모두 돌려보면서 배치한 후, 각 연산자에 따른 값 계산
 */

int main() {
    //입력
    cin >> n;   //n 입력받음
    for (int i = 0; i < n; i++) {   //n번 도는 반복문
        cin >> num[i];              //num벡터에 자연수들 입력받음
    }
    for (int i = 0; i < 4; i++) {   //4번 도는 반복문
        cin >> expression[i];       //각 연산자의 개수에 대한 정보 expression 벡터에 입력받음
    }

    //연산
    backtracking(0, num[0]);

    //출력
    cout << max_value << '\n' << min_value; //결과값 출력
    return 0;   //프로그램 종료
}