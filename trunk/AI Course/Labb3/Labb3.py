from car import *
from decisionTree import *
#from math import *
#from math import log2
import math
carDatabase = []
attributes = {'buying':['vhigh','high','med','low'],
              'maint':['vhigh','high','med','low'],
              'doors':['2','3','4','5more'],
              'persons':['2','4','more'],
              'lug_boot':['small','med','big'],
              'safety':['low','med','high'],
              'attractiveness':['unacc','acc','good','vgood']
              }

def readData():
    dataFile = open('car.data')
    for dataLine in dataFile.readlines():
        dataLine = dataLine[:-1]
        temp = dataLine.split(',')
        carDatabase.append(car(temp[0],temp[1],temp[2],temp[3],temp[4],temp[5],temp[6]))

def ID3(Cars, Attributes):
    #kolla alla cars har samma class
    if(CheckClass(Cars,Attributes)):
        return DecisionLeaf(Cars[0].attractiveness)

    #kolla om attributes är tom
    elif(len(Attributes) == 0):
        return DecisionLeaf(MostCommonClass(Cars, Attributes))

    A = MaxInfoGain(Cars, Attributes)
    theTree = DecisionFork(A,{})

    for value in Attributes[A]:
        Cars_v = split(Cars,A,value)
        if(len(Cars_v) == 0):
            theTree.branches[value] = DecisionLeaf(MostCommonClass(Cars, Attributes))
        else:
            asd = Attributes.copy()
            del asd[A]
            theTree.branches[value] = ID3(Cars_v, asd)

    theTree.display()
    return theTree


def CheckClass(Cars, Attributes):
    for car in Cars:
        if (Cars[0].attractiveness != car.attractiveness):
            return False

    return True
def MostCommonClass(Cars, Attribute):
    countDict = {}
    for value in Attribute['attractiveness']:
        countDict[value] = 0
    
    for Car in Cars:
        countDict[Car.attractiveness] += 1

    mostCommonClass = ""
    temp = 0
    for item in countDict:
        if(countDict[item] > temp):
            temp = countDict[item]
            mostCommonClass = item
    return mostCommonClass

def InformationGain(Cars, Attribute):
#A is the attribute whichs information gain shall be calculated,
#S is the decision attribute

    HS = CalculateEntropy(Cars) 
    HA = 0

    for vi in attributes[Attribute]:
        E_vi = split(Cars, Attribute, vi)
        HA += ((len(E_vi)/len(Cars))*CalculateEntropy(E_vi))
    return HS-HA

def CalculateEntropy(Cars):
    data = {'unacc':0, 'acc':0, 'good':0, 'vgood':0}
    for x in Cars:
        data[x.attractiveness] += 1

    all = len(Cars)
    HS = 0

    for key in data:
        #????????????????????????????????????????
        if(data[key] != 0):
            HS += - (data[key]/all)  * (math.log2(data[key] / (all)))

    return HS

def split(Cars, Attribute, value):
    #vill ha en ny lista med alla bilar som har attributet man skickar med.
    #returnar E_vi
    reducedList = []
    for car in Cars:
        if(Attribute=='buying' and car.buying == value):
            reducedList.append(car)
        elif(Attribute=='maint' and car.maint == value):
            reducedList.append(car)
        elif(Attribute=='doors' and car.doors == value):
            reducedList.append(car)          
        elif(Attribute=='persons' and car.persons == value):
            reducedList.append(car)       
        elif(Attribute=='lug_boot' and car.lug_boot == value):
            reducedList.append(car)
        elif(Attribute=='safety' and car.safety == value):
            reducedList.append(car)
        elif(Attribute=='attractiveness' and car.attractiveness == value):
            reducedList.append(car)

    return reducedList

def MaxInfoGain(Cars, Attributes):
    max = 0
    bestAttribute = ""

    for attribute in Attributes.keys():
        temp = InformationGain(Cars,attribute)
        if(temp>max):
            max=temp
            bestAttribute=attribute

    return bestAttribute
    
def main():
    readData()
    asd = ID3(carDatabase, attributes)
    dfg=1




main()