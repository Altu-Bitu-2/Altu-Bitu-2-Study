#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


//팁의 최댓값을 구하는 함수
long long int findMax(int n, vector<int> arr) {
    long long int total_tip = 0;
    int tip = 0;
    for(int i = 1; i <= n; i++) {
        tip = arr[i - 1] - (i - 1);
        if(tip > 0) {
            total_tip += tip;
        }
    }
    return total_tip;
}


int main() {
    int N;
    long long int max_tip;
    vector<int> arr;

    //입력
    cin >> N;
    arr.assign(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), greater<>());
    max_tip = findMax(N, arr);

    //출력
    cout << max_tip << '\n';

    return 0;
}