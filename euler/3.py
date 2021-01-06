n = 600851475143
factor = 2 # start with the smallest prime number

while n > 1:
  if n % factor == 0:
    n /= factor
  
  else:
    factor += 1

print(factor)
