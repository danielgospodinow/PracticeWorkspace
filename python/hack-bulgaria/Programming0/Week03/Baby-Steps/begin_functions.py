def square(number):
    return number*number

def fact(number):
    result = 1
    while(number>0):
        result*=number
        number-=1
    return result

def count_elements(items):
    count = 0
    for item in items:
        count += 1
    return count

def member(x,xs):
    for xitem in xs:
        if xitem == x:
            return True
    return False

def grades_that_pass(students, grades, limit):
    result = []
    for i in range(len(students)):
        if grades[i] >= limit:
            result += [students[i]]
    return result
