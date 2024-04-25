
def merge_sort(array: list[int]) -> None:
  if len(array) > 1:
    mid: int = len(array) // 2

    left_half: list[int] = []
    right_half: list[int] = []
    
    # Split the array into left and right halves
    for i in range(mid):
      left_half.append(array[i])
    for i in range(mid, len(array)):
      right_half.append(array[i])

    # Recursively sort the left and right halves
    merge_sort(left_half)
    merge_sort(right_half)

    # Merge the sorted halves
    i: int = 0
    j: int = 0
    k: int = 0

    while i < len(left_half) and j < len(right_half):
      if left_half[i] < right_half[j]:
        array[k] = left_half[i]
        i += 1
      else:
        array[k] = right_half[j]
        j += 1
      k += 1

    # Copy the remaining elements of left_half
    while i < len(left_half):
      array[k] = left_half[i]
      i += 1
      k += 1

    # Copy the remaining elements of right_half
    while j < len(right_half):
      array[k] = right_half[j]
      j += 1
      k += 1

def main() -> None:
  data: list[int] = [-2, 45, 0, 11, -9]
  merge_sort(data)

  print('Sorted Array in Ascending Order:')
  for element in data:
    print(element)

if __name__ == "__main__":
  main()
