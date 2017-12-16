n = input("Enter n: ")
n = int(n)

start = 0
numbers = []

while start < n:
    number = input("Enter number " + str(start+1) + ": ")
    number = int(number)
    numbers = numbers + [number]
    start += 1

print(min(numbers))
