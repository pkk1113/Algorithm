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


	// ������ �����մϴ�.
	while (n-- > 0) {
		tmp_m = m;

		// �� ��� ž�ϴ�. (�� �¿�ų�, �� ������ �����ϴ�.)
		while (tmp_m-- > 0) {
			if (ti < tt.size() && tt[ti] <= lt)
				ti++;
			else
				break;
		}

		// ���� ���� ���� �ڸ��� ���µ�, ��簡 ���ų� �� Ÿ������
		if (n == 0) {
			if (tmp_m == -1 && ti <= tt.size()) {
				int tmp = tt[ti - 1]; // ���������� ź ���
				while (ti >= 0 && tmp != tt[--ti]); // �ٸ� �ð��� ���� ������
				mt = tt[ti] - 1; // �ٷ� �� ������ 1�� ������(ġ��..)
			} else {
				mt = lt;
				break;
			}
		}

		// �ð��� t�� �帨�ϴ�.
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