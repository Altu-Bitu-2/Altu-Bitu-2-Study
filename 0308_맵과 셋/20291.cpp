//
// Created by kjy82 on 2022-03-14.
//

#include <iostream>
#include <vector>
#include <map>


using namespace std;


void count_extension(vector<string> ext) { //확장자와 그 개수를 map에 저장 + 출력하는 함수
    map<string, int> m;
    while (!ext.empty()) {
        int count = 0;
        string extension = ext[0];
        for (int i = 0; i < ext.size(); i++) {
            if (ext[i] == extension) {
                count++;
                ext.erase(ext.begin() + i);
                i--;
            }
        }
        m[extension] = count;
    }

    //출력
    for (auto iter:m) {
        cout << iter.first << ' ' << iter.second << '\n';
    }
}


void search_extension(vector<string> v) { //파일명에서 확장자만 저장하는 함수
    vector<string> extension;
    extension.assign(v.size(), "");
    for (int i = 0; i < v.size(); i++) {
        size_t pos = v[i].rfind('.');
        extension[i] = v[i].substr(pos + 1);
    }
    count_extension(extension);
}


int main() {
    int N;
    vector<string> files;

    //입력
    cin >> N; //파일의 개수
    files.assign(N, "");
    for (int i = 0; i < N; i++) { //파일의 이름
        cin >> files[i];
    }

    search_extension(files);

    return 0;
}