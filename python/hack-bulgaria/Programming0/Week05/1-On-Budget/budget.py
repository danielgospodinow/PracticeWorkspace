def on_budget(books, budget):
    result = {"books_on_budget" : 0, "loan" : 0}
    books.sort()
    current_book = 0
    books_left = []
    
    for i in range(len(books)):
        if books[i] < budget:
            result["books_on_budget"] +=1
            budget -= books[i]
        else:
            books_left += [books[i]]
            
    sum_of_remaining_books = 0
    
    if len(books_left) > 0:
        for i in range(len(books_left)):
            sum_of_remaining_books += books_left[i]     
        result["loan"] = sum_of_remaining_books - budget
    
    return result


test01 = [[0, 10, 100, 5, 3, 8, 25], 35]
test02 = [[0,0,0], 10]
test03 = [[50,60,100], 20]

print(on_budget(*test03))
