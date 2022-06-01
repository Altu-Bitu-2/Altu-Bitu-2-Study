//
// Created by kjy82 on 2022-05-31.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> parent; //자료형 int인 벡터 parent 선언

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { //음수 -> 루트 정점
        return node; //node 리턴
    }
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); //xp: x의 부모
    int yp = findParent(y); //yp: y의 부모

    if (xp == yp) { //x, y이미 같은 집합에 있다면
        return false; //false 리턴
    }
    if (parent[xp] < parent[yp]) { //새로운 루트가 xp인 경우
        parent[xp] += parent[yp]; //parent[yp] 값을 parent[xp]에 더함 -> yp의 자식들 xp에 붙여줌
        parent[yp] = xp; //xp를 yp의 루트로 설정
    } else { //새로운 루트가 yp인 경우
        parent[yp] += parent[xp]; //parent[xp] 값을 parent[yp]에 더함 -> xp의 자식들 yp에 붙여줌
        parent[xp] = yp; //yp를 xp의 루트로 설정
    }
    return true; //true 리턴
}

/**
 * [사이클 게임]
 *
 * 사이클이 발생한 순간 = 같은 집합에 있는 원소 두 개를 유니온하려 할 때
 * unionInput 함수의 반환형을 bool로 선언하여 cycle이 생성되는 순간 발견하기
 */

int main() {
    int n, m, x, y;
    //n:점의 개수, m:진행된 차례의 수, x,y: 플레이어가 선택한 두 점의 번호

    //입력
    cin >> n >> m; //n,m 입력받기
    parent.assign(n, -1);
    for (int i = 0; i < m; i++) { //m번 반복
        cin >> x >> y; //x,y 입력받기

        //연산 & 출력
        if (!unionInput(x, y)) { //사이클이 생성됨
            cout << i + 1; //사이클 만들어진 차례의 번호 출력
            return 0; //프로그램 종료
        }
    }
    cout << 0; //0 출력
    return 0; //프로그램 종료
}