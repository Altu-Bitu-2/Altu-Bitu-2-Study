//
// Created by kjy82 on 2022-03-09.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int getMin(int n, vector<int> a, vector<int> b) {
    int min = 0;
    for (int i = 0; i < n; i++) {
        min += a[i] * b[i];
    }
    return min;
}


int main() {
    int N, result = 0;
    vector<int> arr_a, arr_b;

    //입력
    cin >> N;
    arr_a.assign(N, 0);
    arr_b.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> arr_a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> arr_b[i];
    }

    sort(arr_a.begin(), arr_a.end()); //오름차순 정렬
    sort(arr_b.begin(), arr_b.end(), greater<>()); //내림차순 정렬
    result = getMin(N, arr_a, arr_b);

    //출력
    cout << result << '\n';

    return 0;
}