//https://school.programmers.co.kr/learn/courses/30/lessons/67256
//키패드 누르기
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int arr[2][10] = { // 키패드 좌표
    {3,0,0,0,1,1,1,2,2,2},
    {1,0,1,2,0,1,2,0,1,2}
};
bool r;
int rh[2] = { 3,2 };
int lh[2] = { 3,0 };

string solution(vector<int> numbers, string hand) {
    string answer = "";
    if (hand[0] == 'r') r = 1; // 오른손잡이

    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if (num % 3 == 1) { // 1 4 7
            answer += "L";
            lh[0] = arr[0][num];
            lh[1] = arr[1][num];
        }
        else if (num % 3 == 0 && num != 0) {// 3 6 9
            answer += "R";
            rh[0] = arr[0][num];
            rh[1] = arr[1][num];
        }
        else { // 2 5 8 0
            int llen = abs(lh[0] - arr[0][num]) + abs(lh[1] - arr[1][num]);
            int rlen = abs(rh[0] - arr[0][num]) + abs(rh[1] - arr[1][num]);

            if (llen == rlen) {
                if (r) {
                    answer += "R";
                    rh[0] = arr[0][num];
                    rh[1] = arr[1][num];
                }
                else {
                    answer += "L";
                    lh[0] = arr[0][num];
                    lh[1] = arr[1][num];
                }
            }
            else if (llen < rlen) {
                answer += "L";
                lh[0] = arr[0][num];
                lh[1] = arr[1][num];
            }
            else {
                answer += "R";
                rh[0] = arr[0][num];
                rh[1] = arr[1][num];
            }
        }
    }

    return answer;
}