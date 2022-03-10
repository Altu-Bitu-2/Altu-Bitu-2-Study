//
// Created by kjy82 on 2022-03-10.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


vector<int> card;


void swapCard(int start, int end) {
    for (int i = start - 1, n = 0; i < end - 1; i++, n++) {
        for (int j = start - 1; j < end - n - 1; j++) {
            swap(card[j], card[j + 1]);
        }
    }
}


int main() {
    int start, end;
    card.assign(20, 0);
    for (int i = 0; i < 20; i++) {
        card[i] = i + 1;
    }

    //입력
    for (int i = 0; i < 10; i++) {
        cin >> start >> end;
        swapCard(start, end);
    }

    //출력
    for (int i = 0; i < 20; i++) {
        cout << card[i] << ' ';
    }

    return 0;
}