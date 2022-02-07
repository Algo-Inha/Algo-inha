# https://programmers.co.kr/learn/courses/30/lessons/17683


def solution(m, musicinfos):
    search_string = m.replace("C#", "c").replace("D#", "d").replace("F#", "f").replace("G#", "g").replace("A#", "a")
    max_time = 0
    max_name = "(None)"
    for mi in musicinfos:
        tmp_mi = mi.split(",")
        hour_diff = int(tmp_mi[1].split(":")[0]) - int(tmp_mi[0].split(":")[0])
        min_diff = int(tmp_mi[1].split(":")[1]) - int(tmp_mi[0].split(":")[1])
        real_time = hour_diff * 60 + min_diff
        tmp_melody = tmp_mi[3].replace("C#", "c").replace("D#", "d").replace("F#", "f").replace("G#", "g").replace("A#",
                                                                                                                   "a")
        real_melody = ""
        for i in range(int(real_time / len(tmp_melody)) + 1):  # 실제 재생된 노래 텍스트화
            real_melody = real_melody + tmp_melody
        real_melody = real_melody[0:real_time]
        if search_string in real_melody:  # Search
            if max_time < real_time:
                max_time = real_time
                max_name = tmp_mi[2]

    return max_name


print(solution("ABCDEFG", ["12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
print(solution("CC#BCC#BCC#BCC#B", ["03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"]))
print(solution("ABC", ["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]))
