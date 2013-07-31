# Python Standard Library Imports
# External Imports
import tornado.web

# Custom Imports
import templates


class LoginHandler(tornado.web.RequestHandler):
    def get(self):
        template = templates.get('login.html')
        self.finish(template.render())
        
    def post(self):
	    pass


class MainHandler(tornado.web.RequestHandler):
    def get(self):
        template = templates.get('simple.html')
        self.finish(template.render())  

    def post(self):
        pass
 
class CameraHandler(tornado.web.RequestHandler):
    def get(self):
        template = templates.get('camera.html')
        self.finish(template.render())  

    def post(self):
        pass
 

