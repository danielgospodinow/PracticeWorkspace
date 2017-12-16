def quick_sort(arr):
    quick_sort(arr, 0, len(arr) - 1)


def quick_sort(arr, left, right):
    if left >= right:
        return

    pivot = arr[(left + right) // 2]
    divider = qs_partition(arr, left, right, pivot)

    quick_sort(arr, left, divider - 1)
    quick_sort(arr, divider, right)


def qs_partition(arr, left, right, pivot):
    while left <= right:
        while arr[left] < pivot:
            left += 1
        while arr[right] > pivot:
            right -= 1

        if left <= right:
            swap(arr, left, right)
            left += 1
            right -= 1

    return left


def swap(arr, a, b):
    temp = arr[a]
    arr[a] = arr[b]
    arr[b] = temp


def main():
    arr = [1, -8, 14, -5, 0, 9]
    print(arr)

    quick_sort(arr, 0, len(arr) - 1)
    print(arr)
main()
