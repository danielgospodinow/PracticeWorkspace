n = input("Enter count of numbers: ")
n = int(n)

count = 1
even_numbers = []

while count <= n:
    number = input("Enter number: ")
    number = int(number)
    
    if number % 2 == 0:
        even_numbers += [number]

    count += 1

print("Count of evens: " + str(len(even_numbers)))
print("Evens are: ")

for x in range(len(even_numbers)):
    print(even_numbers[x])
