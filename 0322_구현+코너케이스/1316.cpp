//
// Created by kjy82 on 2022-03-27.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

//그룹 단어인지 확인하는 함수
int checkGroupWord(map<char, bool> m, string word) {
    for (int i = 0; i < word.length(); i++) {
        if (m[word[i]] == true && word[i] != word[i - 1]) {
            //이미 등장한 알파벳인데 바로 전 알파벳과 현재 알파벳이 다르면 그룹 단어 아님
            return 0;
        }
        m[word[i]] = true; //등장한 알파벳은 bool값 true로 바꿈
    }
    return 1;
}

int main() {
    int N, count = 0;			//N:단어의 개수, count: 그룹 단어의 개수
    vector<string> words;		//입력되는 단어들
    map<char, bool> m;			//알파벳과 그 알파벳이 등장했는지 여부를 저장할 map

    //알파벳들 m에 담아줌
    for (char j = 'a'; j <= 'z'; j++) {
        m[j] = false;
    }

    //입력
    cin >> N;
    words.assign(N, " ");
    for (int i = 0; i < N; i++) {
        cin >> words[i];
        count += checkGroupWord(m, words[i]);
    }

    //출력
    cout << count << '\n';

    return 0;
}