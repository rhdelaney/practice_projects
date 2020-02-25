#Import the necessary methods from tweepy library
from tweepy import StreamListener
from tweepy import OAuthHandler
from tweepy import Stream

#Variables that contains the user credentials to access Twitter API 
access_token = "4146039057-35fiT7ddYX6bEZkqb9yvPod7qsK6twFSaCrWZR0"
access_token_secret = "FqIexfTIoyiLmGSOWSpamb3pbzOAVxB1Dk2LKv3Mqukgn"
consumer_key = "lc5JNYnWsr7V7qXws3y59UVpl"
consumer_secret = "I6s3l7YBNSrvFSDv2q4QSipPCItxlx0J5MyjX8bY2dEFnzVxBw"


#This is a basic listener that just prints received tweets to stdout.
class StdOutListener(StreamListener):

    def on_data(self, data):
        print data
        return True

    def on_error(self, status):
        print status


if __name__ == '__main__':

    #This handles Twitter authetification and the connection to Twitter Streaming API
    l = StdOutListener()
    auth = OAuthHandler(consumer_key, consumer_secret)
    auth.set_access_token(access_token, access_token_secret)
    stream = Stream(auth, l)

    #This line filter Twitter Streams to capture data by the keywords: 'python', 'javascript', 'ruby'
    stream.filter(track=['python', 'javascript', 'ruby'])
