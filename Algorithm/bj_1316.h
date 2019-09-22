// 그룹 단어 체커

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#pragma warning(disable:4018) // unsigned를 int로 변환
#endif

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_group(string& s) {
	auto rec = vector<bool>(26, false);
	for (int i = 0; i < s.size(); i++) {
		int index = s[i] - 'a';
		if (i != 0 && s[i - 1] != s[i] && rec[index])
			return false;
		else
			rec[index] = true;
	}
	return true;
}

int main() {
	int n;
	cin >> n;

	int cnt = 0;

	while (n--) {
		string w;
		cin >> w;

		if (is_group(w))
			cnt++;
	}

	printf("%d\n", cnt);
}