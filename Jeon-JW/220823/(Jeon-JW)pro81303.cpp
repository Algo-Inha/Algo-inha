//https://school.programmers.co.kr/learn/courses/30/lessons/81303
//표 편집
#include <string>
#include <vector>
#include <stack>
#include<string>

using namespace std;

int pivot;
stack<int> s;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    pivot = k;

    vector<pair<int, int>> v(n);
    vector<int> visit(n, 0);

    v[0].first = -1;
    v[0].second = 1;
    v[n - 1].first = n - 2;
    v[n - 1].second = -1;

    for (int i = 1; i < n - 1; i++) {
        v[i].first = i - 1;
        v[i].second = i + 1;
    }

    //for (int i = 0; i < n; i++) {
    //    cout << v[i].first << " " << v[i].second << endl;
    //}

    int top = n - 1, bottom = 0;

    int temp;
    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'U') { //"U X": 현재 선택된 행에서 X칸 위에 있는 행을 선택합니다. - 
            //temp = cmd[i][2] - '0';
            temp = stoi(cmd[i].substr(2));

            while (temp) {
                pivot = v[pivot].first;
                temp--;
            }
        }
        else if (cmd[i][0] == 'D') {//"D X": 현재 선택된 행에서 X칸 아래에 있는 행을 선택합니다. + 
            //temp = cmd[i][2] - '0';
            temp = stoi(cmd[i].substr(2));

            while (temp) {
                pivot = v[pivot].second;
                temp--;
            }
        }
        else if (cmd[i][0] == 'C') {//"C" : 현재 선택된 행을 삭제한 후, 바로 아래 행을 선택합니다. 단, 삭제된 행이 가장 마지막 행인 경우 바로 윗 행을 선택합니다.
            s.push(pivot);
            //cout << "ok" << endl;

            if (v[pivot].second == -1) { // 맨뒤일경우
                //cout << "ok1" << endl;
                int tempnum = v[pivot].first;
                visit[pivot] = 1; // 없앤거 인증.
                v[tempnum].second = -1;
                pivot = tempnum;
                top = tempnum;
            }
            else if (v[pivot].first == -1) { // 맨앞일경우
                //cout << "ok2" << endl;

                int tempnum = v[pivot].second;
                visit[pivot] = 1;
                v[tempnum].first = -1;
                pivot = tempnum;
                bottom = tempnum;
            }
            else {
                //cout << "ok3" << endl;

                int prev = v[pivot].first;
                int next = v[pivot].second;
                visit[pivot] = 1;
                v[prev].second = next;
                v[next].first = prev;
                pivot = next;
            }

        }
        else {//"Z" : 가장 최근에 삭제된 행을 원래대로 복구합니다. 단, 현재 선택된 행은 바뀌지 않습니다.
            int tempnum = s.top();
            s.pop();
            if (tempnum < bottom) {
                v[bottom].first = tempnum;
                visit[tempnum] = 0;
                v[tempnum].first = -1;
                v[tempnum].second = bottom;

                bottom = tempnum;
            }
            else if (tempnum > top) {
                v[top].second = tempnum;
                visit[tempnum] = 0;
                v[tempnum].first = top;
                v[tempnum].second = -1;

                top = tempnum;
            }
            else {
                int prev, next;
                int j = 0;
                for (;;) {
                    j++;
                    if (!visit[tempnum - j] || tempnum - j < 0) {
                        break;
                    }
                }
                int k = 0;
                for (;;) {
                    k++;
                    if (!visit[tempnum + k] || tempnum + k >= n) {
                        break;
                    }
                }
                prev = tempnum - j;
                next = tempnum + k;

                visit[tempnum] = 0;
                v[tempnum].first = prev;
                v[tempnum].second = next;
                v[prev].second = tempnum;
                v[next].first = tempnum;
            }
        }

        /*for (int i = 0; i < n; i++) {
            if (visit[i]) {
                answer += "X";
            }
            else answer += "O";
        }*/
        //cout << cmd[i] << " " << pivot << " " << answer << endl;
        //answer = "";

    }

    for (int i = 0; i < n; i++) {
        if (visit[i]) {
            answer += "X";
        }
        else answer += "O";
    }


    return answer;
}