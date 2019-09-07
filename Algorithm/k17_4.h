#pragma warning(disable:4996)
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	vector<int> tt; // timetable
	int ti = 0; // tt index
	int tmp_m; // temp m

	int lt = 9 * 60; // leave time
	int mt = -1; // my time
	int et = lt + t * (n - 1); // end time

	for (auto& el : timetable) {
		int h = stoi(el.substr(0, 2));
		int m = stoi(el.substr(3, 2));
		int v = 60 * h + m;
		if (v <= et)
			tt.push_back(v);
	}

	sort(tt.begin(), tt.end());


	// 운행을 시작합니다.
	while (n-- > 0) {
		tmp_m = m;

		// 한 명식 탑니다. (다 태우거나, 더 없으면 떠납니다.)
		while (tmp_m-- > 0) {
			if (ti < tt.size() && tt[ti] <= lt)
				ti++;
			else
				break;
		}

		// 지금 보니 남은 자리가 없는데, 쿠루가 남거나 딱 타있으면
		if (n == 0) {
			if (tmp_m == -1 && ti <= tt.size()) {
				int tmp = tt[ti - 1]; // 마지막으로 탄 사람
				while (ti >= 0 && tmp != tt[--ti]); // 다른 시간이 나올 때까지
				mt = tt[ti] - 1; // 바로 그 전보다 1분 빠르게(치사..)
			} else {
				mt = lt;
				break;
			}
		}

		// 시간이 t분 흐릅니다.
		lt += t;
	}

	char buf[6] = "";
	{
		int h = mt / 60;
		int m = mt % 60;
		sprintf(buf, "%02d:%02d", h, m);
	}

	return string(buf);
}

int main() {
	int n = 10;
	int t = 1;
	int m = 10;
	auto tt = vector<string>{
		"08:50", "08:51", "08:52", "08:53", "08:54",
		"08:55", "08:55", "08:55", "08:55", "08:55",
		"08:55", "08:55", "08:55", "08:55", "08:55",
		"08:55", "08:55", "08:55", "08:55", "08:55",
		"08:55", "08:55", "08:55", "08:55", "08:55",
		"08:55", "08:55", "08:55", "08:55", "08:55",
	};
	auto r = solution(n, t, m, tt);
	printf("%s\n", r.c_str());
}