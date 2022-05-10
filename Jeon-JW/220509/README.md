
# 꽃길
### bj14620
+ `구현`
```c++
void func(int cnt, int y, int x) {
	for (int i = y; i < N; i++) {
		for (int j = 2; j < N; j++) {
			if (i == y && j <= x) j = x + 1;
			if (check(i, j)) continue;

			v.push_back(make_pair(i, j));
			if (cnt == 2) {
				int temp = 0;
				for (int i = 0; i < 3; i++) {
					temp += map2[v[i].first][v[i].second];
				}
				if (answer > temp) {
					/*for(int i=0;i<3;i++){
						cout << v[i].first << " " << v[i].second << " value = " << map2[v[i].first][v[i].second] << endl;
					}*/
					answer = temp;
					//cout << "renew answer = " << answer << endl;
				}
			}
			else func(cnt + 1, i, j);
			v.pop_back();
		}
	}
}
```
>-  이쁘게 풀고싶어서 이래저래 해봤는데... 쉽게 만족되지 않았다...
>- 이전 주에서도 느꼈 듯 단순하지만 보기는 안좋아보이는 코드를 사용하여 단순하게 꽃들의 위치를 전부 하는 것으로 확인하였다.


# 개똥벌레
### bj3020
- `이분탐색`
```c++
int answer = 999999999;
	int cnt = 1;
	for (int i = 1; i <= H; i++) {
		//해당 높이에 겹치는 석순
		//lower_bound(bottom.begin(), bottom.end(), i) - bottom내부에서 i보다 같거나 큰숫자가 몇번째에 처음 등장하는지
		int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		//해당 높이에 겹치는 종유석
		//upper_bound(top.begin(), top.end(), H - i) - top내부에서 H-i보다 같거나 작은 숫자가 몇번째에 처음 등장하는지
		temp += top.size() - (upper_bound(top.begin(), top.end(), H - i) - top.begin());

		//temp에는 결국 해당 높이에 겹치는 석순과 종유석이 저장되게 된다.

		if (answer == temp)// 맨 처음에는 안된다.
			cnt++;
		else if (answer > temp) { // temp라는 높이에 몇개의 cnt가 쌓이게 되는지 
			answer = temp;
			cnt = 1;
		}
	}
	cout << answer << " " << cnt;
```
> - 혼자서는 생각하기 너무어렵다고 생각된다..... 풀이를 찾아봐서 힌트를 좀 얻어 최대한 혼자 해보려 노력했다.
> - 다시봐도 이런풀이가 나오도록 열심히 문제를 다시 읽고 그 생각이 떠오를 수 있도록 노력해봤다.


# 타겟넘버
### pro43165
- `DFS`
```c++
void dfs(int rst, int cnt, vector<int> numbers) {
    if (cnt == numbers.size()) {
        if (rst == targetTemp) answer++;
        return;
    }
    dfs(rst + numbers[cnt], cnt + 1, numbers);
    dfs(rst + (numbers[cnt] * -1), cnt + 1, numbers);
}

int solution(vector<int> numbers, int target) {
    targetTemp = target;
    dfs(numbers[0], 1, numbers);
    dfs(numbers[0] * -1, 1, numbers);

    return answer;
}
```
> - 엄~청 스테레오타입인 문제였다.
> - 프로그래머스문제를 풀고 난 뒤에는 보통 다른사람들이 어떻게 풀었는지 확인해보는데, 가장 like를 많이 받은 풀이와 동일하여 기분이 좋았다.

# 톱니바퀴
### bj14891
- `시뮬레이션`
- old_ver
```c++
bool gear[5][8];

// 왼쪽과 오른쪽에 맞닿는 기어의 번호를 return
int findLeft(int gearNum) {
	int left = 0;
	left = (state[gearNum] - 2);
	if (left < 0) left = 8 + left;
	return left;
}
int findRight(int gearNum) {
	int right;
	right = (state[gearNum] + 2) % 8;
	return right;
}

// 1 시계 -1 반시계
// direction 왼0 오1 // flag는 자기자신이 돌지말지.
void chain(int me, int you, int direction, int spinDirection, bool flag) {
	if (you != 0 && you != 5) { // 비교범위 외 제외
		if (!direction) { // 왼비교
			int meLeft = findLeft(me);
			int youRight = findRight(you);
			if (gear[me][meLeft] != gear[you][youRight]) { // 다를경우만
				chain(me - 1, you - 1, 0, -1 * spinDirection, 1);
			}
		}
		else { // 오비교
			int meRight = findRight(me);
			int youLeft = findLeft(you);
			if (gear[me][meRight] != gear[you][youLeft]) { // 다를경우만
				chain(me + 1, you + 1, 1, -1 * spinDirection, 1);
			}
		}
	}
	if (flag)spinMove(me, spinDirection); // 자기자신 움직여주기
}

void go(int num) { // 돌아버려
	int gearNum = spin[num][0]; int spinDir = spin[num][1];

	if (gearNum == 1) {
		chain(1, 2, 1, spinDir, 1); // 오른쪽으로
	}
	else if (gearNum == 2 || gearNum == 3) {
		chain(gearNum, gearNum + 1, 1, spinDir, 0); // 오른
		chain(gearNum, gearNum - 1, 0, spinDir, 1); // 왼
	}
	else if (gearNum == 4) {
		chain(4, 3, 0, spinDir, 1); // 왼
	}
}
```
>- 이전에 풀어본 풀이이다. 풀이 내용은 배열은 돌릴 수 없으니 pivot을 생성하여 pivot이 톱니가 어떻게 움직였는지, 12시 방향이 어느부분인지 저장하는 풀이이다.

```c++
void rotate() {
	//첫번째
	if (state[1] == 1) {//시계 맨뒤를 떼서 앞에 붙여주기
		str1 = str1[7] + str1.substr(0, 7);
	}
	else if (state[1] == -1) {//반시계 맨앞을 떼서 맨뒤에 붙여주기
		str1 = str1.substr(1, 7) + str1[0];
	}

	if (state[2] == 1) {//시계 맨뒤를 떼서 앞에 붙여주기
		str2 = str2[7] + str2.substr(0, 7);
	}
	else if (state[2] == -1) {//반시계 맨앞을 떼서 맨뒤에 붙여주기
		str2 = str2.substr(1, 7) + str2[0];
	}

	if (state[3] == 1) {//시계 맨뒤를 떼서 앞에 붙여주기
		str3 = str3[7] + str3.substr(0, 7);
	}
	else if (state[3] == -1) {//반시계 맨앞을 떼서 맨뒤에 붙여주기
		str3 = str3.substr(1, 7) + str3[0];
	}

	if (state[4] == 1) {//시계 맨뒤를 떼서 앞에 붙여주기
		str4 = str4[7] + str4.substr(0, 7);
	}
	else if (state[4] == -1) {//반시계 맨앞을 떼서 맨뒤에 붙여주기
		str4 = str4.substr(1, 7) + str4[0];
	}
}
```
> - 이번에는 string으로 입력을 받아서 진행한 풀이이다.
> - 돌아가는 데에 있어서 연계되는 방법이 선택된 톱니의 위치마다 달라서 그 부분은 하드코딩으로 처리하였지만, 다른 자료구조를 안쓰고 string을 이용하여 머리속은 편했다는 장점이 있다.
> - 이렇게 붙어있는 입력이 들어올 때 scanf("%1d", a)가 아닌 string으로 처리하는 방법을 생각해낸걸 봐서 확실히 문자열처리에 조금 익숙해진 것 같다 생각했다.
