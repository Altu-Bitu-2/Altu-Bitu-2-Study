//
// Created by kjy82 on 2022-04-08.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;  //int쌍 ci 선언

vector<bool> is_valid;

//최대 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMax(priority_queue<ci> &heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) { //heap 비어있지 않고 heap의 top 데이터가 is_valid 하지 않을때
        heap.pop(); //heap의 top 원소 삭제
    }
}

//최소 힙에서 top 데이터가 is_valid 할 때까지 pop
void deleteMin(priority_queue<ci, vector<ci>, greater<>> &heap) {
    while (!heap.empty() && !is_valid[heap.top().second]) { //heap 비어있지 않고 heap의 top 데이터가 is_valid 하지 않을때
        heap.pop(); //heap의 top 원소 삭제
    }
}

/**
 * 우선순위 큐 풀이
 * 최대 힙과 최소 힙을 동시에 관리하면서 각각의 힙에서 삭제된 데이터를 다른 힙에 반영하는 방법
 * -> 각 데이터의 유효성을 체크하는 배열을 만들기
 */
int main() {
    int t, k, n;    //t: 테스트 케이스의 수, k: 연산의 수, n: 삽입할 정수
    char cmd;       //연산의 종류를 나타낼 명령어

    cin >> t;       //t 입력받음
    while (t--) {   //t번 반복
        priority_queue<ci> max_heap; //최대 힙
        priority_queue<ci, vector<ci>, greater<>> min_heap; //최소 힙
        cin >> k;   //k 입력받음
        int idx = 0; //I 연산으로 입력된 숫자의 인덱스
        while (k--) {   //k번 반복
            //입력
            cin >> cmd >> n;

            //연산
            switch (cmd) {  //명령어에 따라 케이스 나눔
                case 'I': //두가지 힙 모두에 값을 넣은 뒤, is_valid 벡터에도 추가
                    max_heap.push(ci(n, idx));  //max_heap에 n값과 idx 넣는다
                    min_heap.push(ci(n, idx));  //min_heap에 n값과 idx 넣는다
                    is_valid.push_back(true);   //is_valid에 true 넣는다
                    idx++;  //idx 증가
                    break;  //케이스 빠져나오기
                case 'D': //n에 따라 최대 힙 또는 최소 힙에서 데이터 삭제
                    if (n == 1) {   //n이 1일때
                        deleteMax(max_heap); //D연산 전처리
                        if (!max_heap.empty()) { //D연산
                            is_valid[max_heap.top().second] = false; //max_heap의 top 데이터의 is_valid를 false로
                            max_heap.pop(); //max_heap의 top 데이터 삭제
                        }
                    }
                    if (n == -1) {  //n이 -1일때
                        deleteMin(min_heap); //D연산 전처리
                        if (!min_heap.empty()) { //D연산
                            is_valid[min_heap.top().second] = false; //min_heap의 top 데이터의 is_valid를 false로
                            min_heap.pop(); //min_heap의 top 데이터 삭제
                        }
                    }
                    break;  //케이스 빠져나오기
            }
        }
        //마지막으로 각 힙의 top이 valid 하도록 처리
        deleteMax(max_heap);    //max_heap의 top데이터가 valid 하도록
        deleteMin(min_heap);    //min_heap의 top데이터가 valid 하도록

        //출력
        if (max_heap.empty()) { //max_heap이 비어있으면
            cout << "EMPTY\n";  //비어있다는 메세지 출력
        }
        else {  //max_heap이 비어있지 않다면
            cout << max_heap.top().first << ' ' << min_heap.top().first << '\n'; //최댓값과 최솟값 출력
        }
        is_valid.clear(); //새로운 테스트 케이스 전 is_valid 벡터 초기화
    }
}