//
// Created by kjy82 on 2022-05-22.
//

#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* makeTree(node* v, int data) {
    if (v == NULL) {
        v = new node(); //동적 할당
        v->data = data;
        v->left = v->right = NULL;
    }
    else if (v->data > data) { //삽입할 노드가 루트 노드보다 값이 작을 때
        v->left = makeTree(v->left, data);
    }
    else if (v->data < data) { //삽입할 노드가 루트 노드보다 값이 클 때
        v->right = makeTree(v->right, data);
    }
    return v;
}

//후위 순회
void postorder(node* v) {
    if (v == NULL) { //자식 없으면
        return;
    }
    postorder(v->left); //왼쪽 자식 출력
    postorder(v->right); //오른쪽 자식 출력
    cout << v->data << '\n'; //자기 자신 출력
}

int main() {
    int input;
    node* root = NULL;
    vector<int> arr;

    //입력
    while (cin >> input) {
        root = makeTree(root, input);
    }

    //출력
    postorder(root);

    return 0;
}