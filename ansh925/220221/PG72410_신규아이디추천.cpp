//https://programmers.co.kr/learn/courses/30/lessons/72410
#include <string>
using namespace std;

string solution(string new_id)
{
	// step1
	for (int i = 0; i < new_id.length(); i++)
	{
		if (new_id[i] >= 'A' && new_id[i] <= 'Z')
			new_id[i] = tolower(new_id[i]);
	}

	// step2
	for (int i = 0; i < new_id.length();)
	{
		if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') ||
			new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
		{
			i++;
			continue;
		}
		new_id.erase(new_id.begin() + i);
	}

	// step3
	for (int i = 1; i < new_id.length();)
	{
		if (new_id[i] == '.' && new_id[i - 1] == '.')
		{
			new_id.erase(new_id.begin() + i);
			continue;
		}
		else
			i++;
	}

	// step4
	if (new_id.front() == '.')
		new_id.erase(new_id.begin());
	if (new_id.back() == '.')
		new_id.erase(new_id.end() - 1);

	// step5
	if (new_id.length() == 0)
		new_id = "a";

	// step6
	if (new_id.length() >= 16)
	{
		while (new_id.length() != 15)
			new_id.erase(new_id.begin() + 15);
	}
	if (new_id.back() == '.')
		new_id.erase(new_id.end() - 1);

	// step7
	if (new_id.length() <= 2)
	{
		while (new_id.length() != 3)
			new_id += new_id.back();
	}

	return new_id;
}