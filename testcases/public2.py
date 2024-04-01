data: list[float] = [-2.3, 3.14, 0.9, 11, -9.1]
def compute_min() -> float:
  min_value: int = 1
  i: int = 0
  for i in range(len(data)):
    j: int = 0
    if not min_value:
      j: int = 0
      min_value = data[i]
    elif data[i] < min_value:
      min_value = data[i]
  return min_value


def compute_avg() -> float:
  avg_value: float = 1
  sum: int = 0
  i: int = 0
  for i in range(len(data)):
    sum += data[i]
  return sum / len(data)


def main():
  min_value: float = compute_min()
  print("Minimum value: ")
  print(min_value)
  avg_value: float = compute_avg()
  print("Average value: ")
  print(avg_value)
  return


if __name__ == "__main__":
  main()
