//
// Created by kjy82 on 2022-05-09.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 2e9;

//다익스트라
vector<int> dijkstra(int start, int n, vector<vector<ci>>& graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq; //first: 시작점으로부터의 거리(시간), second: 정점

    dist[start] = 0;
    pq.push({ 0, start });
    while (!pq.empty()) {
        int weight = pq.top().first; //현재 정점까지의 시간
        int node = pq.top().second; //현재 탐색하려는 정점
        pq.pop();

        if (weight > dist[node]) {
            continue;
        }

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int next_weight = weight + graph[node][i].second;
            if (next_weight < dist[next_node]) { //경유해서 가는게 더 빠른 경우
                dist[next_node] = next_weight;
                pq.push({ next_weight, next_node });
            }
        }
    }
    return dist;
}

int main() {
    int T, n, d, c, a, b, s;

    //입력
    cin >> T;
    while (T--) {
        int cnt = 0, time = 0;
        cin >> n >> d >> c;
        vector<vector<ci>> graph(n + 1, vector<ci>(0));
        while (d--) {
            cin >> a >> b >> s;
            graph[b].push_back({ a, s });
        }
        //연산
        vector<int> dist = dijkstra(c, n, graph);

        for (int i = 1; i <= n; i++) {
            if (dist[i] != INF) {
                cnt++;
                if (dist[i] > time)
                    time = dist[i];
            }
        }

        //출력
        cout << cnt << ' ' << time << '\n';
    }

    return 0;
}