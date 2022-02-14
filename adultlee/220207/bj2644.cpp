#include <iostream> 
#include <queue> 

using namespace std; 

#define MAX 102 

int n; // 전체 사람의 수
int first_person; //첫번째 사람
int second_person; // 두번째 사람
int m; // 관계의 개수
int cnt=0; //
int family[MAX][MAX]; 
int visited[MAX]; 

queue<int> temp_queue;

void find_person(int k) 
{
    temp_queue.push(k); 

    while(!temp_queue.empty())
    { 
        k = temp_queue.front(); 
        temp_queue.pop(); 
        for(int i=0; i <= n-1; i++) 
        { 
            if(family[k][i]!=0 && !visited[i]) 
            { 
                temp_queue.push(i); 
                visited[i]=visited[k]+1; 
            }
        } 
    } 
}

 
int main() 
{ 
    cin >> n; 
    cin >> first_person >> second_person; 
    cin >> m; 

    int x,y; 

    for(int i=0;i<m;i++) 
    { 
        cin >> x >> y; 
        family[x][y]=1; 
        family[y][x]=1; 
    } 

    find_person(first_person); 

    if(visited[second_person]==0) 
    {
        visited[second_person]=-1; 
    }

    cout << visited[second_person]; 
}



