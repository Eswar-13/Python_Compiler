data: list[float] = [-2.3, 3.14, 0.9, 11, -9.1]
data[0]=-2
i:int=0
j:int=0 

def compute_min(data: list[float]) -> float:
  min_value: float = 100
  for i in range(5):
    if data[i] < min_value:
      min_value = data[i]
  return min_value

def compute_avg(data: list[float]) -> float:
  sum_values: float = 0
  for i in range(5):
    sum_values += data[i]
  return sum_values / len(data)

def compute_mode(data: list[float]) -> float:
  mode_count: int = 0
  mode_value: float = 1
  for i in range(5):
    count_value: int = 0
    for j in range(5):
      if data[i] == data[j]:
        count_value += 1
    if count_value > mode_count:
      mode_count = count_value
      mode_value = data[i]
  return mode_value

def main() -> None:
  min_value: float = compute_min(data)
  print("Minimum i: ", min_value)

  avg_value: float = compute_avg(data)
  print("Average i: ", avg_value)

  mode_value: float = compute_mode(data)
  print("Mode i: ", mode_value)
  

if __name__ == "__main__":
  main()