class SimpleStack:
    def __init__(self):
        self.data = []
 
    def push(self, n):
        self.data.append(n)
 
    def pop(self):
        el = self.data[-1]
        self.data.pop(-1)
        return el
 
    def back(self):
        return self.data[-1]
 
    def size(self):
        return len(self.data)
 
    def clear(self):
        self.data.clear()
 
 
stack = SimpleStack()
 
f_out = open("output.txt", "w")
 
command = ""
commands = []
with open("input.txt") as file:
    commands = [line.rstrip() for line in file]
 
for cmd in commands:
    data = list(cmd.split())
    command = data[0]
    if command == "push":
        stack.push(int(data[1]))
        f_out.write("ok\n")
    elif command == "pop":
        f_out.write(str(stack.pop())+"\n")
    elif command == "back":
        f_out.write(str(stack.back())+"\n")
    elif command == "size":
        f_out.write(str(stack.size())+"\n")
    elif command == "clear":
        stack.clear()
        f_out.write("ok\n")
    else:
        break
 
f_out.write("bye")
f_out.close()
exit()
