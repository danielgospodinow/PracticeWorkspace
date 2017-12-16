def head(_list):
    if len(_list) > 0:
        return _list[0]

def last(_list):
    if len(_list) > 0:
        return _list[-1]

def tail(_list):
    if len(_list) > 0:
        return _list[1:]

def equal_lists(list01, list02):
    if len(list01) == len(list02):
        for i in range(len(list01)):
            if list01[i] != list02[i]:
                return False
        return True
    else:
        return False

def count_item(item, _list):
    result = 0
    for i in range(len(_list)):
        if item == _list[i]:
            result += 1
    return result

def take(number, _list):
    result = []
    for i in range(number):
        result += [_list[i]]
    return result

def drop(number, _list):
    result = []
    for i in range(number, len(_list)):
        result += [_list[i]]
    return result

def reverse(_list):
    result = []
    for item in _list[::-1]:
        result += [item]
    return result
