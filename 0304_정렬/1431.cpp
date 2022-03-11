//
// Created by kjy82 on 2022-03-10.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int calSum(const string &a) {
    int sum = 0;
    for (int i = 0; i < a.length(); i++) {
        if (isdigit(a[i]))
            sum += a[i] - '0';
    }
    return sum;
}


bool cmp(const string& a, const string& b) {
    int sum_a = 0;
    int sum_b = 0;
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }
    if (calSum(a) != calSum(b)) {
        return calSum(a) < calSum(b);
    }
    return a < b;
}


int main() {
    int N;
    vector<string> guitar;

    //입력
    cin >> N;
    guitar.assign(N, "");
    for (int i = 0; i < N; i++) {
        cin >> guitar[i];
    }

    sort(guitar.begin(), guitar.end(), cmp);

    //출력
    for (int i = 0; i < N; i++) {
        cout << guitar[i] << '\n';
    }

    return 0;
}