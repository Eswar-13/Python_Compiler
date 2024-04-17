a:list[int]=[1,2,3,4,5]
i:int=1
if a[0]==5 :
  for i in range(5):
    a[i]=2
    while a[i]<10 :
      a[i]=a[i]+1
      break
    continue
else :
  for i in range(1,5):
    a[i]=2
    while a[i]>10 :
      a[i]=a[i]-1
      break
    continue
        