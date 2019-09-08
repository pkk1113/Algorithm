#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int min_len = s.size();

	for (int i = 1; i < s.size(); i++) {
		int start = 0;
		string result = "";
		string tmp1 = s.substr(start, i);
		int cnt = 1;

		for (start = i; start < s.size(); start += i) {
			string tmp2 = s.substr(start, i);

			if (tmp1 == tmp2) {
				cnt++;
			} else {
				if (cnt > 1)
					result.append(to_string(cnt) + tmp1);
				else
					result.append(tmp1);
				tmp1 = tmp2;
				cnt = 1;
			}
		}

		if (cnt > 1)
			result.append(to_string(cnt) + tmp1);
		else
			result.append(tmp1);

		if (result.size() < min_len)
			min_len = result.size();
	}

	return min_len;
}

int main() {
	auto r = solution("aabbaccc");
	printf("%d\n", r);
}