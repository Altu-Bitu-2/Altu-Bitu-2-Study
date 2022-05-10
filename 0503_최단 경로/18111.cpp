//
// Created by kjy82 on 2022-05-10.
//

#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9; //INF 값을 1e9로 지정

//땅을 고르는 데 걸리는 시간을 구하는 함수
int mineLand(int n, int m, int b, int height, vector<vector<int>> &land) {
    int tot_time = 0; //땅을 고르는 데 걸리는 시간
    for (int i = 0; i < n; i++) { //n번 반복
        for (int j = 0; j < m; j++) { //m번 반복
            if (land[i][j] > height) { //블록 제거
                b += (land[i][j] - height); //b에 제거한 만큼의 블록 수 더함
                tot_time += 2 * (land[i][j] - height); //tot_time에 2초 * (잘라야 하는 블록의 수) 더함
            } else if (land[i][j] < height) { //블록 쌓기
                b -= (height - land[i][j]); //b에 쌓은 만큼의 블록 수 뺌
                tot_time += (height - land[i][j]); //tot_time에 1초 * (쌓는 블록의 수) 더함
            }
        }
    }
    if (b < 0) //최종적으로 블럭이 음수면 불가능한 높이
        return INF + 1; //INF(초기화된 min_time) + 1 값 반환
    return tot_time; //tot_time 반환
}

/**
 * [마인크래프트]
 *
 * 1. 가장 낮은 땅의 높이를 h라고 할 때, h-1의 높이를 만드는건 h보다 2*(N*M)의 시간이 더 소요됨
 * 2. 가장 높은 땅의 높이를 h라고 할 때, h+1의 높이를 만드는건 h보다 (N*M)의 시간이 더 소요됨
 * -> 따라서 땅의 높이가 될 수 있는 후보는 (가장 낮은 땅) ~ (가장 높은 땅)
 * -> 가능한 모든 높이에 대해 브루트포스 연산해도 시간 초과 X
 *
 * !주의! 당장 쌓을 블록이 없더라도 언젠가 다른 곳의 블록을 제거해서 쌓을 수 있음.
 */

int main() {
    int n, m, b, min_height = 256, max_height = 0;
    //n: 집터의 세로 크기, m: 집터의 가로 크기, b: 인벤토리에 있는 블록의 수, min_height: 땅의 최대 높이, max_height: 땅의 최소 높이

    //입력
    cin >> n >> m >> b;
    vector<vector<int>> land(n, vector<int>(m, 0)); //n*m 크기의 이중벡터 land 선언 및 값 0으로 초기화
    for (int i = 0; i < n; i++) { //n번 반복
        for (int j = 0; j < m; j++) { //m번 반복
            cin >> land[i][j]; //땅의 높이 입력 받아 land에 저장
            min_height = min(min_height, land[i][j]); //제일 낮은 땅 높이
            max_height = max(max_height, land[i][j]); //제일 높은 땅 높이
        }
    }

    //연산
    int min_time = INF, height = 0; //min_time: 땅을 고르는 데 걸리는 시간, height: 땅의 높이
    for (int i = min_height; i <= max_height; i++) { //max_height - min_height + 1번 반복
        int t = mineLand(n, m, b, i, land); //땅을 고르는 데 걸리는 시간 구하기
        if (t <= min_time) { //가장 빨리 작업이 끝나는 높이
            min_time = t; //t 값 min_time에 저장
            height = i; //i 값 height에 저장
        }
    }

    //출력
    cout << min_time << ' ' << height; //땅을 고르는 데 걸리는 시간과 땅의 높이 출력
    return 0; //프로그램 종료
}