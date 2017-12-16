from datetime import date

first_name = input("Enter first name: ")
second_name = input("Enter second name: ")
third_name = input("Enter third name: ")
birth_year = input("Enter year of birth: ")
birth_year = int(birth_year)
current_year = date.today().year

print(dict(current_age = current_year - birth_year, birth_year = birth_year, second_name = second_name, third_name = third_name, first_name = first_name))
