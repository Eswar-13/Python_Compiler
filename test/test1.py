def bubble_sort(arr:list[int]):
  n:int = len(arr)
  # Traverse through all array elements
  i:int=0
  for i in range(n):
    # Last i elements are already in place
    j:int=0
    for j in range(0, n - i - 1):
      # Traverse the array from 0 to n-i-1
      # Swap if the element found is greater
      # than the next element
      if arr[j] > arr[j + 1]:
        # Swap the elements using a temporary variable
        temp:int = arr[j]
        arr[j] = arr[j + 1]
        arr[j + 1] = temp

def main():
  data:list[int] = [64, 34, 25, 12, 22, 11, 90]
  bubble_sort(data)
  i:int=0
  for i in range(len(data)):
    print(data[i])
