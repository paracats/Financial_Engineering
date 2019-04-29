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
    data['num_of_words'] = len(text.split())

    """
    Get MD&A section
    """
    pre = 'Management’s Discussion and Analysis of Financial Condition and Results of Operations'.lower()
    suf = 'Quantitative and Qualitative Disclosures About Market Risk'.lower()
    text_MDA = text[text.lower().rfind(pre) + len(pre) : text.lower().rfind(suf)]

    """
    The number of words in the filing’s “Management 
    Discussion and Analysis” (MD&A) section
    """
    data['words_in_MDA'] = len(text_MDA.split()) - 2

    """
    The number of times the word “competition” 
    is mentioned in the MD&A section
    """
    data['competition_in_MDA'] = text_MDA.lower().count('competition')

    """
    The ten words before and ten words after 
    the date mentioned in the MD&A section
    """
    p = compile(
        '(((Jan(uary)?|Mar(ch)?|May|Jul(y)?|Aug(ust)?|Oct(ober)?|Dec(ember)?)( |-|\/)(30|31))| ((Apr(il)?|Jun(e)?|Sep(tember)?|Nov(ember)?)( |-|\/)30)|((Jan(uary)?|Feb(ruary)?|Mar(ch)?|Apr(il)?|May|Jun(e)?|Jul(y)?|Aug(ust)?|Sep(tember)?|Oct(ober)?|Nov(ember)?|Dec(ember)?)( |-|\/)((0|1|2)?[0-9])))|(((0?1|0?3|0?5|0?7|0?8|10|12)(-|\/)(30|31))|((0?4|0?6|0?9|11)(-|\/)30)|((0?1|0?2|0?3|0?4|0?5|0?6|0?7|0?8|0?9|10|11|12)(-|\/)((0|1|2)?[0-9])))(-|\/)(\d{2}(\d{2})?)',
        flags=IGNORECASE
    )
    data['date_text'] = []
    for m in p.finditer(text):
        pre = text[m.start()-400:m.start()].split()
        suf = text[m.end():m.end()+400].split()
        data['date_text'].append({
            'dat': m.group(),
            'pre': pre[-10:],
            'suf': suf[:10]
        })
        
    """
    Return data as a dict
    """
    return data
    
if __name__ == '__main__':
    dataset = []

    with open('TASK1.csv', 'r') as csv:
        spamreader = reader(csv)
        next(spamreader, None) # skip the headers

        for row in spamreader:
            print(row[0], end='')
            # ignore the empty url
            if row[3] == '':
                print('... [skip]')
                continue


            # extract data and save it
            page = load_web_page(row[3])
            data = get_data_dict(page, row[0], row[2])
            dataset.append(data)
            print('... [done]')
    
        
        
