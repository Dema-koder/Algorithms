r = open('input.txt', 'r')
w = open('output.txt', 'w')

first = 0
queue = []
while True:
    command, *args = r.readline().split()
    if command == "push":
        queue.append(int(args[0]))
        w.write("ok")
    elif command == "pop":
        if len(queue) - first == 0:
            w.write("error")
        else:
            w.write(str(queue[first]))
            first += 1
    elif command == "front":
        if len(queue) - first == 0:
            w.write("error")
        else:
            w.write(str(queue[first]))
    elif command == "size":
        w.write(str(len(queue) - first))
    elif command == "clear":
        first = len(queue)
        w.write("ok")
    elif command == "exit":
        w.write("bye")
        break
    w.write('\n')
