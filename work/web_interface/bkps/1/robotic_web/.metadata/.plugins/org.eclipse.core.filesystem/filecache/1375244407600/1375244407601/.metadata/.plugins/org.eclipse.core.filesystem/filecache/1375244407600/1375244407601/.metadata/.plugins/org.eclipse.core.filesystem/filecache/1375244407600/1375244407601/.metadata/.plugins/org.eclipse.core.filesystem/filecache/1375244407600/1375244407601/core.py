# External Imports
#import tornado.gen
import tornado.web

# Custom Imports
import handlers


def main():
    http_server = tornado.web.Application([
        (r"/", handlers.LoginHandler),
        (r'/main', handlers.MainHandler),
        (r'/camera', handlers.CameraHandler),
        (r'/arm', handlers.ArmHandler),
	(r'/chat', handlers.ChatHandler),
	(r'/ws', handlers.EchoWebSocket),
        (r'/static/(.*)', tornado.web.StaticFileHandler, {'path': 'static'})
       ])
    
    http_server.listen(8090)
    print 'http port started at 8090'
    try:
        tornado.ioloop.IOLoop.instance().start()
    except KeyboardInterrupt: pass
    
if __name__ == '__main__':
    main()
