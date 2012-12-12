'''
-----------------------------------------------------------------------------------------------------
Created on 12-Dec-2012
@author: unais

This is the main program for the weather app

weather server used : http://openweathermap.org/data/2.1/forecast/city?q=Kochin

Here urllib is used to fetch climate data from openweathermap.org

"jinja2" template engine is used to render html pages with tornado

Template is saved in /template/weather.html

we can give different city names in plase of "Palakkad" for getting weather datas of different citys
------------------------------------------------------------------------------------------------------
'''
import urllib2
import ast
import tornado.ioloop
import tornado.web
import jinja2
import os


jinja_environment = jinja2.Environment(loader=jinja2.FileSystemLoader(os.path.dirname(__file__) + "/templates"))
 
def getWeatherCondition(city) :
    try :
        url = "http://openweathermap.org/data/2.1/forecast/city?q="
        url += city
        req = urllib2.Request(url)
        response=urllib2.urlopen(req)
    except Exception :
        print("Not a matched city")
    return response.read()

def print_weather(place):
    Data_str =  getWeatherCondition(place)
    Data = ast.literal_eval(Data_str) # converting string to dict type
    Temperature =  Data['list'][0]['main']['temp']
    Humidity    =  Data['list'][0]['main']['humidity']
    Pressure    =  Data['list'][0]['main']['pressure']
    Result      =  place , Temperature , Humidity , Pressure
    return Result
   
class MainHandler(tornado.web.RequestHandler):
    def get(self):
        weather_data = print_weather("Palakkad")
        template_values = { 'place':weather_data[0], 'temperature': str(weather_data[1] -272.15), 'humidity': str(weather_data[2]), 'pressure': str(weather_data[3])}
        template = jinja_environment.get_template('weather.html')
        self.write(template.render(template_values))

application = tornado.web.Application([
    (r"/", MainHandler),
])

if __name__ == "__main__":
    application.listen(5616)
    tornado.ioloop.IOLoop.instance().start()
