from __future__ import print_function
from googleapiclient.discovery import build
from httplib2 import Http
from oauth2client import file, client, tools
from datetime import datetime, timedelta

print (datetime.now())

SCOPES = 'https://www.googleapis.com/auth/gmail.readonly'
store = file.Storage('token.json')
creds = store.get()
if not creds or creds.invalid:
    flow = client.flow_from_clientsecrets('credentials.json', SCOPES)
    creds = tools.run_flow(flow, store)
service = build('gmail', 'v1', http=creds.authorize(Http()))

# Call the Gmail API
response = service.users().messages().list(userId='me',labelIds=['INBOX']).execute()

messages = []
if 'messages' in response:
    messages.extend(response['messages'])

oldmsg = False

for msg in messages:
    msgid = msg['id']
    message = service.users().messages().get(userId='me', id=msgid).execute()
    payld = message['payload']
    hdr = payld['headers']
    for x in hdr:
        if x['name'] == 'Subject':
            print(x['value'])
        if x['name'] == 'Date':
            strdt = x['value']
            print(strdt)
            dt = strdt[5:7]
            dt1 = strdt[0:2]
            currentdt = datetime.today().strftime('%d')
            yesterday = datetime.today() - timedelta(1)
            yesterdaydt = yesterday.strftime('%d')
            print (dt)
            print (dt1)
            print (currentdt)
            print (yesterdaydt)
            if not (dt == currentdt or dt1 == currentdt or dt == yesterdaydt or dt1 == yesterdaydt):
                oldmsg = True
                break
        if x['name'] == 'From':
            print(x['value'])
    if oldmsg:
        break

        