//
// Created by kjy82 on 2022-04-15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int childNum(int len, vector<int> &snacks) {
    int cnt = 0;   //과자를 나눠줄 수 있는 아이들의 수
    for (int i = snacks.size() - 1; i >= 0; i--) { //가장 긴 과자부터 검사
        if (snacks[i] < len) { //나누어주려는 길이보다 작아지면 더 이상 못 나눠줌
            break; //반복문 빠져나감
        }
        cnt += (snacks[i] / len);
        //snacks[i] / len값 (=나눠주는 과자의 길이 len일때 snacks[i]로 만들 수 있는 len길이의 과자의 수)만큼 cnt 증가
    }

    return cnt;  //cnt 반환
}

int upperSearch(int left, int right, int target, vector<int> &snacks) {
    while (left <= right) { //left가 right 이하일때 반복
        int mid = (left + right) / 2; //과자의 길이
        int cnt = childNum(mid, snacks); //과자 길이가 mid일 때 몇 명에게 나눠주는지

        if (cnt >= target) { //target보다 더 많은 아이들에게 나눠준다면 -> 과자 길이를 더 늘릴 수 있음
            left = mid + 1; //left 값을 mid+1로
        } else { //target만큼의 아이들에게 과자 못 나눠줄때 -> 과자 길이 줄여야 함
            right = mid - 1; //right 값을 mid-1로
        }
    }
    return left - 1; //left-1값 반환 (cnt == target일때 left=mid+1을 했으므로)
}

/**
 * [과자 나눠주기]
 *
 * n개의 과자가 있을 때 m명의 조카에게 각각 같은 길이로 줄 수 있는 과자의 최대 길이를 구하는 문제
 * -> 특정 과자 길이에 대하여 m명의 조카에게 나누어 줄 수 있는가?
 *
 * left: 과자 길이의 최솟값 -> 1
 * right: 과자 길이의 최댓값
 *
 * 과자를 몇 명에게 나누어줄 수 있는지 차례로 검사하다 나누어줄 수 없으면 빠져나오기 위해 정렬을 먼저 해주면 좋음
 */

int main() {
    int m, n, left = 1, right = 0;
    //m: 조카의 수, n:과자의 수, left:과자 길이의 최솟값, right: 과자 길이의 최댓값

    //입력
    cin >> m >> n;
    vector<int> snacks(n, 0);   //과자의 길이 저장할 벡터 snacks
    for (int i = 0; i < n; i++) {   //n번 반복
        cin >> snacks[i];   //과자의 길이 입력 받음
    }

    //연산
    sort(snacks.begin(), snacks.end()); //과자의 길이 오름차순으로 정렬
    right = snacks[n - 1];  //과자 길이의 최댓값 right에 저장

    //연산 & 출력
    cout << upperSearch(left, right, m, snacks);
    return 0;   //프로그램 종료
}