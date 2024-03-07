def main():
    from sys import stdin, stdout

    a = list(map(int, stdin.readline().split()))
    n = a[0]
    a = a[1:]

    st = [0] * n
    sz = 0

    i = 0
    while i < n:
        st[sz] = a[i]
        sz += 1

        if sz >= 3 and st[sz - 1] == st[sz - 2] and st[sz - 2] == st[sz - 3]:
            while i + 1 < n and a[i + 1] == st[sz - 1]:
                i += 1
                st[sz] = a[i]
                sz += 1

            color = st[sz - 1]

            while sz > 0 and st[sz - 1] == color:
                sz -= 1

        i += 1

    stdout.write(str(n - sz))


main()
