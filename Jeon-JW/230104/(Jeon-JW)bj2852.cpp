//https://www.acmicpc.net/problem/2852
//NBA 농구
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int N;
int m1, s1;
int m2, s2;
int score1, score2;
int team_temp;
string time_temp;
//마지막 계산된 시간.
int last_time1, last_time2;

int main() {

	cin >> N;
	//첫번째
	cin >> team_temp;
	cin >> time_temp;
	//점수
	if (team_temp == 1) score1++;
	else score2++;
	last_time1 = stoi(time_temp.substr(0, time_temp.find(":")));
	last_time2 = stoi(time_temp.substr(time_temp.find(":") + 1));

	for (int i = 1; i < N; i++) {
		cin >> team_temp;
		cin >> time_temp;
		int input_m = stoi(time_temp.substr(0, time_temp.find(":")));
		int input_s = stoi(time_temp.substr(time_temp.find(":") + 1));
		
		if (score1 > score2) {
			m1 += input_m - last_time1;
			s1 += input_s - last_time2;
			if (s1 > 60) {
				s1 -= 60;
				m1 += 1;
			}
			if (s1 < 0) {
				m1 -= 1;
				s1 += 60;
			}
		}
		else if (score2 > score1) {
			m2 += input_m - last_time1;
			s2 += input_s - last_time2;
			if (s2 > 60) {
				s2 -= 60;
				m2 += 1;
			}
			if (s2 < 0) {
				m2 -= 1;
				s2 += 60;
			}
		}

		//점수
		if (team_temp == 1) score1++;
		else score2++;

		last_time1 = input_m;
		last_time2 = input_s;


		/*cout << "==============" << i << "============" << endl;
		if (m1 < 10) cout << "0" << m1 << ":";
		else cout << m1 << ":";
		if (s1 < 10) cout << "0" << s1 << endl;
		else cout << s1 << endl;
		if (m2 < 10) cout << "0" << m2 << ":";
		else cout << m2 << ":";
		if (s2 < 10) cout << "0" << s2 << endl;
		else cout << s2 << endl;*/
	}
	//48분
	if (score1 > score2) {
		m1 += 48 - last_time1;
		s1 += 0 - last_time2;
		if (s1 < 0) {
			m1 -= 1;
			s1 += 60;
		}
	}
	else if (score2 > score1) {
		m2 += 48 - last_time1;
		s2 += 0 - last_time2;
		if (s2 < 0) {
			m2 -= 1;
			s2 += 60;
		}
	}

	if (m1 < 10) cout << "0" << m1 << ":";
	else cout << m1 << ":";
	if (s1 < 10) cout << "0" << s1 << endl;
	else cout << s1 << endl;
	if (m2 < 10) cout << "0" << m2 << ":";
	else cout << m2 << ":";
	if (s2 < 10) cout << "0" << s2 << endl;
	else cout << s2 << endl;

	return 0;
}