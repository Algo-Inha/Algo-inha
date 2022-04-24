//https://programmers.co.kr/learn/courses/30/lessons/60059
//ÀÚ¹°¼è¿Í ¿­¼è
#include <string>
#include <vector>

using namespace std;

int ks;
int ls;
vector<vector<int>> v;
int key2[20][20];
int key3[20][20];
int key4[20][20];
void make_keys(vector<vector<int>> key) {
	int a, b;

	a = 0;
	for (int j = ks - 1; j >= 0; j--) {
		b = 0;
		for (int i = 0; i < ks; i++) {
			key2[a][b] = key[i][j];
			b++;
		}
		a++;
	}
	a = 0;
	for (int j = ks - 1; j >= 0; j--) {
		b = 0;
		for (int i = 0; i < ks; i++) {
			key3[a][b] = key2[i][j];
			b++;
		}
		a++;
	}
	a = 0;
	for (int j = ks - 1; j >= 0; j--) {
		b = 0;
		for (int i = 0; i < ks; i++) {
			key4[a][b] = key3[i][j];
			b++;
		}
		a++;
	}
}



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	ks = key.size();
	ls = lock.size();

	make_keys(key);

	int len = (2 * ks) + ls - 2;
	v.assign(len, vector<int>(len, 0));

	//lock°ª ¿Å°ÜÁÖ±â
	for (int i = 0; i < ls; i++) {
		for (int j = 0; j < ls; j++) {
			v[i + ks - 1][j + ks - 1] = lock[i][j];
		}
	}

	bool flag1 = 0;
	for (int i = 0; i < ks + ls - 1; i++) {
		for (int j = 0; j < ks + ls - 1; j++) {
			flag1 = 0;
			//¿­¼è ¸ÂÃçº¸±â
			for (int k = 0; k < ks; k++) {
				for (int l = 0; l < ks; l++) {
					v[i + k][j + l] += key[k][l];
				}
			}

			//È®ÀÎÇÏ±â
			for (int k = ks - 1; k < ks + ls - 1; k++) {
				for (int l = ks - 1; l < ks + ls - 1; l++) {
					if (v[k][l] != 1) {
						flag1 = 1;
						break;
					}
				}
			}

			//¿­¼è »©±â
			for (int k = 0; k < ks; k++) {
				for (int l = 0; l < ks; l++) {
					v[i + k][j + l] -= key[k][l];
				}
			}
		}
		if (!flag1) return true;
	}
	for (int i = 0; i < ks + ls - 1; i++) {
		for (int j = 0; j < ks + ls - 1; j++) {
			flag1 = 0;
			//¿­¼è ¸ÂÃçº¸±â
			for (int k = 0; k < ks; k++) {
				for (int l = 0; l < ks; l++) {
					v[i + k][j + l] += key2[k][l];
				}
			}

			//È®ÀÎÇÏ±â
			for (int k = ks - 1; k < ks + ls - 1; k++) {
				for (int l = ks - 1; l < ks + ls - 1; l++) {
					if (v[k][l] != 1) {
						flag1 = 1;
						break;
					}
				}
			}

			//¿­¼è »©±â
			for (int k = 0; k < ks; k++) {
				for (int l = 0; l < ks; l++) {
					v[i + k][j + l] -= key2[k][l];
				}
			}
		}
		if (!flag1) return true;
	}
	for (int i = 0; i < ks + ls - 1; i++) {
		for (int j = 0; j < ks + ls - 1; j++) {
			flag1 = 0;
			//¿­¼è ¸ÂÃçº¸±â
			for (int k = 0; k < ks; k++) {
				for (int l = 0; l < ks; l++) {
					v[i + k][j + l] += key3[k][l];
				}
			}

			//È®ÀÎÇÏ±â
			for (int k = ks - 1; k < ks + ls - 1; k++) {
				for (int l = ks - 1; l < ks + ls - 1; l++) {
					if (v[k][l] != 1) {
						flag1 = 1;
						break;
					}
				}
			}

			//¿­¼è »©±â
			for (int k = 0; k < ks; k++) {
				for (int l = 0; l < ks; l++) {
					v[i + k][j + l] -= key3[k][l];
				}
			}
		}
		if (!flag1) return true;
	}
	for (int i = 0; i < ks + ls - 1; i++) {
		for (int j = 0; j < ks + ls - 1; j++) {
			flag1 = 0;
			//¿­¼è ¸ÂÃçº¸±â
			for (int k = 0; k < ks; k++) {
				for (int l = 0; l < ks; l++) {
					v[i + k][j + l] += key4[k][l];
				}
			}

			//È®ÀÎÇÏ±â
			for (int k = ks - 1; k < ks + ls - 1; k++) {
				for (int l = ks - 1; l < ks + ls - 1; l++) {
					if (v[k][l] != 1) {
						flag1 = 1;
						break;
					}
				}
			}

			//¿­¼è »©±â
			for (int k = 0; k < ks; k++) {
				for (int l = 0; l < ks; l++) {
					v[i + k][j + l] -= key4[k][l];
				}
			}
		}
		if (!flag1) return true;
	}

	return false;
}