from selenium import webdriver
from selenium.webdriver import ActionChains
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
import time

browser = webdriver.Chrome()
try:
    browser.get('https://www.taobao.com')
    input = browser.find_element_by_class_name('search-combobox-input')
    print(input.get_attribute('aria-combobox'))
    input.send_keys('机械键盘')
    time.sleep(3)
    input.clear()
    input.send_keys('iPad')
    time.sleep(3)
    button = browser.find_element_by_class_name('btn-search')
    button.click()

#     input.send_keys('Python')
#     input.send_keys(Keys.ENTER)
#     wait = WebDriverWait(browser,10)
#     wait.until(EC.presence_of_all_elements_located((By.ID,'content_left')))
#     print(browser.current_url)
#     print(browser.get_cookies())
#     print(browser.page_source)
finally:
    browser.close()