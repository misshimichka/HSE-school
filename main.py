# Ленивая динамика: палиндромы
def isPal(s):
    return s == s[::-1]


def f(s, i):
    if i == len(s):
        return 0
    if i in mem:  # кеширование
        return mem[i]
    m = len(s)
    for j in range(i, len(s)):
        if isPal(s[i:j+1]):
            m = min(m, 1 + f(s, j+1))
    mem[i] = m
    return m

# динамика
mem = {}
s = 'asdfregsjj'
n = len(s)

isPmem = {}
def isP(i, j):
    if i >= j: return True
    if (i,j) in isPmem: return isPmem[(i, j)]
    f = (s[i] == s[j]) and isP(i+1, j-1)
    isPmem[(i, j)] = f


mem[n] = 0
for i in range(n)[::-1]:
    m = n
    for j in range(i, n):
        if isP(i, j):
            m = min(m, 1 + mem[j + 1])
    mem[1] = m
print(mem[0])



print(f("abaaaxyzyxxyyx", 0))