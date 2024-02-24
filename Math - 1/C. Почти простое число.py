n = int(input())
i = 2
divs = []
while i * i <= n:
    while n % i == 0:
        divs.append(i)
        n //= i
    i += 1
if n > 1:
    divs.append(n)
 
print("YES" if len(divs) == 2 and divs[0] != divs[1] else "NO")
