def binarySearch(array: list[int], x: int, low: int, high: int) -> int:
  a:int=0
  c:int=array[a]
  while low <= high:
    mid: int = low + (high - low) // 2
    b:int=array[mid]
    if array[mid] == x:
      return mid
    elif array[mid] < x:
      low = mid + 1
    else:
      high = mid - 1
  return -1


def main():
  array: list[int] = [3, 5, 6, 7, 8, 9]
  result: int = binarySearch(array, 6, 0, len(array) - 1)

  if result != -1:
    print("Element is present at index:")
    print(result)
  else:
    print("Element is not present")


if __name__ == "__main__":
  main()
