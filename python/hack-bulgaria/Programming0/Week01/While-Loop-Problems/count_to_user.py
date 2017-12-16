n = input("Enter number: ")
n = int(n)

print("Counting from 1 to " + str(n))
current = 1
while current <= n:
    print(current)
    current = current + 1

print("Counting from " + str(n) +" to 1")
current = n
while current >= 1:
    print(current)
    current = current - 1
