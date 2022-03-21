//달력
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int arr[367] = {0,}; //arr[1] 부터 시작합니다.

    cin >> N;
    for(int i=0; i< N; i++)
    {
        int temp_a, temp_b;
        cin >> temp_a >> temp_b;

        for(int j = temp_a; j<= temp_b; j++)
        {
            arr[j] ++ ;
        }
    }

    int max_cnt = -1;
    int cnt = 0;
    int ans = 0;
    for(int i=1; i<= 366; i++)
    {
       if(arr[i] > 0)
       {
           cnt ++;
           max_cnt =max(max_cnt,arr[i]);
       }
       if(arr[i-1] >0 && arr[i] == 0)
       {
           ans += max_cnt * cnt;
           max_cnt =-1;
           cnt =0;
       }
    }

    
    cout <<  ans <<endl;
}

// 크게 어려운 문제는 아니였다.
// 입력받을때 각 일정을 배열에 ++로 받고 연결된 일정을 처리하는 법을 고민할때
// 연결된 하나의 일정이 다른 연결된 일정을 처리할때 고려할 필요가 없어서 
//굳이 나눌 필요는 없다고 판단하게 되었다.
// 따라서 n 차 도는 시간동안 처리하여 바로 계산할 수 있었다.