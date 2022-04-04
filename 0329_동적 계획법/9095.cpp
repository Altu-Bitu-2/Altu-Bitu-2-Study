//
// Created by kjy82 on 2022-04-04.
//

#include <iostream>
#include <vector>

using namespace std;

//1,2,3의 합으로 나타내는 방법의 수를 구하는 프로그램
int countSum(int n) {
    vector<int> dp(n + 1, 0);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    /*
    ex. 7 = 1 + 6 (= dp[6])
          = 2 + 5 (= dp[5])
          = 3 + 4 (= dp[4])
    */
    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    int T, n;

    //입력
    cin >> T;
    while (T--) {
        cin >> n;

        //연산+출력
        cout << countSum(n) << '\n';
    }
    return 0;
}