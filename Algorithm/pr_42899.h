#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// [구간으로][시간이내] = 최대모금

int solution(int K, vector<vector<int>> travel) {
	int N = travel.size();

	auto mem = vector<vector<int>>(N + 1, vector<int>(K + 1, 0)); // 모금

	for (int i = 1; i <= N; i++) { // 구간
		for (int k = 0; k <= K; k++) { // 시간
			int wt = travel[i - 1][0]; // walk time 
			int wc = travel[i - 1][1]; // walk cost
			int bt = travel[i - 1][2]; // bicycle time
			int bc = travel[i - 1][3]; // bicycle cost
			int wm = -1; // walk money
			int bm = -1; // bicycle money

			// 이전 구간에서 현재 구간으로 `도보` 선택시
			if (wt <= k && mem[i - 1][k - wt] >= 0) // 존재하는 구간인 경우만
				wm = wc + mem[i - 1][k - wt];

			// 이전 구간에서 현재 구간으로 `자전거` 선택시
			if (bt <= k && mem[i - 1][k - bt] >= 0) // 존재하는 구간인 경우만
				bm = bc + mem[i - 1][k - bt];

			mem[i][k] =  max(wm, bm); // -1이 들어갈 경우, k 시간에 존재할 수 없는 구간이다.
		}
	}

	// K초에서 각 구간별 가장 많은 모금을 모은 곳을 꺼낸다
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