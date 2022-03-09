//
// Created by kjy82 on 2022-03-09.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


vector<int> arr_a, arr_b;


bool compare(int i, int j) {
    return j < i;
}


int getMin(int n) {
    int min = 0;
    for (int i = 0; i < n; i++) {
        min += arr_a[i] * arr_b[i];
        cout << min << '\n';
    }
    return min;
}


int main() {
    int N, result = 0;

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
    sort(arr_b.begin(), arr_b.end(), compare); //내림차순 정렬
    result = getMin(N);

    //출력
    cout << result << '\n';

    return 0;
}