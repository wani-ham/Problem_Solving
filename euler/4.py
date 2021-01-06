import math

p = 0
result = 0

# check if the number is made from the product of 3-digit numbers
# return true if yes, false if no
# use the inequation 100 < x/i < 1000
def check_digits(x):
  global p
  for i in range(math.ceil(x/1000), math.floor(math.sqrt(x))):
    if x % i == 0:
      p = i
      return True
  return False

# possible types : abccba, abcba
for a in range(1, 10):
  for b in range(0, 10):
    for c in range(0, 10):
      abccba = 100001*a + 10010*b + 1100*c
      abcba = 10001*a + 1010*b + 100*c
      if check_digits(abccba) and result < abccba:
        result = abccba
      elif check_digits(abcba) and result < abcba:
        result = abcba
      else:
        pass

check_digits(result) # run the function for the last time to get p
print(p, "*", result//p, "=", result)  
