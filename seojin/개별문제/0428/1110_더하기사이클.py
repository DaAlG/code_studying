def chain(number):
  new = str(number)
  if len(new) == 1:
    new = '0'+new
  res = str(int(new[0])+int(new[1]))
  if len(res) == 1:
    res = '0'+res
  result = int(str(new[1])+res[1])
  return result


real_number = int(input())
cnt = 0
number = real_number
while True:
  number = chain(number)
  if number == real_number:
    break
  cnt+=1
cnt+=1
print(cnt)