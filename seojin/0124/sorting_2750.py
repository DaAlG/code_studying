n = int(input())
a = []
for i in range(n):
    a.append(int(input()))
    
a.sort()
for i in a:
    print(i)

    n = int(input())

# a = []
# for i in range(n):
#     a.append(int(input()))
    
# def quick_sort(array, start, end):
#     if start >= end:
#         return
#     pivot = start + 1
#     left = start + 1 
#     right = end
    
#     while left <= right:
#         while left<=end and array[left]<=array[pivot]:
#             left+=1
#         while right>start and array[right]>=array[pivot]:
#             right-=1
#         if left > right:
#             array[right], array[pivot] = array[pivot], array[right]
#         else:
#             array[left], array[right] = array[right], array[left]
        
#         quick_sort(array, start, right-1)
#         quick_sort(array, right+1, end)
        
# quick_sort(a,0,len(array)-1)

# for i in a:
#     print(i)
