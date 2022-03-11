#include <iostream>
#include <vector>


using namespace std;


vector<int> card;


void swapCard(int start, int end) {
    for(int i = start - 1, n = 0; i < (start + end) / 2; i++, n++) {
        if (start + n - 1 == end - n - 1) break;
        swap(card[start + n - 1], card[end - n - 1]);
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