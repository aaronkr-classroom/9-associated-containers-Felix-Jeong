//split2.cpp

#include <algorithm> //find_if() 사용하기 위해
#include <cctype> //isspace() 사용하기 위해
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 인수가 공백일 때는 true, 그렇지 않을때는 false
bool space(char c) {
	return isspace(c);
}

// 인수가 공백일 때는 false, 그렇지 않을때는 true
bool not_space(char c) {
	return !isspace(c);
}

vector<string> split(const string& str) {
	typedef string::const_iterator iter;
	iter i = str.begin();
	vector<string> ret;

	// for(iter i = str.begin(); i != str.end(); i++) {}
	while (i != str.end()) {
		
		i = find_if(i, str.end(), not_space); 
		
		iter j = find_if(i, str.end(), space);
		
		// [i, j) 범위의 문자를 복사
		if (i != str.end()) {
			ret.push_back(string(i, j));
		}

		// i반복자 위치가 j반복자의 위치를 저장 
		i = j; 
	}
	return ret;
}
