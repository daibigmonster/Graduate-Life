# 假设一个探险家被困在了地底的迷宫之中，要从当前位置开始找到一条通往迷宫出口的路径。迷宫可以用一个二维矩阵组成，有的部分是墙，有的部分是路。迷宫之中有的路上还有门，每扇门都在迷宫的某个地方有与之匹配的钥匙，只有先拿到钥匙才能打开门。请设计一个算法，帮助探险家找到脱困的最短路径。如前所述，迷宫是通过一个二维矩阵表示的，每个元素的值的含义如下 0-墙，1-路，2-探险家的起始位置，3-迷宫的出口，大写字母-门，小写字母-对应大写字母所代表的门的钥匙
# 输入描述:
# 迷宫的地图，用二维矩阵表示。第一行是表示矩阵的行数和列数M和N
# 后面的M行是矩阵的数据，每一行对应与矩阵的一行（中间没有空格）。M和N都不超过100, 门不超过10扇。
# 输出描述:
# 路径的长度，是一个整数
# 输入例子1:
# 5 5
# 02111
# 01a0A
# 01003
# 01001
# 01111
# 输出例子1:
# 7

import sys
import collections
line = sys.stdin
M,N = list(map(int,line.readline().strip().split()))
maze = []
for _ in range(M):
    maze.append(list(line.readline().strip()))

# print(M,N,maze)
for i in range(M):
    for j in range(N):
        if maze[i][j] == '2':
            man = [i,j]
        elif maze[i][j] == 'a':
            key = [i,j]
        elif maze[i][j] == 'A':
            door = [i,j]

def BFS(maze,M,N,destination):
    dic = ((1,0), (-1,0), (0,1), (0,-1))
    Visited = [[False for _ in range(M)] for _ in range(N)]
    stack = collections.deque([[man[0], man[1]]])
    step = 0
    while len(stack) != 0:
        length = len(stack)
        step += 1
        for _ in range(length):
            curposition = stack.popleft()
            Visited[curposition[0]][curposition[1]] = True
            for i in range(4):
                tempposition = curposition
                tempposition[0] += dic[i][0]
                tempposition[1] += dic[i][1]
                if tempposition[0] >= M or tempposition[0] < 0 \
                or tempposition[1] >= N or tempposition[1] < 0 \
                or maze[tempposition[0]][tempposition[1]] == '0':
                    continue
                if maze[tempposition[0]][tempposition[1]] == destination :
                    return step
                if Visited[tempposition[0]][tempposition[1]] == False :
                    stack.append(tempposition)
    return -1


dest = '3'
keydest = 'a'
doordest = 'A'
index = BFS(maze,M,N,dest)
print(dest)
            
        

            
        
