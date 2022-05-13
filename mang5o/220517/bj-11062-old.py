import sys

all_query = int(sys.stdin.readline().rstrip())
all_answer = []
for query in range(all_query):
    cases = int(sys.stdin.readline().rstrip())
    all_figure = list(map(int, sys.stdin.readline().rstrip().split()))
    start_ptr = 0
    end_ptr = cases - 1

    score_g = 0  # 근
    score_m = 0

    now_g = True
    while True:
        if end_ptr - start_ptr == 0:
            if now_g:
                score_g += all_figure[start_ptr]
            else:
                score_m += all_figure[start_ptr]
            break
        elif end_ptr - start_ptr == 1:
            if now_g:
                score_g += max(all_figure[start_ptr], all_figure[end_ptr])
                score_m += min(all_figure[start_ptr], all_figure[end_ptr])
            else:
                score_m += max(all_figure[start_ptr], all_figure[end_ptr])
                score_g += min(all_figure[start_ptr], all_figure[end_ptr])
            break
        else:
            left_case = all_figure[start_ptr] - max(all_figure[start_ptr + 1], all_figure[end_ptr])
            right_case = all_figure[end_ptr] - max(all_figure[start_ptr], all_figure[end_ptr - 1])
            if left_case > right_case:
                if now_g:
                    score_g += all_figure[start_ptr]
                else:
                    score_m += all_figure[start_ptr]
                start_ptr += 1
            else:
                if now_g:
                    score_g += all_figure[end_ptr]
                else:
                    score_m += all_figure[end_ptr]
                end_ptr -= 1
            now_g = not now_g

    all_answer.append(score_g)

for aa in all_answer:
    print(aa)