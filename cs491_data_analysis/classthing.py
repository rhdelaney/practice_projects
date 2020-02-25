from numpy import average
from utils import txt2words,w2v_load_model
import numpy as np
import gensim

class DeepTextAnalyzer(object):
    def __init__(self, word2vec_model):
        """
        Construct a DeepTextAnalyzer using the input Word2Vec model
        :param word2vec_model: a trained Word2Vec model
        """
        self._model = word2vec_model

    def txt2vectors(self,txt, is_html):
        """
        Convert input text into an iterator that returns the corresponding vector representation of each
        word in the text, if it exists in the Word2Vec model
        :param txt: input text
        :param is_html: if True, then extract the text from the input HTML
        :return: iterator of vectors created from the words in the text using the Word2Vec model.
        """
        words = txt2words(txt,is_html=is_html, lower=True, remove_none_english_chars=True)
        words = [w for w in words if w in self._model]
        if len(words) != 0:
            for w in words:
                yield self._model[w]


    def txt2avg_vector(self, txt, is_html):
        """
        Calculate the average vector representation of the input text
        :param txt: input text
        :param is_html: is the text is a HTML
        :return the average vector of the vector representations of the words in the text  
        """
        vectors = self.txt2vectors(txt,is_html=is_html)
        vectors_sum = next(vectors, None)
        if vectors_sum is None:
            return None
        count =1.0
        for v in vectors:
            count += 1
            vectors_sum = np.add(vectors_sum,v)
        
        #calculate the average vector and replace +infy and -inf with numeric values 
        avg_vector = np.nan_to_num(vectors_sum/count)
        return avg_vector

    def load tweets(fname):
        tweets=[]
        for line in open(fname):
            id_str,label,text= line.rstrip().split('\t')
            tweets.append([id_str,label,text])
        return tweets

    def generate_arff_header(f):
        f.write('@relation Word2VectRelation\n\n')
        for i in range(300):
            f.write('@attribute feature%s numberic\n' %i)
        f.write('@attribute class {positive,negative,neutral}\n')
        f.write('\n')

    def generate_arff_data(f,tweets):
        



