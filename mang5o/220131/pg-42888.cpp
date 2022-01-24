// https://programmers.co.kr/learn/courses/30/lessons/42888

#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}


vector<string> solution(vector<string> record) {
    vector<string> answer;
    queue<pair<string,bool>> record_log;
    map<string,string> map_convert; // <uid, nickname>
    string tmp_str;
    
    vector<string> tmp_splited;
    for(int i = 0; i<record.size(); i++){
        tmp_splited = split(record[i], ' ');
        if(tmp_splited[0][0]=='E'){
            record_log.push(make_pair(tmp_splited[1], true));
            map_convert.erase(tmp_splited[1]);
            map_convert.insert(pair<string, string>(tmp_splited[1], tmp_splited[2]));
        }else if(tmp_splited[0][0]=='L'){
            record_log.push(make_pair(tmp_splited[1], false));
        }else{
            map_convert.erase(tmp_splited[1]);
            map_convert.insert(pair<string, string>(tmp_splited[1], tmp_splited[2]));
        }
    }
    while(!record_log.empty()){
        tmp_str = map_convert[record_log.front().first] + "님이 ";
        if(record_log.front().second){
            tmp_str+= "들어왔습니다.";
        }else{
            tmp_str+= "나갔습니다.";
        }
        answer.push_back(tmp_str);
        record_log.pop();
    }
    return answer;
}

int main(){
    vector<string> input;
    input.push_back("Enter uid1234 Muzi");
    input.push_back("Enter uid4567 Prodo");
    input.push_back("Leave uid1234");
    input.push_back("Enter uid1234 Prodo");
    input.push_back("Change uid4567 Ryan");

    vector<string> result = solution(input);
    cout<<"result size : "<<result.size()<<endl;
    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<endl;
    }
    return 0;
}