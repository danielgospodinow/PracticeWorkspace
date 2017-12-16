n = input("Enter n: ")
n = int(n)

summ = 0

i = 1

while i <= n:
    if i % 2 == 1:
        summ += i
    i += 1

print("The sum is: " + str(summ))
