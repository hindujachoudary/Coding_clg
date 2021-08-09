n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
c=0
p=0
count=[0]*101
for i in range(n):
    count[a[i]]+=1
a=list(set(a))
n=len(a)
for i in range(n):
    for j in range(n):
        for k in range(max(i,j),n):
            s=a[i]+a[j]+a[k]
            if(a[i]!=a[j] and a[j]!=a[k] and a[i]!=a[k]):
                if(s%a[i]==0) and (s%a[j]!=0) and (s%a[k]!=0):
                    c+=count[a[i]]*count[a[j]]*count[a[k]]
                if(s%a[i]!=0) and (s%a[j]==0) and (s%a[k]!=0):
                    c+=count[a[i]]*count[a[j]]*count[a[k]]
                if(s%a[i]!=0) and (s%a[j]!=0) and (s%a[k]==0):
                    c+=count[a[i]]*count[a[j]]*count[a[k]]
            if(a[i]==a[j] and a[i]!=a[k]):
                if(s%a[k]==0 and s%a[i]!=0):
                    c+=count[a[k]]*count[a[i]]*(count[a[i]]-1)//2
            if(a[i]==a[k] and a[i]!=a[j]):
                if(s%a[j]==0 and s%a[i]!=0):
                    c+=count[a[j]]*count[a[i]]*(count[a[i]]-1)//2
            if(a[j]==a[k] and a[j]!=a[i]):
                if(s%a[i]==0 and s%a[j]!=0):
                    c+=count[a[i]]*count[a[j]]*(count[a[j]]-1)//2
            # print(a[i], a[j], a[k], c)
print(c*3)