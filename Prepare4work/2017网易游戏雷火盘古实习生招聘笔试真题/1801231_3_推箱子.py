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