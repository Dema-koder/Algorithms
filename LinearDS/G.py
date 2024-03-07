stack = []
for cur in input().strip().split():
    if cur not in '+-*':
        stack.append(int(cur))
    elif cur == '+':
        stack.append(stack.pop() + stack.pop())
    elif cur == '-':
        stack.append(-stack.pop() + stack.pop())
    elif cur == '*':
        stack.append(stack.pop() * stack.pop())

print(stack[0])
