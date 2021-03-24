def bin_search(array, target, start, end, length):
  if start > end:
    return 0
  mid = (start+end)//2
  # 포함되는 게 있으면 return
  if target == array[mid][:length]:
    return 1
  else:
  # mid 번째에서 포함되는 게 없으면 그 뒤는 나랑 상관없는 애들이라서 mid보다 작은 범위만 확인하면 된다.
    end = mid-1
    return bin_search(array, target, start, end, length)


def solution(phone_book):
    answer = True
    
    phone = dict()
    phone_book.sort()
    for i in range(len(phone_book)):
      phone[i] = phone_book[i]
    # print(phone)
    # print(phone_book)
    
    # 시간 초과 걸릴 것 같더라니 ..
    # 그냥 풀었을 때 시간초과 ..
    res = 0
    n = len(phone)
    for i in range(len(phone_book)):
      length = len(phone[i])
      # 지금 phone dict에는 11,1112,11345,1235 이런식으로 앞 숫자에 따라 정렬되어있고~ 이진탐색으로 찾아보자
      # 근데 지금 내 위치보다 앞은 항상 안맞거나 나보다 작은 범위의 애들이기 때문에 그 다음 부터 보면 된다.
      res += bin_search(phone, phone[i], i+1, n-1, length)

    if res != 0:
      return False
    return answer

# phone_book = list(input().split())
# print(solution(phone_book))