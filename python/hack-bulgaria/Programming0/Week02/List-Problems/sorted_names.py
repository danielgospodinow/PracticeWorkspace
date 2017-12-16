n = input("Enter count of names: ")
n = int(n)

count = 0
names = []

while count < n:
    name = input("Name "+ str(count+1) +": ")
    names += [name]
    count += 1

names = sorted(names)

for name in names:
    print(name)
