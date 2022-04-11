# https://programmers.co.kr/learn/courses/30/lessons/60059
# 자물쇠와 열쇠

def solution(key, lock):
    key_size = len(key)
    lock_size = len(lock)
    return_val = False
    for dir_change in range(4):
        for y in range(-1*key_size+1, lock_size):
            for x in range(-1*key_size+1, lock_size):
                # key_size의 맨 좌측상단이 존재하는 (y,x)값 (lock 기준)
                match_flag = True
                for lock_y in range(lock_size):
                    for lock_x in range(lock_size):
                        # (lock_y, lock_x) 좌표에서의 key값과 lock값
                        now_lock_add = lock[lock_y][lock_x]
                        now_key_add_y = lock_y - y
                        now_key_add_x = lock_x - x
                        now_key_add = 0
                        if 0<=now_key_add_y<key_size and 0<=now_key_add_x<key_size:
                            if dir_change==0:
                                now_key_add = key[now_key_add_y][now_key_add_x]
                            elif dir_change==1: # 시계방향 90도
                                now_key_add = key[now_key_add_x][key_size-1-now_key_add_y]
                            elif dir_change==2: # 시계방향 180도
                                now_key_add = key[key_size-1-now_key_add_y][key_size-1-now_key_add_x]
                            else: # 시계방향 270도
                                now_key_add = key[key_size-1-now_key_add_x][now_key_add_y]
                        if now_lock_add + now_key_add != 1:
                            match_flag = False
                            break
                    if not match_flag:
                        break
                if match_flag:
                    return_val = True
                    break
            if return_val:
                break
        if return_val:
            break
    return return_val


print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]))
