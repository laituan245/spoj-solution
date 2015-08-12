# UJ - Uncle Jack
# http://www.spoj.com/problems/UJ/
# laituanksa245

while True:
    inputs = raw_input().strip().split(" ")
    if inputs[0] == "0" and inputs[1] == "0":
        break
    print int(inputs[0]) ** int(inputs[1])
