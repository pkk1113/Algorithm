// 단어의 개수

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#pragma warning(disable:4018) // unsigned를 int로 변환
#endif

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	stringstream ss(s);
	
	int cnt = 0;

	while (!ss.eof()) {
		s.clear();
		ss >> s;
		if (!s.empty()) {
			cnt++;
		}
	}

	printf("%d", cnt);
}