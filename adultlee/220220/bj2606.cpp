// https://www.acmicpc.net/problem/2606

// 바이러스 ,  실패

#include <iostream>
#include <vector>

using namespace std;

// vector <pair<int,int>> line; 요렇게 해보려고 했으나 방향전환!!

bool pair_pc[101][101];

vector <int> answer;

int main()
{   
    int pc_cnt;
    cin >> pc_cnt;

    int pair_pc_cnt;
    cin >> pair_pc_cnt;
    answer.push_back(1);

    for(int i=0; i< pair_pc_cnt; i++)
    {   
        int temp_a =0;
        int temp_b =0;
        cin >> temp_a >> temp_b;

        int answer_cnt = answer.size();
        if(temp_a ==1 || temp_b==1)
        {   
            pair_pc[temp_a][temp_b] = true;
            if(temp_a ==1)
            {   
                int answer_tmp_cnt =0;
                for(int j = 0; j < answer_cnt; j++)
                {   
                    if(temp_b == answer[j])
                    {
                        answer_tmp_cnt++;
                    }
                    
                }
                if(answer_tmp_cnt ==0)
                {
                    answer.push_back(temp_b);
                }
            }
            if(temp_b ==1)
            {   
                int answer_tmp_cnt =0;
                for(int j = 0; j < answer_cnt; j++)
                {   
                    if(temp_a == answer[j])
                    {
                        answer_tmp_cnt++;
                    }
                    
                }
                if(answer_tmp_cnt ==0)
                {
                    answer.push_back(temp_a);
                }
            }
        }
    }

    for(int i =0; i< answer.size(); i++)
    {
        cout << answer[i];
    }


}
 // 실패 버전.... 이딴 방식의 접근은 아무런 의미가 없을거라고 생각... dfs 로풀어야 겠다고 다짐함
