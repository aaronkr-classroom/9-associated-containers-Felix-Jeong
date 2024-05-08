// chp7-7.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "split2.h"

using namespace std;

// 입력에서 각 단어가 등장한 모든 행을 찾음.
map<string, vector<int>> xref(istream& in, vector<string> find_words(const string&) = split) {
    string line;
    int line_number = 0;
    map<string, vector<int>> ret;

    // 다음 행을 읽음.
    while (getline(in, line)) {
        ++line_number;

        // 입력한 행을 단어로 나눔.
        vector<string> words = find_words(line);

        // 현재 행에 등장한 모든 단어를 저장
        if (words.size() == 1) {
            // 행이 하나인 경우
            ret[words[0]].push_back(line_number);
        }
        else {
            // 행이 여러 개인 경우
            for (const string& word : words)
                ret[word].push_back(line_number);
        }
    }
    return ret;
}

int main() {
    cout << "Enter words (CTRL+Z to stop): " << endl;

    // 기본 인수인 split 함수를 사용하여 xref 함수를 호출
    map<string, vector<int>> ret = xref(cin);

    // 결과를 출력
    for (const auto& pair : ret) {
        // 단어를 출력
        cout << "\"" << pair.first << "\" occurs on line(s): ";

        // 이어서 하나 이상의 행 번호를 출력
        vector<int>::const_iterator line_it = pair.second.begin();

        // 해당 단어가 등장한 첫 번째 행 번호를 출력
        cout << *line_it;
        ++line_it;

        // 행 번호가 더 있으면 마저 출력
        while (line_it != pair.second.end()) {
            cout << "," << *line_it;
            ++line_it;
        }

        // 각 단어를 다음 단어와 구분하려고 새로운 행을 출력
        cout << endl;
    }
    return 0;
}
