from selenium import webdriver
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support.ui import WebDriverWait
import time
from bs4 import BeautifulSoup

url = "https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000"
browser = webdriver.Chrome()
try:
    browser.get(url)
    soup = BeautifulSoup(browser.page_source, "html.parser")
    menu_tag = soup.find(id="x-wiki-index", class_="uk-nav uk-nav-side")
    urls = []
    for div in menu_tag.find_all("div"):
        url = div.a.get("href")
        menu = browser.find_element_by_css_selector('[herf={}]'.format(url))
        time.sleep(3)
        menu.click()


finally:
    browser.close()

