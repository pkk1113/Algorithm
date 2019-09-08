#include <string>
#include <vector>
#include <set>

using namespace std;

struct Info {
	int x;
	int y;
	int a; // kind

	Info(int x_, int y_, int a_) : x(x_), y(y_), a(a_) {}

	bool operator<(const Info& o) const {
		if (x != o.x)
			return x < o.x;
		else if (y != o.y)
			return y < o.y;
		else
			return a < o.a;
	}
};

int N;
set<Info> infos;

// 배열에 있는지
bool exist(int x, int y, int a) {
	// 기둥은
	if (a == 0) {
		if (x < 0 || y < 0 || x > N || y > N)
			return false;
	} else {
		if (x < 0 || y < 0 || x >= N || y >= N)
			return false;
	}

	return infos.find(Info(x, y, a)) != infos.cend();
}

// 존재할 수 있는지
bool exist_in(int x, int y, int a) {
	// 처음부터 없으면 신경 안 쓰게 합니다.
	if (!exist(x, y, a))
		return true;

	// 기둥이면
	if (a == 0) {
		// 바닥에 있으면 존재 가능 
		if (y == 0) {
			return true;
		}
		// 밑에 하나라도 존재하면 존재 가능
		else {
			return 
				exist(x, y - 1, 0) ||
				exist(x, y, 1) ||
				exist(x - 1, y, 1);
		}
	}
	// 보면
	else {
		// 양 옆에 보가 있으면 존개 가능
		if (exist(x - 1, y, 1) && exist(x + 1, y, 1))
			return true;
		// 밑에 하나라도 있으면 존재 가능
		else {
			return
				exist(x, y - 1, 0) ||
				exist(x + 1, y - 1, 0);
		}
	}
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	N = n;

	for (int i = 0; i < build_frame.size(); i++) {
		// 입력을 통해
		Info info(build_frame[i][0],
				  build_frame[i][1],
				  build_frame[i][2]);

		// 삭제시
		if (build_frame[i][3] == 0) {
			infos.erase(info); // 지워보고

			// 기둥
			if (info.a == 0) {
				// 존재할 수 없게 되면 롤백
				if (!exist_in(info.x, info.y + 1, 0) ||
					!exist_in(info.x, info.y + 1, 0) ||
					!exist_in(info.x, info.y + 1, 0)) infos.insert(info);
			}
			// 보
			else {
				// 존재할 수 없게 되면 롤백
				if (!exist_in(info.x, info.y, 0) ||
					!exist_in(info.x + 1, info.y, 0) ||
					!exist_in(info.x - 1, info.y, 1) ||
					!exist_in(info.x + 1, info.y, 1)) infos.insert(info);
			}
		}
		// 추가시
		else {
			infos.insert(info); // 넣어보고

			// 존재할 수 없으면 롤백
			if (!exist_in(info.x, info.y, info.a)) infos.erase(info);
		}
	}

	vector<vector<int>> answer;
	for (auto& el : infos)
		answer.push_back({ el.x, el.y, el.a });
	return answer;
}

int main() {
	auto bf = vector<vector<int>>{ {0, 0, 0, 1}, {2, 0, 0, 1}, {4, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 1, 1}, {2, 1, 1, 1}, {3, 1, 1, 1}, {2, 0, 0, 0}, {1, 1, 1, 0}, {2, 2, 0, 1} };
	solution(5, bf);
}