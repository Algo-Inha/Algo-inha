### Python

## 이분 탐색
```python
def binary_search(arr, target, min, max):
  min, max = 0, len(arr) - 1
    while min <= max:
        mid = (min + max) // 2
        if arr[mid] > target:
            max = mid - 1
        if arr[mid] == target:
            return mid
        if arr[mid] < target:
            min = mid + 1
    return -1
```
