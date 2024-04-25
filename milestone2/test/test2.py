data: list[float] = [-2.3, 3.14, 0.9, 11, -9.1]

def compute_min(data: list[float]) -> float:
  min_value: float = 1.2
  value:int=0
  for value in range(2):
    if value < min_value:
      min_value = value
  return min_value

def compute_avg(data: list[float]) -> float:
  sum_values: float = 0
  value:int=0
  for value in range(2):
    sum_values += value
  return sum_values / len(data)

def compute_mode(data: list[float]) -> float:
  mode_count: int = 0
  mode_value: float = 1.2
  value:int=0
  for value in range(2):
    count_value: int = 0
    other_value:int=0
    for other_value in range(2):
      if value == other_value:
        count_value += 1
    if count_value > mode_count:
      mode_count = count_value
      mode_value = value
  return mode_value

def main() -> None:
  i:int=0
  avg_value: float = compute_avg(data)
  print("Average value: ", avg_value)

  mode_value:float=compute_mode(data)
  mode_count:float = compute_mode(data)
  print("Mode value: ", mode_value)
  print("Mode count: ", mode_count)

if __name__ == "__main__":
  main()
