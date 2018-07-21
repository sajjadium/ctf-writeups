#!/usr/bin/env python

import sys

def ethan_contains(A, B):
    i = 1
    j = 1

    while True:
        if i > len(A):
            return True

        if j > len(B):
            return False

        if A[i - 1] == B[j - 1]:
            i += 1
            j += 1
        elif i == 1:
            j += 1
        else:
            i = 1

T = int(sys.stdin.readline().strip())

for t in range(T):
    A = sys.stdin.readline().strip()

    word = None

    for a in range(1, len(A)):
        B = A[0:a] + A

        if not ethan_contains(A, B):
            word = B
            break

    print 'Case #{}: {}'.format(t + 1, 'Impossible' if word is None else word)

