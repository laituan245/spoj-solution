# TREE1 - Tree
# http://www.spoj.com/problems/TREE1/

factorials = []
factorials.append(1)
factorials.append(1)
factorials.append(2)
factorials.append(6)
factorials.append(24)
factorials.append(120)
factorials.append(720)
factorials.append(5040)
factorials.append(40320)
factorials.append(362880)
factorials.append(3628800)
factorials.append(39916800)
factorials.append(479001600)
factorials.append(6227020800)
factorials.append(87178291200)
factorials.append(1307674368000)
factorials.append(20922789888000)
factorials.append(355687428096000)
factorials.append(6402373705728000)
factorials.append(121645100408832000)
factorials.append(2432902008176640000)
factorials.append(51090942171709440000)
factorials.append(1124000727777607680000)
factorials.append(25852016738884976640000)
factorials.append(620448401733239439360000)
factorials.append(15511210043330985984000000)
factorials.append(403291461126605635584000000)
factorials.append(10888869450418352160768000000)
factorials.append(304888344611713860501504000000)
factorials.append(8841761993739701954543616000000)
factorials.append(265252859812191058636308480000000)

def constructTree(a, left, right):
    if left > right:
        return None
    if left == right:
        return [a[left], None, None]
    idx = left + 1
    while idx <= right and a[idx] < a[left]:
        idx += 1
    return [a[left], constructTree(a, left+1, idx-1), constructTree(a, idx, right)]

def nChoosek(n, k):
    rs = factorials[n]
    rs = rs / factorials[n-k]
    rs = rs / factorials[k]
    return rs

def findAns(tree):
    if tree == None:
        return (1, 0)
    if tree[1] == None and tree[2] == None:
        return (1, 1)
    leftResult0, leftResult1 = findAns(tree[1])
    rightResult0, rightResult1 = findAns(tree[2])
    result0 = leftResult0 * rightResult0 * nChoosek(leftResult1 + rightResult1, leftResult1)
    result1 = 1 + leftResult1 + rightResult1
    return (result0, result1)


t = int(raw_input())
for z in range(t):
    n = int(raw_input())
    a = map(int, raw_input().strip().split())
    myTree = constructTree(a, 0, n-1)
    print findAns(myTree)[0]
