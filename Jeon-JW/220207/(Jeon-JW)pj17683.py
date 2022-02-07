# https://programmers.co.kr/learn/courses/30/lessons/17683?language=python3
# 방금그곡

# 대문자+#을 소문자로 대체한다. 
# replace함수 - 문자를 변경한다.
def change(melody):
    if 'A#' in  melody : melody = melody.replace('A#', 'a')
    if 'C#' in  melody : melody = melody.replace('C#', 'c')
    if 'D#' in  melody : melody = melody.replace('D#', 'd')
    if 'F#' in  melody : melody = melody.replace('F#', 'f')
    if 'G#' in  melody : melody = melody.replace('G#', 'g')
    return melody


def solution(m, musicinfos):
    m = change(m)
    answer = ('(None)', None) # 순회후 없으면 '(None)'을 반환하기 위해서 tuple형태 사용
    for info in musicinfos:
        start, end, title, melody = info.split(',')
        # map함수를 통해서 결과를 int로 저장, map의 return 은 map이기 때문에 원래는 list(), tuple()같은 것으로 map을 감싸줘야하지만 그대로 넣어준다.
        start_h, start_m, end_h, end_m = map(int, start.split(':') + end.split(':'))
        time = 60 * (end_h-start_h) + (end_m-start_m)
        melody = change(melody)
        # [:time]은 리스트 slice방식으로 처음부터 time이전까지의 리스트를 자르는방법
        # melody*time 은 melody를 time만큼 반복시켜 생성한다.
        melody_played = (melody*time)[:time]
        # m에 melody_played가 있을 경우.
        if m in melody_played:
            # 존재하는데, 앞에 들어간게 없거나 시간으로 따졌을 때 더 빠르거나
            if(answer[1] == None) or (time>answer[1]):
                answer = (title, time)
    return answer[0]