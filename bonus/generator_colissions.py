import json
import sys as ratio
import random as r

f = open(ratio.argv[1])
d = json.load(f)
colissions = list(map(int, d['layers'][1]['data']))
colissions2 = list(map(int, d['layers'][3]['data']))
height = int(d['layers'][1]['height'])
width = int(d['layers'][1]['width'])
TOUCHE_PAS = list(map(int, ratio.argv[2:])) + [0]

for i in range(len(colissions)):
    if colissions[i] in TOUCHE_PAS and colissions2[i] in TOUCHE_PAS:
        print(0, end="")
    else:
        print(1, end="")
    if ((i+1) % width == 0 and i > 0):
        print()
f.close()
