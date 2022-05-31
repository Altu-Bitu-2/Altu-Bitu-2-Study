//
// Created by kjy82 on 2022-05-31.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { //값 음수 -> 루트 정점
        return node; //node 리턴
    }
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //xp: x의 부모
    int yp = findParent(y); //yp: y의 부모

    if (xp == yp) { //x, y이미 같은 집합에 있다면
        return; //리턴
    }
    if (parent[xp] < parent[yp]) { //새로운 루트가 xp인 경우
        parent[xp] += parent[yp]; //parent[yp] 값을 parent[xp]에 더함 -> yp의 자식들 xp에 붙여줌
        parent[yp] = xp; //xp를 yp의 루트로 설정
    } else { //새로운 루트가 yp인 경우
        parent[yp] += parent[xp]; //parent[xp] 값을 parent[yp]에 더함 -> xp의 자식들 yp에 붙여줌
        parent[xp] = yp; //yp를 xp의 루트로 설정
    }
}

int liarParty(vector<int> &parties) {
    int cnt = 0; //cnt: 정답
    for (int i = 0; i < parties.size(); i++) { //파티에 온 사람 수만큼 반복
        if (findParent(parties[i]) != findParent(0)) { //파티원들 0과 같은 집합 아니면 -> 거짓말 가능
            cnt++; //cnt 값 증가
        }
    }
    return cnt; //cnt 반환
}

/**
 * [거짓말]
 *
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 * -> 이때, 진실을 아는 사람들의 루트 정점을 0으로 설정해서 유니온 파인드를 통해 집합으로 묶고 시작
 * -> 0과 같은 집합이 아니어야 거짓말을 할 수 있음
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */

int main() {
    int n, m; //n: 사람의 수, m: 파티의 수

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1); //벡터 parent 초기화

    int init, p; //init: 진실을 아는 사람의 수, p: 진실 아는 사람의 번호
    cin >> init; //init 입력받기
    while (init--) { //진실을 아는 사람들
        cin >> p; //p 입력받기
        unionInput(0, p); //union 연산 수행
    }

    int cnt, first_person, person; //cnt: 파티 오는 사람의 수, first_person: 파티의 첫번째 사람, person: 그 외 파티에 오는 사람
    vector<int> parties; //벡터 parties 선언
    while (m--) { //파티의 수만큼 반복
        cin >> cnt >> first_person; //cnt, first_person 입력받기

        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        while (--cnt) { //cnt-1만큼 반복 (first_person은 뺐으니까)
            cin >> person; //person 입력받기
            unionInput(first_person, person); //union 연산 수행
        }
    }

    //연산 & 출력
    cout << liarParty(parties);
    return 0; //프로그램 종료
}