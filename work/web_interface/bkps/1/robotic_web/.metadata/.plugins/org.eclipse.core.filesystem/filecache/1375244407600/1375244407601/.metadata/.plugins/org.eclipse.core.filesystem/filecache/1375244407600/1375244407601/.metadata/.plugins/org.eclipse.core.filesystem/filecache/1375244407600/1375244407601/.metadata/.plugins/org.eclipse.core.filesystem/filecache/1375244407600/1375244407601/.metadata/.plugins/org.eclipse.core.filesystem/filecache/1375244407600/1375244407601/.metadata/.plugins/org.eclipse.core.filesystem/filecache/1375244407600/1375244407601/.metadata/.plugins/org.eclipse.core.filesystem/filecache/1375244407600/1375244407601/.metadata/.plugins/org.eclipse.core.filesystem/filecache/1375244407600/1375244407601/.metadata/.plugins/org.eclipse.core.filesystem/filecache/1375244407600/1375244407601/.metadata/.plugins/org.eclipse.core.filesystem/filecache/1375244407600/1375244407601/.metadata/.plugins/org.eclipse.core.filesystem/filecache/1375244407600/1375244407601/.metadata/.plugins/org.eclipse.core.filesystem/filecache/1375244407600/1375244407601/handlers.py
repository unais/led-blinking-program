# Python Standard Library Imports
# External Imports
import tornado.web
#import logging
#import base64

import os
import logging

from tornado.ioloop import IOLoop
from tornado.options import define, options
from tornado.web import Application, RequestHandler
from tornado.websocket import WebSocketHandler



# Custom Imports
import templates



users = {'a' : 'a',
         'asimov' : 'asimov'}


class LoginHandler(tornado.web.RequestHandler):
    def get(self):
        template = templates.get('login.html')
        self.finish(template.render())
        
    def post(self):
        
        try:
            username = self.request.arguments['username'][0]
            password = self.request.arguments['password'][0]
            print username,password
        except KeyError:
            pass
        if username in users and password == users[username]:
            self.redirect('/main')
        else:
            template = templates.get('login.html')
            #now = datetime.datetime.now()
            self.finish(template.render())
        


class MainHandler(tornado.web.RequestHandler):
    def get(self):
        template = templates.get('main.html')
        self.finish(template.render())  

    def post(self):
        pass
 
class CameraHandler(tornado.web.RequestHandler):
    def get(self):
        template = templates.get('camera.html')
        self.finish(template.render())  

    def post(self):
        pass

class ArmHandler(tornado.web.RequestHandler):
    def get(self):
        template = templates.get('arm.html')
        self.finish(template.render())  

    def post(self):
        pass

class ChatHandler(tornado.web.RequestHandler):
	def get(self):
            template = templates.get('chat.html')
            self.finish(template.render())

        def post(self):
            pass


class EchoWebSocket(WebSocketHandler):
    clients = []

    def open(self):
        logging.info('WebSocket opened from %s', self.request.remote_ip)
        EchoWebSocket.clients.append(self)

    def on_message(self, message):
        logging.info('got message from %s: %s', self.request.remote_ip, message)
        for client in EchoWebSocket.clients:
            if client is self:
                continue
            client.write_message(message)

    def on_close(self):
        logging.info('WebSocket closed')
        EchoWebSocket.clients.remove(self)



