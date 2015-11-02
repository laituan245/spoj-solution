# FACTMUL - Product of factorials
# http://www.spoj.com/problems/FACTMUL/

modulo = 109546051211
n = int(raw_input())
if (n > 587116):
    print 0
else:
    rs = 1
    factorial = 1
    for i in range (2, n + 1):
        factorial = factorial * i
        if (factorial >= modulo):
            factorial = factorial % modulo
        rs = rs * factorial
        if (rs >= modulo):
            rs = rs % modulo
    print rs
