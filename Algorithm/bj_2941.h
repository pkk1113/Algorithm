// 크로아티아 알파벳

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#pragma warning(disable:4018) // unsigned를 int로 변환
#endif

#include <iostream>
#include <string>
using namespace std;

void cvt(string& s, const string& val) {
	int pos = 0;

	while ((pos = s.find(val)) != -1) {
		s.erase(pos, val.size());
		s.insert(pos, "*");
	}
}

int main() {
	string s;
	cin >> s;

	string croatia[] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
	for (auto& v : croatia) {
		cvt(s, v);
	}

	printf("%d\n", s.size());
}