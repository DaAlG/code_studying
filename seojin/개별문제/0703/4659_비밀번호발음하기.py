vow = ['a','e','i','o','u']
en = [0 for i in range(26)]

# 모음 위치를 1로 고정
for v in vow:
  en[ord(v)-97] = 1
# print(en)

def first(pwd):
  for i in pwd:
    if en[ord(i)-97] == 1:
      return 0
  return 1

def second(pwd):
  if len(pwd)<3:
    return 0
  else:
    check = ''
    for i in pwd:
      if en[ord(i)-97] == 1: # 모음이면
        check += 'v'
      else:
        check += 'c'
      if 'vvv' in check or 'ccc' in check:
        return 1
    return 0


def third(pwd):
  for i in range(1, len(pwd)):
    if pwd[i] == pwd[i-1]: # 같은 글자가 두 번 연속 온다면
      if pwd[i] == 'e' or pwd[i] == 'o':
        return 0
      else:
        return 1
  return 0


while True:
  pwd = input()
  if pwd == 'end':
    break
  if not first(pwd) and not second(pwd) and not third(pwd): #모두 통과면(내가 return 0으로 잡아놔서,, 다 1로 바꿔주려면 not)
    print('<'+pwd+'> is acceptable.')
  else:
    print('<'+pwd+'> is not acceptable.')