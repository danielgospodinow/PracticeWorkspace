n = input("Enter n: ")
n = int(n)

start = 0
numbers = []

while start < n:
    number = input()
    number = int(number)
    numbers += [number]
    start += 1

total_sum = 0

for number in numbers:
    total_sum += number

avg = total_sum / len(numbers)

print("The average is: " + str(avg))
