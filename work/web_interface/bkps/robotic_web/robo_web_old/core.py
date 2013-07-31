#!/usr/bin/env python

'''
'''

# Python Standard Library Imports

# External Imports
import tornado.gen
import tornado.web

# Custom Imports
import handlers


def main():
    http_server = tornado.web.Application([
        (r'/', handlers.MainHandler),
        (r'/static/(.*)', tornado.web.StaticFileHandler, {'path': 'static'})
       ])
    
    http_server.listen(8008)
    print 'http port started at 8008'
    try:
        tornado.ioloop.IOLoop.instance().start()
    except KeyboardInterrupt: pass
    
if __name__ == '__main__':
    main()
