//https://programmers.co.kr/learn/courses/30/lessons/42746?language=cpp
//가장 큰 수
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//vector<int> high_numbers;
vector<string> number;

bool cmp(const string& a, const string& b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    //int vec_len = numbers.size();

    /*
    for(int i=0;i<vec_len; i++){
        int temp = numbers[i];
        for(;;){
            if(temp / 10 == 0) break;
            temp = temp / 10;
        }
        high_numbers.push_back(temp);
    }
    sort(high_numbers.begin(), high_numbers.end());
    */

    for (int i = 0; i < numbers.size(); i++) number.push_back(to_string(numbers[i]));

    sort(number.begin(), number.end(), cmp);

    for (int i = 0; i < number.size(); i++) {
        answer += number[i];
    }

    if (number[0] == "0") return "0";

    return answer;
}