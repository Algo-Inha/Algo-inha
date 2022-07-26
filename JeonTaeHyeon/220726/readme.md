
# 문제풀이
## 크레인 인형뽑기 게임
https://school.programmers.co.kr/learn/courses/30/lessons/64061
 ```c++
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack <int>basket;
    int row = board.size();

    for (int i = 0; i < moves.size(); i++) {
        for (int j = 0; j < row; j++) {
            if (board[j][moves[i] - 1]) {
                if (!basket.empty() && basket.top() == board[j][moves[i] - 1]) {
                    basket.pop();
                    answer += 2;
                }
                else {
                    basket.push(board[j][moves[i] - 1]);
                }
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }

    return answer;
}
 ```
문제 자체가 아주 어렵진 않았지만 지난 번에도 문제였던 비어있는 스택의 top을 참조하는 오류를 범하고 문제를 제대로 읽지않아 moves의 index가 0부터 시작한다고 생각하고, 인형이 터질때 한번에 1개씩 터진다고 생각해서 이것저것 고치느라 많이 고생했습니다. 
>앞으로 문제를 잘 읽겠습니다.


## 다리놓기
https://www.acmicpc.net/problem/1010
```c++
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		dp[1][1] = 1;
		dp[1][2] = 2;
		dp[2][2] = 1;
		dp[2][3] = 3;

		for (size_t i = 1; i <= 30; i++)
		{
			dp[1][i] = i;
		}
		for (int i = 1; i <= 30; i++)
		{
			for (int j = 1; j <= 30; j++)
			{
				if (!dp[i][j])dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
			}
		}

		cout << dp[n][m] << "\n";
	}
}
```
예전에 풀어봤던 문제라 쉽게 풀 수 있을줄 알았는데 생각보다 DP식을 떠올리기가 쉽지가 않았습니다. 나중에 조합식으로도 한번 도전해보겠습니다.



## 기타리스트
https://www.acmicpc.net/problem/1495
```c++
//void back(int sum, int cur) {
//	if (sum<0 || sum>m) {
//		return;
//	}
//	if (cur == n) {
//		res =max(res, sum);
//		return;
//	}
//	back(sum + vol[cur], cur + 1);
//	back(sum - vol[cur], cur + 1);
//}
//
//
//int main() {
//	cin >> n >> s >> m;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> vol[i];
//	}
//	back(s, 0);
//	cout << res;
//}


int main() {
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> vol[i];
	}

	dp[0][s] = true;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (dp[i - 1][j]) {
				if (j + vol[i] <= m)dp[i][j + vol[i]] = true;
				if (j - vol[i] >= 0)dp[i][j - vol[i]] = true;
			}
		}
	}
	//음량을 0에서 1000까지 펼쳐놓고 해당 음량으로 이동가능하면 true아니면 false;
	for (int i = 0; i <= 1000; i++)
	{
		if (dp[n][i] == true)res = i;
	}//true가 있으면 중간에 끊기지 않고 음량을 조절할 수 있음.
	cout << res;
}
```
백트렉킹으로도 최대한 타이트하게 구현하면 시간초과가 안날것이라고 생각했는데 전혀아니었습니다. DP로 해결하였는데 DP식자체는 백트렉킹이 작동하는 방법과 유사하게 구현하였습니다. 

##  리모컨

https://www.acmicpc.net/problem/1107
```c++
int main() {
	cin >> n >> m;
	for (int i = 0; i < 10; i++)
	{
		btn[i] = true;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> broken;
		btn[broken] = false;
	}
	res = abs(100 - n);//시작이 100
	for (int i = 0; i <= 999999; i++)
	{
		int possible = true;
		string str = to_string(i);
		int size = str.size();
		for (int j = 0; j < size; j++)
		{
			if (!btn[str[j]-'0']) {//고장난 숫자있으면 건너뛰기
				possible = false;
				break;
			}
		}
		if (possible) {
			int temp = abs(n - i);
			res = min(res, temp + size);
		}
	}
	cout << res;
}
```
너무 나이브하게 해서 혹시 시간초과가 날까 걱정했는데 다행이 시간초과는 나지 않았습니다. 1부터 999999까지의 모든 경우의 수를 고려하여 그중 가장 적게 터치할 수 있는 값을 res에 저장하는 방법을 사용했는데, 좀 더 고민해보면 더 빠른 코드를 찾을 수 있을 것 같습니다.


## 킹

https://www.acmicpc.net/problem/1063
```c++
void move(int x, int y, string s) {
	if (s == "R"&&y+1<8) {
		if (map[x][y + 1])move(x, y + 1, s);
		//돌멩이가 앞에있으면 move한번더 호출
		if (map[x][y + 1])return;
		//돌멩이를 움직였는데 여전히 앞에 돌멩이가 있으면 체스판 끝임
		map[x][y + 1] = map[x][y];
		map[x][y] = false;
		dy = y + 1;
		//그게 아니면 킹 움직이기
	}
	if (s == "T"&&x-1>=0) {
		if (map[x-1][y])move(x-1, y, s);
		if (map[x-1][y])return;
		map[x-1][y] = map[x][y];
		map[x][y] = false;
		dx = x - 1;
	}
	if (s == "L"&&y-1>=0) {
		if (map[x][y-1])move(x , y-1, s);
		if (map[x][y-1])return;
		map[x ][y-1] = map[x][y];
		map[x][y] = false;
		dy = y - 1;
	}
	if (s == "B"&&x+1<8) {
		if (map[x+1][y])move(x+1, y, s);
		if (map[x+1][y] )return;
		map[x+1][y] = map[x][y];
		map[x][y] = false;
		dx = x + 1;
	}
	if (s == "RT"&&x-1>=0&&y+1<8) {
		if (map[x-1][y + 1])move(x-1, y + 1, s);
		if (map[x-1][y + 1])return;
		map[x-1][y + 1] = map[x][y];
		map[x][y] = false;
		dx = x - 1; dy = y + 1;
	}
	if (s == "LT" && x - 1 >= 0 && y -1 >=0) {
		if (map[x-1][y - 1])move(x-1, y - 1, s);
		if (map[x-1][y - 1])return;
		map[x-1][y - 1] = map[x][y];
		map[x][y] = false;
		dx = x - 1; dy = y - 1;
	}
	if (s == "RB" && x + 1 < 8 && y + 1 < 8) {
		if (map[x + 1][y + 1])move(x + 1, y + 1, s);
		if (map[x + 1][y + 1] )return;
		map[x + 1][y + 1] = map[x][y];
		map[x][y] = false;
		dx = x + 1; dy = y + 1;
	}
	if (s == "LB" && x + 1 < 8 && y - 1 >= 0) {
		if (map[x + 1][y - 1] )move(x + 1, y - 1, s);
		if (map[x + 1][y - 1])return;
		map[x + 1][y - 1] = map[x][y];
		map[x][y] = false;
		dx = x + 1; dy = y - 1;
	}
}



int main() {
	cin >> init;
	map[8 - init[1] + '0'][init[0] - 'A'] = 1;
	dx = 8 - init[1] + '0';
	dy = init[0] - 'A';
	cin >> init;
	map[8 - init[1] + '0'][init[0] - 'A'] = 2;
	cin >> num;
	//스트링좌표를 정수좌표로 변환
	for (int i = 0; i < num; i++)
	{
		cin >> m;
		move(dx,dy, m);

	}
	
	for (int  i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{

			if (map[i][j] == 1) {
				king += (j + 'A'); 
				king+= (8-i + '0');
			}
			if (map[i][j] == 2) {
				stone += (j + 'A'); 
				stone+= (8-i + '0');
			}
		}
		
	}
	cout << king << "\n" << stone;
}
```
첫 바늘을 잘못꿰서 생각보다 코드가 너무 길어졌습니다. 다음부터는 중복되는 코드도 최대한 줄여 리팩토링해보겠습니다.

