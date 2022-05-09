//
// Created by kjy82 on 2022-05-01.
//

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef long long ll; //long long 데이터 타입을 ll로 정의
const ll INF = 3 * 1e9 + 1; //INF는 세 용액 특성값 합의 최대값 + 1

ll min_diff = INF; //min_diff를 INF로 초기화

//다른 위치에서 시작하여 서로를 향해 가까워지는 투 포인터
pair<ll, ll> liquid(vector<ll> &arr, ll fixed, int left, int right) {
    pair<ll, ll> ans; //한 용액 고정 시, 나머지 두 용액 저장할 페어 ans 선언
    ans = make_pair(INF, INF); //INF, INF 페어로 ans 초기화

    while (left < right) { //left가 right보다 작을 동안
        ll mix = fixed + arr[left] + arr[right]; //mix = 고정 용액 하나 + arr[left] + arr[right]
        if (mix == 0) { //mix가 0일때 -> 무조건 특성값 0에 가장 가까운 경우
            return make_pair(arr[left], arr[right]); //arr[left], arr[right] 페어 반환
        }
        if (abs(mix) < min_diff) { //mix의 절대값이 min_diff보다 작을때
            min_diff = abs(mix); //min_diff의 값을 mix의 절대값으로 갱신
            ans = make_pair(arr[left], arr[right]); //ans에 arr[left], arr[right] 페어 저장
        }
        if (mix > 0) { //mix가 0보다 클 때 -> mix의 값 감소시켜보자
            right--; //right의 값 감소
        } else { //mix가 0보다 작을 때 -> mix의 값 증가시켜보자
            left++; //left의 값 증가
        }
    }
    return ans; //정답 페어 ans 반환
}

/**
 * 2470번 : 두 용액 섞기
 * 2473번 : 세 용액 섞기
 *
 * [세 용액]
 *
 * 1. 하나의 용액을 반드시 사용한다고 가정
 * 2. 용액 하나 고정
 * 3. 해당 용액 이후의 범위에 대해 투 포인터 알고리즘 적용
 *
 * pair : 2개의 값 저장
 * tuple : 3개의 값 저장
 *
 * !주의! 세 용액의 최댓값은 1e9(=10억)이기 때문에 3개를 섞은 최댓값은 30억이고, int를 넘어감!
 */
int main() {
    int n; //n: 전체 용액의 수

    //입력
    cin >> n;
    vector<ll> arr(n, 0); //크기 n의 배열 arr !!범위 ll!!
    for (int i = 0; i < n; i++) { //n번 반복
        cin >> arr[i]; //arr에 용액의 특성값 입력받기
    }

    //연산
    sort(arr.begin(), arr.end()); //오름차순 정렬
    tuple<ll, ll, ll> ans; //세 용액의 특성값 담을 투플 ans !범위 ll!
    for (int i = 0; i < n - 2; i++) { //n-2번 반복
        pair<ll, ll> p = liquid(arr, arr[i], i + 1, n - 1); //arr[i] 용액은 고정
        if ((p.first != INF) && (p.second != INF)) { //최솟값이 갱신된 경우
            ans = make_tuple(arr[i], p.first, p.second); //ans에 답 저장
        }
    }

    //출력
    cout << get<0>(ans) << ' ' << get<1>(ans) << ' ' << get<2>(ans);
    return 0; //프로그램 종료
}