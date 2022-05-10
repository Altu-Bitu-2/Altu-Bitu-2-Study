//
// Created by kjy82 on 2022-05-10.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

//플로이드-워셜
void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &table) {
    for (int k = 1; k <= n; k++) { //n번 반복
        for (int i = 1; i <= n; i++) { //n번 반복
            for (int j = 1; j <= n; j++) { //n번 반복
                int new_dist = graph[i][k] + graph[k][j]; //new_dist: i->k->j로 갈때의 가중치
                if (new_dist < graph[i][j]) { //i->k->j가 i->j보다 가중치 작을 때
                    graph[i][j] = new_dist; //i->k->j의 가중치 graph[i][j]에 저장
                    table[i][j] = table[i][k]; //i->j로의 최단경로에선 먼저 k거쳐야 한다는 의미로 table[i][k] 값 table[i][j]에 저장
                }
            }
        }
    }
}

/**
 * [택시]
 *
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 14을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */

int main() {
    int n, m, s, d, c;
    //n: 집하장의 개수, m: 집하장간 경로의 개수, s,d,c: 집하장간 경로

    //입력
    cin >> n >> m; //n, m 입력 받음
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF)); //집하장간 가중치 저장할 이중벡터 graph
    vector<vector<int>> table(n + 1, vector<int>(n + 1, 0)); //경로표 작성을 위한 이중벡터 table
    for (int i = 1; i <= n; i++) { //n번 반복
        graph[i][i] = 0; //graph의 값 0으로 초기화
    }

    while (m--) { //무방향 그래프
        cin >> s >> d >> c; //s, d, c 입력 받은
        //간선 정보
        graph[s][d] = graph[d][s] = c; //s와 d 사이의 가중치 c 저장

        //경로 정보
        table[s][d] = d; //s->d의 최단경로를 경유하지 않는 경로(s->d)로 초기화
        table[d][s] = s; //d->s의 최단경로를 경유하지 않는 경로(d->s)로 초기화
    }

    //연산
    floydWarshall(n, graph, table);

    //출력
    for (int i = 1; i <= n; i++) { //n번 반복
        for (int j = 1; j <= n; j++) { //n번 반복
            if (i == j) { //행,열 값 같은 좌표
                cout << "- "; // "-" 넣는다
            } else { //행,열 값 다른 좌표
                cout << table[i][j] << ' '; //table[i][j]값 출력
            }
        }
        cout << '\n'; //엔터 출력
    }
    return 0; //프로그램 종료
}