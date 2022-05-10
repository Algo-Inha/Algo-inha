//https://www.acmicpc.net/problem/14891
//��Ϲ���
#include<iostream>
#include<vector>
#include<string>

//���� �ٸ��ٸ� ȸ���� ����� �ݴ�//���� ���ٸ� ȸ������ ����.

using namespace std;
//   1   1 // 3��°, 7��° - �ε����� 2(������), 6(����)
// 00000000
string str1, str2, str3, str4;
int K;
int number, dir; // �ð� 1 �ݽð� -1
int state[5]; // ��ϵ��� ���� �ȵ��� �ð�1 ����0 �ݽð�-1


int answer() {
	int ans = 0;
	if (str1[0] == '1') ans += 1;
	if (str2[0] == '1') ans += 2;
	if (str3[0] == '1') ans += 4;
	if (str4[0] == '1') ans += 8;

	return ans;
}


void rotate() {
	//ù��°
	if (state[1] == 1) {//�ð� �ǵڸ� ���� �տ� �ٿ��ֱ�
		str1 = str1[7] + str1.substr(0, 7);
	}
	else if (state[1] == -1) {//�ݽð� �Ǿ��� ���� �ǵڿ� �ٿ��ֱ�
		str1 = str1.substr(1, 7) + str1[0];
	}

	if (state[2] == 1) {//�ð� �ǵڸ� ���� �տ� �ٿ��ֱ�
		str2 = str2[7] + str2.substr(0, 7);
	}
	else if (state[2] == -1) {//�ݽð� �Ǿ��� ���� �ǵڿ� �ٿ��ֱ�
		str2 = str2.substr(1, 7) + str2[0];
	}

	if (state[3] == 1) {//�ð� �ǵڸ� ���� �տ� �ٿ��ֱ�
		str3 = str3[7] + str3.substr(0, 7);
	}
	else if (state[3] == -1) {//�ݽð� �Ǿ��� ���� �ǵڿ� �ٿ��ֱ�
		str3 = str3.substr(1, 7) + str3[0];
	}

	if (state[4] == 1) {//�ð� �ǵڸ� ���� �տ� �ٿ��ֱ�
		str4 = str4[7] + str4.substr(0, 7);
	}
	else if (state[4] == -1) {//�ݽð� �Ǿ��� ���� �ǵڿ� �ٿ��ֱ�
		str4 = str4.substr(1, 7) + str4[0];
	}
}


//������ �����ʿ��� �´�.
void top1(int lastDir) {
	if (lastDir == 0) state[1] = 0;
	else if (str1[2] == str2[6]) { // ���� ���� ��
		state[1] = 0;
	}
	else { // ���� �ٸ� ��
		state[1] = lastDir * -1;
	}
}

void top4(int lastDir) {
	if (lastDir == 0) state[4] = 0;
	else if (str3[2] == str4[6]) {
		state[4] = 0;
	}
	else {
		state[4] = lastDir * -1;
	}
}
void top3(int lastTop, int lastDir);

void top2(int lastTop, int lastDir);


int main() {

	int temp;
	cin >> str1 >> str2 >> str3 >> str4; // N 0 S 1
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> number >> dir;
		state[number] = dir;

		if (number == 1) {
			top2(1, dir);
		}
		else if (number == 2) {
			top1(dir);
			top3(2, dir);
		}
		else if (number == 3) {
			top2(3, dir);
			top4(dir);
		}
		else {
			top3(4, dir);
		}

		//cout << state[1] << " " << state[2] << " " << state[3] << " " << state[4] << endl;

		//������
		rotate();

		//cout << str1 << "\n" << str2 << "\n" << str3 << "\n" <<  str4 <<"\n";
	}


	cout << answer();


	//cout << str1 << endl;
	//str1 = str1[7] + str1.substr(0, 7);
	//cout << str1 << endl;



	//cout << str1 << endl;
	//cout << "1" + str1.substr(0,7) << endl;



	return 0;

}

void top3(int lastTop, int lastDir) {
	if (lastDir == 0) {
		state[3] = 0;
		if (lastTop == 2) top4(0);
		else top2(3, 0);
	}
	else if (lastTop == 2) {
		if (str2[2] == str3[6]) {
			state[3] = 0;
			top4(0);
		}
		else {
			state[3] = lastDir * -1;
			top4(state[3]);
		}
	}
	else {
		if (str3[2] == str4[6]) {
			state[3] = 0;
			top2(3, 0);
		}
		else {
			state[3] = lastDir * -1;
			top2(3, state[3]);
		}
	}
}

void top2(int lastTop, int lastDir) {
	if (lastDir == 0) {
		state[2] = 0;
		if (lastTop == 1) top3(2, 0);
		else top1(0);
	}
	else if (lastTop == 1) { // 1���� ���� ���
		if (str1[2] == str2[6]) {
			state[2] = 0;
			top3(2, 0);
		}
		else {
			state[2] = lastDir * -1;
			top3(2, state[2]);
		}
	}
	else { //3���� ���� ���
		if (str2[2] == str3[6]) {
			state[2] = 0;
			top1(0);
		}
		else {
			state[2] = lastDir * -1;
			top1(state[2]);
		}
	}

}
