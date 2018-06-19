import sys
import operator

def pickNumbers(numbers):
    countSet = dict()
    countSet2 = dict()
    for number in numbers:
        if countSet.has_key(number):
            countSet[number] = countSet[number] + 1
            countSet2[number] = countSet2[number] + 1
        else:
            countSet[number] = 1
            countSet2[number] = 1
            
        if countSet.has_key(number - 1):
            countSet[number - 1] = countSet[number - 1] + 1
        
        if countSet.has_key(number + 1):
            countSet2[number + 1] = countSet2[number + 1] + 1
    maxV = max(countSet.values())
    maxV2 = max(countSet2.values())

    if maxV > maxV2:
        return maxV

    return maxV2

count = raw_input()
numbers = map(int, raw_input().split(' '))

print (pickNumbers(numbers))