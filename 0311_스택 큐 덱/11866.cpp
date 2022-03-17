//
// Created by kjy82 on 2022-03-17.
//

#include <iostream>
#include <queue>


using namespace std;


int main() {
    int N, K;
    queue<int> q;

    //입력
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        q.push(i + 1);
    }

    //출력
    cout << "<";
    while (q.front() != q.back()) {
        for (int i = 0; i < K - 1; i++) {
            //맨 앞의 원소 제일 뒤에 추가 및 기존 위치에서 삭제
            q.push(q.front());
            q.pop();
        }
        //K번째 원소마다 출력 및 삭제
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">\n";

    return 0;
}