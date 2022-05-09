//
// Created by kjy82 on 2022-05-01.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx) {
    while (left < right) { //left가 right보다 작을 동안
        if (left == idx) { //left와 idx의 값이 같으면
            left++; //left의 값 증가
            continue; //반복문 계속
        }
        if (right == idx) { //right와 idx의 값이 같으면
            right--; //right의 값 감소
            continue; //반복문 계속
        }

        if (num[left] + num[right] == num[idx]) { //num[left]와 num[right]의 합이 num[idx]이면
            return true; //true 반환 (좋은 수이다)
        }
        if (num[left] + num[right] > num[idx]) { //num[left]와 num[right]의 합이 num[idx]보다 크면
            right--; //right의 값 감소 -> num[left] + num[right]의 값 작아질 것
        } else { //num[left]와 num[right]의 합이 num[idx]보다 작으면
            left++; //left의 값 감소 -> num[left] + num[right]의 값 커질 것
        }
    }
    return false; //false 반환(좋은 수가 아님)
}

/**
 * [좋다]
 *
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {
    int n, ans = 0; //n: 수의 개수, ans: 좋은 수의 개수

    //입력
    cin >> n;
    vector<int> num(n, 0); //크기 n의 벡터 num
    for (int i = 0; i < n; i++) { //n번 반복
        cin >> num[i]; //입력받은 수 num에 저장
    }

    //연산
    sort(num.begin(), num.end()); //오름차순 정렬
    for (int i = 0; i < n; i++) { //n번 반복 (num의 모든 원소에 대해 isGood 실행)
        if (isGood(num, 0, n - 1, i)) { //수가 좋은 수이면
            ans++; //정답 개수 +1
        }
    }

    //출력
    cout << ans;
    return 0; //프로그램 종료
}