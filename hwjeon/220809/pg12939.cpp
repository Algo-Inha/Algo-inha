#include <string>
#include <vector>
#include <algorithm>

using namespace std;


string solution(string s)
{
	string answer = "";
	vector<int> data;

	// 슬라이싱
	int idx = 0, start_idx = 0, size = s.size();
	while (true)
	{
		if (s[idx] == ' ')
		{
			string tmp = s.substr(start_idx, idx - start_idx);
			data.push_back(stoi(tmp));
			start_idx = idx + 1;
		}

		if (++idx == size)
		{
			string tmp = s.substr(start_idx);
			data.push_back(stoi(tmp));
			break;
		}
	}

	// 오름차순 정렬
	sort(data.begin(), data.end());
	answer += to_string(data.front()) + ' ' + to_string(data.back());
	return answer;
}