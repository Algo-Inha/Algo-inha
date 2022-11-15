vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> id_name;
	vector<pair<string, string>> result;

	for (int i = 0; i < record.size(); i++) {
		string first, second, third;
		stringstream sstream;
		sstream.str(record[i]);
		sstream >> first >> second >> third;

		if (first == "Enter") {
			id_name[second] = third;
			result.push_back(make_pair(second, "���Խ��ϴ�."));

		}
		else if (first == "Leave")
			result.push_back(make_pair(second, "�������ϴ�."));
		else if (first == "Change")
			id_name[second] = third;
	}
	for (int i = 0; i < result.size(); i++) {
		answer.push_back(id_name[result[i].first] + "���� " + result[i].second);
	}
	return answer;
}