#include <iostream> 
#include <cmath> 
#include <string> 
#include <stdio.h>

using namespace std;

int N;

void hanoi(int n, int start, int temp, int end)
{
    if(n ==1)
    {
        cout << start << " " << end <<endl;
    }
    else{
        hanoi(n-1,start,end,temp);
        cout << start << " " << end<<endl;
        hanoi(n-1,temp,start,end);
    }
}

int main()
{
    cin >> N;
    long long answer= pow(2,N);
    cout << answer-1 << endl;

    if(N <= 20)
    {
        hanoi(N,1,2,3);
    }
    return 0;
}
