
# 문제풀이
## 정사각형
https://www.acmicpc.net/problem/1485 
```c++
long long caldis(long long x1, long long y1,long long x2, long long y2) {

	return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		bool check = false;
		for (int i = 0; i < 4; i++)
		{
			cin >> c[i].first;
			cin >> c[i].second;
		}
		int cnt=0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++) {
				dis[cnt] = caldis(c[i].first, c[i].second, c[j].first, c[j].second);
				cnt++;
			}
		}

		sort(dis, dis + 6);

		if (dis[0] == dis[1] && dis[1] == dis[2] && dis[2] == dis[3] && dis[4] == dis[5])check = true;
		cout << check << endl;
	}
}
 ```
좌표 4개에서 나올 수 있는 선분 6개를 모두 구한 후 정렬하면 처음 4개의 값이 4변의 길이로 모두 같고 마지막 2개의 값이 대각선의 길이로 같으면 정사각형이 성립하는 것을 사용하여 풀었습니다. 생각보다 훨씬 어렵게 느껴졌습니다.


##  랭킹전 대기열
https://www.acmicpc.net/problem/20006
```c++
int countroom;//방의 수
int levelroom[301];//방의 레벨
pair<string, int>u;//유저 정보
map<string, int>user[301];//이름순 정렬
int p, m;

int main() {
	cin >> p >> m;

	for (int i = 0; i < p; i++)
	{
		cin >> u.second >> u.first;
		if (!countroom) {
			++countroom;
			levelroom[countroom] = u.second;
			user[countroom].insert(u);
		}
		else {
			for (int j = 1; j <= countroom; j++)
			{
				if ((u.second >= levelroom[j] - 10 && u.second <= levelroom[j] + 10) && user[j].size() < m) {
					user[j].insert(u);
					break;
				}
				else {
					if (j == countroom) {
						++countroom;
						levelroom[countroom] = u.second;
						user[countroom].insert(u);
						break;
					}
				}
			}
		}
	}
	for (int i = 1; i <=countroom ; i++)
	{
		if (user[i].size() == m) {
			cout << "Started!" << endl;
			for (const auto a : user[i]) {
				cout << a.second << " " << a.first << endl;
			}
		}
		else if (user[i].size() != m) {
			cout << "Waiting!" << endl;
			for (const auto a : user[i]) {
				cout << a.second << " " << a.first << endl;
			}
		}
	}

}
```
countroom이라는 변수와 countlevel이라는 변수를 사용하여 방의 수와 방에 입장할 수 있는 level을 저장하였습니다. map을 사용하여 이름을 사전순으로 출력할 수 있도록 하였습니다. 기본적으로 조건을 만족하면 방에 입장시키고, 만족하는 방이없으면 방을 새로 만들어서 입장하도록 하였습니다.

## 게임

https://www.acmicpc.net/problem/1072
```c++
int main() {
	cin >> x >> y;
	z = floor(y * 100 / x);
	if (z>=99)cout << "-1";
	else {		
		/*int start = 0;
		int end = Max;
		int result = -1;

		while (start<=end) {
			int mid = (start + end) / 2;
			long long compz = long long(100 * long long(y + mid) / long long (x + mid));
			
			cout << compz << endl;
			
			if (compz <= z) {
				result = mid +1;
				start = mid + 1;
			}
			else {
				end = mid -1;
			}
		}
		cout << result;*/

		int ans = (int)ceil((x * z + x - 100 * y) / (99 - z));
		cout << ans;
	}
}

```
이분탐색을 활용하여 풀고싶었는데 자꾸 예외가 발생하여 식을 유도해서 해결했습니다. 

## N과M(1)
//https://www.acmicpc.net/problem/15649
 ```c++
void back(int level) {
	if (level == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true;
			res[level] = num[i];
			back(level + 1);
			visit[i] = false;
		}

	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		num[i] = i;
	}

	back(0);

}
 ```
백 트렉킹을 이해하기에 좋은 문제인 것 같습니다.

## 배열 돌리기

https://www.acmicpc.net/problem/16926
 ```c++
void spin(int start, int xend, int yend) {

	for (int i = start; i < xend; i++)
	{
		int temp = map[start][start];
		map[start][start] = map[i + 1][start];
		map[i + 1][start] = temp;
	}
	for (int i = start; i < yend; i++)
	{
		int temp = map[start][start];
		map[start][start] = map[xend][i + 1];
		map[xend][i + 1] = temp;
	}
	for (int i = xend; i > start; i--)
	{
		int temp = map[start][start];
		map[start][start] = map[i - 1][yend];
		map[i - 1][yend] = temp;
	}
	for (int i = yend; i > start; i--)
	{
		int temp = map[start][start];
		map[start][start] = map[start][i - 1];
		map[start][i - 1] = temp;
	}

}


int main() {
	cin >> n >> m >> r;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}

	while (r--) {
		int comp = min(n, m);

		for (int i = 1; i <= comp - i; i++)
		{
			spin(i, n + 1 - i, m + 1 - i);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
 ```
모든 배열의 값들을 하나하나 돌려주는 작업을 해서 시간 초과가 날 수도 있겠다고 생각했는데 그렇진 않았습니다.
