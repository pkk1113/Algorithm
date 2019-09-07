#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [��������][�ð��̳�] = �ִ���

int solution(int K, vector<vector<int>> travel) {
	int N = travel.size();

	auto mem = vector<vector<int>>(N + 1, vector<int>(K + 1, 0)); // ���

	for (int i = 1; i <= N; i++) { // ����
		for (int k = 0; k <= K; k++) { // �ð�
			int wt = travel[i - 1][0]; // walk time 
			int wc = travel[i - 1][1]; // walk cost
			int bt = travel[i - 1][2]; // bicycle time
			int bc = travel[i - 1][3]; // bicycle cost
			int wm = -1; // walk money
			int bm = -1; // bicycle money

			// ���� �������� ���� �������� `����` ���ý�
			if (wt <= k && mem[i - 1][k - wt] >= 0) // �����ϴ� ������ ��츸
				wm = wc + mem[i - 1][k - wt];

			// ���� �������� ���� �������� `������` ���ý�
			if (bt <= k && mem[i - 1][k - bt] >= 0) // �����ϴ� ������ ��츸
				bm = bc + mem[i - 1][k - bt];

			mem[i][k] =  max(wm, bm); // -1�� �� ���, k �ð��� ������ �� ���� �����̴�.
		}
	}

	// K�ʿ��� �� ������ ���� ���� ����� ���� ���� ������
	int answer = 0;
	for (int i = 0; i <= N; i++)
		if (mem[i][K] > answer)
			answer = mem[i][K];

	return answer;
}

int main() {
	// case 1
	if (true) {
		auto travel = vector<vector<int>>{
			{500, 200, 200, 100},
			{800, 370, 300, 120},
			{700, 250, 300, 90}
		};

		auto r = solution(500, travel);
		printf("%d\n", r); // 220
	}

	// case 2
	if (true) {
		auto travel = vector<vector<int>>{
			{1000, 2000, 300, 700},
			{1100, 1900, 400, 900},
			{900, 1800, 400, 700},
			{1200, 2300, 500, 1200}
		};

		auto r = solution(3000, travel);
		printf("%d\n", r);
	}
}