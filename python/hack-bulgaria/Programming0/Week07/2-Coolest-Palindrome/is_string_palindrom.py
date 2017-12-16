def is_string_palindrom(string):
    isPalindrom = False
    clearString = ""
    notNeededSymbols = ["?", "!", ",", ".", " "]
    reversedString = ""

    for i in range(len(string)):
        goodToGo = True
        for j in range(len(notNeededSymbols)):
            if string[i] == notNeededSymbols[j]:
                goodToGo = False
                
        if goodToGo == True:
            clearString += string[i].lower()

    for item in clearString[::-1]:
        reversedString += item

    if clearString == reversedString:
        return True
    else:
        return False

test01 = "Az obi4am ma4 i boza"
test02 = "A Toyota!"
test03 = "bozaaa"
test04 = "Kapak!"

print(is_string_palindrom(test03))
