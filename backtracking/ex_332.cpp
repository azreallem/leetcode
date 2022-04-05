#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <unordered_map>
#include <map>

using namespace std;

namespace std {
	template<typename T>
	ostream& operator<<(ostream &os, const vector<T> vec)
	{
		os << "[";
		for (int i = 0; i < vec.size(); i++) {
			os << vec[i];
			if (i != vec.size() - 1)
				os << ", ";
		}
		os << "]";
		return os;
	}
}

vector<string> res;

bool backtracking(unordered_map<string, map<string,int>>& tickets, int nums)
{
	if (res.size() == nums)
		return true;

	for (auto& ticket : tickets[res.back()]) {
		if (ticket.second == 0)
			continue;
		res.push_back(ticket.first);
		ticket.second--;
		if(backtracking(tickets, nums))
			return true;
		res.pop_back();
		ticket.second++;
	}
	return false;
}

vector<string> combine(vector<vector<string>> tickets_str)
{
	unordered_map<string, map<string,int>> tickets;
	for (auto ticket : tickets_str) {
		if (tickets.count(ticket[0]) == 0)
			tickets[ticket[0]].insert(pair<string,int>{ticket[1],1});
		else
			tickets[ticket[0]][ticket[1]]++;
	}
	res.clear();
	res.push_back("JFK");
	backtracking(tickets, tickets_str.size() + 1);
	return res;
}




int main()
{
	//vector<vector<string>> vec = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
	vector<vector<string>> vec = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
	vector<string> res = combine(vec);
	copy(res.begin(), res.end(), ostream_iterator<string>{cout," "});
	return 0;
}


