#!/bin/python3

import math
import os
import random
import re
import sys

def updateGroups(countryGroups, astro1, astro2):

    for group in countryGroups:
        if astro1 in group:
            group.add(astro2)
            return
        if astro2 in group:
            group.add(astro1)
            return
    newGroup = {astro1, astro2}
    countryGroups.append(newGroup)

def getSingleInSetCount(countryGroups, n):
    groupsSize = 0
    for group in countryGroups:
        groupsSize = groupsSize + len(group)

    return n - groupsSize

def calculatePairCount(countryGroups, singleInSetCount):
    totalCount = singleInSetCount * (singleInSetCount - 1) / 2
    currGroup = 0
    groupCounts = []
    for group in countryGroups:
        groupCounts.append(len(group))

    for i in range(len(groupCounts)):
        for j in range(i + 1, len(groupCounts)):
            totalCount = totalCount + groupCounts[i] * groupCounts[j]
    for i in range(len(groupCounts)):
        totalCount = totalCount + groupCounts[i] * singleInSetCount
    return totalCount

# Complete the journeyToMoon function below.
def journeyToMoon(n, astronaut):

    countryGroups = []

    for pair in astronaut:
        updateGroups(countryGroups, pair[0], pair[1])

    singleInSetCount = getSingleInSetCount(countryGroups, n)

    return calculatePairCount(countryGroups, singleInSetCount)
     

if __name__ == '__main__':
    #fptr = open(os.environ['OUTPUT_PATH'], 'w')

    np = input().split()

    n = int(np[0])

    p = int(np[1])

    astronaut = []

    for _ in range(p):
        astronaut.append(list(map(int, input().rstrip().split())))

    result = int(journeyToMoon(n, astronaut))

    print (result)

    #fptr.write(str(result) + '\n')

    #fptr.close()
