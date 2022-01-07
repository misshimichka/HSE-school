# с указателями

a = sorted(map(int, input().split()))
s = int(input())
for x in a:
    need = s - x
    iz = len(a) - 1
    for y in a:
        while iz > 0 and y + a[iz] > need:
            iz -= 1
        if y + a[iz] == need:
            print(x, y, s - x - y)