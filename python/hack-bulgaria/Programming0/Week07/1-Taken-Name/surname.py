def taken_name(surname_husband, surname_wife):
    if surname_husband.lower() in surname_wife.lower():
        return True
    return False

test01 = ["Petrov", "Petrova"]
test02 = ["Ivanov", "Tsvetanova"]
test03 = ["Petrov", "Ivanova-Petrova"]

print(taken_name(*test03))
