def fibonacci(n: int) -> int:
  if n < 2:
    return 1
  else:
    return fibonacci(n - 1) + fibonacci(n - 2)

def perimeter(length: int, width: int) -> int:
  return 2*(length+width)

class Device:

  def __init__(self, make: str, model: str):
    self.make: str = make
    self.model: str = model

  def start(self) -> None:
    print(self.make)
    print(self.model)


class Laptop(Device):

  def __init__(self, make: str, model: str, year: int):
    self.make = make
    self.model = model
    self.year: int = year

  def start(self) -> None:
    print(self.year)
    print(self.make)
    print(self.model)


def main():
  x: int = 13
  y: int = 7
  s: str = "Cs335"
  b: bool = True

  lst: list[int] = [1, 2, 3, 4, 5]

  a: int = x + y
  b: int = x - y
  c: int = x * y
  d: int = x / y
  e: int = x // y
  f: int = x % y

  print(x == y)
  print(x != y)
  print(x > y)
  print(x < y)
  print(x >= y)
  print(x <= y)

  print(True and False)
  print(True or False)
  print(not True)

  p: int = 10
  q: int = 11
  print(p & q)
  print(p | q)
  print(p ^ q)
  print(~p)

  x = 5
  x += 3
  x -= 2
  x *= 4
  x /= 3
  x //= 2
  x %= 3
  x **= 2
  y = 2
  y &= 7
  y |= 8
  y ^= 18
  y <<= 2
  y >>= 2

  if x > 10:
    print("x is greater than 10")
  elif (x < 5):
    print("x is less than 5")
  else:
    print("x is between 5 and 10")

  i : int =0
  for i in range(0, 5):
    print(lst[i])

  i = 0
  while i < 5:
    print(i)
    i += 1
    if i == 3:
      break

  fact: int = fibonacci(5)
  print(fact)

  per: int = perimeter(5, 3)
  print(per)

  pc:Laptop = Laptop("Dell", "Inspiron", 2021)
  pc.start()

if __name__ == "__main__":
  main()