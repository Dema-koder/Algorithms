def main():
    from sys import stdin, stdout
 
    cnt = [0] * 10
    stdin.readline()
    for i in list(map(int, stdin.readline().split())):
        cnt[i] += 1
 
    stdout.write("".join(map(str, [chr(48 + i) * cnt[i] for i in range(9, -1, -1)])))
 
 
main()
