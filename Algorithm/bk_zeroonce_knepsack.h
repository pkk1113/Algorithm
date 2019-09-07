#pragma warning(disable:4996)
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <vector>

template<typename F, typename ...Args>
auto log_time(F fn, Args... args) -> decltype(fn(args...)) {
	auto prev = std::chrono::system_clock::now();
	auto r = fn(args...);
	std::chrono::duration<double> delta = std::chrono::system_clock::now() - prev;
	printf("걸린 시간: %f 초\n", delta.count());

	return r;
}

struct item {
	int capacity;
	int price;

	item(int c, int p) : capacity(c), price(p) {}
};

int zeroone_knapsack_dc(item* items, int count, int capacity) {
	if ((count <= 0) || (capacity <= 0))
		return 0;
	else if (capacity < items->capacity)
		// zero
		return zeroone_knapsack_dc(items + 1, count - 1, capacity);
	else
		return std::max(
			// zero
			zeroone_knapsack_dc(items + 1, count - 1, capacity),
			// one
			zeroone_knapsack_dc(items + 1, count - 1, capacity - items->capacity) + items->price
		);
}

int zeroone_knapsack_dp(item* items, int count, int capacity) {
	using std::vector;
	using std::array;

	vector<vector<int>> data(capacity + 1, vector<int>(count + 1, 0));

	for (int c = 0; c <= capacity; c++) {
		for (int k = 0; k <= count; k++) {
			if ((k <= 0) || (c == 0))
				data[c][k] = 0;
			else if (items[k - 1].capacity <= c)
				data[c][k] = std::max(data[c][k - 1],
									  data[c - items[k - 1].capacity][k - 1] + items[k - 1].price);
			else
				data[c][k] = data[c][k - 1];
		}
	}

	return data[capacity][count];
}


int main() {
	std::vector<item> items;
	items.reserve(100);
	items.emplace_back(1, 600);
	items.emplace_back(2, 1000);
	items.emplace_back(3, 1200);
	items.emplace_back(4, 1300);
	items.emplace_back(5, 1500);
	items.emplace_back(6, 1700);
	items.emplace_back(7, 1800);
	items.emplace_back(8, 2100);
	items.emplace_back(9, 2500);
	items.emplace_back(10, 3400);
	items.emplace_back(11, 5000);
	items.emplace_back(12, 10000);
	items.emplace_back(20, 11000);
	items.emplace_back(30, 115000);
	items.emplace_back(35, 120000);
	items.emplace_back(40, 200000);
	items.emplace_back(45, 400000);

	int result = 0;

	result = log_time(zeroone_knapsack_dc, items.data(), std::size(items), 40);
	printf("결과: %d원\n", result);

	result = log_time(zeroone_knapsack_dp, items.data(), std::size(items), 40);
	printf("결과: %d원\n", result);
}