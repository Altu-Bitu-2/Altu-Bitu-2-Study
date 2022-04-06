//
// Created by kjy82 on 2022-04-06.
//

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, a, value;	//n: 방문 횟수, a: 충전하는 선물의 개수, value: 선물의 가치

    //입력
    cin >> n;
    priority_queue<int> gift;

    while (n--) {
        cin >> a;
        // 거점지에 들렀을 때
        if (a != 0) {
            while (a--) {
                cin >> value;
                gift.push(value);
            }
        }

            //아이들을 만났을 때
        else {
            if (gift.empty()) {
                cout << -1 << '\n';
            }
            else {
                cout << gift.top() << '\n';
                gift.pop();
            }
        }
    }

    return 0;
}