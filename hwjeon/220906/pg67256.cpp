#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int lefthand = 10, righthand = 12, leftdist = 0, rightdist = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7)
		{
			answer += "l";
			lefthand = numbers[i];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9)
		{
			answer += "r";
			righthand = numbers[i];
		}
		else
		{
			if (numbers[i] == 0)
				numbers[i] = 11;
			int tmp_l = abs(lefthand - numbers[i]);
			int tmp_r = abs(righthand - numbers[i]);

			leftdist = (tmp_l / 3) + (tmp_l % 3); //3개의 숫자마다 줄이 바뀌어 있음을 이용
			rightdist = (tmp_r / 3) + (tmp_r % 3);

			if (leftdist == rightdist)
			{
				if (hand == "right")
				{
					answer += "r";
					righthand = numbers[i];
				}
				else
				{
					answer += "l";
					lefthand = numbers[i];
				}
			}
			else if (leftdist < rightdist)
			{
				answer += "l";
				lefthand = numbers[i];
			}
			else
			{
				answer += "r";
				righthand = numbers[i];
			}
		}
	}
	return answer;
}