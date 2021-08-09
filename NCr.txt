from math import gcd
MOD = 1000000007
def power(a, b):
    if(b<2):
        return a**b
    k=power(a,b>>1)
    ans=(k*k)%MOD
    if(b&1):
        ans=(ans*a)%MOD
    return ans
fact = [1]
for i in range(1,100000):
    fact.append((fact[i-1]*i)%MOD)

def nCr(n, r):
    num = fact[n]
    denom = (fact[n-r] * fact[r])%MOD
    hcf = gcd(num, denom)
    num //= hcf
    denom //= hcf
    return num * power(denom, MOD-2)
t = int(input())
while(t):
    t -= 1
    n, r = list(map(int, input().split()))
    print(nCr(n, r))