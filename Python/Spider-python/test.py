from selenium import webdriver
from selenium.webdriver import ActionChains
from selenium.webdriver.common.by import By
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support.ui import WebDriverWait
import time


try:
    browser = webdriver.Chrome()
    url = 'https://www.baidu.com'
    browser.get(url)
    print(browser.get_cookies())
    browser.add_cookie({'name':'dai','value':'123'})#一定要记得有value否则会报错
    print(browser.get_cookies())
    browser.delete_all_cookies()
    print(browser.get_cookies())
    browser.execute_script('window.open()')
    browser.switch_to.window(browser.window_handles[1])
    browser.get('https://www.sina.com')
    time.sleep(2)
    browser.switch_to.window(browser.window_handles[0])
    time.sleep(1)
    browser.switch_to.window(browser.window_handles[1])
    time.sleep(1)
    browser.close()
    # wait = WebDriverWait(browser,10)
    # intput = wait.until(EC.presence_of_element_located((By.ID,'q')))
    # button = wait.until(EC.element_to_be_clickable((By.,'***')))
    # answer = browser.find_elements_by_class_name('zh-summary')[1]
finally:
    browser.close()
