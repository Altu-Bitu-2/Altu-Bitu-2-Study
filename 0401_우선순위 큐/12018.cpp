//
// Created by kjy82 on 2022-04-06.
//

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

//성준이가 신청할 수 있는 과목 수 찾는 함수
int countSubject(int m, priority_queue<int, vector<int>, greater<>>& subjects) {
    int count = 0;  //신청 과목 수
    while (!subjects.empty() && m - subjects.top() >= 0) {
        m -= subjects.top();
        count++;
        subjects.pop();
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, p, l, others_m;
    //n:과목 수, m:마일리지, p:신청인원, l: 수강인원, others_m: 타학생들이 넣은 마일리지
    priority_queue<int, vector<int>, greater<>> subjects;	//과목별 성준이가 넣어야할 최소 마일리지 저장할 pg

    //입력
    cin >> n >> m;
    while (n--) {
        cin >> p >> l;
        vector<int> mileage(p, 0);	//과목별 타학생들 마일리지 입력받을 pq

        for (int i = 0; i < p; i++) {
            //타학생들이 마일리지 얼마나 넣었는지 입력받음
            cin >> mileage[i];
        }

        sort(mileage.begin(), mileage.end(), greater<>());   //mileage 내림차순 정렬

        //인원 미달이면 마일리지 1만 넣어도 수강 가능 -> 성준이가 넣어야 할 최소 마일리지: 1
        if (p < l) {
            subjects.push(1);
        }

            //신청인원=수강인원 -> 성준이가 넣어야 할 최소 마일리지: 가장 적게 마일리지 넣은 사람과 동일한 값
        else if (p == l) {
            subjects.push(mileage.back());
        }

            //신청인원>수강인원(l) -> 성준이가 넣어야 할 최소 마일리지: l번째로 많은 마일리지 넣은 사람과 동일한 값
        else {
            subjects.push(mileage[l - 1]);
        }
    }

    //출력
    cout << countSubject(m, subjects) << '\n';

    return 0;
}