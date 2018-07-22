#!/usr/bin/env python

import sys

def pre_order(tree, root):
    order = [root]

    pos = 0
    while pos < len(order):
        node = order[pos]

        if node == 0:
            order.pop(pos)
            continue

        order.insert(pos + 1, tree[node][0])
        order.insert(pos + 2, tree[node][1])

        pos += 1

    return order

def post_order(tree, root):
    order = [root]
    pos = 0

    while pos >= 0:
        node = order[pos]

        if node == 0:
            order.pop(pos)
            pos -= 1
            continue

        order.insert(pos, tree[node][1])
        order.insert(pos, tree[node][0])

        pos += 1

    return order

if __name__ == '__main__':
    T = int(sys.stdin.readline().strip())

    for t in range(T):
        tokens = sys.stdin.readline().strip().split()
        N = int(tokens[0])
        K = int(tokens[1])

        tree = {}

        for n in range(N):
            tokens = sys.stdin.readline().strip().split()
            A = int(tokens[0])
            B = int(tokens[1])

            tree[n + 1] = (A, B) # (left, right)

        pre = pre_order(tree, 1)
        post = post_order(tree, 1)

        table = {}
        K_list = []
        for i in range(len(pre)):
            if pre[i] == post[i]:
                K_list.append(set([pre[i]]))
                table[pre[i]] = K_list[-1]
            else:
                if pre[i] not in table and post[i] not in table:
                    K_list.append(set([pre[i], post[i]]))
                    table[pre[i]] = K_list[-1]
                    table[post[i]] = K_list[-1]
                elif pre[i] in table and post[i] not in table:
                    table[pre[i]].add(post[i])
                    table[post[i]] = table[pre[i]]
                elif pre[i] not in table and post[i] in table:
                    table[post[i]].add(pre[i])
                    table[pre[i]] = table[post[i]]
                else:
                    if table[pre[i]] != table[post[i]]:
                        table[pre[i]].update(table[post[i]])

                        old_post = table[post[i]]

                        for n in old_post:
                            table[n] = table[pre[i]]

                        old_post.clear()

        K_list = [x for x in K_list if len(x) > 0]

        if len(K_list) < K:
            print 'Case #{}: Impossible'.format(t + 1)
        else:
            mapping = [0] * N
            for k in range(min(K, len(K_list))):
                for n in K_list[k]:
                    mapping[n - 1] = k + 1

            if K < len(K_list):
                for k in range(K, len(K_list)):
                    for n in K_list[k]:
                        mapping[n - 1] = k

            print 'Case #{}: {}'.format(t + 1, ' '.join([str(x) for x in mapping]))

