#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void to_lowwer(string& str) {
	constexpr char to_low = ('a' - 'A');
	for (auto& el : str)
		if (el >= 'A' && el <= 'Z')
			el += to_low;
}

struct Page {
	int index;
	double score = 0.0;
	double link_score = 0.0; // 남에게 주는 점수
	unordered_set<string> outer_links;
	string name;
	string page;

	Page(int index_, const string& page_) : index(index_), page(page_) {
		find_name(); // name
		find_links(); // outer_links
	}

private:
	void find_name() {
		static constexpr char key[] = "<meta property=\"og:url\" content=\"";
		static constexpr size_t key_len = sizeof(key) - 1;

		size_t offset = page.find(key, 0);
		offset += key_len;
		size_t end = page.find("\"", offset);

		name = page.substr(offset, end - offset);
	}
	void find_links() {
		static constexpr char key[] = "<a href=\"";
		static constexpr size_t key_len = sizeof(key) - 1;

		size_t offset = 0;

		while ((offset = page.find(key, offset)) != string::npos) {
			offset += key_len;
			size_t end = page.find("\"", offset);
			auto link = page.substr(offset, end - offset);
			outer_links.insert(link);
			offset = end;
		}
	}

public:
	void calc_score(const string& word) {
		size_t offset = 0;
		int cnt = 0;

		while ((offset = page.find(word, offset)) != string::npos) {
			// 이전 글자 체크
			if (offset != 0) {
				char prev_char = page[offset - 1];
				if (prev_char >= 'a' && prev_char <= 'z') {
					offset += word.size();
					continue;
				}
			}

			// 다음 글자 체크
			char next_char = page[offset + word.size()];
			if (next_char >= 'a' && next_char <= 'z') {
				offset += word.size();
				continue;
			}

			// 글자 검색!
			cnt++;
			offset += word.size();
		}

		score = (double)cnt;
		link_score = outer_links.empty() ? (0.0) : (score / outer_links.size());
	}
};

int solution(string word, vector<string> pages) {
	const int N = (int)pages.size();

	// 검색어
	to_lowwer(word);

	// 페이지 {인덱스, 이름, 외부 링크 수 } 생성
	unordered_map<string, Page*> tmp;
	vector<Page> pages_;
	pages_.reserve(N);
	for (int i = 0; i < N; i++) {
		to_lowwer(pages[i]);
		pages_.emplace_back(i, pages[i]);
		tmp[pages_[i].name] = &(pages_[i]);
	}

	// 기본점수 계산
	for (auto& el : pages_)
		el.calc_score(word);

	// 링크점수 추가 계산
	for (auto& el : pages_) {
		for (auto& el2 : el.outer_links) {
			if (tmp.find(el2) != tmp.cend()) {
				tmp[el2]->score += el.link_score;
			}
		}
	}

	// 점수(내림) > 인덱스(오름) 순으로 정렬
	std::partial_sort(pages_.begin(), pages_.begin() + 1, pages_.end(), [](const Page& left, Page& right) {
		if (std::abs(left.score - right.score) < std::numeric_limits<double>::epsilon())
			return left.index < right.index;
		return left.score > right.score;
	});

	int answer = pages_[0].index;
	return answer;
}

//------------------------------------------------
int main() {
	// case 1
	{
		auto pages = vector<string>{
			"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>",
			"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>",
			"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"
		};
		int result = solution("Blind", pages);
		printf("%d\n", result); // 0
	}

	// case 2
	{
		auto pages = vector<string>{
			"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>",
			"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"
		};
		int result = solution("Muzi", pages);
		printf("%d\n", result); // 1
	}
}