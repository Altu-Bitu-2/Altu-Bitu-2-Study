//
// Created by kjy82 on 2022-04-04.
//

#include <iostream>
#include <vector>

using namespace std;

//가장 긴 증가하는 부분 수열의 길이를 찾는 함수
int findIncrease(int n, vector<int>& arr) {
    int ans = 1;
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            //j번째 원소보다 숫자가 큰 경우 (증가 부분수열인 경우)
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
    }

    return ans;
}

int main() {
    int n;
    vector<int> arr;

    //입력
    cin >> n;
    arr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //연산+출력
    cout << findIncrease(n, arr) << '\n';

    return 0;
}