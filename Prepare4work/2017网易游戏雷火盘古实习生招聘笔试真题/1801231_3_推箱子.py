
# 大家一定玩过“推箱子”这个经典的游戏。具体规则就是在一个N*M的地图上，有1个玩家、1个箱子、1个目的地以及若干障碍，其余是空地。玩家可以往上下左右4个方向移动，但是不能移动出地图或者移动到障碍里去。如果往这个方向移动推到了箱子，箱子也会按这个方向移动一格，当然，箱子也不能被推出地图或推到障碍里。当箱子被推到目的地以后，游戏目标达成。现在告诉你游戏开始是初始的地图布局，请你求出玩家最少需要移动多少步才能够将游戏目标达成。
# 输入描述:

# 每个测试输入包含1个测试用例
# 第一行输入两个数字N，M表示地图的大小。其中0<N，M<=8。
# 接下来有N行，每行包含M个字符表示该行地图。其中 . 表示空地、X表示玩家、*表示箱子、#表示障碍、@表示目的地。
# 每个地图必定包含1个玩家、1个箱子、1个目的地。



# 输出描述:

# 输出一个数字表示玩家最少需要移动多少步才能将游戏目标达成。当无论如何达成不了的时候，输出-1。


# 输入例子1:

# 4 4
# ....
# ..*@
# ....
# .X..
6 6
...#..
......
#*##..
..##.#
..X...
.@#...


# 输出例子1:

# 3
# 11
import sys
import collections

def moveBox(bmap,N,M):
    dic = ((1,0), (-1,0), (0,1), (0,-1))#define a man's movement can only be up(-1,0),down(1,0),right(0,1),left(0,-1)
    for i in range(N):
        for j in range(M):
            if bmap[i][j] == '*' :
                box = [i,j]
            elif bmap[i][j] == 'X':
                people = [i,j]

    dp = [[[[False for _ in range(M)]for _ in range(N)]for _ in range(M)]for _ in range(N)]
    dp[box[0]][box[1]][people[0]][people[1]] = True
    stack = collections.deque([[box[0],box[1],people[0], people[1]]])
    step = 0
    while stack:
        step += 1   
        length = len(stack)
        for _ in range(length):

            boxx,by,px,py = stack.popleft()
            print(boxx,by,px,py,step)
            for dx,dy in dic :
                nx,ny = px + dx,py + dy  
                # move
                if -1 < nx < N and -1 < ny < M and bmap[nx][ny] != '#':
                    #if the man arrives the box
                    if nx == boxx and ny == by:
                        nbx,nby = boxx + dx,by + dy #box and man move at the same time
                        # estimate if the box in map
                        if -1 < nbx < N and -1 < nby < M:
                            #if arrive the target
                            if bmap[nbx][nby] == '@':
                                return step
                            if not dp[nbx][nby][nx][ny]:
                                dp[boxx+dx][by+dy][nx][ny] = True
                                stack.append([boxx+dx, by+dy, nx, ny])
                    else:
                        if not dp[boxx][by][nx][ny]:
                            dp[boxx][by][nx][ny] = True
                            stack.append([boxx,by,nx,ny])
    return -1

if __name__ == '__main__':
    while True:
        line = sys.stdin.readline()
        if not line :
            break
        N,M = [int(t) for t in line.split()]
        
        NMmap = []
        for i in range(N):
            line = list(sys.stdin.readline().strip())
            NMmap.append(line)
        print(moveBox(NMmap,N,M))