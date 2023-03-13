import sys
input = sys.stdin.readline

graph = []

while(1):
    board = input().rstrip()
    graph.append(board)
    if graph[-1] == "end":
        graph.pop()
        break


for i in graph:
    if ((i.count("X") == 5 and i.count("O") == 4)
        and not
        (i[:3] == "OOO" or i[3:6] == "OOO" or i[6:] == "OOO" 
        or (i[0] == "O" and i[4] == "O" and i[8] == "O") 
        or (i[2] == "O" and i[4] == "O" and i[6] == "O")
        or (i[0] == "O" and i[3] == "O" and i[6] == "O")
        or (i[1] == "O" and i[4] == "O" and i[7] == "O")
        or (i[2] == "O" and i[5] == "O" and i[8] == "O"))):
        print("valid")
    elif i.count("X") == i.count("O"):
        if ((i[:3] == "OOO" or i[3:6] == "OOO" or i[6:] == "OOO" 
            or (i[0] == "O" and i[4] == "O" and i[8] == "O") 
            or (i[2] == "O" and i[4] == "O" and i[6] == "O")
            or (i[0] == "O" and i[3] == "O" and i[6] == "O")
            or (i[1] == "O" and i[4] == "O" and i[7] == "O")
            or (i[2] == "O" and i[5] == "O" and i[8] == "O"))
            and not 
            (i[:3] == "XXX" or i[3:6] == "XXX" or i[6:] == "XXX" 
            or (i[0] == "X" and i[4] == "X" and i[8] == "X") 
            or (i[2] == "X" and i[4] == "X" and i[6] == "X")
            or (i[0] == "X" and i[3] == "X" and i[6] == "X")
            or (i[1] == "X" and i[4] == "X" and i[7] == "X")
            or (i[2] == "X" and i[5] == "X" and i[8] == "X"))):
            print("valid")
        else:
            print("invalid")
    elif (i.count("X") == (i.count("O") + 1)):
        if ((i[:3] == "XXX" or i[3:6] == "XXX" or i[6:] == "XXX" 
            or (i[0] == "X" and i[4] == "X" and i[8] == "X") 
            or (i[2] == "X" and i[4] == "X" and i[6] == "X")
            or (i[0] == "X" and i[3] == "X" and i[6] == "X")
            or (i[1] == "X" and i[4] == "X" and i[7] == "X")
            or (i[2] == "X" and i[5] == "X" and i[8] == "X"))
            and not
            (i[:3] == "OOO" or i[3:6] == "OOO" or i[6:] == "OOO" 
            or (i[0] == "O" and i[4] == "O" and i[8] == "O") 
            or (i[2] == "O" and i[4] == "O" and i[6] == "O")
            or (i[0] == "O" and i[3] == "O" and i[6] == "O")
            or (i[1] == "O" and i[4] == "O" and i[7] == "O")
            or (i[2] == "O" and i[5] == "O" and i[8] == "O"))):
            print("valid")
        else:
            print("invalid")

    else:
        print("invalid")

