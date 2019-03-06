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

def get_data_dict(text, name, time):
    data = {'name': name, 'time': time}

    """ 
    The number of words in the overall 10-K filing 
    (not including HTML tags)
    """


    
    
    
    
