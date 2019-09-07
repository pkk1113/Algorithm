#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int id;
	int x;
	int y;

	Node* left;
	Node* right;

	Node(int id_, int x_, int y_) :
		id(id_), x(x_), y(y_),
		left(nullptr), right(nullptr) {}
};

struct Tree {
	Node* root;

	Tree() : root(nullptr) {}

	void add(Node* added) {
		if (root == nullptr)
			root = added;
		add(root, added);
	}
	void preorder(vector<int>& result) const {
		preorder(root, result);
	}
	void postorder(vector<int>& result) const {
		postorder(root, result);
	}

private:
	void add(Node* base, Node* added) {
		if (added->x > base->x) {
			if (base->right == nullptr)
				base->right = added;
			else
				add(base->right, added);
		} else if (added->x < base->x) {
			if (base->left == nullptr)
				base->left = added;
			else
				add(base->left, added);
		}
	}
	void preorder(Node* base, vector<int>& result) const {
		if (!base)
			return;
		
		result.push_back(base->id);
		preorder(base->left, result);
		preorder(base->right, result);
	}
	void postorder(Node* base, vector<int>& result) const {
		if (!base) 
			return;

		postorder(base->left, result);
		postorder(base->right, result);
		result.push_back(base->id);
	}
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	const int N = (int)nodeinfo.size();

	// 노드 생성
	vector<Node*> nodes;
	nodes.reserve(N);
	for (int i = 0; i < N; i++)
		nodes.push_back(new Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]));

	// 정렬(y는 내림차순, x는 오름차순)
	sort(nodes.begin(), nodes.end(), [](const Node* left, const Node* right) {
		return (left->y == right->y) ? (left->x < right->x) : (left->y > right->y);
	});

	// 트리 생성
	Tree tree;
	for (auto& el : nodes)
		tree.add(el);

	// 결과 생성
	vector<vector<int>> answer(2);
	answer[0].reserve(N);
	answer[1].reserve(N);
	tree.preorder(answer[0]);
	tree.postorder(answer[1]);

	// 해제
	for (auto& el : nodes)
		delete el;

	return answer;
}

//---------------------------------------
void print_vector(const vector<int>& v) {
	for (auto el : v) {
		printf("%d ", el);
	}
	printf("\n");
}

int main() {
	auto nodeinfo = vector<vector<int>>{
		{5, 3}, {11, 5}, {13, 3}, {3, 5},
		{6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2},
	};

	auto result = solution(nodeinfo);

	print_vector(result[0]); // 7,4,6,9,1,8,5,2,3
	print_vector(result[1]); // 9,6,5,8,1,4,3,2,7
}
