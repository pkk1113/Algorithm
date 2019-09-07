#include <vector>
#include <unordered_map>

using namespace std;

void find_block(int b, int r, int c, int N,
		 vector<vector<int>>& board,
		 vector<pair<int, int>>& checked) {
	// 4���� ������.
	if (checked.size() == 4)
		return;

	// ������ ����� ������.
	if (r < 0 || r >= N || c < 0 || c >= N)
		return;

	// �̹� �Դٸ� ������.
	for (auto& el : checked)
		if (el.first == r && el.second == c)
			return;

	// �־��� ���� ���ٸ� �߰��Ѵ�. (�ƴϸ� ������.)
	if (b == board[r][c])
		checked.emplace_back(r, c);
	else
		return;

	// �¿�����θ� ��ȸ
	find_block(b, r, c - 1, N, board, checked); // ��
	find_block(b, r, c + 1, N, board, checked); // ��
	find_block(b, r - 1, c, N, board, checked); // ��
}

int get_width(const vector<pair<int, int>>& checked) {
	unordered_map<int, int> range;
	for (auto& el : checked)
		range[el.second]++;

	return (int)range.size();
}

int solution(vector<vector<int>> board) {
	const int N = (int)board.size();

	int answer = 0;


	// ������ ������ ����� �����Ѵ�.
	while (true) {
		unordered_map<int, int> double_check; // ���� üũ��
		vector<pair<int, int>> checked; // üũ�� ���
		bool found = false;

		for (int c = 0; c < N; c++) {
			checked.clear();

			for (int r = 0; r < N; r++) {
				if (board[r][c] == 0)
					continue;

				find_block(board[r][c], r, c, N, board, checked);

				if (checked.size() == 4) {
					int width = get_width(checked);

					// �ʺ� 2���� �ٷ� ���
					if (width == 2) {
						found = true;
						break;
					} 
					// �ʺ� 3���� �ѹ��� �˻��Ǹ� ���
					else if (width == 3) {
						if (++double_check[board[r][c]] == 2)
							found = true;
						break;
					}
				} else
					break;
			}

			if (found)
				break;
		}

		// üũ ���� 4���� ����, �ƴϸ� �����Ѵ�.
		if (found) {
			answer++;
			for (auto& el : checked)
				board[el.first][el.second] = 0;
		} else {
			break;
		}
	}

	return answer;
}

//-----------------------------------------

#pragma warning(disable:4996)
#include <cstdio>

int main() {
	// case 1
	{
		auto board = vector<vector<int>>{
			// (0, 0)
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 4, 0, 0, 0},
			{0, 0, 0, 0, 0, 4, 4, 0, 0, 0},
			{0, 0, 0, 0, 3, 0, 4, 0, 0, 0},
			{0, 0, 0, 2, 3, 0, 0, 0, 5, 5},
			{1, 2, 2, 2, 3, 3, 0, 0, 0, 5},
			{1, 1, 1, 0, 0, 0, 0, 0, 0, 5} }; // (8, 8)

		auto result = solution(board);
		printf("%d\n", result); // 2
	}

	// case 2
	{
		auto board = vector<vector<int>>{
			{3, 3, 4, 0},
			{3, 4, 4, 4},
			{3, 5, 0, 0},
			{5, 5, 5, 0}
		};

		auto result = solution(board);
		printf("%d\n", result); // 2
	}
}