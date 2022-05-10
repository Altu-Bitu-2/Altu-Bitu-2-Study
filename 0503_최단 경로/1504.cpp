//
// Created by kjy82 on 2022-05-10.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci; //정수, 정수
const int INF = 1e5 * 8 * 3; //최대 N-1개의 간선을 지나게 됨 * 중복 순회 가능(3)

//다익스트라
vector<int> dijkstra(int start, int v, vector<vector<ci>> &graph) {
    vector<int> dist(v + 1, INF); //v+1 크기의 dist 벡터의 원소들을 INF로 초기화
    priority_queue<ci, vector<ci>, greater<>> pq; //내림차순으로 정렬되는 우선순위 큐 pq 선언

    dist[start] = 0; //시작 정점 초기화
    pq.push({0, start});
    while (!pq.empty()) { //pq가 빈 큐가 아닐 동안 반복
        int weight = pq.top().first; //현재 정점까지의 거리
        int node = pq.top().second; //현재 탐색하려는 정점
        pq.pop(); //pq의 top 원소 pop

        if (weight > dist[node]) { //이미 최단 경로로 값이 기록된 정점
            continue; //연산을 건너뛴다
        }
        for (int i = 0; i < graph[node].size(); i++) { //현재 node와 연결된 정점들 개수만큼 반복
            int next_node = graph[node][i].first; //현재 node와 연결된 정점
            int next_weight = weight + graph[node][i].second; //시작 정점에서 현재 node를 거쳐 다음 정점까지 갈 때의 거리
            if (next_weight < dist[next_node]) { //경유해서 갈 때가 최단 거리이면
                dist[next_node] = next_weight; //dist[next_node]에 next_weight 저장
                pq.push({next_weight, next_node}); //pq에 최단 거리와 연결된 정점 push
            }
        }
    }
    return dist; //dist 벡터 반환
}

/**
 * [특정한 최단 경로]
 *
 * 가능한 경로
 * 1. 1 -> v1 -> v2 -> n
 * 2. 1 -> v2 -> v1 -> n
 * -> 1, v1, v2를 시작점으로 하는 다익스트라 함수 실행하기
 *
 * !주의! 한 번 이동했던 정점, 간선을 다시 방문할 수 있음. 즉 1->N의 최댓값이 INF(1e5*8)이 아니라 3*INF!
 */

int main() {
    int n, e, a, b, c, v1, v2;
    //n: 정점 개수, e: 간선 개수, a, b: 정점, c: a, b 사이 거리, v1: 꼭 지나야 되는 정점 1, v2: 꼭 지나야 되는 정점 2

    //입력
    cin >> n >> e;

    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //정점들의 거리 정보를 담을 이중 벡터 graph 선언
    vector<vector<int>> dist(3, vector<int>(n + 1, 0)); //크기 3(1, v1, v2)의 dist 벡터 선언
    while (e--) { //무방향 그래프
        cin >> a >> b >> c; //정점들과 거리 정보 입력받는다
        graph[a].emplace_back(b, c); //a에서 b로 향하는 방향 정보 저장
        graph[b].emplace_back(a, c); //b에서 a로 향하는 방향 정보 저장
    }
    cin >> v1 >> v2; //꼭 지나야 되는 정점 두 개 입력받는다

    //연산
    vector<int> start_nodes = {1, v1, v2}; //시작 정점들을 담는 벡터 start_nodes 선언 및 초기화
    for (int i = 0; i < 3; i++) { //1, v1, v2에서 시작한 다익스트라 결과 저장
        dist[i] = dijkstra(start_nodes[i], n, graph); //다익스트라 결과 dist 벡터에 저장
    }

    //1->v1->v2->n의 경로와 1->v2->v1->n의 경로 중 최솟값
    //무방향 그래프기 때문에 v1->v2와 v2->v1은 사실 같은 값!
    int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

    //출력
    cout << ((ans >= INF) ? -1 : ans); //ans가 INF 이상이면(v1, v2 모두 지나는 최단 경로 없으면) -1, 아니면 ans 값을 출력
    return 0; //프로그램 종료
}