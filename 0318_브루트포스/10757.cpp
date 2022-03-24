//
// Created by kjy82 on 2022-03-24.
//

#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


int main() {
    string A, B;
    vector<int> answer;

    //입력
    cin >> A >> B;
    answer.assign(max(A.size(), B.size()) + 1, 0); //10(두자리) + 90(두자리) = 100(세자리). 최대 문자열 길이 + 1로 크기 지정
    reverse(A.begin(), A.end()); //A문자열 거꾸로 -> 인덱스 0이 일의 자리되도록
    reverse(B.begin(), B.end());

    //연산
    //A,B 중 길이가 작은 문자열까지 먼저 계산
    for (int i = 0; i < min(A.size(), B.size()); i++) {
        if (A[i] + B[i] - 2 * '0' + answer[i] > 9) {
            answer[i + 1] = 1;
        }
        answer[i] = (A[i] + B[i] - 2 * '0' + answer[i]) % 10;
    }
    //그 이후 남은 문자열 더해줌
    for (int j = min(A.size(), B.size()); j < max(A.size(), B.size()); j++) {
        if (A.size() > B.size()) {
            answer[j] += A[j] - '0';
        }
        else {
            answer[j] += B[j] - '0';
        }
    }

    //출력
    int j;
    for (answer[answer.size() - 1] != 0 ? j = answer.size() - 1 : j = answer.size() - 2; j > -1; j--) {
        //123 + 10 = 0133 나오지 않도록 조건 조절
        cout << answer[j];
    }

    return 0;
}