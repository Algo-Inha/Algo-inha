//https://programmers.co.kr/learn/courses/30/lessons/60057
//문자열 압축
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = s.size(); // s문자열의 길이
	for (int i = 1; i <= s.size() / 2; i++) { // i는 패턴의 길이
		string str1, str2; // str1은 바뀐 문자열, str2는 패턴의 문자열
		int count = 1; // 반복되는 패턴을 문자열에 넣어줄 숫자
		str2 = s.substr(0, i); // 0부터 i까지를 패턴으로 생성
		for (int j = i; j < s.size(); j += i) { // j는 패턴 확인
			if (str2 == s.substr(j, i)) count++; // 패턴이 같으면 count ++
			else { // 패턴이 끊겼을 때
				if (count > 1) str1 += to_string(count); // count가 1이상이면 숫자를 넣어줌
				// 다시 패턴 초기화
				str1 += str2;
				str2 = s.substr(j, i);
				count = 1;
			}
		}
		if (count > 1) str1 += to_string(count);
		str1 += str2;
		if (answer > str1.size()) answer = str1.size();
	}
	return answer;
}