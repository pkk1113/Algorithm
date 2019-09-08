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

// �迭�� �ִ���
bool exist(int x, int y, int a) {
	// �����
	if (a == 0) {
		if (x < 0 || y < 0 || x > N || y > N)
			return false;
	} else {
		if (x < 0 || y < 0 || x >= N || y >= N)
			return false;
	}

	return infos.find(Info(x, y, a)) != infos.cend();
}

// ������ �� �ִ���
bool exist_in(int x, int y, int a) {
	// ó������ ������ �Ű� �� ���� �մϴ�.
	if (!exist(x, y, a))
		return true;

	// ����̸�
	if (a == 0) {
		// �ٴڿ� ������ ���� ���� 
		if (y == 0) {
			return true;
		}
		// �ؿ� �ϳ��� �����ϸ� ���� ����
		else {
			return 
				exist(x, y - 1, 0) ||
				exist(x, y, 1) ||
				exist(x - 1, y, 1);
		}
	}
	// ����
	else {
		// �� ���� ���� ������ ���� ����
		if (exist(x - 1, y, 1) && exist(x + 1, y, 1))
			return true;
		// �ؿ� �ϳ��� ������ ���� ����
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
		// �Է��� ����
		Info info(build_frame[i][0],
				  build_frame[i][1],
				  build_frame[i][2]);

		// ������
		if (build_frame[i][3] == 0) {
			infos.erase(info); // ��������

			// ���
			if (info.a == 0) {
				// ������ �� ���� �Ǹ� �ѹ�
				if (!exist_in(info.x, info.y + 1, 0) ||
					!exist_in(info.x, info.y + 1, 0) ||
					!exist_in(info.x, info.y + 1, 0)) infos.insert(info);
			}
			// ��
			else {
				// ������ �� ���� �Ǹ� �ѹ�
				if (!exist_in(info.x, info.y, 0) ||
					!exist_in(info.x + 1, info.y, 0) ||
					!exist_in(info.x - 1, info.y, 1) ||
					!exist_in(info.x + 1, info.y, 1)) infos.insert(info);
			}
		}
		// �߰���
		else {
			infos.insert(info); // �־��

			// ������ �� ������ �ѹ�
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