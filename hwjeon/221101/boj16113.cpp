#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main()
{

	map<string, int> m =
	{
	{"####.##.##.####",0},
	{"###..#####..###", 2},
	{"###..####..####", 3},
	{"#.##.####..#..#", 4},
	{"####..###..####", 5},
	{"####..####.####", 6},
	{"###..#..#..#..#", 7},
	{"####.#####.####", 8},
	{"####.####..####", 9} };


	int n;
	cin >> n;
	string sig;
	cin >> sig;


	vector<string> num_sig;

	int N = n / 5;

	//1
	for (int i = 0; i < n; i += N) {
		num_sig.push_back(sig.substr(i, N));
	}

	//2
	for (int i = 0; i < N; i++) {
		if (num_sig[0][i] == '#') {

			//3
			if ((i == N - 1 || (num_sig[0][i + 1] == '.' && num_sig[3][i] == '#')))
			{
				cout << 1 << ""; continue;
			}

			//4 
			string num = "";
			for (int j = 0; j < 5; j++)
			{
				num += num_sig[j].substr(i, 3);
			}

			//5
			if (m.find(num) != m.end()) { 
				cout << m[num] << "";
				i += 3;
			}
		}
		return 0;
	}