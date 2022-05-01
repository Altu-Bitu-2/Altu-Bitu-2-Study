//
// Created by kjy82 on 2022-05-01.
//

#include <iostream>
#include <vector>

using namespace std;

//가능한 성원이의 현재 몸무게를 구하는 함수
vector<int> possibleWeight(int left, int right, int g) {
    vector<int> ans; //정답을 저장할 벡터 ans 선언
    while (left < right) { //left가 right보다 작을 동안
        int diff = right * right - left * left; //diff=성원이의 현재 몸무게(right)의 제곱 - 성원이가 기억하고 있던 몸무게(left)의 제곱

        if (diff <= g) { //diff가 g이하일때
            if (diff == g) { //diff와 g의 값이 같으면 (right가 현재 성원이의 몸무게인게 사실이라면)
                ans.push_back(right); //right를 ans에 저장한다
            }
            right++; //right의 값 증가
        } else { //diff가 g보다 크면 -> diff의 값 줄여야됨
            left++; //left의 값 증가
        }
    }
    return ans; //정답 벡터 ans 반환
}

/**
 * [다이어트]
 *
 * left: 성원이가 기억하고 있던 몸무게
 * right: 성원이의 현재 몸무게
 *
 * 같은 위치에서 시작해서 점점 증가하는 투 포인터로 풀이
 * 대신, left ~ right를 모두 고려하는 것이 아니라 left, right 포인터 값 자체만 고려
 *
 * !주의! 몸무게의 범위가 딱히 정해져 있지 않으므로, 종료 조건을 잘 세우는 것이 중요!
 *       -> 두 몸무게가 같아지는 순간 종료!
 *       -> left가 right와 같은 값을 가진다면, 직전 상황은 두 몸무게가 1차이 나는 상황
 *       -> 이때 몸무게 차이가 g 이상이었다는 것은 이후로 나올 수 있는 차이는 무조건 g이상이 된다. (제곱수의 간격은 수가 커질수록 늘어나기 때문)
 */

int main() {
    int g; //g: 성원이의 현재 몸무게의 제곱 - 성원이가 기억하고 있던 몸무게의 제곱

    //입력
    cin >> g;

    //연산
    vector<int> ans = possibleWeight(1, 2, g);

    //출력
    if (!ans.size()) { //가능한 몸무게가 없을때
        cout << "-1"; //-1 출력
        return 0; //프로그램 종료
    }
    for (int i = 0; i < ans.size(); i++) { //ans의 원소 개수만큼 반복
        cout << ans[i] << '\n'; //정답 출력
    }
    return 0; //프로그램 종료
}