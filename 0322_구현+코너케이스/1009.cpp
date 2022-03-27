//
// Created by kjy82 on 2022-03-28.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T, a, b;	//T: 테스트케이스 수, a: 밑, b: 지수
    int num = 0;	//a의 b승

    //입력
    cin >> T;
    while (T--) {
        cin >> a >> b;
        /**2, 4, 8, 16, 32, 64...2, 4, 8, 6 계속 반복됨
        * 다른 밑에 대해서도 최대 5번째에서 다시 같은 숫자 반복됨
        * 일의 자리가 a의 5승 = a의 1승!
        **/
        if (b % 4 == 0) {
            b = 4;
        }
        else {
            b = b % 4;
        }

        num = pow(a, b);

        //출력
        if (num % 10 == 0) {
            cout << 10 << '\n';
        }
        else {
            cout << num % 10 << '\n';
        }
    }

    return 0;
}