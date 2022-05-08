//https://programmers.co.kr/learn/courses/30/lessons/43165
//Å¸°Ù ³Ñ¹ö
#include <string>
#include <vector>

using namespace std;
int answer = 0;
int targetTemp;

void dfs(int rst, int cnt, vector<int> numbers) {
    if (cnt == numbers.size()) {
        if (rst == targetTemp) answer++;
        return;
    }
    dfs(rst + numbers[cnt], cnt + 1, numbers);
    dfs(rst + (numbers[cnt] * -1), cnt + 1, numbers);
}

int solution(vector<int> numbers, int target) {
    targetTemp = target;
    dfs(numbers[0], 1, numbers);
    dfs(numbers[0] * -1, 1, numbers);

    return answer;
}