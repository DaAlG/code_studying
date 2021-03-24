while True:
  d, m, y = map(int, input().split())
  if y == 0:
    break
  if y % 4 == 0:
    if y % 100 != 0 or y % 400 == 0:
      # 윤년인경우
      month = [31,29,31,30,31,30,31,31,30,31,30,31]
    else:
      month = [31,28,31,30,31,30,31,31,30,31,30,31]
  else:
    month = [31,28,31,30,31,30,31,31,30,31,30,31]
  res = 0
  for i in range(m-1):
    res += month[i]
  res += d
  print(res)