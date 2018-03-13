n = int(input())
for i in range(n):
  s = int(input())
  v = int(input())
  o = int(input())
  sub = [""] * s
  verb = [""] * v
  obj = [""] * o
  for i in range(s):
    sub[i] = input()
  for i in range(v):
    verb[i] = input()
  for i in range(o):
    obj[i] = input()
    
  for i in sub:
    for j in verb:
      for k in obj:
        print(i, end = " ")
        print(j, end = " ")
        print(k, end = ".")
        print()
