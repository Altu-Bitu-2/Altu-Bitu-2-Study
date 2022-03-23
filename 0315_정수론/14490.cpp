//
// Created by kjy82 on 2022-03-21.
//

#include <iostream>
#include <string>


using namespace std;


//유클리드 호제법으로 최대공약수 구하는 함수
int getGcd(int n, int m) {
    if (m == 0) {
        return n;
    }
    return getGcd(m, n % m);
}


int main() {
    string input;
    int n = 0, m = 0, pos = 0, gcd = 0;

    //입력
    cin >> input;

    //문자열 ":" 기준으로 정수 n, m 나누기
    pos = input.find(":");
    n = stoi(input.substr(0, pos));
    m = stoi(input.substr(pos + 1, input.length()));

    //n, m의 최대공약수
    gcd = getGcd(n, m);

    //출력
    cout << n / gcd << ":" << m / gcd;

    return 0;
}