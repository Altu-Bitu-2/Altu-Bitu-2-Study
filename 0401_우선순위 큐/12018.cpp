//
// Created by kjy82 on 2022-04-06.
//

#include <iostream>
#include <queue>

using namespace std;

//비교연산자: 더 작은 값 반환
struct cmp {
    bool operator()(const int& x1, const int& x2) {
        return x2 < x1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, p, l, count = 0, others_m;
    //n:과목 수, m:마일리지, p:신청인원, l:수강인원, count: 신청 과목 수, others_m: 타학생들이 넣은 마일리지
    priority_queue<int, vector<int>, cmp> mileage;	//과목별 타학생들 마일리지 입력받을 pq
    priority_queue<int, vector<int>, cmp> subjects;	//과목별 성준이가 넣어야할 최소 마일리지 저장할 pg

    //입력
    cin >> n >> m;
    while (n--) {
        cin >> p >> l;

        for (int i = 0; i < p; i++) {
            //타학생들이 마일리지 얼마나 넣었는지 입력받음
            cin >> others_m;
            mileage.push(others_m);
        }

        //인원 미달이면 마일리지 1만 넣어도 수강 가능 -> 성준이가 넣어야 할 최소 마일리지: 1
        if (p < l) {
            subjects.push(1);
        }

            //신청인원=수강인원 -> 성준이가 넣어야 할 최소 마일리지: 가장 적게 마일리지 넣은 사람과 동일한 값
        else if (p == l) {
            subjects.push(mileage.top());
        }

            //신청인원>수강인원(l) -> 성준이가 넣어야 할 최소 마일리지: l번째로 많은 마일리지 넣은 사람과 동일한 값
        else {
            for (int i = 0; i < p - l; i++) {
                mileage.pop();
            }
            subjects.push(mileage.top());
        }
        mileage = priority_queue<int, vector<int>, cmp>();
    }

    //성준이가 마일리지 넣을 수 있는지 확인하고 수강신청
    while (!subjects.empty() && m - subjects.top() > -1) {
        m -= subjects.top();
        count++;
        subjects.pop();
    }

    //출력
    cout << count << '\n';

    return 0;
}