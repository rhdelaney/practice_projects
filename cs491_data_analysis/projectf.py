from datetime import datetime, timedelta
import httplib2
import os
import sys
import io

from apiclient.discovery import build
from apiclient.errors import HttpError
from oauth2client.client import flow_from_clientsecrets
from oauth2client.file import Storage
from oauth2client.tools import argparser, run_flow
now=datetime.utcnow()
local_time =datetime.utcnow()

# Set DEVELOPER_KEY to the API key value from the APIs & auth > Registered apps
# tab of
#   https://cloud.google.com/console
# Please ensure that you have enabled the YouTube Data API for your project.
DEVELOPER_KEY = "AIzaSyCYBPE9IL_n_d7aXwqen0lWETCUvVD6sjE"
YOUTUBE_API_SERVICE_NAME = "youtube"
YOUTUBE_API_VERSION = "v3"

CLIENT_SECRETS_FILE = "client_secrets.json"

# This OAuth 2.0 access scope allows for full read/write access to the
# authenticated user's account and requires requests to use an SSL connection.
YOUTUBE_READ_WRITE_SSL_SCOPE = "https://www.googleapis.com/auth/youtube.force-ssl"
API_SERVICE_NAME = "youtube"
API_VERSION = "v3"

# This variable defines a message to display if the CLIENT_SECRETS_FILE is
# missing.
MISSING_CLIENT_SECRETS_MESSAGE = "WARNING: Please configure OAuth 2.0" 

# Authorize the request and store authorization credentials.
def get_authenticated_service(args):
  flow = flow_from_clientsecrets(CLIENT_SECRETS_FILE, scope=YOUTUBE_READ_WRITE_SSL_SCOPE,
    message=MISSING_CLIENT_SECRETS_MESSAGE)

  storage = Storage("youtube-api-snippets-oauth2.json")
  credentials = storage.get()

  if credentials is None or credentials.invalid:
    credentials = run_flow(flow, storage, args)

  # Trusted testers can download this discovery document from the developers page
  # and it should be in the same directory with the code.
  return build(API_SERVICE_NAME, API_VERSION,
      http=credentials.authorize(httplib2.Http()))


args = argparser.parse_args()
service = get_authenticated_service(args)

def print_results(results):
  print('%s\t%s\t%s\n' %
    (results['items'][0]['id'],
    results['items'][0]['snippet']['title'],
    results['items'][0]['statistics']['viewCount']))

def build_resource(properties):
  resource = {}
  for p in properties:
    prop_array = p.split('.')
    ref = resource
    for pa in range(0, len(prop_array)):
      is_array = False
      key = prop_array[pa]
      if key[-2:] == '[]':
        key = key[0:len(key)-2:]
        is_array = True
      if pa == (len(prop_array) - 1):
        if properties[p]:
          if is_array:
            ref[key] = properties[p].split(',')
          else:
            ref[key] = properties[p]
      elif key not in ref:
        ref[key] = {}
        ref = ref[key]
      else:
        ref = ref[key]
  return resource

# Remove keyword arguments that are not set
def remove_empty_kwargs(**kwargs):
  good_kwargs = {}
  if kwargs is not None:
    for key, value in kwargs.iteritems():
      if value:
        good_kwargs[key] = value
  return good_kwargs

### END BOILERPLATE CODE

# Sample python code for videos.list

def videos_list_by_id(service, **kwargs):
  stuff=[]
  kwargs = remove_empty_kwargs(**kwargs) # See full sample for function
  results = service.videos().list(
    **kwargs
  ).execute()
  #print_results(results)

def youtube_search(options):
  youtube = build(YOUTUBE_API_SERVICE_NAME, YOUTUBE_API_VERSION,
    developerKey=DEVELOPER_KEY)

  # Call the search.list method to retrieve results matching the specified
  # query term.
  search_response = youtube.search().list(
    q=options.q,
    part="id,snippet,statistics",
    order=options.order,
    maxResults=options.max_results,
    publishedAfter=options.published_after,
    publishedBefore=options.published_before
    #order=options.order
  ).execute()

  videos=[]

  one_day_ago=(now - timedelta(days=1)).strftime("%Y-%m-%d")
  curr_day=now.strftime("%Y-%m-%d")
  print('%s\t%s\n' % (one_day_ago, curr_day) )
  # Add each result to the appropriate list, and then display the lists of
  # matching videos, channels, and playlists.
  for search_result in search_response.get("items", []):
    if search_result["id"]["kind"] == "youtube#video":
      print('%s\t%s\t%s\n' % (search_result['id'],search_result['snippet']['title'],
    search_result['statistics']['viewCount']))

o_day=(local_time- timedelta(days=1)).isoformat() + "Z"
c_day=local_time.isoformat() + "Z"

if __name__ == "__main__":
  argparser.add_argument("--q", help="Search term", default="landslide")  
  argparser.add_argument("--max-results", help="Max results", default=10)
  argparser.add_argument("--order", help="Sort order", default="viewCount")
  argparser.add_argument("--published-after",help="Start date", default=o_day)
  argparser.add_argument("--published-before",help="End date", default=c_day)
  #argparser.add_argument("--order", help="Sort order", default="viewCount")
  args = argparser.parse_args()

  try:  
    #print ('%s\n') % (o_day)
    #print ('%s\n') % (c_day)
    youtube_search(args)
    #for search_result in videos:
    #  videos_list_by_id(service,part='id,snippet,statistics',id=search_result["id"]["videoId"])

  except HttpError, e:
    print "An HTTP error %d occurred:\n%s" % (e.resp.status, e.content)