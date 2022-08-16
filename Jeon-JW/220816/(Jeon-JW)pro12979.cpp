//https://school.programmers.co.kr/learn/courses/30/lessons/12979
//������ ��ġ
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int index = 1;
    for (int i = 0; i < stations.size(); i++) {
        int width = stations[i] - w - index; // ����� ����
        if (width > 0) {
            if (width % (w * 2 + 1) == 0) {
                answer += width / (w * 2 + 1); // ������ �������� ���̷� �����ֱ�
            }
            else {
                answer += width / (w * 2 + 1) + 1;
            }
        }
        index = stations[i] + w + 1;// ���� ����� ������ ���ؼ� ���
    }
    // �������� ������� ���� ������ ���� ��� �̺κе� ������ֱ�.
    if (index <= n) {
        if ((n - index + 1) % (w * 2 + 1) == 0) {
            answer += (n - index + 1) / (w * 2 + 1);
        }
        else {
            answer += (n - index + 1) / (w * 2 + 1) + 1;
        }
    }

    return answer;
}
//��������µ� �� �������� �𸣰ڴ�.... level3�� ���� �׷��Ű��⵵..