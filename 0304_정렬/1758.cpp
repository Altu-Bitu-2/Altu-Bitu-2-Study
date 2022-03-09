#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


vector<int> arr;


bool compare(int i, int j) {
    return j < i;
}


//팁의 최댓값을 구하는 함수
int findMax(int n) {
    int total_tip = 0;
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
    int N, max;

    //입력
    cin >> N;
    arr.assign(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end(), compare);
    max = findMax(N);

    //출력
    cout << max << '\n';

    return 0;
}