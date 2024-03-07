nine=[]
ten=[]
eleven=[]
n = int(input())
for i in range(n):
    arr=tuple(input().split())
    if arr[0]=="9":
        nine.append(arr)
    elif arr[0]=="10":
        ten.append(arr)
    else:
        eleven.append(arr)
temp=""
if len(nine)>0:
    for i in range(len(nine)):
        temp=nine[i][0]+" "+nine[i][1]
        print(temp)
if len(ten)>0:
    for i in range(len(ten)):
        temp=ten[i][0]+" "+ten[i][1]
        print(temp)
if len(eleven)>0:
    for i in range(len(eleven)):
        temp=eleven[i][0]+" "+eleven[i][1]
        print(temp)
