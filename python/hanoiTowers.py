#!/usr/bin/python3

def towersOfHanoi(start, temp, end):
    printTowers(start, temp, end)
    moveDisks(start, temp, end, len(start))
    printTowers(start, temp, end)

def printTowers(tower1, tower2, tower3):
    print("Tower 1: {} \nTower 2: {}\nTower 3: {}\n".format(tower1, tower2, tower3))

def moveDisks(start, temp, end, n):
    if n == 1:
        end.append(start.pop())
        return

    moveDisks(start, end, temp, n-1)
    moveDisks(start, temp, end, 1)
    moveDisks(temp, start, end, n-1)
    
towersOfHanoi([5, 4, 3, 2, 1], [], [])