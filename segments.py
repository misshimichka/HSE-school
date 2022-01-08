n = int(input())
a = sorted([list(map(int, input().split()))[::-1] for i in range(n)])
endR = -10^100
count = 0
for R, L in a:
    if L > endR:
        count += 1
        endR = R
print(count)

# отрезки