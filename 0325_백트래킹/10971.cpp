//
// Created by kjy82 on 2022-04-01.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e8;

vector<bool> visited; //방문 검사 배열
vector<vector<int>> matrix; //비용 행렬
int n, ans = INF; //최소 비용 저장 위해 미리 최댓값으로 초기화

/**
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 */
void backtracking(int cnt, int cur_city, int cost) { //cnt: 수 인덱스, cur_city: 현재 도시(출발지), cost: 비용
    if (cost >= ans) { //생각해보기 : 이 조건문이 없으면 어떻게 될까요?
        //cost가 ans보다 크면 어차피 최소 비용 아님 (같다면 굳이 더 계산할 필요없이 ans 쓰면 됨)
        return; //함수 리턴
    }
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시(0)로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][0] != 0) { //출발도시로 다시 돌아올 수 있다면
            ans = min(ans, cost + matrix[cur_city][0]); //ans와 계산된 비용 중 작은 값 ans에 저장
        }
        return; //기저조건 만족했으므로 함수 리턴
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시
            visited[i] = true;  //방문했으니 visited벡터 true로
            backtracking(cnt + 1, i, cost + matrix[cur_city][i]); //backtracking 함수 재호출
            //다시 돌아왔을때
            visited[i] = false; //visited 다시 false로
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * 한 사이클을 만들면, 어느 도시에서 시작하든 값은 같으므로 0번 도시부터 시작하는 경우만 검사하면 된다.
 */

int main() {
    //입력
    cin >> n;   //도시의 수 입력받음
    visited.assign(n, false);   //visited 벡터를 크기 n, 값 false로 초기와
    matrix.assign(n, vector<int>(n, 0));    //matrix 벡터를 행 n, 열 n, 값 0으로 초기화
    for (int i = 0; i < n; i++) {       //n번 도는 반복문
        for (int j = 0; j < n; j++) {   //n번 도는 반복문
            cin >> matrix[i][j];        //비용 정보 입력받음
        }
    }

    //연산
    visited[0] = true;  //0번 도시 방문한 것으로 (true로)
    backtracking(1, 0, 0);  //backtracking 함수 호출

    //출력
    cout << ans;    //정답 출력
    return 0;       //프로그램 종료
}