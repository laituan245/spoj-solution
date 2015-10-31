# TIPTOP - Tip Top Game
# http://www.spoj.com/problems/TIPTOP/

from math import sqrt

t = int(raw_input())
for z in range(t):
    n = int(raw_input())
    k = int(sqrt(n))
    if (k * k == n):
        print "Case " + str(z+1) + ": Yes"
    else:
        print "Case " + str(z+1) + ": No"
