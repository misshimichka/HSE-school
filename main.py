mem = {}

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


print(f("abaaaxyzyxxyyx", 0))