//
// Created by kjy82 on 2022-03-22.
//

#include <iostream>
#include <cmath>

using namespace std;

// 유클리드 호제법
int gcdRecursion(int a, int b) {
    // a > b 일 때, a와 b의 최대공약수를 리턴
    if (b == 0) { //b가 0인 경우
        return a; //a(최대공약수)를 반환
    }
    return gcdRecursion(b, a % b); //b가 0이 아니면 재귀함수 반복
}

/**
 * 최대공약수를 G, 최소공배수를 L 이라고 하자.
 * G*L = A*B 이고
 * A = G*a, B = G*b로 나타낼 수 있다.
 * 이에 따라 G*L = G*G*a*b라 할 수 있고 이를 정리하면
 * L/G = a*b 이다.
 *
 * A+B가 최소가 되려면, a+b가 최소가 되어야 하고, 그러기 위해선 a, b의 차이가 최소여야 한다.
 */

int main() {
    int gcd, lcm; //최대공약수, 최소공배수를 담을 변수 선언

    //입력
    cin >> gcd >> lcm;

    //연산
    int ab = lcm / gcd; //a * b = lcm / gcd
    int a = -1, b = -1; //a, b -1로 초기화하여 선언
    for (int i = sqrt(ab); i > 0; i--) { //a, b의 차이가 가장 작을 제곱근부터 체크
        if (ab % i != 0) { //i가 ab의 약수 아니라면
            continue;      //건너뛰고 for문 반복
        }
        //i가 ab의 약수라면
        int tmp_a = i, tmp_b = ab / i; //a를 임시로 i (tmp_a), b를 임시로 ab / i (tmp_b)로 생각
        //두 수가 서로소인지 체크 -> 만약 두 수가 서로소가 아니라면 두 수의 최대공약수가 gcd가 될 수 없음
        if (gcdRecursion(tmp_b, tmp_a) == 1) { //tmp_a, tmp_b의 최대공약수가 1이라면 (둘이 서로소라면)
            a = tmp_a; //tmp_a 값이 a
            b = tmp_b; //tmp_b 값이 b
            break;     //for문 벗어남
        }
    }
    //a, b의 차이가 가장 작을 제곱근부터 체크했기 때문에 처음으로 얻는 값이 최소합일 것이다

    //출력
    cout << a * gcd << ' ' << b * gcd;
}