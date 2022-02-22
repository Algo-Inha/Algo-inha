// 이항계수 2
#include <iostream>

using namespace std;

int main()
{
    int N;
    int K;
    int answer;
    int arr[1001][1001];
    cin >> N >> K;

    arr[1][0] =1;
    arr[1][1] =1;
    arr[2][0] =1;
    arr[2][1] =2;
    arr[2][2] =1;

    for(int i =3 ; i <= N; i++)
    {
        for(int j=0; j <= i; j++)
        {   
            if((j == 0) || (j == i))
            {
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) %10007;
            }
        }
    }


    cout << arr[N][K];
}


//틀린 이유 i 랑 j 랑 자꾸 중복해서 겹쳐 씀... 바보 같음
// 10007을 마지막에 나눌 필요 없음 그때그때 나누어 두면 됨
// 꼭 괄호로 묶어두자... ㅂㄷㅂㄷ