n = 1000 # a+b+c = n
max = n - 2 # 1 <= a, b, c <= max

for i in range(1, max + 1):
  if (n * (n - 2*i)) % (2*(n - i)) == 0 and i < n/2:
    a = int((n*n - 2*n*i)/(2*(n - i)))
    b = int(i)
    c = int(n - b - a)
    print(a, b, c, int(a*b*c))
