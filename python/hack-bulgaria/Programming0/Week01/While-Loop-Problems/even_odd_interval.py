start = input("Enter start: ")
start = int(start)

end = input("Enter end: ")
end = int(end)

while start <= end:
    n = start
    if n % 2 == 0:
        print(str(n) + " - even")
    else:
        print(str(n) + " - odd")
    start += 1
