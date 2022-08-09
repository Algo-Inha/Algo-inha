//2개 이하로 다른 비트
//https://school.programmers.co.kr/learn/courses/30/lessons/77885?language=cpp
#include <string>
#include <vector>
#include<iostream>
#include <bitset>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (auto n : numbers) {
        if (n % 2 == 0) {
            answer.push_back(n + 1);
        }//짝수는 항상 +1이 들어감
        else {
            long long temp = n;
            string res = "";
            while (temp - 1 > 0) {
                if (temp % 2 == 0) {
                    res = '0' + res;
                }
                else {
                    res = '1' + res;
                }
                temp /= 2;
            }
            if (temp)res = '1' + res;
            //2진수로 만들기
            for (int i = res.size() - 1; i >= 0; i--) {
                if (res[i] == '0') {
                    res[i] = '1';
                    res[i + 1] = '0';
                    break;
                }//규칙 1 : 2진수 비트가 0이면 1로바꿔주고 하위비트를 0으로 바꿔줌
                if (i == 0) {
                    res = '1' + res;
                    res[1] = '0';
                    break;
                }//규칙 2 : 모든 비트가 1이라면 MSB1을 추가하고 하위비트를 0으로 바꿔줌
            }
            temp = 0;
            long long e = 1;
            for (int i = res.size() - 1; i >= 0; i--) {
                if ((res[i] - '0'))temp += e;
                e *= 2;
            }//다시 정수로 바꾸기
            answer.push_back(temp);
        }
    }

    return answer;
}