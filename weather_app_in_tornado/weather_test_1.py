'''
Created on 10-Dec-2012

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

if __name__ == "__main__":
    Data_str =  getWeatherCondition("Kochi")
    Data = ast.literal_eval(Data_str)
    Temperature =  Data['list'][0]['main']['temp']
    Humidity    =  Data['list'][0]['main']['humidity']
    Pressure    =  Data['list'][0]['main']['pressure']
    print "Temperature : " , Temperature - 272.15 , "Celcius"
    print "Humidity    : " , Humidity , "%"
    print "Pressure    : " , Pressure , "mbar"