""" David Li               """
""" Web Crawler            """


from csv import reader
from urllib import request
from bs4 import BeautifulSoup
from re import compile, IGNORECASE
from json import dumps

def load_web_page(url):
    soup = BeautifulSoup(request.urlopen(url), 'html.parser')
    page = soup.text

    for char in '\n.,()':
        page = page.replace(char,' ')

    return page


    
    
    
    
