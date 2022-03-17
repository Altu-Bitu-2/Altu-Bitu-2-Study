//
// Created by kjy82 on 2022-03-17.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>


using namespace std;


int main() {
    int N, num;
    double mean = 0;
    int median = 0, mode = 0, range = 0, max = 0, count = 0;
    vector<int> v, arr;
    map<int, int> m;

    //입력
    cin >> N;
    v.assign(N, 0);
    arr.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> num;
        v[i] = num;
        m[num]++;
    }

    sort(v.begin(), v.end()); //숫자열 크기순 정렬

    //산술평균
    for (auto iter : v) {
        mean += iter;
    }
    mean = (int) round(mean / N);
    if (mean == -0) {
        mean = 0;
    }

    //중앙값
    median = v[N / 2];

    //최빈값
    //최빈값의 빈도수 찾기
    for (auto iter : m) {
        if (iter.second > max) {\
			max = iter.second;
        }
    }
    //최빈값 여러개일 경우 2번째로 작은 수 찾기
    for (auto iter : m) {
        if (iter.second == max) {
            mode = iter.first;
            count++;
            if (count == 2) {
                mode = iter.first;
                break;
            }
        }
    }

    //범위
    range = v[N - 1] - v[0];

    //출력
    cout << mean << '\n' << median << '\n' << mode << '\n' << range << '\n';
    return 0;
}