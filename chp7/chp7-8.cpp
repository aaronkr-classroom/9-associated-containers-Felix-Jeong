// chp7-8.cpp

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "split2.h"

using namespace std;

// URL�� ã�� �ش� URL�� �����ϴ� ��� ���� ��ȯ�ϴ� �Լ�
map<string, vector<int>> find_urls(istream& in) {
    string line;
    int line_number = 0;
    map<string, vector<int>> url_lines;

    while (getline(in, line)) {
        ++line_number;

        // �Է��� ���� �ܾ�� ����.
        vector<string> words = split(line);

        // ���� �࿡ �ִ� �ܾ���� Ȯ���Ͽ� URL���� Ȯ��
        for (const string& word : words) {
            // ������ URL �������� Ȯ�� (http:// �Ǵ� https://�� ����)
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

    // URL�� ã�� �ش� URL�� �����ϴ� ��� ���� ����
    map<string, vector<int>> url_lines = find_urls(file);

    // ����� ���
    for (const auto& pair : url_lines) {
        cout << "URL: " << pair.first << endl;
        cout << "Lines: ";
        for (int line : pair.second)
            cout << line << " ";
        cout << endl;
    }

    return 0;
}
