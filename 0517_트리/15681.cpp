//
// Created by kjy82 on 2022-05-24.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> subtree_cnt; //벡터 subtree_cnt 선언 (서브트리의 정점 수 저장)

int treeDp(int cur, vector<vector<int>> &graph) {
    if (subtree_cnt[cur] != -1) { //이미 탐색했던 상태
        return subtree_cnt[cur]; //cur를 루트로 하는 서브트리에 속한 정점의 수 반환
    }

    //서브트리에 속한 정점의 수를 세고, 저장
    subtree_cnt[cur] = 0;
    int node = 1; //node:서브트리에 속한 정점의 수
    for (int i = 0; i < graph[cur].size(); i++) { //cur과 연결된 점점 수만큼 반복
        node += treeDp(graph[cur][i], graph); //재귀적으로 cur과 연결된 정점 탐색해 node에 1씩 추가
    }
    return subtree_cnt[cur] = node; //cur을 루트로 하는 서브트리에 속한 정점의 수 반환
}

/**
 * PPT 트리의 정점의 수 구하기 응용
 *
 * [트리와 쿼리]
 *
 * 1. 루트에서부터 dfs 탐색
 * 2. 각 노드를 루트로 하는 서브트리의 정점 수를 재귀적으로 메모리제이션하며 계산
 * - 서브트리에 속한 정점의 개수를 저장하는 dp 배열의 초기화를 -1로 해주고,
 *   dfs 탐색 시 현재 정점의 dp 값을 0으로 설정함으로써 자식 노드만 탐색할 수 있도록 함 (부모 노드에 0이 저장되어 있으므로 바로 리턴)
 *
 */

int main() {
    //입출력 시간 줄이기 위한 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q, u, v, input;
    //n:정점의 수, r:루트의 번호, q:쿼리의 수, u,v:간선 정보, input:입력받을 쿼리

    //입력
    cin >> n >> r >> q; //n, r, q 입력 받기
    vector<vector<int>> graph(n + 1, vector<int>(0)); //이중벡터 graph 초기화
    subtree_cnt.assign(n + 1, -1); //subtree_cnt 크기 지정 및 초기화

    while (--n) { //무방향 그래프
        cin >> u >> v; //u, v 입력 받기
        graph[u].push_back(v); //u->v
        graph[v].push_back(u); //v->u
    }

    //연산
    treeDp(r, graph);

    //출력
    while (q--) { //q번 반목
        cin >> input; //쿼리의 u 입력받기
        cout << subtree_cnt[input] << '\n'; //쿼리의 답 출력
    }
    return 0; //프로그램 종료
}