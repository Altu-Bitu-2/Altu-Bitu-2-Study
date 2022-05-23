//
// Created by kjy82 on 2022-05-22.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
map<int, pair<int, int>> tree;

//후위 순회
void postorder(int v) {
    if (v == NULL) { //자식 없으면
        return;
    }
    postorder(tree[v].first); //왼쪽 자식 출력
    postorder(tree[v].second); //오른쪽 자식 출력
    cout << v << '\n'; //자기 자신 출력
}

int main() {
    int node, root = 0;
    vector<int> arr;

    //입력
    while (cin >> node) {
        arr.push_back(node);
    }

    for (int j = 1; j < arr.size(); j++) {
        root = arr[0];
        while (true) {
            if (arr[j] < root) { //삽입할 노드가 루트 노드보다 값이 작을 때
                if (tree[root].first == NULL) { //루트 노드에 왼쪽 자식이 비어있을 때
                    tree[root].first = arr[j];
                    break;
                }
                root = tree[root].first; //다음 루트 -> 왼쪽 자식
            }
            else { //삽입할 노드가 루트 노드보다 값이 클 때
                if (tree[root].second == NULL) { //루트 노드에 오른쪽 자식이 비어있을 때
                    tree[root].second = arr[j];
                    break;
                }
                root = tree[root].second; //다음 루트 -> 오른쪽 자식
            }
        }
    }

    //출력
    postorder(arr[0]);

    return 0;
}