// https://www.acmicpc.net/problem/5430

#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int all_repeat, list_len, start_ptr, end_ptr;
string input_function, input_list, print_tmp_string;
bool now_forward, now_error;

int main(){
    string all_text = "";
    cin >> all_repeat;
    for(int ar = 0; ar<all_repeat; ar++){
        cin >> input_function >> list_len >> input_list;

        start_ptr = 0;
        end_ptr   = input_list.length()-1;
        now_forward = true;
        now_error = false;
        for(int i = 0; i<input_function.length(); i++){
            if (input_function[i]=='R'){
                now_forward = !now_forward;
            }else{
                if(input_list.compare("[]")==0){
                    now_error = true;
                    break;
                }
                if(now_forward){ // pivot at ',' & ']' & '['
                    while(1){
                        start_ptr++;
                        if(input_list[start_ptr]==','||input_list[start_ptr]==']'){
                            break;
                        }
                    }
                }else{
                    while(1){
                        end_ptr--;
                        if(input_list[end_ptr]==','||input_list[end_ptr]=='['){
                            break;
                        }
                    }
                }
                if(start_ptr>end_ptr){
                    now_error = true;
                }
            }
        }
        if(now_error){
            all_text += "error\n";
        }else{
            print_tmp_string = "";
            if(now_forward){
                all_text += "[";
                for(int i = start_ptr+1; i<end_ptr; i++){
                    if(input_list[i]==','){
                        all_text += print_tmp_string + ",";
                        print_tmp_string = "";
                    }else{
                        print_tmp_string = print_tmp_string+input_list[i];
                    }
                }
                all_text += print_tmp_string + "]\n";
            }else{
                all_text += "[";
                for(int i = end_ptr-1; i>start_ptr; i--){
                    if(input_list[i]==','){
                        all_text += print_tmp_string + ",";
                        print_tmp_string = "";
                    }else{
                        print_tmp_string = input_list[i]+print_tmp_string;
                    }
                }
                all_text += print_tmp_string + "]\n";
            }
        }
    }
    cout<<all_text;
    return 0;
}