//
// Created by kjy82 on 2022-03-21.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


//가장 큰 30의 배수 찾고 출력하는 함수
void findMax(string& N) {
    int sum = 0;
    vector<char> v(N.length());

    for (int i = 0; i < N.length(); i++) {
        sum += N[i];
        v[i] = N[i];
    }

    //3의 배수 또는 10의 배수가 아니면 -1 반환
    if (sum % 3 != 0 || N.find('0') == -1) {
        cout << -1 << '\n';
        return;
    }

    sort(v.begin(), v.end(), greater<>()); //내림차순 정렬
    for (auto iter : v) {
        cout << iter;
    }
}


int main() {
    string N;

    //입력
    cin >> N;

    findMax(N);

    return 0;
}