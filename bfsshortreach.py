#!/bin/python

import math
import os
import random
import re
import sys

# Complete the bfs function below.
def bfs(n, m, edges, s):
    

q = int(raw_input())

for q_itr in xrange(q):
    nm = raw_input().split()

    n = int(nm[0])
    m = int(nm[1])

    edges = []

    for _ in xrange(m):
        edges.append(map(int, raw_input().rstrip().split()))

    s = int(raw_input())
    result = bfs(n, m, edges, s)