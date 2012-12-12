'''
Created on 11-Dec-2012

@author: unais
'''
import urllib2
import ast


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
    Data = ast.literal_eval(Data_str)  
    Temperature =  Data['list'][0]['main']['temp']
    Humidity    =  Data['list'][0]['main']['humidity']
    Pressure    =  Data['list'][0]['main']['pressure']
    Result = place , Temperature , Humidity , Pressure
    return Result

def Test():
    print print_weather("Washington")
    print print_weather("Havana")
    print print_weather("Mumbai")
    print print_weather("Palakkad")
    print print_weather("Kochi")
    print print_weather("Chennai")
 
Test()
