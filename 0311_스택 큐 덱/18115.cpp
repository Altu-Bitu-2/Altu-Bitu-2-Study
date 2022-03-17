//
// Created by kjy82 on 2022-03-17.
//

#include <iostream>
#include <vector>
#include <deque>


using namespace std;


int main() {
    int N, input, tmp = 0;
    vector<int> v;
    deque<int> q;

    //입력
    cin >> N;
    v.assign(N, 0);
    //숫자열 거꾸로 저장
    for (int i = 0; i < N; i++) {
        cin >> input;
        v[N - 1 - i] = input;
    }

    for (int j = 0; j < N; j++) {
        switch (v[j]) {
            //1일 때 front에 저장
            case 1:
                q.push_front(j + 1);
                break;
                //2일 때 front 다음(두번째)에 저장
            case 2:
                tmp = q.front();
                q.pop_front();
                q.push_front(j + 1);
                q.push_front(tmp);
                break;
                //3일 때 rear에 저장
            case 3:
                q.push_back(j + 1);
                break;
        }
    }

    //출력
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop_front();
    }

    return 0;
}