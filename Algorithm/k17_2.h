#include <string>

using namespace std;

int get_num(string s, int& i) {
	int r = 0;
	for (; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9')
			r = r * 10 + (s[i] - '0');
		else
			break;
	}

	return r;
}

int solution(string dartResult) {
	int score[4] = { 0, };

	int d = 1;

	for (int i = 0; i < dartResult.size();) {
		int s = get_num(dartResult, i); // 점수
		char b = dartResult[i++]; // 보너스

		if (b == 'S')
			score[d] += s;
		else if (b == 'D')
			score[d] += s * s;
		else if (b == 'T')
			score[d] += s * s * s;

		if (dartResult[i] == '*') {
			score[d - 1] *= 2;
			score[d] *= 2;
			i++;
		}
		else if (dartResult[i] == '#') {
			score[d] *= -1;
			i++;
		}

		d++;
	}

	return score[1] + score[2] + score[3];
}

int main() {
	auto t1 = solution("1D2S3T*");
	printf("%d\n", t1);
}