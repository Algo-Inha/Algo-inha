// https://programmers.co.kr/learn/courses/30/lessons/42747

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_func(int a, int b) {
    return a > b;
}


int solution(vector<int> citations) { // committed function
    sort(citations.begin(), citations.end(), compare_func);
    int now_h_index = 0;
    bool now_h_flag;
    for(int i = 1; i<citations.size()+1; i++){
        now_h_flag = true;
        for(int j = 0; j<i; j++){
            if(citations[j]<i){
                now_h_flag = false;
            }
        }
        if(now_h_flag){
            now_h_index = i;
        }
    }
    return now_h_index;
}


int main()// test main function
{
    vector<int> test_data;
    int input_arr[] = {5,5,5,5,5};
    test_data.assign(input_arr, input_arr+5);
    cout<<solution(test_data);
}