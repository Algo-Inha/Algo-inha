//https://programmers.co.kr/learn/courses/30/lessons/92335?language=cpp
//k진수에서 소수 개수 구하기
#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool prime(long long num) {
    if (num < 2)return false;

    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int func1(string str) {
    int answer = 0;
    string temp = "";

    // 오른쪽에 0이 있는 경우 확인
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0' && !temp.empty()) {
            long long num = stoll(temp);
            if (prime(num))answer++;
            temp = "";
        }
        else temp += str[i];
    }

    // 왼쪽에 0이 있는 경우 + P자체가 소수인 경우 확인
    if (!temp.empty()) {
        long long num = stoll(temp);
        if (prime(num)) answer++;
    }

    return answer;
}


int solution(int n, int k) {
    int answer = -1;

    //n을 k진수로 변환
    string str = "";
    while (n) {
        str += to_string(n % k);
        n /= k;
    }
    str = string(str.rbegin(), str.rend());

    // 0이 있는 경우를 확인(p는 0을 포함하지 않음)
    // 확인 후 해당 숫자가 prime number인지 확인.
    answer = func1(str);

    return answer;
}