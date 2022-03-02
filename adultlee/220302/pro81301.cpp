// 숫자 문자열과 영단어
#include <string>
#include <vector>

using namespace std;

vector<string> temp;

int solution(string s) {
int answer = 0;

    for(int i =0; i < s.length(); i++)
    {
        if((s[i] == 'z'&&s[i+1] == 'e' && s[i+2]== 'r' && s[i+3] == 'o') || s[i] =='0')
        {
                temp.push_back("0");
        }
         if((s[i] == 'o'&&s[i+1] == 'n' && s[i+2]== 'e' ) || s[i] =='1')
        {
                temp.push_back("1");
        }
          if((s[i] == 't'&&s[i+1] == 'w' && s[i+2]== 'o') || s[i] =='2')
        {        
                temp.push_back("2");
        }
        if((s[i] == 't'&&s[i+1] == 'h' && s[i+2]== 'r' && s[i+3] == 'e'&& s[i+4] == 'e') || s[i] =='3')
        {     
                temp.push_back("3");
        }
        if( (s[i] == 'f'&& s[i+1] == 'o' && s[i+2]== 'u'&& s[i+3]== 'r')|| s[i] == '4' )
        {
                temp.push_back("4");
        }
         if((s[i] == 'f'&&s[i+1] == 'i' && s[i+2]== 'v' && s[i+3] == 'e') || s[i] =='5')
        {
                temp.push_back("5");
        }
         if((s[i] == 's'&&s[i+1] == 'i' && s[i+2]== 'x') || s[i] =='6')
        {
                temp.push_back("6");
        }
         if((s[i] == 's'&&s[i+1] == 'e' && s[i+2]== 'v' && s[i+3] == 'e'&& s[i+4] == 'n') || s[i] =='7')
        {
                temp.push_back("7");
        }
         if((s[i] == 'e'&&s[i+1] == 'i' && s[i+2]== 'g' && s[i+3] == 'h'&& s[i+4] == 't') || s[i] =='8')
        {
                temp.push_back("8");
        }
         if((s[i] == 'n'&&s[i+1] == 'i' && s[i+2]== 'n' && s[i+3] == 'e') || s[i] =='9')
        {
                temp.push_back("9");
        }
    }
    string answer_string;
    for(int i =0; i<temp.size(); i++)
    {
        answer_string += temp[i];
    }
    answer = stoi(answer_string);
    return answer;
}

// 