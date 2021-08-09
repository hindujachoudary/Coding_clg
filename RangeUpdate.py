t=int(input())
while(t):
    t-=1
    q=int(input())
    rem=[0]*7
    while(q):
        q-=1
        l,r=map(int,input().split())
        rem[l]+=1
        rem[r+1]-=1
    b = [0]*7
    b[0]=rem[0]
    for i in range(1,7):
        b[i]=rem[i]+b[i-1]
    print(*b)