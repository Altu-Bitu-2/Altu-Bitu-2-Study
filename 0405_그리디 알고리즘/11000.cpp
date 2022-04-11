//
// Created by kjy82 on 2022-04-11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

void maxLecture(int n, vector<ci>& classroom) {
    int prev_end = 0;	//직전 강의가 끝난 시간
    for (int i = 0; i < classroom.size(); i++) {
        int end = classroom[i].first;		//강의 끝난 시간
        int start = classroom[i].second;	//강의 시작 시간
        if (start >= prev_end) {	//강의 시작 시간 >= 직전 강의 끝난 시간
            prev_end = end;
            classroom.erase(classroom.begin() + i);
            i--;	//erase 사용하면서 삭제한 원소 뒤의 인덱스들이 1씩 줄었으므로 i 감소시킨다
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, count = 0;

    //입력
    cin >> n;
    vector<ci> classroom(n, { 0,0 });

    for (int i = 0; i < n; i++) {
        cin >> classroom[i].second >> classroom[i].first;
    }
    //빨리 끝나는 순서대로, 빨리 시작하는 순서대로 정렬
    sort(classroom.begin(), classroom.end());

    //연산
    while (!classroom.empty()) {
        maxLecture(n, classroom);
        count++;
    }

    //출력
    cout << count;

    return 0;
}