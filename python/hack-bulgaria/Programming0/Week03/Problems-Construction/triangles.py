import math

def is_triangle(a,b,c):
    if a+b>c and a+c>b and b+c>a:
        return True
    else:
        return False

def area(a,b,c):
    p = (a+b+c)/2
    S = math.sqrt(p*(p-a)*(p-b)*(p-c))
    return S

def is_pythagorean(a,b,c):
    if a**2 + b**2 == c**2:
        return True
    else:
        return False

def max_area(triangles):
    max_S = 0
    result = []
    for triangle in triangles:
        if area(triangle[0], triangle[1], triangle[2]) > max_S:
            max_S = area(triangle[0], triangle[1], triangle[2])
            result = triangle
    return result


triangles = [ [3, 4, 5], [7, 8, 9] ]

print(max_area(triangles))
