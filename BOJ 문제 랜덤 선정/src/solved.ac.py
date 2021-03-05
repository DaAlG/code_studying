import requests
from bs4 import BeautifulSoup
import openpyxl

wb = openpyxl.Workbook()
sheet = wb.active
sheet.append(['Number', 'Link', 'Level'])

for level in range(0, 31):
    url = "https://solved.ac/problems/level/" + str(level)
    webpage = requests.get(url)
    soup = BeautifulSoup(webpage.content, "html.parser")
    tier = soup.find("img", {"class" : "TierBadge__TierBadgeStyle-bguxxi-0 jwmsvP"})["alt"]
    print(tier)
    pages = soup.find_all("div", {"class" : "Paginationstyles__PageIndicator-gesjo3-0 kzFdWo"})
    if not pages:
        pages = 1
    else:
        pages = int(pages[len(pages) - 1].text)

    for page in range(1, pages + 1):
        url_2 = url + "?page=" + str(page)
        webpage = requests.get(url_2)
        soup = BeautifulSoup(webpage.content, "html.parser")
        question_area = soup.find_all("a", {"class" : "ProblemInline__ProblemStyle-cvf1lm-0 ivEtZs"})
        for question in question_area:
            link = question["href"]
            number = question.find("span").text
            sheet.append([number, link, tier])

title = "solved.ac 티어별 문제.xlsx"
wb.save(title)