#include <string>
#include <vector>

using namespace std;

vector<int> answer;
int max_score = -1;

int get_score(vector<int> &a, vector<int> &r) {
	int apeach = 0, ryan = 0;
	for (int i = 0; i < 11; ++i) {
		if (a[i] == 0 && r[i] == 0) continue; // �� �� 0���̸� �н�

		if (a[i] >= r[i]) apeach += (10 - i); // ����ġ >= ���̾��̸� ����ġ��
		else ryan += (10 - i); // ����ġ < ���̾��̸� ���̾��� ���� ȹ��
	}

	if (ryan > apeach) return ryan - apeach;
	else return -1;
}

bool shoot_lower_score(vector<int> &ryan) {
	for (int i = 11 - 1; i >= 0; --i) { // 0�� ������� ��
		if (ryan[i] > answer[i]) return true;
		else if (ryan[i] < answer[i]) return false;
	}
	return false;
}

void func(vector<int> &apeach, vector<int> &ryan, int chance, int idx) {
	if (idx == 11 || chance == 0) {
		int score = get_score(apeach, ryan);
		if (score != -1) {
			/*
				���� ������ �� ���� ���� ��찡 �켱 ������ �ֱ� ������,
				ȭ���� ���������� 0���� ������ ȭ���� ��� ��
			*/
			if (chance > 0) ryan[idx - 1] = chance;

			if (score == max_score && shoot_lower_score(ryan)) {
				answer = ryan;
			}

			else if (score > max_score) {
				max_score = score;
				answer = ryan;
			}

			ryan[idx - 1] = 0;
		}
		return;
	}

	if (chance > apeach[idx]) { // ����ġ���� �� �� �� ���߱�
		ryan[idx] = apeach[idx] + 1;
		func(apeach, ryan, chance - ryan[idx], idx + 1);
		ryan[idx] = 0;
	}

	func(apeach, ryan, chance, idx + 1); // ���� �ʰ� ���� ��������
}

vector<int> solution(int n, vector<int> info) {
	vector<int> ryan(11, 0);

	func(info, ryan, n, 0);

	if (max_score == -1) return { -1 };

	return answer;
}