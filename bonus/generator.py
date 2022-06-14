import json
import sys as ratio

f = open(ratio.argv[1])
d = json.load(f)
data = list(map(int, d['layers'][1]['data']))
index, index2 = 0, -1
height = int(d['layers'][1]['height'])
width = int(d['layers'][1]['width'])
res = [[0 for x in range(width)] for y in range(height)]

for i in range(height):
    for j in range(width):
        res[i][j] = data[index]
        index += 1
for x in res:
    for i in range(len(x)):
        print(str(x[i])+"," if i+1 < len(x) else str(x[i]), end='')
    print()
f.close()
