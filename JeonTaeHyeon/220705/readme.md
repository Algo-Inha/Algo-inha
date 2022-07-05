
# 문제풀이
## 나무 자르기

https://www.acmicpc.net/problem/2805<!--line-->
 ```c++
#define size 1000000

using namespace std;
int s, b;
int n, m;
long long h[size];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> h[i];
	}
	sort(h, h+n);
	s = 0/*h[0]*/;
	b = h[n - 1];

	long long sum = 0;
	int res=0;
	int temp=0;
	while (s<=b) {
		temp = (s + b) / 2;
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (h[i] > temp) {
				sum += (h[i] - temp);
			}
		}
		if (sum < m) {
			b = temp-1;
		}
		else if (sum >= m) {
			res = temp;
			s = temp+1;
		}
		
	}
	cout << res;
}

 ```
어디 부분을 자르는 것이 가장 optimal한지 이분탐색을 이용하여 푸는 문제였습니다.  초기 s와 b값을 잘 설정해주는 것이 중요했던 것 같습니다.

## 시그널
https://www.acmicpc.net/problem/16113
```c++
string signal[20000];
string s;
int n;
int main() {
	cin >> n;
	cin>> s;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < n/5; j++)
		{
			signal[j] += s[i * n / 5 + j];
		}
	}
	int num;
	string decode;
	//for (int i = 0; i < n/5; i++)
	//{
	//	cout << signal[i];
	//}
	//cout << endl;
	for (int i = 0; i < n/5; i++)
	{
		if (signal[i] != ".....") {
			decode += signal[i];
		}
			if (i == n / 5 - 1||signal[i] == ".....") {
				//마지막에 공백없이 끝나는 경우를 대비하여 i == n / 5 - 1 의 경우 고려
			if (decode == "######...######")num = 0;
			if (decode == "#####")num=1;
			if (decode == "#.####.#.####.#")num=2;
			if (decode == "#.#.##.#.######")num=3;
			if (decode == "###....#..#####")num=4;
			if (decode == "###.##.#.##.###")num=5;
			if (decode == "######.#.##.###")num=6;
			if (decode == "#....#....#####")num=7;
			if (decode == "######.#.######")num=8;
			if (decode == "###.##.#.######")num=9;
			if (decode[0] == '#')cout << num;//모든 숫자는 #로 시작
			decode = "";
		}

	}
}
```
하나하나 처리를 해주는 것이 최선의 방법인가 고민해보았지만 더 좋은 방법을 찾기 못했습니다.

## 가장 큰 수
https://programmers.co.kr/learn/courses/30/lessons/42746
```c++
bool comp(string a, string b) {
    return a + b > b + a;
}//더했을때 더 큰놈으로 리턴

string solution(vector<int> numbers) {
    string save[100000];
    int i = 0;
    for (auto a : numbers) {
        save[i] = to_string(a);
        i++;
    }//스트링에 저장
    sort(save, save + i, comp);//정렬
    string answer = "";
    for (int j = 0; j < i; j++) {
        answer += save[j];
    }
    if (answer[0] == '0')return "0";//0으로 시작하면 0리턴
    return answer;
}
```
어떻게 푸는지 모르겠어서 다른 분 풀이를 살짝봤는데 comp함수를 생각해 낼 수 있다면 쉽게 풀 수 있었던 문제였던 것 같습니다. 

## 후보 추천하기

https://www.acmicpc.net/problem/1713
```c++
int n, r;
int recommend[101], when[101], cur;

int main() {

	cin >> n >> r;
	for (int i = 1; i <= r; ++i) {
		int vote;
		cin >> vote;
		if (recommend[vote] > 0) recommend[vote]++;
		else {
			if (cur < n) {
				recommend[vote]++;
				when[vote] = i;
				cur++;
			}
			else {
				int drop;
				int reco = INT_MAX;
				for (int i = 1; i <= 100; ++i) {
					if (!recommend[i]) continue;
					if (reco > recommend[i]) {
						drop = i;
						reco = recommend[i];
					}
					else if (reco == recommend[i]) {
						if (when[i] < when[drop]) drop = i;
					}
				}
				recommend[vote]++;
				when[vote] = i;
				recommend[drop] = 0;
				when[drop] = 0;
			}
		}
	}
	for (int i = 1; i <= 100; ++i)
		if (when[i]) cout << i << ' ';

	return 0;
}
```
추천수가 낮은 사람들 중 누가 더 오래됐나를 고려해주는 것이 중요했던 것 같습니다. 추천수와 언제 추천을 받았는지를 저장하는 배열을 선언하여 해결할 수 있었습니다.

## DFS와 BFS

https://www.acmicpc.net/problem/1260
```c++
int n, m, v;
vector<int> vec[1001];
int visit[1001];
queue<pair<int, int>> q;


void dfs(int x) {
	visit[x] = true;

	sort(vec[x].begin(), vec[x].end());
	cout << x << " ";
	for (int i = 0; i < vec[x].size(); i++) {
		if (!visit[vec[x][i]]) {
			visit[vec[x][i]] = true;
			dfs(vec[x][i]);
		}
	}

}

void bfs(int x) {
	visit[x] = true;
	queue<int> q;
	q.push(x);
	while (!q.empty()) {
		int xx = q.front();
		q.pop();
		cout << xx << " ";
		for (int i = 0; i < vec[xx].size(); i++) {
			if (!visit[vec[xx][i]]) {
				visit[vec[xx][i]] = true;
				q.push(vec[xx][i]);
			}
		}
	}

}

int main() {
	cin >> n >> m >> v;
	int num1, num2;

	for (int i = 0; i < m; i++) {
		cin >> num1 >> num2;
		vec[num1].push_back(num2);
		vec[num2].push_back(num1);
	}

	dfs(v);

	memset(visit, NULL, sizeof(visit));
	cout << endl;
	bfs(v);
}
```
bfs와 dfs의 개념과 방문순서를 다시 한 번 공부해볼 수 있는 문제였습니다. 기본적으로 오름차순으로 출력하기 위해 한번 정렬을 해주는 것을 조심하고 visit함수를 잘 초기화 해 주어 오류가 발생하지 않도록 해야했습니다.

