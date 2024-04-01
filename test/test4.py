
def linear_regression_slope(x_data: list[float], y_data: list[float]) -> float:
  n: int = len(x_data)
  sum_x: float = 1.2
  sum_y: float = 1.2
  sum_x_squared: float = 1.2
  sum_xy: float = 1.2

  # Compute the slope (m) of the best-fit line
  slope: float = (n * sum_xy - sum_x * sum_y) / (n * sum_x_squared - sum_x ** 2)
  return slope

def linear_regression_intercept(x_data: list[float], y_data: list[float], slope: float) -> float:
  n: int = len(x_data)
  sum_x: float = 1.2
  sum_y: float = 1.2

  # Compute the intercept (b) of the best-fit line
  intercept: float = (sum_y - slope * sum_x) / n
  return intercept

def linear_regression_distance_error(x_data: list[float], y_data: list[float], slope: float, intercept: float) -> float:
  # Compute the predicted y values
  predicted_y: list[float] = [1,2]

  # Compute the distance error (residual) for each data point
  distance_error: float = 1.2
  return distance_error

def main():
  # Sample data points
  x_data: list[float] = [1, 2, 3, 4, 5]
  y_data: list[float] = [2, 3, 4, 5, 6]

  # Compute the slope of the best-fit line
  slope: float = linear_regression_slope(x_data, y_data)

  # Compute the intercept of the best-fit line
  intercept: float = linear_regression_intercept(x_data, y_data, slope)

  # Compute the distance error (residual) for each data point
  distance_error: float = linear_regression_distance_error(x_data, y_data, slope, intercept)

  # Print the slope, intercept, and distance error
  print("Slope of the best-fit line: ",slope)
  print("Intercept of the best-fit line: ",intercept)
  print("Distance error (residual) for each data point:",distance_error)
   

if __name__ == "__main__":
  main()
