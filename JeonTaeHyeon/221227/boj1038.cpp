//감소하는 수
//https://www.acmicpc.net/problem/1038
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<long long> res;

void dfs(long long digit, int cnt) {
    if (cnt > 10)
        return;
    res.push_back(digit);
    for (int i = 0; i < 10; i++) {
        if (digit % 10 > i) {
            dfs(digit * 10 + i, cnt + 1);
        }
    }
    return;
}
int main() {
    cin >> n;
    for (int i = 0; i < 10; i++) {
        dfs(i, 1);
    }
    sort(res.begin(), res.end());
    if (res.size() <= n) {
        cout << "-1" << endl;
    }
    else if (res.size() > n) {
        cout << res[n] << endl;
    }
}