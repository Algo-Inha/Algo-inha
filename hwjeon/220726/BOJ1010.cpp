//�ٸ�����
#include<iostream>
#include<math.h>
using namespace std;

int result;

long long comb(int k,int j) {
	int numer = 1;
	long long result=1;
	for ( int a=j ; a>j-k ;a--)
	{
		result *= a;
		result /= numer++; //�и���� ���ڵ��� ���ϸ� ũ�⿡ ���� �����÷ο� �߻� 
	}
	return result;
}

int main() {
	int t, N, M, ans;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> N >> M;
		ans = comb(N,M);
		cout << ans << endl;
	}
}