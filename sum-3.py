# тупой перебор

a = set(map(int, input().split()))
s = int(input())
for x in a:
    for y in a:
        if (s - x - y) in a:
            print(x, y, s - x - y)