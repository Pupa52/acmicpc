n = int(input())
l0 = list()
l1 = list()
cnt = 0
ind = 0
while True:
    x = n-5*cnt
    cnt+=1
    if x < 0:
        break
    l0.append(x)
for k in l0:
    if k%3 == 0:
        l1.append((k//3)+ind)
    ind+=1

if len(l1)==0:
    print(-1)
else:
    print(min(l1))
