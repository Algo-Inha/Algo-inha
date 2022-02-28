//https://programmers.co.kr/learn/courses/30/lessons/72411
// 메뉴 리뉴얼


#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> FoodMaps[11];
int MaxCnt[11] = { 0 };

void comb(string str, int pos, string candi) {
    if (pos >= str.length()) {
        int len = candi.length();
        if (len >= 2) {
            FoodMaps[len][candi]++; // candi key로 접근해서 value증가 이러면 알아서 값을 대입해준다
            MaxCnt[len] = max(MaxCnt[len], FoodMaps[len][candi]);
        }
        return;
    }

    // 조합
    comb(str, pos + 1, candi + str[pos]);
    comb(str, pos + 1, candi);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for (auto str : orders) {
        sort(str.begin(), str.end());
        comb(str, 0, "");
    }

    vector<string> answer;
    for (int len : course) {
        for (auto item : FoodMaps[len]) { // item은 pair
            if (item.second >= 2 && item.second == MaxCnt[len]) {
                answer.push_back(item.first);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}