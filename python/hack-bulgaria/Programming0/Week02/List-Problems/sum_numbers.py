n = input("Enter n: ")
n = int(n)

start = 0
numbers = []

while start < n:
    number = input()
    number = int(number)
    numbers = numbers + [number]
    start += 1

total_sum = 0

for number in numbers:
    total_sum += number

print("Total sum is: " + str(total_sum))
