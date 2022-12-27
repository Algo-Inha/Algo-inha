//https://school.programmers.co.kr/learn/courses/30/lessons/118667
//두 큐 합 같게 만들기
#include <string>
#include <vector>

using namespace std;

long long sum1, sum2;
int q_size;

int func(int index) {
    if (index + 1 >= 2 * q_size) {
        return 0; // 인덱스가 배열보다 크면 맨 앞으로.
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

    int q11 = 0, q12 = q_size - 1; // queue1의 시작 끝 피봇
    int q21 = q_size, q22 = 2 * q_size - 1; // queue2의 시작 끝 피봇

    //두 벡터 합치기.
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());

    while (answer <= 4 * q_size) {
        //q1이 q2보다 더 클경우.
        if (sum1 > sum2) {
            sum1 -= queue1[q11];
            sum2 += queue1[q11];

            q11 = func(q11);
            q22 = func(q22);
        }
        //q1보다 q2가 더 클경우.
        else if (sum1 < sum2) {
            sum2 -= queue1[q21];
            sum1 += queue1[q21];

            q21 = func(q21);
            q12 = func(q12);
        }
        //둘이 똑같을 경우.
        else return answer;

        answer++;
    }

    //q_size*4를 못견딘경우.
    return -1;
}