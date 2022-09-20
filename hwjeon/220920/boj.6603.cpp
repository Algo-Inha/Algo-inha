#include <iostream>
#include <vector>
#include <string>

using namespace std;
int k = 6;
vector<int> lotto(13, 0);
vector<int> visitied(13, 0);
void cal(int c, string answer, int start) {
	if (c == 7) {
		cout << answer << "\n";
	}
	else {
		for (int i = start; i < k; i++) {
			if (visitied[i] == 1)
				continue;
			visitied[i] = 1;
			cal(c + 1, answer + to_string(lotto[i]) + " ", i + 1);
			visitied[i] = 0;
		}
	}
}
int main() {
	int temp;
	while (true) {
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++) {
			cin >> temp;
			lotto[i] = temp;
			visitied[i] = 0;
		}
		cal(1, "", 0);
		cout << "\n";

	}
}
