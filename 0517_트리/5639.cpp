//
// Created by kjy82 on 2022-05-22.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef pair<int, int> ci;
map<int, pair<int, ci>> tree; //pair<int, ci> -> 부모 + 왼쪽, 오른쪽 자식

//후위 순회
void postorder(int v) {
    if (v == NULL) { //자식 없으면
        return;
    }
    postorder(tree[v].second.first); //왼쪽 자식 출력
    postorder(tree[v].second.second); //오른쪽 자식 출력
    cout << v << '\n'; //자기 자신 출력
}

int main() {
    int node, root = 0, temp = 0;
    vector<int> arr;

    //입력
    while (cin >> node) {
        arr.push_back(node);
    }

    for (int j = 0; j < arr.size() - 1; j++) {
        if (arr[j] > arr[j + 1]) { //50 30 -> 30은 50의 왼쪽 자식
            tree[arr[j + 1]].first = arr[j]; //30의 부모: 50
            tree[arr[j]].second.first = arr[j + 1]; //50의 왼쪽 자식: 30
            temp = arr[j];
        }
        else {
            root = temp;
            while (tree[root].second.second) { //오른쪽 자식 붙일 부모 찾기 -> 이미 right child 있으면 안 됨
                root = tree[root].first;
            }
            if (arr[j + 1] > root) { //24 5 28 -> 28 > 24 -> 28은 24의 오른쪽 자식
                tree[arr[j + 1]].first = root; //28의 부모: 24
                tree[root].second.second = arr[j + 1]; //24의 오른쪽 자식: 28
                root--;
            }
            else { //98 52 60 -> 60 < 98 -> 60은 98의 자식 X, 52의 오른쪽 자식
                tree[arr[j + 1]].first = arr[j]; //60의 부모: 52
                tree[arr[j]].second.second = arr[j + 1]; //52의 오른쪽 자식: 60

            }
        }
    }

    //출력
    postorder(arr[0]);

    return 0;
}