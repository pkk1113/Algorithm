// �Ǻ���ġ �� 2

#ifdef _WIN32
#pragma warning(disable:4996) // c io
#pragma warning(disable:6031) // ��ȯ�� ��� �� ��
#endif

#include <cstdio>
using namespace std;
using ll = long long;

int main() {
	int n;
	scanf("%d", &n);

	ll a = 0;
	ll b = 1;

	while (n--) {
		ll t = a + b;
		a = b;
		b = t;
	}

	printf("%lld", a);
}