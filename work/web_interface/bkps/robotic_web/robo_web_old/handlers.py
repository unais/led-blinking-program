# Python Standard Library Imports

# External Imports
import tornado.web


# Custom Imports
import templates


class MainHandler(tornado.web.RequestHandler):
    def get(self):
        template = templates.get('index.html')
        self.finish(template.render())  

    def post(self):
        pass
