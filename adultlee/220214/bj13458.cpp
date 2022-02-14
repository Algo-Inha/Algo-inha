// https://www.acmicpc.net/problem/13458
// 시험감독

#include<iostream>
#include<cstdio>
 
using namespace std;
 
  int n;      //시험장 수
  int room[100001];


  int major;  
  int sub;    

int main(){
  
    cin >> n;
 
 
    for(int i=0; i<n; i++){
        cin >> room[i]; 
    }

    cin >> major;
    cin >> sub;

   long long cnt=0;  //count.

    for(int i=0; i<n; i++){
        room[i] -= major;   //각 시험장마다 주감독을 한번 씩 빼줍니다
        cnt++;

        if(room[i] > 0) { 
            if(room[i] % sub == 0)  //남은 room의 인원이 나누어 떨어지는 지 확인합니다
            { 
                cnt += (room[i] / sub); // 나누어 떨어진다면 cnt는 딱 맞추어 몫을 가져갑니다
            }else
            {
                cnt += (room[i] / sub)+1; // 나누어 떨어지지 않는다면 cnt 는 하나더 증가합니다
            }
        }
    }
 
 
    cout << cnt;
 
    return 0;

}