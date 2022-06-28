//https://programmers.co.kr/learn/courses/30/lessons/12936
//줄 서는 방법
#include <string>
#include <vector>

using namespace std;

//기본적인 개념
//n!는 n자리의 값을 생성하는 경우의 수이다.
//n-1!는 n-1자리의 값을 생성하는 경우의 수이다.

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> v;
    long long check = 1;
    for (int i = 1; i < n; i++) check *= i; // n개 중 1개를 선택하고 나머지의 경우의 수 -> (n-1)의 경우의 수
    for (int i = 1; i <= n; i++) v.push_back(i); // 1~n까지

    int len = n - 1;

    while (v.size() != 1) { // v에 하나가 남으면 멈추게
        for (int i = 1; i <= v.size(); i++) {
            //i는 1부터 시작하기 때문에 경우의 수로 자기보다 클 때 이전의 값을 넣어주면 된다.
            if (i * check >= k) { // 경우의 수로 자기보다 클 때
                answer.push_back(v[i - 1]); // 그 이전의 값을 뒤로 넣어준다.
                v.erase(v.begin() + i - 1); // v에선 지워줘
                // 원하는 번째의 경우의 수에 고려한 경우의 수를 빼준다.
                k -= (i - 1) * check; // k에선 그만큼의 경우의 수를 빼준다.
                // 하나를 골랐으니 n -> n-1의 경우의 수를 고려하는 셈이다.
                check /= (len--); // 길이의 경우의 수를 빼준다.
                break;
            }
        }
    }

    answer.push_back(v[0]); // 마지막값을 넣어준다.

    return answer;
}