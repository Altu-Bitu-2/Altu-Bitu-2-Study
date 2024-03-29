//
// Created by kjy82 on 2022-05-31.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map <ll, ll> parent;

//Find 연산
ll findParent(ll node) {
    if (parent.find(node) == parent.end()) { //아직 배정받지 않은 방인 경우 -> 배정 가능
        parent[node] = node + 1; //다음 방을 집합의 루트 정점으로
        return node; //node 반환
    }
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

vector<ll> assignRoom(vector<ll> &room_number) {
    vector<ll> answer(room_number.size(), 0); //고객 수를 크기로 가지고 0으로 초기화된 벡터 answer 선언
    for (int i = 0; i < room_number.size(); i++) { //room_number의 크기만큼 반복
        answer[i] = findParent(room_number[i]); //부모 찾기
    }
    return answer; //answer 리턴
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer = assignRoom(room_number); //answer에 정답 배열 저장
    return answer; //answer 리턴
}

/**
 * [호텔 방 배정]
 *
 * - 방을 배정할 때마다 이번에 배정한 방의 다음 방을 집합의 루트 정점으로 만들어 바로 접근할 수 있도록 설정
 * - parent를 벡터(혹은 배열)로 사용하면 전체 방 개수(k)의 최대가 10^12이기 때문에 메모리 초과
 * -> 따라서 필요한 방의 parent정보만 저장하기 위해 map을 사용해야 함.
 * -> 이때 키 값이 정렬될 필욘 없으므로 unordered_map 사용. map은 시간초과남!
 *
 * (참고) 백준의 10775와 매우 유사한 문제
 */

//디버깅을 위한 메인 코드 - 프로그래머스에는 제출 X
int main() {
    ll k = 10; //k:방의 개수
    vector<ll> room_number = {1, 3, 4, 1, 3, 1}; //room_number:고객들이 원하는 방 번호
    vector<ll> result = solution(k, room_number); //result:실제 배정받은 방
    for (int i = 0; i < result.size(); i++) { //result의 크기만큼 반복
        cout << result[i] << ' '; //출력
    }
    return 0; //프로그램 종료
}