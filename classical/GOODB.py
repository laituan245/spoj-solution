# GOODB - Good Predictions
# http://www.spoj.com/problems/GOODB/
inputStr = raw_input()
tempList = inputStr.strip().split (" ")
n = int(tempList[0])
w = int(tempList[1])
t = int(tempList[2])
r = int(tempList[3])

factorial = [1 for i in range(301)]
for i in range (1, 301):
    factorial[i] = i * factorial[i-1]

ans = factorial[n]/factorial[w];
ans = ans/factorial[t];
ans = ans/factorial[r];
ans = ans % (1000000000 + 7);
print ans
