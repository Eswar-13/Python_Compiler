def compute_min(data:list[int]) -> int:
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


def compute_avg(data:list[int]) -> int:
  avg_value: int = 1
  sum: int = 0
  i: int = 0
  for i in range(len(data)):
    sum += data[i]
  return sum / len(data)


def main():
  data: list[int] = [-1, 9, 3, 15, 24]
  min_value: int = compute_min(data)
  print("Minimum value: ")
  print(min_value)
  avg_value: int = compute_avg(data)
  print("Average value: ")
  print(avg_value)


if __name__ == "__main__":
  main()
