a = input("Enter a: ")
b = input("Enter b: ")
oper = input("Enter operation: ")

a = int(a)
b = int(b)

if oper == "+":
    result = a + b
    print("The result is: " + str(result))
elif oper == "-":
    result = a - b
    print("The result is: " + str(result))
elif oper == "*":
    result = a * b
    print("The result is: " + str(result))
elif oper == "/":
    result = a / b
    print("The result is: " + str(result))
else:
    print("We do not support that operation.")

    
