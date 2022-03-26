//
// Created by kjy82 on 2022-03-24.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//필요한 제곱수의 최소 개수를 구하는 함수
int findMinNumber(int n, int num_size, vector<int> &square_num) {
    if (square_num[num_size - 1] == n) { //1개로 만들 수 있을 경우 바로 리턴
        return 1; //1 리턴
    }
    for (int i = num_size - 1; i >= 0; i--) { //2개로 만들 수 있는 경우 검사
        for (int j = num_size - 1; j >= 0; j--) { //가능한 제곱수들 다 검사
            if (square_num[i] + square_num[j] == n) { //두개의 제곱수의 합으로 n 나타낼 수 있으면
                return 2; //2 리턴
            }
        }
    }
    for (int i = num_size - 1; i >= 0; i--) { //3개로 만들 수 있는 경우 검사
        for (int j = num_size - 1; j >= 0; j--) { //가능한 제곱수들 다 검사
            for (int k = num_size - 1; k >= 0; k--) { //가능한 제곱수들 다 검사
                if (square_num[i] + square_num[j] + square_num[k] == n) { //세개의 제곱수의 합으로 n 나타낼 수 있으면
                    return 3; //3 리턴
                }
            }
        }
    }
    return 4; //1,2,3개의 제곱수로 표현 못하면 답은 무조건 4
    //개수 구하는 문제니 굳이 어떤 제곱수들 조합인지 구할 필요 없음
}

/**
 * [Four Squares] - 브루트포스 풀이 (8ms)
 * 자연수 n에 대해 최소 몇개의 제곱수의 합으로 표현할 수 있는지 찾는 문제
 * 미리 최댓값까지의 제곱수를 구해놓고, 완전탐색
 *
 * 1 ~ 3개 조합으로 불가능한 경우, 답은 무조건 4가 된다 -> 4개의 합은 시도해보지 않아도 된다.
 *
 * sqrt(50000) = 약 223
 * 전체 연산 수  < 223^2 + 223^3 = 11139296 <1억 -> 브루트포스 가능
 */

int main() {
    int n, num_size; //자연수 n, 제곱수 개수 num_size 선언
    vector<int> square_num; //제곱수들 저장할 벡터 square_num 선언

    //입력
    cin >> n;

    //연산
    for (int i = 1; i <= sqrt(n); i++) { //미리 루트 n 까지의 제곱수 저장
        square_num.push_back(i * i); //n이하의 제곱수들 square_num에 저장
    }
    num_size = square_num.size(); //제곱수 개수

    //출력
    cout << findMinNumber(n, num_size, square_num);
    return 0; //프로그램 종료
}