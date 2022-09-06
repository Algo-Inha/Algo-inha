# https://school.programmers.co.kr/learn/courses/30/lessons/81303
# 표 편집

def solution(n, k, cmd):
    # dictionary로 linked list 구현 -> key: 행 번호, value: [이전행,다음행]
    table = { i:[i - 1, i + 1] for i in range(n) }
    answer = ['O'] * n          # 행 존재 여부 O/X 표시
    table[0] = [None, 1]        # 처음 행 설정
    table[n - 1] = [n - 2, None]# 마지막 행 설정    
    stack = []    
    
    for c in cmd:        
        if c == "C":            # 행 삭제
            answer[k] = 'X'     # 행 삭제 후 X 표시       
            prev, next = table[k]            
            stack.append([prev, k, next])      

            if next == None:    # 마지막 행이면 윗 행 선택            
                k = table[k][0]            
            else:               # 그 외에는 다음 행 선택
                k = table[k][1]     

            if prev == None:           
                table[next][0] = None            
            elif next == None:                
                table[prev][1] = None            
            else:
                table[prev][1] = next    # 현재행 삭제 후 이전행과 다음행 연결            
                table[next][0] = prev         
        
        elif c == "Z":          # 행 복구
            prev, now, next = stack.pop()            
            answer[now] = 'O'   # 행 복구 후 O 표시
            if prev == None:                
                table[next][0] = now            
            elif next == None:                
                table[prev][1] = now            
            else:                
                table[next][0] = now                
                table[prev][1] = now   

        else:                   # 행 이동   
            UD, num = c.split(' ')            
            num = int(num)            
            if UD == 'D':       # 아래로        
                for _ in range(num):                    
                    k = table[k][1]            
            else:               # 위로 
                for _ in range(num):                    
                    k = table[k][0]    

    return ''.join(answer)

print(solution(8,2,["D 2", "C", "U 3", "C", "D 4", "C", "U 2", "Z", "Z"]))