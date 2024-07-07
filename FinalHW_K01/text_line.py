import logging
log = logging.getLogger('werkzeug')
log.setLevel(logging.ERROR)

def gettext(request):
    try:
        obj = request.get_json(silent=True,force=True)
        #print(obj["events"])
        if (obj["events"][0]["message"]["type"] == "text"):
            text = obj["events"][0]["message"]["text"]
            replay_token = obj["events"][0]["replyToken"]
            return text,replay_token
        else:
            return "",""            
    except:
        return "",""
