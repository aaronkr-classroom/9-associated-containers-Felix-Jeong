// chp7-8.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "split2.h"

using namespace std;

// URL을 찾아 해당 URL이 등장하는 모든 행을 반환하는 함수
map<string, vector<int>> find_urls(istream& in) {
    string line;
    int line_number = 0;
    map<string, vector<int>> url_lines;

    while (getline(in, line)) {
        ++line_number;

        // 입력한 행을 단어로 나눔.
        vector<string> words = split(line);

        // 현재 행에 있는 단어들을 확인하여 URL인지 확인
        for (const string& word : words) {
            // 간단한 URL 패턴으로 확인 (http:// 또는 https://로 시작)
            if (word.substr(0, 7) == "http://" || word.substr(0, 8) == "https://")
                url_lines[word].push_back(line_number);
        }
    }

    return url_lines;
}

int main() {
    cout << "Enter the file name: ";
    string filename;
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    // URL을 찾고 해당 URL이 등장하는 모든 행을 저장
    map<string, vector<int>> url_lines = find_urls(file);

    // 결과를 출력
    for (const auto& pair : url_lines) {
        cout << "URL: " << pair.first << endl;
        cout << "Lines: ";
        for (int line : pair.second)
            cout << line << " ";
        cout << endl;
    }

    return 0;
}
