def inner_trim(string):
    words = []
    tempWords = []
    string = list(string)
    currentWord = ""
    result = ""
    
    for i in range(len(string)):
        if string[i] != " ":
            currentWord += string[i]
        else:
            tempWords += [currentWord]
            currentWord = ""

    for i in range(len(tempWords)):
        if tempWords[i] != " " and tempWords[i] != "":
            words += [tempWords[i]]

    for i in range(len(words)):
        if i == len(words)-1:
            result += words[i]
            break
        result += (words[i] + " ")
    
    return result
    

test01 = "   Python    Django   "
print(inner_trim(test01))
