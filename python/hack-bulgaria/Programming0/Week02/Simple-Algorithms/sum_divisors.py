n = input("Enter a number: ")
n = int(n)

divisors = []

for x in range (1, n-1):
    if n % x == 0:
        divisors += [x]

total_sum = 0

for divisor in divisors:
    total_sum += divisor

print("The total sum of the divisors is: " + str(total_sum))
