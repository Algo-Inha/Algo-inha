#include<iostream>
#include<iostream>
#include<string>
//Àý´ñ°ª Èü
#include<cstdlib>
#include<queue>
#include<set>
#include<vector>
#include<algorithm>
#include<string.h>
#include<cmath>

using namespace std;

priority_queue <int> po;
priority_queue <int> ne;
int n; int number;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> number;
		if (number > 0) {
			po.push(-number);
		}//
		else if (number < 0){
			ne.push(number);
		}
		else {
			if (po.empty() && ne.empty())cout << "0\n";
			else if (po.empty()) {
				cout << ne.top()<<endl;
				ne.pop();
			}
			else if (ne.empty()) {
				cout << -po.top() << endl;
				po.pop();
			}
			else {
				if (po.top() > ne.top()) {
					cout << -po.top() << endl;
					po.pop();
				}
				else {
					cout << ne.top() << endl;
					ne.pop();
				}
			}
			
		}
	}
}