
# 바이러스
### bj2606
+ `재귀`
```c++
vector<int> com[101];
bool check[101];

int ans;

void recur(int num) {
	check[num] = 1;
	ans++;
	//cout << num << endl;
	for (int i = 0; i < com[num].size(); i++) {
		if (check[com[num][i]] == 0) {
			recur(com[num][i]);
		}
	}
}
```
> + dom vector에 값을 저장해서 받은 뒤 재귀를 통해서 DFS로 찾아가는 형식으로 구현하였다.
- 크게 어려움이 없는 문제라 생각된다.

# 감시카메라
### bj5584
- `구현`
```c++
	for (int i = 0; i < n; i++) {
		cin >> temp_y >> temp_x;
		cow.push_back(make_pair(temp_y, temp_x));
		//um_y[temp_y]++;
		//um_x[temp_x]++;
		um["y" + to_string(temp_y)]++;
		um["x" + to_string(temp_x)]++;
	}
	//최대 빈도확인
	for (auto elem : um) {
		if (select_int[0] < elem.second) {
			select_int[2] = select_int[1];
			select_str[2] = select_str[1];
			select_int[1] = select_int[0];
			select_str[1] = select_str[0];
			select_int[0] = elem.second;
			select_str[0] = elem.first;
		}
		else if (select_int[1] < elem.second) {
			select_int[2] = select_int[1];
			select_str[2] = select_str[1];
			select_int[1] = elem.second;
			select_str[1] = elem.first;
		}
		else if (select_int[2] < elem.second) {
			select_int[2] = elem.second;
			select_str[2] = elem.first;
		}
	}
```
> - 처음에는 조합을 통해서 확인하려 하였지만, 문제에 적혀있는 시간과 제한 메모리를 보고 이렇게 푸는 것이 아니라 생각이 들어서 문제를 푸는 방향을 아예 틀었다.
> -  사실 이렇게 빈도수를 확인하여 최대 빈도로 확인하는 것에 대한 확신을 갖고 문제를 풀진 않았고, 우선 이렇게 해보고 아니면 다른 방식으로 풀어야겠다 생각하였다.
>  - 역시나 `C++`의 `unordered_map`은 그저 사랑스러울 뿐이었다. 문제를 푸는 와중에서 `to_string`, `stoi`, `substr` 등 스킬을 익히는데 좋은 문제라 생각한다.


# 빗물
### bj14719
- `구현`
- O(n)의 구현 시간으로 풀려다가(bj14719_wrong.cpp) 어떻게든 답이안나와서 해설을 찾아보았다....
```c++
	for (int i = 1; i < w-1; i++) {
		left1 = 0; right1 = 0;
		for (int j = 0; j < i; j++) left1 = max(left1, wh[j]);
		for (int j = w - 1; j > i; j--) right1 = max(right1, wh[j]);
		ans += max(0, min(left1, right1) - wh[i]);
	}
```
> - 중앙 select된(for i) w를 기준으로 왼쪽의 최대값 오른쪽의 최대값을 찾아서 해당 w의 값을 찾는 과정을 거치게 된다.

- 구현문제를 꽤나 풀었다 생각했지만, 이렇게 기준을 세워두고 왼쪽 오른쪽으로 직관적으로 문제를 풀이하는 것은 처음이라 창의력이 부족한 만큼 문제를 많이 풀어서 실력을 늘리는게 낫겠다고 생각했다..


# 피아노 체조
### bj21318
- `부분 합`
- 처음에 문제를 보고 완전 탐색을 통해서 풀었던 과정을 나중에도 볼 수 있도록 남겨두었다...
```c++
	for (int i = 0; i < n; i++) {
		cin >> temp;
		a.push_back(temp);
		if (i == 0) continue;
		if (a[i - 1] > temp) cnt[i] = cnt[i - 1] + 1;
		else cnt[i] = cnt[i - 1];
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> temp >> temp1;
		/*b.push_back(make_pair(temp, temp1));*/
		//ans.push_back(cnt[temp1-1] - cnt[temp-1]);
		cout << cnt[temp1 - 1] - cnt[temp - 1] << '\n'; // 매우 나쁜 endl
	}	
```
> - 문제는 부분합 문제였고, 입력을 받음과 동시에 계산을 진행해서 풀이를 이어나가는 것이 keypoint였다.
> - 역시 이 문제에서도 출력시에 endl을 사용할 경우 시간초과를 만날 수 있어서 endl 대신에 '\n'의 활용을 적극적으로 활용해야겠다는 생각을 하였다..


# 마법사 상어와 토네이도
### bj20057
+ `시뮬레이션`
- 풀이에는 오랜 시간을 투자하지 않았지만, 틀린 행렬을 생성하여 그 부분을 찾는데에 엄청나게 오랜 시간을 쏟아서 매우 맥빠지는 문제였다.
```c++
	tor[0] = (n / 2) + 1;
	tor[1] = (n / 2) + 1;
	tor[2] = 3;

	int range = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			//마지막 한번만 빼주기
			if (i == n - 1 && j == 1) break;
			for (int k = 0; k < range; k++) {
				int dy = tor[0] + dir[0][tor[2]];
				int dx = tor[1] + dir[1][tor[2]];
				//cout << "dy,dx : " << dy << " " << dx << " " << tor[2] << endl;
				//계산해주기

				if (tor[2] == 0) {
					north(dy, dx);
				}
				else if (tor[2] == 1) {
					east(dy, dx);
				}
				else if (tor[2] == 2) {
					south(dy, dx);
				}
				else if (tor[2] == 3) {
					west(dy, dx);
				}

				tor[0] = dy; tor[1] = dx;

				/*for (int a = 1; a <= n; a++) {
					for (int b = 1; b <= n; b++) {
						cout << map[a][b] << " ";
					}
					cout << endl;
				}
				cout << "ans = " << ans << endl;*/

				//마지막 한번만 빼주기
				if (dy == 1 && dx == 1) break;

			}
			//방향 전환해주기
			tor[2] = tor[2] - 1;
			if (tor[2] < 0) tor[2] = 3;
		}
		range++; // 두개씩 거리 늘려주기
	}
```
> - 시뮬레이션을 풀이하는 순회 과정이다. 문제를 보면 중앙에서 두쌍 씩({1,1}, {2,2}, {3,3}, ...) 늘려가면서 진행하는 것을 확인하여 이러한 3중for문을 사용하게 되었다. 굳이 시간복잡도를 활용하자면 O(n^3)을 사용한 것처럼 보이지만 실제 코드에서 동작하는 것은 다른 사람들이 짠 코드와 완전히 동일하기에 시간 초과의 걱정은 없다.

```c++
float north1[9][3] = {
	{0, -2, 2},{-1,-1,10},{0,-1,7},{1,-1,1},
	{-2,0,5},
	{-1,1,10},{0,1,7},{1,1,1},{0,2,2}
};
void north(int dy, int dx) {
	int whole = map[dy][dx];
	for (int i = 0; i < 9; i++) {
		int y = dy + north1[i][0];
		int x = dx + north1[i][1];
		int result = (map[dy][dx] * north1[i][2]) / 100;

		whole -= result;
		if (x < 1 || y < 1 || x > n || y > n) {
			ans += result;
			
		}
		else {
			map[y][x] += result;
		}
	}
	if (dy - 1 < 1) {
		ans += whole;
	}
	else {
		map[dy-1][dx] += whole;
	}
	map[dy][dx] = 0;
}
```
> - 어찌보면 하드코딩이지만, 실제로 토네이도가 영향을 미치는 것을 북동남서 방향으로 하나하나 배열을 생성하고 그를 활용하여 함수를 지정하였다. 함수의 내용은 대부분이 동일하지만 행렬과 마지막 if(dy-1<1)의 범위체크 부분을 수정하여 구현하였다.

- 어찌보면 시뮬레이션 문제중에서 구현이 굉장히 쉬운편이라 생각되었지만, 시뮬레이션 특성상 처음에 잘못하면 시간이 엄청나게 오래걸리는 바람에 풀이를 하는데에서는 꽤나 애를 먹은 문제였다.

# 신규 아이디 추천
### pro72410
- `문자열 처리`
```python
def solution(new_id):
    # 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    new_id = new_id.lower()
    # 이전 주 확인가능
    
    # 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    new_id = re.sub(r'[^a-z0-9-_.]', '', new_id)
    # re모듈의 sub는 주어진 문자열에서 일치하는 모든 패턴을 replace 그 결과를 문자열로 다시 반환함
    # 문자열 앞에 r이 붙은 것은 해당 문자열이 구성된 그대로 문자열로 반환하게 되기 때문이다.
    # ^가 앞에 사용되었기 때문에 해당 문자 패턴이 아닌 것과 매칭하게 된다. 고로 (a-z)모든 소문자, (0-9)모든 숫자, (-_.)을 제외한 모든 문자를 ''로 replace하게 된다.
    
    # 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    new_id = re.sub(r'\.{2,}','.', new_id)
    # \.{2,}는 .이 2번이상 반복될 경우를 뜻한다. 따라서 .이 2번 이상 반복될 경우 .으로 replace되도록 만든다.
    
    # 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    new_id = re.sub(r'^\.|\.$','',new_id)
    # 정규 표현식에서 ^\.은 맨 앞에.이 있을 경우, $\.은 맨 뒤에 .이 있을 경우를 뜻하게 된다.
    # ^은 문자열 맨 앞부터 $는 문자열 맨 끝부터를 의미한다.
    
    # 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    # 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    # 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    if len(new_id) == 0 : 
        new_id = 'a'
    elif len(new_id) >= 16 :
        if new_id[14] == '.' :
            new_id = new_id[:14]
        else :
            new_id = new_id[:15]
    # 문자열 슬라이스는 신이고 파이썬은 무적이다.
    
    # 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    if len(new_id) <= 2 :
        while len(new_id) != 3 :
            new_id = new_id + new_id[-1]
    # python list[-1]는 list의 마지막값을 의미한다.
    
    return new_id
```
- 주석으로 해설을 대신한다.

