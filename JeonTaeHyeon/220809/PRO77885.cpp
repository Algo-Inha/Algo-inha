//2�� ���Ϸ� �ٸ� ��Ʈ
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
        }//¦���� �׻� +1�� ��
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
            //2������ �����
            for (int i = res.size() - 1; i >= 0; i--) {
                if (res[i] == '0') {
                    res[i] = '1';
                    res[i + 1] = '0';
                    break;
                }//��Ģ 1 : 2���� ��Ʈ�� 0�̸� 1�ιٲ��ְ� ������Ʈ�� 0���� �ٲ���
                if (i == 0) {
                    res = '1' + res;
                    res[1] = '0';
                    break;
                }//��Ģ 2 : ��� ��Ʈ�� 1�̶�� MSB1�� �߰��ϰ� ������Ʈ�� 0���� �ٲ���
            }
            temp = 0;
            long long e = 1;
            for (int i = res.size() - 1; i >= 0; i--) {
                if ((res[i] - '0'))temp += e;
                e *= 2;
            }//�ٽ� ������ �ٲٱ�
            answer.push_back(temp);
        }
    }

    return answer;
}