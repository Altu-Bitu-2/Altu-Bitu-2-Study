//
// Created by kjy82 on 2022-04-04.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, n;
    vector<int> dp(12, 0);
    //dp 미리 채워놓기
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    /*
    ex. 7 = 1 + 6 (= dp[6])
          = 2 + 5 (= dp[5])
          = 3 + 4 (= dp[4])
    */
    for (int i = 4; i <= 11; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    //입력
    cin >> T;
    while (T--) {
        cin >> n;

        //연산+출력
        cout << dp[n] << '\n';
    }
    return 0;
}