//https://programmers.co.kr/learn/courses/30/lessons/42885
//구명보트
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0;
    int idx = 0;
    for (;;) {
        if (people.size() <= idx) break;
        int back = people.back();
        people.pop_back();
        if (people[idx] + back <= limit) {
            answer++;
            idx++;
        }
        else answer++;
    }
    return answer;
}