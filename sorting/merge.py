def merge(arr, s, e):
    mid = s + (e - s) // 2
    len1 = mid - s + 1
    len2 = e - mid
 
    first = arr[s : mid + 1]
    second = arr[mid + 1 : e + 1]
 
    i = j = 0
    k = s
    
    while i < len1 and j < len2:
        if first[i] < second[j]:
            arr[k] = first[i]
            i += 1
        else:
            arr[k] = second[j]
            j += 1
        k += 1
 
    while i < len1:
        arr[k] = first[i]
        i += 1
        k += 1
 
    while j < len2:
        arr[k] = second[j]
        j += 1
        k += 1
 
def merge_sort(arr, s, e):
    if s < e:
        mid = s + (e - s) // 2
        merge_sort(arr, s, mid)
        merge_sort(arr, mid + 1, e)
        merge(arr, s, e)
 

arr = [5, 4, 3, 2, 1]
n = len(arr)
merge_sort(arr, 0, n - 1)
print(arr)
