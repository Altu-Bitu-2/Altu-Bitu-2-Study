//
// Created by kjy82 on 2022-04-11.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, count = 0;

    //입력
    cin >> n;
    vector<ci> classroom(n, { 0,0 });
    priority_queue<int, vector<int>, greater<>> end_time;	//강의 끝나는 시간 내림차순으로 저장할 우선순위 큐

    for (int i = 0; i < n; i++) {
        cin >> classroom[i].first >> classroom[i].second;
    }
    //빨리 시작하는 순서대로 정렬
    sort(classroom.begin(), classroom.end());
    end_time.push(classroom[0].second);

    //연산
    for (int i = 1; i < n; i++) {
        if (end_time.top() <= classroom[i].first) {	//가장 빨리 끝나는 강의 시간 <= 강의 시작 시간일때
            end_time.pop(); //뒤에 강의 추가되니까 pop
            end_time.push(classroom[i].second); //추가된 강의의 끝나는 시간을 push
        }
        else {
            end_time.push(classroom[i].second);
        }
    }

    //출력
    cout << end_time.size() << '\n';

    return 0;
}