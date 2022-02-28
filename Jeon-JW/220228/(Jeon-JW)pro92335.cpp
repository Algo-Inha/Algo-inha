//https://programmers.co.kr/learn/courses/30/lessons/92335?language=cpp
//k�������� �Ҽ� ���� ���ϱ�
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

    // �����ʿ� 0�� �ִ� ��� Ȯ��
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0' && !temp.empty()) {
            long long num = stoll(temp);
            if (prime(num))answer++;
            temp = "";
        }
        else temp += str[i];
    }

    // ���ʿ� 0�� �ִ� ��� + P��ü�� �Ҽ��� ��� Ȯ��
    if (!temp.empty()) {
        long long num = stoll(temp);
        if (prime(num)) answer++;
    }

    return answer;
}


int solution(int n, int k) {
    int answer = -1;

    //n�� k������ ��ȯ
    string str = "";
    while (n) {
        str += to_string(n % k);
        n /= k;
    }
    str = string(str.rbegin(), str.rend());

    // 0�� �ִ� ��츦 Ȯ��(p�� 0�� �������� ����)
    // Ȯ�� �� �ش� ���ڰ� prime number���� Ȯ��.
    answer = func1(str);

    return answer;
}