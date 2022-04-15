//
// Created by kjy82 on 2022-04-15.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

ll cntTree(int height, vector<int> &tree) {
    ll sum = 0; //잘리는 나무 길이의 합
    for (int i = 0; i < tree.size(); i++) { //n번 반복
        if (height >= tree[i]) { //height가 tree[i] 이상일때 -> 나무 잘리지 않는다
            return sum; //sum 반환
        }
        //height가 tree[i] 미만일때 -> 나무 tree[i] - height만큼 잘린다
        sum += (tree[i] - height); //sum에 tree[i] - height 값 더함
    }
    return sum; //sum 반환
}

int upperSearch(int left, int right, int target, vector<int> &tree) {
    while (left <= right) { //left가 right 이하일때 반복
        int mid = (left + right) / 2; //mid를 (left+right)/2로 초기화
        ll tree_cnt = cntTree(mid, tree);

        if (tree_cnt >= target) { //잘리는 나무 길이의 합이 target 이상일때 -> 절단기 높이 더 높일 수 있다
            left = mid + 1; //left 값을 mid+1로
        } else { //잘리는 나무 길이의 합이 target 미만일때 -> 절단기 높이 낮춰야 함
            right = mid - 1; //right 값을 mid-1로
        }
    }
    return left - 1; //left-1값 반환 (tree_cnt == target일때 left=mid+1을 했으므로)
}

/**
 * [나무 자르기]
 *
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값은?
 * -> 절단기의 높이가 k(임의의 값)일 때, M미터의 나무를 집에 가져갈 수 있는가?
 *
 * left: 절단기의 최소 높이 -> 0
 * right: 절단기의 최대 높이 -> 주어진 나무 중 가장 높은 나무 높이
 *
 * !주의! int 자료형 범위를 넘어가므로 long long써야 함
 */

int main() {
    int n, m; //n:나무의 수, m: 집으로 가져가려고 하는 나무의 길이

    //입력
    cin >> n >> m;
    vector<int> tree(n, 0);ㅡ//나무의 길이 저장할 벡터 tree
    for (int i = 0; i < n; i++) { //n번 반복
        cin >> tree[i]; //나무의 길이 입력받음
    }

    sort(tree.begin(), tree.end(), greater<>());
    //나무의 길이 내림차순으로 정렬

    //연산 & 출력
    cout << upperSearch(0, tree[0], m, tree);
    return 0; //프로그램 종료
}