#!/usr/bin/env python

def visit_campus(A, K, V):
    for i in xrange(V):
        A.sort(key=lambda a: (a['visited'], a['popularity']))

        for j in xrange(K):
            A[j]['visited'] += 1

        if len(set([a['visited'] for a in A])) == 1:
            return visit_campus(A, K, V % (i + 1))

    return [a['name'] for a in sorted(A[0:K], key=lambda a: a['popularity'])]

if __name__ == '__main__':
    with open('tourist.txt') as f:
        T = int(f.readline().strip())

        for i in xrange(T):
            tokens = f.readline().strip().split()

            N = int(tokens[0])
            K = int(tokens[1])
            V = long(tokens[2])
            A = []

            for j in xrange(N):
                A.append({
                    'name': f.readline().strip(),
                    'popularity': j,
                    'visited': 0
                })

            names = visit_campus(A, K, V)
            print 'Case #{}: {}'.format(i + 1, ' '.join(names))

