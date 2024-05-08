// chp7-7.cpp

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "split2.h"

using namespace std;

// �Է¿��� �� �ܾ ������ ��� ���� ã��.
map<string, vector<int>> xref(istream& in, vector<string> find_words(const string&) = split) {
    string line;
    int line_number = 0;
    map<string, vector<int>> ret;

    // ���� ���� ����.
    while (getline(in, line)) {
        ++line_number;

        // �Է��� ���� �ܾ�� ����.
        vector<string> words = find_words(line);

        // ���� �࿡ ������ ��� �ܾ ����
        if (words.size() == 1) {
            // ���� �ϳ��� ���
            ret[words[0]].push_back(line_number);
        }
        else {
            // ���� ���� ���� ���
            for (const string& word : words)
                ret[word].push_back(line_number);
        }
    }
    return ret;
}

int main() {
    cout << "Enter words (CTRL+Z to stop): " << endl;

    // �⺻ �μ��� split �Լ��� ����Ͽ� xref �Լ��� ȣ��
    map<string, vector<int>> ret = xref(cin);

    // ����� ���
    for (const auto& pair : ret) {
        // �ܾ ���
        cout << "\"" << pair.first << "\" occurs on line(s): ";

        // �̾ �ϳ� �̻��� �� ��ȣ�� ���
        vector<int>::const_iterator line_it = pair.second.begin();

        // �ش� �ܾ ������ ù ��° �� ��ȣ�� ���
        cout << *line_it;
        ++line_it;

        // �� ��ȣ�� �� ������ ���� ���
        while (line_it != pair.second.end()) {
            cout << "," << *line_it;
            ++line_it;
        }

        // �� �ܾ ���� �ܾ�� �����Ϸ��� ���ο� ���� ���
        cout << endl;
    }
    return 0;
}
