#include <string>
#include <vector>

using namespace std;

// p는 언제나 짝수 길이

vector<char> p_stack;

bool is_good(char c) {
	if (c == '(') {
		p_stack.push_back(1);
	} else if (c == ')') {
		if (p_stack.empty())
			return false;
		p_stack.pop_back();
	}

	return true;
}

bool is_bad(char c) {
	if (c == ')') {
		p_stack.push_back(1);
	} else if (c == '(') {
		if (p_stack.empty())
			return false;
		p_stack.pop_back();
	}

	return true;
}

string dfs(string p) {
	if (p.empty())
		return p;

	bool u_is_good = p[0] == '(' ? true : false;
	int v_pos = -1;

	p_stack.clear();

	for (int i = 0; i < p.size(); i++) {
		if (u_is_good) {
			if (!is_good(p[i])) {
				v_pos = i;
				break;
			}
		} else {
			if (!is_bad(p[i])) {
				v_pos = i;
				break;
			}
		}
	}

	if (v_pos == -1) {
		if (u_is_good) {
			return p;
		}

		v_pos = p.size();
	}

	string u = p.substr(0, v_pos);
	string v = p.substr(v_pos, p.size() - v_pos);

	// u가 올바르다면
	if (u_is_good) {
		return u + dfs(v);
	}

	// u가 올바르지 않다면
	string tmp = "(";
	tmp.append(dfs(v) + ")");
	for (int i = 1; i < u.size() - 1; i++) {
		tmp += (u[i] == '(') ? ')' : '(';
	}

	return tmp;
}

string solution(string p) {
	return dfs(p);
}

int main() {
	string p = "())(()";
	auto r = solution(p);
	printf("%s\n", r.c_str());
}