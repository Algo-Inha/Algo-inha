//���� ū ��
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    return a + b > b + a;
}//�������� �� ū������ ����

string solution(vector<int> numbers) {
    string save[100000];
    int i = 0;
    for (auto a : numbers) {
        save[i] = to_string(a);
        i++;
    }//��Ʈ���� ����
    sort(save, save + i, comp);//����
    string answer = "";
    for (int j = 0; j < i; j++) {
        answer += save[j];
    }
    if (answer[0] == '0')return "0";//0���� �����ϸ� 0����
    return answer;
}