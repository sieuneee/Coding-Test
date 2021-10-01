#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'fibonacciModified' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER t1
#  2. INTEGER t2
#  3. INTEGER n
#
  
def fib(a,b,n):
    for i in range(n-1):
        a,b = b,a+b**2
    return a

a,b,n = map(int,input().split())
print(fib(a,b,n))
