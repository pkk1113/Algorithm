#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // 반환값 사용 안 함
#endif

// 평균은 넘겠지
#include <stdio.h>
#include <stdlib.h>

int main() {
	int c; // cases
	int n; // number of student
	int i; // index
	int m; // mean
	int s; // sum of bigger than mean

	int* arr; // 학생들의 점수

	scanf("%d", &c);

	while (c--) {
		scanf("%d", &n);
		arr = (int*)malloc(n * sizeof(int));
		i = 0;
		m = 0;

		while (i < n) {
			scanf("%d", arr + i);
			m += arr[i];
			i++;
		}

		m /= n;
		i = 0;
		s = 0;

		while (i < n) {
			if (arr[i] > m)
				s++;
			i++;
		}
		
		printf("%.3f%%\n", 100.f * s / n);

		free(arr);
	}
}

#ifdef ENDGAME
// OX퀴즈(8958)
#include <stdio.h>
int main() {
	int t; // test case
	char arr[80]; // ox array
	int i; // index
	int s; // score
	int b; // bonus

	scanf("%d", &t);
	while (t--) {
		scanf("%s", arr);

		i = 0;
		s = 0;
		b = 1;

		while (arr[i] != '\0') {
			if (arr[i++] == 'O') {
				s += b;
				b++;
			} else {
				b = 1;
			}
		}

		printf("%d\n", s);
	}
}

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