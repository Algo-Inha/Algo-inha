// 아니 queue 로 만들었는데 시간초과가 나는군요 역시... 조금 너무 하다 싶었습니다 ㅠ
// 첫번째 시도는 모든 배열을  R 을 받을때마다 뒤집으며 시도하는것 이었습니다. 당연히  시간초과가 났구... 
// 자존심이 좀 상하지만 deque 를 사용하라는 글을 보고 하게 되었습니다

#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;

    while(T--)
    {
        string testFunc;
        cin >> testFunc;

        int numberCount;
        cin >> numberCount;

        string numArr;
        cin >> numArr;

        deque<int> tempDq;
        string tmp= "";

        for(int i=0; i< numArr.size(); i++)
        {   

            if(numArr[i] =='[')
            {
                continue;
            }
            else if( '0' == numArr[i] || '1' == numArr[i] || '2' == numArr[i] || '3' == numArr[i] || '4' == numArr[i]
                  || '5' == numArr[i] || '6' == numArr[i] || '7' == numArr[i] || '8' == numArr[i] || '9' == numArr[i])
            // else if (numArr[i] <= '9' &&  '0' <= numArr[i] )
            {
                
                tmp+=numArr[i];
             
            }
            else if( numArr[i]==']' || numArr[i]==',')
            {
                if(!tmp.empty())
                {
                    tempDq.push_back(stoi(tmp));
                    tmp.clear();
                }
            }
        }

        bool direction = true;
        bool isEmpty = false;
        for(int i =0; i < testFunc.size(); i++)
        {
            if(testFunc[i] == 'R')
            {
                direction = !direction;
            }
            else{
                if(!tempDq.empty())
                {
                    if(direction)
                    {
                        tempDq.pop_front();
                    }else{
                        tempDq.pop_back();
                    }
                }else{
                    isEmpty = true;
                    cout<< "error"<<endl;
                    break;
                }
            }
        }
        if(!isEmpty)
        {
            cout<<"[";
            if(direction)
            {
                while(!tempDq.empty())
                {
                     cout << tempDq.front();
                     tempDq.pop_front();
                     if(!tempDq.empty())
                     {
                         cout << ",";
                     }
                }
            }
            else{
                while(!tempDq.empty())
                {
                     cout << tempDq.back();
                     tempDq.pop_back();
                     if(!tempDq.empty())
                     {
                         cout << ",";
                     }
                }
            }
            cout <<"]"<<endl;
        }


    }
 return 0;
}