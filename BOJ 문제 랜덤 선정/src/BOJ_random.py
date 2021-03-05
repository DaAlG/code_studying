import requests
from bs4 import BeautifulSoup
import openpyxl
import pandas as pd

''' # 엑셀 파일 만들기
wb = openpyxl.Workbook()
# 현재 활성화된 시트 선택
sheet = wb.active
'''

# 맞은 문제 불러오고 싶은 id 입력
# 마지막 아이디 입력이 끝나면 -1 입력
ids = []
print('아이디를 입력하세요 (종료 : -1)')
while True:
    id = input()
    if id == '-1':
        break
    ids.append(id)

# 백준에서 각 id별로 맞은 문제 가져오기
question_numbers = []
for id in ids:
    url = "https://www.acmicpc.net/user/" + id
    webpage = requests.get(url)
    soup = BeautifulSoup(webpage.content, "html.parser")
    question_area = soup.find("div", {"class" : "panel-body"}).select("a")
    for question in question_area:
        question_numbers.append(int(question.text))

question_numbers = sorted(list(set(question_numbers)))

''' # 엑셀에 데이터 입력
for number in question_numbers:
    sheet.append([number])

# 엑셀으로 저장
title = "BOJ_공통_맞은문제.xlsx"
wb.save(title)
'''

# 티어별 문제 Excel 파일에서 데이터 불러오기
df = pd.read_excel('./solved.ac 티어별 문제.xlsx')

# Unrated ~ Ruby I / 총 31개
tmp = pd.unique(df.Level).tolist()
tier = dict(zip(tmp, range(len(tmp))))

# filter : Bronze II ~ Gold IV
a = tier['Bronze II']
b = tier['Gold IV']

lower = lambda e: e[1] >= a
upper = lambda e: e[1] <= b
condition = [lower, upper]

levels = dict(filter(lambda t: all(f(t) for f in condition), tier.items()))
tiers = list(levels.keys())
print("Filter : " + tiers[0] + " ~ " + tiers[len(tiers) - 1])

# 이미 푼 문제 제외, 선택한 레벨 내의 문제 선택
filtered_df = df[~df.Number.isin(question_numbers) & df.Level.isin(tiers)]

# 후보 선택
print("후보 25개")
sample_df = filtered_df.sample(n = 25, replace=False)
sample_df['sorter'] = sample_df['Level'].map(levels)
sample_df.sort_values('sorter', inplace=True)
sample_df.drop('sorter', 1, inplace=True)

# 후보 출력
data = sample_df.values.tolist()
f = '{:<8}  {:40}  {:15}'
for i in data:
    print(f.format(*i))
