//https://programmers.co.kr/learn/courses/30/lessons/43238?language=cpp
//�Ա��ɻ�
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long left = (long long)times[0]; // ���� ����(ª��) �ɸ��� �ð�
    long long right = (long long)times[times.size() - 1] * n; // ���� ������ �ɸ��� �ð� * ����� �� -> ���� �����ɸ��� ���
    long long answer = right; // 
    while (left <= right) { // left�� right�����Ǵ� �κ�
        long long mid = (right + left) / 2; // ��� �κ�
        long long pass = 0;

        for (int i = 0; i < times.size(); i++) {
            pass += mid / (long long)times[i];
            //���� ����� �ð���� ������ �����ش�.
            //mid�� ������� �� �� �ɸ��� �ð�.
        }
        //�ش� �ð� ���� ��� ������� �ɻ簡 �������� ����
        if (pass >= n) { // pass�� �ο����� �� ����� �� ���� ��
            right = mid - 1; // right�� ���� ���̱�
            if (mid <= answer) answer = mid;
        }
        //�ȵǸ� ������ ����� mid�� �÷��ش�.
        else left = mid + 1;
    }

    return answer;
}