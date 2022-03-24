//
// Created by kjy82 on 2022-03-24.
//

#include <iostream>
#include <math.h>


using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    int a = 0, b = 0, c = 0, d = 0, count = 0, answer = 4;

    //입력
    cin >> n;

    a = sqrt(n);
    count++;

    for (int i = a; i > 0; i--) {
        //두개의 제곱수가 필요한 경우
        if (n - pow(i, 2) > 0) {
            b = sqrt(n - pow(i, 2));
            count++;
        }
        //세개의 제곱수가 필요한 경우
        if (n - pow(i, 2) - pow(b, 2) > 0) {
            c = sqrt(n - pow(i, 2) - pow(b, 2));
            count++;
        }
        //네개의 제곱수가 필요한 경우
        if (n - pow(i, 2) - pow(b, 2) - pow(c, 2) > 0) {
            d = sqrt(n - pow(i, 2) - pow(b, 2) - pow(c, 2));
            count++;
        }
        //네개의 제곱수의 합이 주어진 수보다 작은 경우
        if (n - pow(i, 2) - pow(b, 2) - pow(c, 2) - pow(d, 2) > 0) {
            //count, b, c, d 다시 초기화 (a는 센 상태이므로 count 1로 초기화)
            count = 1;
            b = c = d = 0;
        }
        //네개의 제곱수의 합 구한 경우 개수 최소인지 확인
        if (n - pow(i, 2) - pow(b, 2) - pow(c, 2) - pow(d, 2) == 0) {
            //제곱수 1개면 무조건 개수 최소 만족. for문 빠져나가기
            if (count == 1) {
                answer = 1;
                break;
            }
            else if (count < answer) {
                answer = count;
                count = 1;
                b = c = d = 0;
            }
        }
    }

    //출력
    cout << answer << '\n';

    return 0;
}