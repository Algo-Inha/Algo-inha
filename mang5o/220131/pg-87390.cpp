// https://programmers.co.kr/learn/courses/30/lessons/87390

#include <iostream>

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    int tmp_ans, tmp_mod, tmp_div;
    for(long long i = left; i<=right; i++){
        tmp_mod = i%n;
        tmp_div = i/n;
        if(tmp_mod <= tmp_div){
            tmp_ans = tmp_div + 1;
        }else{
            tmp_ans = tmp_mod + 1;
        }
        answer.push_back(tmp_ans);
    }

    return answer;
}

int main(){
    int n = 4;
    long long left = 7;
    long long right = 14;
    vector<int> result = solution(n, left, right);
    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
}