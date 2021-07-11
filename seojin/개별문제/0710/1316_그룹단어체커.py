# 이미 나온 단어 리스트에 넣고 걔 또 나오면 그룹 단어 아님.
n = int(input())
ans = n
for i in range(n):
  word = input()
  word_list = []
  for j in range(len(word)):
    if word[j] not in word_list:
      word_list.append(word[j])
    else:
      if word[j-1] == word[j]:
        continue
      ans -= 1
      break
print(ans)