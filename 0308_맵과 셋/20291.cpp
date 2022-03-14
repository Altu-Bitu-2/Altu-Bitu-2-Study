//
// Created by kjy82 on 2022-03-14.
//

#include <iostream>
#include <vector>
#include <map>


using namespace std;


void count_extension(vector<string> ext) { //확장자와 그 개수를 map에 저장 + 출력하는 함수
    map<string, int> m;
    for (auto iter : ext) {
        m[iter]++;
    }

    //출력
    for (auto iter:m) {
        cout << iter.first << ' ' << iter.second << '\n';
    }
}


int main() {
    int N;
    string input;
    vector<string> files;

    //입력
    cin >> N; //파일의 개수
    files.assign(N, "");
    for (int i = 0; i < N; i++) { //파일의 이름
        cin >> input;
        size_t pos = input.rfind('.');
        files[i] = input.substr(pos + 1);
    }

    count_extension(files);

    return 0;
}