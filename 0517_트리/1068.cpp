//
// Created by kjy82 on 2022-05-24.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree; //이중 벡터 tree 선언

//주어진 정점을 지웠을 때의 리프 노드의 수
int eraseLeafCnt(int node, int &erase_node) {
    if (node == erase_node) { //입력 받은 노드가 지워야 되는 노드면
        return 0; //0 반환
    }
    if (tree[node].empty() || (tree[node].size() == 1 && tree[node][0] == erase_node)) {
    //1.자식 없음 2.유일한 자식이 지워야 하는 노드
        return 1; //1 반환
    }
    int cnt = 0; //cnt:리프 노드의 수
    for (int i = 0; i < tree[node].size(); i++) { //자식 수만큼 반복
        cnt += eraseLeafCnt(tree[node][i], erase_node); //재귀적으로 리프 노드이면 cnt에 1 추가
    }
    return cnt; //cnt 반환
}

/**
 * [트리]
 *
 * 기존 리프 노드 개수를 세는 dfs 탐색에서 지우는 정점을 만나면 더 이상 탐색하지 않고 0을 리턴
 *
 * !주의! 지우는 정점이 해당 부모 노드의 유일한 자식 노드였을 경우, 해당 정점을 지우면 부모 노드가 리프 노드가 돼서 개수가 1 증가함을 주의
 * !주의! 루트 노드가 항상 0이 아님을 주의
 */

int main() {
    int n, par, root, erase_node;
    //n:노드의 개수, par:부모 노드, root:루트 노드, erase_node:지울 노드의 번호

    //입력
    cin >> n; //노드 개수 입력 받기
    tree.assign(n, vector<int>(0)); //tree 크기 초기화
    for (int i = 0; i < n; i++) { //n번 반복
        cin >> par; //부모 노드 입력받기
        if (par == -1) { //부모가 -1일 때 (부모 없을때) -> 이때의 노드가 루트임
            root = i; //루트 정보 저장
            continue; //반복문 계속
        }
        tree[par].push_back(i); //트리에 부모 노드를 인덱스 값으로 자식 정보 입력 받기
    }
    cin >> erase_node; //지울 노드 입력 받기

    //연산 & 출력
    cout << eraseLeafCnt(root, erase_node);
    return 0; //프로그램 종료
}