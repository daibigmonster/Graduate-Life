s = input()
s += s
lengths = []

for i in range(int(len(s)/2)):
    jewelry = ['A','B','C','D','E']
    if s[i] in jewelry:
        begin,end = i,i+1
        jewelry.remove(s[begin])
        while jewelry != []:
            if s[end] in jewelry:
                jewelry.remove(s[end])
            end += 1
        length = end - begin
        if length != 0:
            lengths.append(length)

print(int(len(s)/2 - min(lengths)))