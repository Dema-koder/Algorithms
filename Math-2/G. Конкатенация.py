n = int(input())
a = list(map(int, input().split()))
 
ans, s = 0, sum(a)
 
for i in a:
    ans += s * pow(10, len(str(i))) + i * n
 
print(ans)
