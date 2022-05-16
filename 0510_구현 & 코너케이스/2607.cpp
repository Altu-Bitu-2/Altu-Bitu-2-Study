//
// Created by kjy82 on 2022-05-16.
//

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

//비슷한 단어의 개수 찾는 함수
int checkWord(vector<string>& words) {
    int first_word[26] = { 0 };
    int cnt = 0, temp = 0, first_length = words[0].size(), cmp_length = 0;
    //cnt: 비슷한 단어의 개수, temp: 연산에 사용될 변수, first_length: 첫 번재 단어의 길이, cmp_length: 비교할 단어의 길이

    for (int i = 0; i < words[0].size(); i++) { //첫번째 단어의 문자 종류+개수 저장
        first_word[words[0][i] - 'A']++;
    }

    for (int i = 1; i < words.size(); i++) {
        temp = 0, cmp_length = words[i].size();
        if (abs(cmp_length - first_length) > 1) { //글자 수 차이가 2이상이면 무조건 비슷한 단어가 아니다
            continue;
        }
        int cmp_word[26] = { 0 };
        for (int j = 0; j < words[i].size(); j++) { //비교하고자 하는 단어의 문자 종류+개수 저장
            cmp_word[words[i][j] - 'A']++;
        }

        for (int k = 0; k < 26; k++) {
            temp += abs(cmp_word[k] - first_word[k]);
        }

        /* 비슷한 단어인 경우
         * 글자 수 같고 같은 구성 -> temp = 0
         * 글자 수 같고 한 글자 수정 -> temp = 2
         * 한 글자 제거 -> temp = 1
         * 한 글자 추가 -> temp = 1
         * */
        if (temp <= 2) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    int n;
    string input;

    //입력
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> input;
        words[i] = input;
    }

    //연산 + 출력
    cout << checkWord(words);

    return 0;
}