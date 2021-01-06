a1 = 1
a2 = 2
a3 = 3
tot = 0
n = 4000000 

while a3 < n:
  a3 = a1 + a2
  if a3 % 2 == 0:
    tot += a3
  a1 = a2
  a2 = a3 

print(tot + 2) # including the second element

