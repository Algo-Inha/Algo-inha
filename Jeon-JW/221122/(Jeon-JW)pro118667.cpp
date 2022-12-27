//https://school.programmers.co.kr/learn/courses/30/lessons/118667
//�� ť �� ���� �����
#include <string>
#include <vector>

using namespace std;

long long sum1, sum2;
int q_size;

int func(int index) {
    if (index + 1 >= 2 * q_size) {
        return 0; // �ε����� �迭���� ũ�� �� ������.
    }
    else {
        return index + 1;
    }

}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    for (int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    q_size = queue1.size();

    int q11 = 0, q12 = q_size - 1; // queue1�� ���� �� �Ǻ�
    int q21 = q_size, q22 = 2 * q_size - 1; // queue2�� ���� �� �Ǻ�

    //�� ���� ��ġ��.
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());

    while (answer <= 4 * q_size) {
        //q1�� q2���� �� Ŭ���.
        if (sum1 > sum2) {
            sum1 -= queue1[q11];
            sum2 += queue1[q11];

            q11 = func(q11);
            q22 = func(q22);
        }
        //q1���� q2�� �� Ŭ���.
        else if (sum1 < sum2) {
            sum2 -= queue1[q21];
            sum1 += queue1[q21];

            q21 = func(q21);
            q12 = func(q12);
        }
        //���� �Ȱ��� ���.
        else return answer;

        answer++;
    }

    //q_size*4�� ���ߵ���.
    return -1;
}