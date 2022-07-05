//시그널
#include<iostream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>

using namespace std;
string signal[20000];
string s;
int n;
int main() {
	cin >> n;
	cin>> s;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < n/5; j++)
		{
			signal[j] += s[i * n / 5 + j];
		}
	}
	int num;
	string decode;
	//for (int i = 0; i < n/5; i++)
	//{
	//	cout << signal[i];
	//}
	//cout << endl;
	for (int i = 0; i < n/5; i++)
	{
		if (signal[i] != ".....") {
			decode += signal[i];
		}
			if (i == n / 5 - 1||signal[i] == ".....") {
				//마지막에 공백없이 끝나는 경우를 대비하여 i == n / 5 - 1 의 경우 고려
			if (decode == "######...######")num = 0;
			if (decode == "#####")num=1;
			if (decode == "#.####.#.####.#")num=2;
			if (decode == "#.#.##.#.######")num=3;
			if (decode == "###....#..#####")num=4;
			if (decode == "###.##.#.##.###")num=5;
			if (decode == "######.#.##.###")num=6;
			if (decode == "#....#....#####")num=7;
			if (decode == "######.#.######")num=8;
			if (decode == "###.##.#.######")num=9;
			if (decode[0] == '#')cout << num;//모든 숫자는 #로 시작
			decode = "";
		}

	}
}