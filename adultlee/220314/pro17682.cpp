// 아이유 님 문제 다트!
// 문자열을 자르고 분기를 나누고 복잡하게 생각했는데 그냥 들어올때마다 곱해주면 될거 같다.

#include <iostream>
#include <cmath>
#include <string>
 using namespace std;

int solution(string dartResult) {
    int cal[4] = {0 , 0 , 0 , 0};
    int cal_cnt = 1;
    int answer = 0;
    
    for(int i=0; i< dartResult.length(); i++)
    {   
        if(dartResult[i] <='9' &&   '0' <= dartResult[i])
        {   if(dartResult[i] =='0' && dartResult[i-1] =='1')
            {
                cal[cal_cnt] = 10;
            }
            else{
            cal[cal_cnt] = dartResult[i] - '0'; // 이러면 쉽게  c -> int  치환이 가능하다

            }
            cout << dartResult[i] <<endl;
           
        }
        else if(dartResult[i] == 'S')
        {
            cal_cnt ++;
        }
         else if(dartResult[i] == 'D')
        {   
            cal[cal_cnt]  = pow(cal[cal_cnt],2) ;
             cal_cnt ++;
        }
         else if(dartResult[i] == 'T')
        {
            cal[cal_cnt] = cal[cal_cnt] * cal[cal_cnt] * cal[cal_cnt];
            cal_cnt ++;
        }
        else if(dartResult[i] == '#')
        {
            cal[cal_cnt-1] = -1 * cal[cal_cnt-1];
        }
        else if(dartResult[i] == '*')
        {   
            if(cal_cnt ==2)
            {
                 cal[cal_cnt-1] = 2 * cal[cal_cnt-1];
            }
            else{
                cal[cal_cnt-2] = 2 * cal[cal_cnt-2];
                cal[cal_cnt-1] = 2 * cal[cal_cnt-1];
            }
        }

    }
    answer = cal[1] + cal[2] +cal[3];
    cout << answer;
    return answer;
}

 int main()
 {
     string cc;
     cin >> cc;

     solution(cc);
 }