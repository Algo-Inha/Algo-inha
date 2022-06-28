//https://programmers.co.kr/learn/courses/30/lessons/12936
//�� ���� ���
#include <string>
#include <vector>

using namespace std;

//�⺻���� ����
//n!�� n�ڸ��� ���� �����ϴ� ����� ���̴�.
//n-1!�� n-1�ڸ��� ���� �����ϴ� ����� ���̴�.

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    long long check = 1;
    for (int i = 1; i < n; i++) check *= i; // n�� �� 1���� �����ϰ� �������� ����� �� -> (n-1)�� ����� ��
    for (int i = 1; i <= n; i++) v.push_back(i); // 1~n����

    int len = n - 1;

    while (v.size() != 1) { // v�� �ϳ��� ������ ���߰�
        for (int i = 1; i <= v.size(); i++) {
            //i�� 1���� �����ϱ� ������ ����� ���� �ڱ⺸�� Ŭ �� ������ ���� �־��ָ� �ȴ�.
            if (i * check >= k) { // ����� ���� �ڱ⺸�� Ŭ ��
                answer.push_back(v[i - 1]); // �� ������ ���� �ڷ� �־��ش�.
                v.erase(v.begin() + i - 1); // v���� ������
                // ���ϴ� ��°�� ����� ���� ����� ����� ���� ���ش�.
                k -= (i - 1) * check; // k���� �׸�ŭ�� ����� ���� ���ش�.
                // �ϳ��� ������� n -> n-1�� ����� ���� ����ϴ� ���̴�.
                check /= (len--); // ������ ����� ���� ���ش�.
                break;
            }
        }
    }

    answer.push_back(v[0]); // ���������� �־��ش�.

    return answer;
}