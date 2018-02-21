from selenium import webdriver
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver import ActionChains
from selenium.webdriver.common.by import By

import time
from bs4 import BeautifulSoup

url = "https://www.liaoxuefeng.com/wiki/0014316089557264a6b348958f449949df42a6d3a2e542c000"

try:
    browser = webdriver.Chrome()
    browser.get(url)
    browser.execute_script('window.open')
    # wait = WebDriverWait(browser, 10)
    # input = wait.until(EC.presence_of_element_located((By.CSS_SELECTOR,'.design')))
    menus = browser.find_elements_by_css_selector('a.x-wiki-index-item')
    # print(menu.text)
    for menu in menus:
        print(menu.text)



finally:
    browser.close()

