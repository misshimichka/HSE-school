# динамика
mem = {}
s = 'asdfregsjj'
n = len(s)

isPmem = {}


def isP(i, j):
    if i >= j:
        return True
    if (i, j) in isPmem:
        return isPmem[(i, j)]
    f = (s[i] == s[j]) and isP(i + 1, j - 1)
    isPmem[(i, j)] = f
    return f


mem[n] = 0
for i in range(n)[::-1]:
    m = n
    for j in range(i, n):
        if isP(i, j):
            m = min(m, 1 + mem[j + 1])
    mem[1] = m

print()