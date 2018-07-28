#!/bin/python3

import math
import os
import random
import re
import sys

def updateGroups(countryGroups, astro1, astro2):
    astro1Found = False
    astro2Found = False
    astro1Group = {}
    astro2Group = {}
    i = 0
    for group in countryGroups:
        if astro1 in group:
            astro1Group = group
            astro1Found = True
        if astro2 in group:
            astro2Group = group
            astro2Found = True
        if astro1Found and astro2Found:
            break

    if not astro1Found and not astro2Found:    
        newGroup = {astro1, astro2}
        countryGroups.append(newGroup)
        return
    if astro1Found and not astro2Found:
        astro1Group.add(astro2)
        return
    if not astro1Found and astro2Found:
        astro2Group.add(astro2)
        return
    newGroup = astro1Group.union(astro2Group)
    countryGroups.remove(astro1Group)
    countryGroups.remove(astro2Group)
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
    return int(totalCount)

# Complete the journeyToMoon function below.
def journeyToMoon(n, astronaut):

    countryGroups = []

    for pair in astronaut:
        updateGroups(countryGroups, pair[0], pair[1])

    singleInSetCount = getSingleInSetCount(countryGroups, n)

    return calculatePairCount(countryGroups, singleInSetCount)
     

if __name__ == '__main__':
    #fptr = open(os.environ['OUTPUT_PATH'], 'w')
    while (True):

        np = raw_input().split()

        n = int(np[0])

        p = int(np[1])  

        astronaut = []

        for _ in range(p):
            astronaut.append(list(map(int, raw_input().rstrip().split())))

        result = int(journeyToMoon(n, astronaut))

        print (result)

    #fptr.write(str(result) + '\n')

    #fptr.close()
