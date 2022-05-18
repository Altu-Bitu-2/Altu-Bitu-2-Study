//
// Created by kjy82 on 2022-05-17.
//

#include <iostream>

using namespace std;

bool isCpp(string str) { //c++ 형식인가?
    for (int i = 0; i < str.size(); i++) { //문자열 크기만큼 반복
        if (isupper(str[i])) { //대문자가 있으면 안됨
            return false; //false 반환
        }
        if (str[i] == '_' && (i == 0 || i == str.size() - 1 || str[i - 1] == '_')) { //첫 or 마지막 글자가 '_' 또는 '_'가 연속 등장
            return false; //false 반환
        }
    }
    return true; //true 반환
}

bool isJava(string str) { //java 형식인가?
    return !isupper(str[0]) && str.find('_') == string::npos; //첫 글자가 대문자거나, '_'가 있으면 안됨
}

string toCpp(string str) { //java 형식을 c++로
    string result; //result: 변환 후의 변수명
    for (int i = 0; i < str.size(); i++) { //문자열 크기만큼 반복
        if (isupper(str[i])) { //대문자라면 앞에 '_' 삽입
            result += '_'; //'_' result에 더해준다
        }
        result += tolower(str[i]); //소문자로 바꿔서 넣기
    }
    return result; //result 반환
}

string toJava(string str) { //c++ 형식을 java로
    string result; //result: 변환 후의 변수명
    for (int i = 0; i < str.size(); i++) { //문자열 크기만큼 반복
        if (str[i] == '_') { //'_' 라면 그 다음 글자를 대문자로 바꿔서 삽입
            result += toupper(str[i + 1]); //대문자로 바꾼 문자로 result에 더해준다
            i++; //i 증가
            continue; //반복문 계속한다
        }
        result += str[i]; //나머지 글자는 그냥 삽입
    }
    return result; //result 반환
}

/**
 * [Java vs C++]
 *
 * 1. 입력으로 주어진 변수가 C++ 형식에도 맞고, JAVA 형식에도 맞을 수 있음 (ex. name)
 * 2. "Error!"인 경우 (C++)
 *    2-1. 언더바('_')로 시작하거나, 끝나는 변수
 *    2-2. 언더바('_')가 연속해서 등장하는 변수
 *    2-3. 대문자가 등장하는 변수
 * 3. "Error!"인 경우 (Java)
 *    3-1. 대문자로 시작하는 변수
 *    3-2. 언더바('_')가 등장하는 변수
 */

int main() {
    string str; //변수명 저장할 str 선언

    cin >> str; //변수명 입력 받는다
    bool is_cpp = isCpp(str);
    bool is_java = isJava(str);

    if (is_cpp && is_java) { //두 형식에 모두 부합하면 그냥 출력
        cout << str;
    } else if (is_cpp) { //c++ 형식이라면 java로 바꿔서 출력
        cout << toJava(str);
    } else if (is_java) { //java 형식이라면 c++로 바꿔서 출력
        cout << toCpp(str);
    } else { //둘 다 아니라면 에러
        cout << "Error!";
    }
    return 0; //프로그램 종료
}