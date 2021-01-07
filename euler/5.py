import math

n = 20
result = 1

# check if x is a prime number
def check_prime(x):
  for i in range(2, x):
    if x % i == 0:
      return False # if not return false
  return True # if prime return true

for i in range(2, n+1):
  if check_prime(i):
    result *= i**(math.floor(math.log(n)/math.log(i)))

print(result)
