from urllib import request
from bs4 import BeautifulSoup
from gensim import corpora
from gensim import models
from gensim import similarities


class SearchKeyWords:
    def __init__(self):
        self.base_url = 'https://www.insider.com/'
        self.lifestyle = 'lifestyle'
        self.get_url_content()
        self.get_data()
        self.get_models()

    # get url html
    def get_url_content(self):
        url = self.base_url + self.lifestyle
        print('getting information')
        self.html = request.urlopen(self.base_url).read()
        print('get the target content', url)
        return self.html

    def local_wite(self):
        with open('test.html', 'wb') as fp:
            fp.write(self.html)

    def local_read(self):
        with open('test.html', 'rb') as fp:
            self.html = fp.read()
            return self.html
        return None

    def get_data(self):
        self.soup = BeautifulSoup(self.html, features="html.parser")
        self.divs = self.soup.find_all('div', attrs={'class': 'tout-text-wrapper default-tout'})
        self.data = []
        for div in self.divs:
            self.data.append({
                'title': div.h2.a.string,
                'body': div.div.string,
                'url': self.base_url + div.h2.a['href']
            })
        return self.data

    def get_models(self):
        print('model building')
        self.stop_list = set('for a of the and to in with'.split(' '))
        self.texts = [[word for word in (d['title'] + d['body']).lower().split() if word not in self.stop_list] for d in
                      self.data]
        self.dictionary = corpora.Dictionary(self.texts)
        self.bow_corpus = [self.dictionary.doc2bow(text) for text in self.texts]
        self.tfidf = models.TfidfModel(self.bow_corpus)
        self.index = similarities.SparseMatrixSimilarity(self.tfidf[self.bow_corpus],
                                                         num_features=len(self.dictionary.token2id))
        return self.dictionary, self.index

    def search_word(self, keywords):
        self.words = keywords.lower().split()
        self.bow = self.dictionary.doc2bow(self.words)
        self.sims = self.index[self.tfidf[self.bow]]
        self.results = list(enumerate(self.sims))


def main():
    skw = SearchKeyWords()
    while True:
        key_word = input('input for interesting keywords (0 exit):')
        if key_word == '0':
            break
        skw.search_word(key_word)
        print(key_word, 'relevance rate and link information:')
        info_count = 0
        for info in skw.results:
            if info[1] != 0:
                info_count = info_count + 1
                print('correlation={}, title={}, url={}, content={}'.format(
                    info[1], skw.data[info[0]]['title'], skw.data[info[0]]['url'], skw.data[info[0]]['body']
                ))
        if info_count == 0:
            print('no related keywords')


if __name__ == '__main__':
    main()
