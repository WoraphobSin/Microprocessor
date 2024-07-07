from flask import Flask, request
from text_line import gettext

from linebot import LineBotApi
from linebot.models import TextSendMessage as send_text

from flask_serial import Serial
from config_flask_serial import config_flask_ser

channel_access_token = "It6WLG6eqA2gKHRELPZ88Oq7aL8eFYSpHFi+q/XFkzZytWJmEYCx3IiXbgi0GnxiIJ8OMM4vvR0Yescqb7+zhOaTNoAehVdpAI9tCflOs4VjoWG4FhT27fBcnFtA6TyfqK+xlVrfOrMdhMt5PwmvLwdB04t89/1O/w1cDnyilFU="
line_send = LineBotApi(channel_access_token).reply_message

app = Flask(__name__)
ser = Serial(config_flask_ser(app,'COM2',9600))

@app.route("/",methods=["GET","POST"])
def digit():
    text,reply_token = gettext(request)
    if (text != ""):
        print(text)
        ser.on_send(text)        
        line_send(reply_token,send_text(text="แสดงผลที่ 7-Segment เรียบร้อย"))                  
    return "Hello LINE"

app.run()
