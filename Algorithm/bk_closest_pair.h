#pragma warning(disable:4996)
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <limits>

using namespace std;

struct point {
	int x, y;

	point() : x(0), y(0) {}
	point(int x_val, int y_val) : x(x_val), y(y_val) {}
};

double distance(const point& a, const point& b) {
	double y = (double)a.y - (double)b.y;
	double x = (double)a.x - (double)b.x;

	return sqrt(x * x + y * y);
}

double closest_pair(const point points[], size_t count) {
	// 3개 이하의 경우
	if (count < 2) {
		return numeric_limits<float>::max();
	} else if (count == 2) {
		return distance(points[0], points[1]);
	} else if (count == 3) {
		return min(distance(points[0], points[1]),
				   min(distance(points[0], points[2]),
					   distance(points[1], points[2])));
	}

	int mid = count / 2;

	double dl = closest_pair(points, mid);
	double dr = closest_pair(points + mid, count - mid);
	double d = std::min(dl, dr);

	std::vector<point> centers;
	centers.reserve(count);

	for (size_t i = 0; i < count; i++) {
		if (abs(points[i].x - points[mid].x) < d) {
			centers.emplace_back(points[i].x, points[i].y);
		}
	}

	if (!centers.empty()) {
		sort(centers.begin(), centers.end(), [](const point& lhs, const point& rhs) {
			return lhs.y < rhs.y;
		});

		for (size_t i = 0; i < centers.size(); i++) {
			for (size_t j = i + 1; j < centers.size(); j++) {
				double dc = distance(centers[i], centers[j]);

				if (dc < d)
					d = dc;
			}
		}
	}

	return d;
}

double closest_pair2(const point points[], size_t count) {
	double min_len = numeric_limits<float>::max();;

	for (size_t i = 0; i < count; i++) {
		for (size_t j = i + 1; j < count; j++) {
			double len = distance(points[i], points[j]);

			if (len < min_len)
				min_len = len;
		}
	}

	return min_len;
}

int main() {
	constexpr int N = 10000;

	vector<point> p;
	p.reserve(N);

	random_device rd;
	default_random_engine re(rd());
	uniform_int_distribution<int> dist(-1000, 1000);

	for (int i = 0; i < N; i++) {
		p.emplace_back(dist(re), dist(re));
	}

	sort(p.begin(), p.end(), [](const point& lhs, const point& rhs) {
		return lhs.x < rhs.x;
	});

	auto prev = chrono::system_clock::now();
	double len = closest_pair(p.data(), N);
	chrono::duration<double> delta = chrono::system_clock::now() - prev;
	printf("case 1: %f, len: %f\n", delta.count(), len);

	prev = chrono::system_clock::now();
	len = closest_pair2(p.data(), N);
	delta = chrono::system_clock::now() - prev;
	printf("case 2: %f, len: %f\n", delta.count(), len);
}
