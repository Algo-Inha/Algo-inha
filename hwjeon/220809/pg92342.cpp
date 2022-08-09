#include <string>
#include <vector>

using namespace std;

vector<int> answer;
int max_score = -1;

int get_score(vector<int> &a, vector<int> &r) {
	int apeach = 0, ryan = 0;
	for (int i = 0; i < 11; ++i) {
		if (a[i] == 0 && r[i] == 0) continue; // 둘 다 0점이면 패스

		if (a[i] >= r[i]) apeach += (10 - i); // 어피치 >= 라이언이면 어피치가
		else ryan += (10 - i); // 어피치 < 라이언이면 라이언이 점수 획득
	}

	if (ryan > apeach) return ryan - apeach;
	else return -1;
}

bool shoot_lower_score(vector<int> &ryan) {
	for (int i = 11 - 1; i >= 0; --i) { // 0점 과녁부터 비교
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
				낮은 점수를 더 많이 맞힌 경우가 우선 순위가 있기 때문에,
				화살이 남아있으면 0점에 나머지 화살을 모두 쏨
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

	if (chance > apeach[idx]) { // 어피치보다 한 발 더 맞추기
		ryan[idx] = apeach[idx] + 1;
		func(apeach, ryan, chance - ryan[idx], idx + 1);
		ryan[idx] = 0;
	}

	func(apeach, ryan, chance, idx + 1); // 쏘지 않고 다음 과녁으로
}

vector<int> solution(int n, vector<int> info) {
	vector<int> ryan(11, 0);

	func(info, ryan, n, 0);

	if (max_score == -1) return { -1 };

	return answer;
}