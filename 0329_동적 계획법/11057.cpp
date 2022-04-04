//
// Created by kjy82 on 2022-04-04.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

//오르막의 개수를 10007로 나눈 나머지 구하는 함수
int findUpNum(int n) {
    int ans = 0;
    vector<long long> dp(10, 1);

    /*
    * ex. n = 2
    * 0 0~9 -> dp[0]+dp[1]+...dp[9]
    * 1 1~9 -> dp[1]+dp[2]+...dp[9]
    * ...
    * 9 9   -> dp[9]
    */

    while (n--) {
        for (int i = 0; i < 10; i++) {
            dp[i] = accumulate(dp.begin() + i, dp.end(), 0) % 10007;
        }
        ans = dp[0];
    }

    return ans;
}

int main() {
    int N;

    //입력
    cin >> N;

    //연산+출력
    cout << findUpNum(N) << '\n';

    return 0;
}