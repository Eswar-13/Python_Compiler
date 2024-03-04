data: list[float] = [-2.3, 3.14, 0.9, 11, -9.1]

def compute_min(data: list[float]) -> float:
  min_value: float = float('inf')
  for value in data:
    if value < min_value:
      min_value = value
  return min_value

def compute_avg(data: list[float]) -> float:
  sum_values: float = 0
  for value in data:
    sum_values += value
  return sum_values / len(data)

def compute_mode(data: list[float]) -> tuple:
  mode_count: int = 0
  mode_value: float = None
  for value in data:
    count_value: int = 0
    for other_value in data:
      if value == other_value:
        count_value += 1
    if count_value > mode_count:
      mode_count = count_value
      mode_value = value
  return mode_value

def main() -> None:
  min_value: float = compute_min(data)
  print("Minimum value: ", min_value)

  avg_value: float = compute_avg(data)
  print("Average value: ", avg_value)

  mode_value, mode_count = compute_mode(data)
  print("Mode value: ", mode_value)
  print("Mode count: ", mode_count)

if __name__ == "__main__":
  main()
