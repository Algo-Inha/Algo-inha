//¿Ã¸²ÇÈ
//https://www.acmicpc.net/problem/8979

#include <iostream>
using namespace std;

int n, m;
int g[1001];
int s[1001];
int b[1001];
int res;

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int index;
        cin >> index;
        cin >> g[index] >> s[index] >> b[index];
    }
    for (int i = 1; i <= n; i++) {
        if (g[i] > g[m]) {
            res++;
        }
        else if (g[i] == g[m]) {
            if (s[i] > s[m]) {
                res++;
            }
            else if (s[i] == s[m]) {
                if (b[i] > b[m]) {
                    res++;
                }
            }
        }
    }

    cout << res + 1;
}