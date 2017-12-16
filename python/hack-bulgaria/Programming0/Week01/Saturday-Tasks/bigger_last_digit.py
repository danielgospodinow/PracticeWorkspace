n = input("Enter first number: ")
n = int(n)

m = input("Enter second number: ")
m = int(m)

last_digit_n = n % 10
last_digit_m = m % 10

if last_digit_n > last_digit_m:
    print(n)
elif last_digit_n < last_digit_m:
    print(m)
else:
    if n > m:
        print(n)
    else:
        print(m)
