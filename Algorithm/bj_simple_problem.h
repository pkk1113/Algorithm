#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

// 나머지(3052)
#include <stdio.h>

int main() {
	int record[42] = { 0, };
	int n = 0;
	int t;
	int cnt = 0;

	while (n++ < 10) {
		scanf("%d", &t);
		t = t % 42;

		if (record[t] == 0) {
			record[t] = 1;
			cnt++;
		}
	}

	printf("%d", cnt);
}


#ifdef ENDGAME
// 숫자의 개수(2577)
#include <stdio.h>

int main() {
	int n = 0;
	int t;
	int r = 1; // result;
	int cnt[10] = { 0, }; // counts

	while (n++ < 3) {
		scanf("%d", &t);
		r *= t;
	}

	while (r != 0) {
		cnt[r % 10]++;
		r /= 10;
	}

	n = 0;

	while (n < 10) {
		printf("%d\n", cnt[n++]);
	}
}

// 음계(2920)
#include <stdio.h>

int main() {
	int n = 7;
	int p; // previous
	int t;
	int is_asc;

	scanf("%d", &p);

	while (n--) {
		scanf("%d", &t);
		if (t == p + 1) {
			is_asc = 1;
		} else if (t == p - 1) {
			is_asc = 0;
		} else {
			puts("mixed");
			return 0;
		}

		p = t;
	}

	if (is_asc)
		puts("ascending");
	else
		puts("descending");
}

// 최댓값(2562)
#include <stdio.h>

int main() {
	int n = 9;
	int t = 0; // temp
	int b = -1; // big
	int p; // big place

	while (n--) {
		scanf("%d", &t);
		if (t > b) {
			b = t;
			p = 9 - n;
		}
	}

	printf("%d\n%d", b, p);
}
#endif