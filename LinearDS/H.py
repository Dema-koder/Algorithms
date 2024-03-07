from sys import stdin, stdout


def main():
    stack_size = 0
    ans = 0

    for c in stdin.readline().strip():
        if c == '(':
            stack_size += 1
        elif stack_size > 0:
            stack_size -= 1
        else:
            ans += 1

    stdout.write(str(ans + stack_size))


main()
