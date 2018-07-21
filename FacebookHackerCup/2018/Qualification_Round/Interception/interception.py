#!/usr/bin/env python

import sys

T = int(sys.stdin.readline().strip())

for t in xrange(T):
    N = int(sys.stdin.readline().strip())
    P = []

    for _ in xrange(N + 1):
        P.append(float(sys.stdin.readline().strip()))

    if (N - 1) % 2 == 0:
        print 'Case #{}: 1'.format(t + 1)
        print '0.0'
    else:
        print 'Case #{}: 0'.format(t + 1)

