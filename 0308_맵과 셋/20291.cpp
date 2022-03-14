//
// Created by kjy82 on 2022-03-14.
//

#include <iostream>
#include <vector>
#include <map>


using namespace std;


int main() {
    int N;
    string input;
    vector<string> files;
    map<string, int> m;

    //입력
    cin >> N; //파일의 개수
    files.assign(N, "");
    for (int i = 0; i < N; i++) { //파일의 이름
        cin >> input;
        size_t pos = input.rfind('.');
        files[i] = input.substr(pos + 1);
    }

    for (auto iter : files) {
        m[iter]++;
    }

    //출력
    for (auto iter : m) {
        cout << iter.first << ' ' << iter.second << '\n';
    }

    return 0;
}