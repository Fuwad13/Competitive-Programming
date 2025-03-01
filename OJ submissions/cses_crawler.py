import time
from datetime import datetime
from pathlib import Path


from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import Select
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys


service = Service(
    executable_path=Path(__file__).resolve().parent.parent
    / "Chrome Driver"
    / "chromedriver.exe"
)
driver = webdriver.Chrome(service=service)
driver.maximize_window()

BASE_URL = "https://cses.fi/"
driver.get(BASE_URL)
driver.find_element(By.LINK_TEXT, "Login").click()
inp = driver.find_element(By.ID, "nick")
inp.send_keys("fuwad")
inp = driver.find_element(By.NAME, "pass")
inp.send_keys("NEVERGONNAGIVEYOUUP")
inp.send_keys(Keys.ENTER)
driver.get(BASE_URL + "problemset/")

PROBLEM_LIST_PATH = Path(__file__).resolve().parent / "cses_list.txt"
if not PROBLEM_LIST_PATH.exists():
    PROBLEM_LIST_PATH.mkdir()

CSES_DIR = Path(__file__).resolve().parent / "CSES"
CSES_DIR.mkdir(exist_ok=True)

# problem_links = driver.find_elements(By.TAG_NAME, "a")

# problem_links = [str(x.get_attribute("href")) for x in problem_links if str(x.get_attribute("href")).startswith("https://cses.fi/problemset/task/")]
# with open(PROBLEM_LIST_PATH, "w") as f:
#     for link in problem_links:
#         f.write(link + "\n")

with open(PROBLEM_LIST_PATH, "r") as f:
    problem_links = f.readlines()

for link in problem_links:
    driver.get(link)
    temp = driver.find_elements(By.TAG_NAME, "a")
    submissions = []
    for x in temp:
        if str(x.get_attribute("href")).startswith(
            "https://cses.fi/problemset/result/"
        ):
            submissions.append(str(x.get_attribute("href")))
    if len(submissions) == 0:
        continue
    ac_submissions = []
    problem_name = ""
    for submission in submissions:
        driver.get(submission)
        tbl = driver.find_element(By.TAG_NAME, "table")
        if "ACCEPTED" in tbl.text:
            if problem_name == "":
                problem_name = tbl.find_element(By.TAG_NAME, "a").text
            code = driver.find_element(By.TAG_NAME, "pre").text
            if code.startswith("input/"):
                code = driver.find_elements(By.TAG_NAME, "pre")[1].text
            submission_time = driver.find_element(
                By.XPATH,
                "//td[contains(text(), 'Submission time:')]/following-sibling::td",
            ).text
            dt = datetime.strptime(submission_time, "%Y-%m-%d %H:%M:%S %z")
            submission_time = dt.timestamp()
            ac_submissions.append((code, submission_time))

    if len(ac_submissions) == 0:
        continue

    PROBLEM_DIR = CSES_DIR / problem_name
    PROBLEM_DIR.mkdir(exist_ok=True)
    for i, (code, submission_time) in enumerate(ac_submissions):
        with open(PROBLEM_DIR / f"{problem_name}_{submission_time}.cpp", "w") as f:
            f.write(code)

driver.quit()
