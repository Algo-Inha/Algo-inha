//가장 큰 수
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    return a + b > b + a;
}//더했을때 더 큰놈으로 리턴

string solution(vector<int> numbers) {
    string save[100000];
    int i = 0;
    for (auto a : numbers) {
        save[i] = to_string(a);
        i++;
    }//스트링에 저장
    sort(save, save + i, comp);//정렬
    string answer = "";
    for (int j = 0; j < i; j++) {
        answer += save[j];
    }
    if (answer[0] == '0')return "0";//0으로 시작하면 0리턴
    return answer;
}