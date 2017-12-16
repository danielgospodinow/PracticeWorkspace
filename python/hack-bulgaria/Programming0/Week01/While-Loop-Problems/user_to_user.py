a = input("Enter a:")
a = int(a)

b = input("Enter b:")
b = int(b)

if a > b:
    while a >= b:
        print(str(b))
        b += 1
elif b > a:
    while b >= a:
        print(str(a))
        a += 1
else:
    print(str(a))
