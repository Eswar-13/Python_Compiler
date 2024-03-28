b:list[int]=[1,2]
b[2]=b[1]
a:list[int]=[1,2]
if a[0] > 2 :
  c:int = 6
  b[2] = c
c:int = 7
while c>1 :
  a[0]=b[0]+1
  b[0]=a[1]
  c=c+1