#pragma once

// https://www.welcomekakao.com/learn/courses/30/lessons/42888

#pragma warning(disable:4996)
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;

	unordered_map<string, string> users;

	string cmd;
	string uid;
	string nik;

	string enter = "님이 들어왔습니다.";
	string leave = "님이 나갔습니다.";
	string change = "님이 들어왔습니다.";

	vector<string> my_recode;
	my_recode.reserve(record.size() * 2);

	for (auto& el : record) {
		stringstream ss(el);

		ss >> cmd;

		if (cmd == "Enter") {
			ss >> uid >> nik;
			users[uid] = nik;
			my_recode.push_back(uid);
			my_recode.push_back(enter);
		} else if (cmd == "Leave") {
			ss >> uid;
			my_recode.push_back(uid);
			my_recode.push_back(leave);
		} else if (cmd == "Change") {
			ss >> uid >> nik;
			users[uid] = nik;
		}
	}

	for (int i = 0; i < my_recode.size(); i += 2) {
		answer.push_back(users[my_recode[i]] + my_recode[i + 1]);
	}

	return answer;
}

int main() {
	vector<string> record = {
		"Enter uid1234 Muzi",
		"Enter uid4567 Prodo",
		"Leave uid1234",
		"Enter uid1234 Prodo",
		"Change uid4567 Ryan" };

	auto result = solution(record);

	for (auto& el : result) {
		puts(el.c_str());
	}
}