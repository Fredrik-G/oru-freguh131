from node import *
from link import *
import math
connections = {}
def readRoads():
    
    dataFile = open('roads.csv')
    for dataLine in dataFile.readlines():
        dataLine = dataLine[:-1]
        temp = dataLine.split(';')
        if(temp[0] == '#'):
            break
        if(temp[0] != "from"):      
            if (temp[0] in connections.keys()):
               connections[temp[0]].append(temp[1])
            else:
                connections[temp[0]] = [temp[1]]
        if(temp[1] != "to"):
            if (temp[1] in connections.keys()):
               connections[temp[1]].append(temp[0])
            else:
                connections[temp[1]] = [temp[0]]

       #     if (temp[0] in connections.keys()):
       #         connections[temp[0]] += [temp[1]]
        #    if (temp[0] in connections.keys()):
       #         connections[temp[1]] += [temp[0]]
       #     else:
       #         connections[temp[0]] = [temp[1]]
                    
           # connections.update({temp[0]:temp[1]})
           # connections.update({temp[1]:temp[0]})

            #if (temp[0] in connections.keys()):
            #    for asd in connections.keys():
            #        if(asd == temp[0]):
            #            if(temp[0] != asd):
            #                connections[temp[0]] += [temp[1]]
                
            #if (temp[1] in connections.keys()):
            #    for asd in connections[temp[0]]:
            #        if(asd == temp[1]):
            #            if(temp[1] != asd):
            #                connections[temp[1]] += [temp[0]]
                                        
  #  print("\n\n")
  #  for key in connections:
  #     print (key, connections[key])


cityList = [ Node("asd",2,3) for i in range(24)]
def readFile():

    dataFile = open('locations.csv')
    n=-1
    for dataLine in dataFile.readlines():
        n=n+1           
        temp = dataLine.split(';')

        if(temp[0] == '#'):
            break
        cityList[n].name = temp[0]
        cityList[n].x = temp[1]
        cityList[n].y = temp[2][:-1]
    #for y in range(23):
    #    print(cityList[y+1].name, cityList[y+1].x, cityList[y+1].y)                 
    dataFile.close()

def deepening_search(start, goal, limit) :
    expanded = 1
    frontier = []
    visited = []
    total = []
    visited.append(start)
    for successor in connections[start]:
        if(successor == goal):
            visited.append(goal)
            print("Found goal ", goal,",expanded ", expanded, "nodes")
            print(visited)
            return visited
        frontier.append(successor)
        total.append(successor)
    while len(frontier) > 0 :          
        path = frontier.pop()

        if len([path]) < limit :
                expanded += 1
                visited.append([path])

                for child in connections[path]:
                    if child == goal :
                        visited.append(goal)
                        print("ads asd ", goal,",expanded ", expanded, "nodes")
                        print(visited)
                        return path
                    if child not in total:
                        frontier.append(child)
                        total.append(child)

                del child


def best_first_search(start, goal):
    min_distance = 999999
    expanded = 0
    done = 0
    frontier = []
    bestWay = []
    #Convert start node X&Y to integer(from string)
    X = int(start.x.strip())
    Y = int(start.y.strip())

    bestWay.append(goal.name)


    while(done != 1):
        if(bestWay[-1] == start.name):

            print("Found best way with ", expanded, " expanded nodes")
            
            path = bestWay

            while(bestWay[-1] != goal.name ):
                print(bestWay.pop())
            print(goal.name)
            done = 1

        for successor in connections[bestWay[-1]]:
            if successor not in bestWay:           
                frontier.append(successor)

        #Calculates the distance to the frontier (successor)
        while(len(frontier) > 0):
            temp = calcDist(X,Y,frontier[-1])   
            
            if(temp < min_distance):
                  min_distance = temp
                  best = frontier[-1] 
            current = frontier.pop()
            

     #   if(len(frontier[-1]) > 0):
        #Hittat bästa nod, fortsätt vid dess successors
        bestWay.append(best)
        min_distance = 999999
        expanded += 1

#used by task C
def calcDist(startX, startY, node):
    for city in cityList:
        if(node == city.name):
            x = int(city.x.strip())
            y = int(city.y.strip())
    #y är "tvärtom"
    asd = math.sqrt( (x-startX)*(x-startX) + (y-startY)*(y-startY) )
   # print(asd)
    return asd

#used by task D
def Astar(start, goal):
    #räkna ut fågelväg för start->goal
    #sen alla starts successor och deras fågelväg
    
    bestWay = []
    frontier = []
    min_distance = 999999
    cost_so_far = 0
    done = 0

    startX = int(start.x.strip())
    startY = int(start.y.strip())

    estimate = calcDist(startX, startY, goal.name)

    bestWay.append(start.name)

    while(done != 1):

        if(bestWay[-1] == goal.name):

            print("Found best way with  expanded nodes")
            
            print(bestWay)
                
            done = 1

        for successor in connections[bestWay[-1]]:                      
            frontier.append(successor)
    
        while(len(frontier) > 0):    
            temp = estDist(frontier[-1], goal)
            
            if (temp < min_distance):
                min_distance = temp
                best = frontier[-1]

            frontier.pop()

        bestWay.append(best)

        cost_so_far = estDist(bestWay[-1], start)

        min_distance = 999999
       # print(bestWay)   
          

def estDist(current, goal):
    for asd in cityList:
        if (goal.name == asd.name):
            goalX = int(asd.x.strip())
            goalY = int(asd.y.strip())

    for city in cityList:
        if(current == city.name):
            currentX = int(city.x.strip())
            currentY = int(city.y.strip())
            city.cost = math.sqrt( (goalX-currentX)*(goalX-currentX) + (goalY-currentY)*(goalY-currentY) )
            return city.cost

def task1b():
    print("Start location? ")
    start = input()
    print("\nGoal location? ")
    goal = input()
    deepening_search(start, goal, 2)

def task1c():
    #print("Start location? ")
    #tempStart = input()
    #print("\nGoal location? ")
    #tempGoal = input()
    tempStart = 'Neuburg'
    tempGoal = 'Denkendorf'
    for startNode in cityList:
        if(tempStart == startNode.name):
            start = startNode
    for goalNode in cityList:
        if(tempGoal == goalNode.name):
            goal = goalNode
    best_first_search(start, goal)

def task1d():
    #print("Start location? ")
    #tempStart = input()
    #print("\nGoal location? ")
    #tempGoal = input()
    tempStart = 'Kosching'
    tempGoal = 'Denkendorf'
    for startNode in cityList:
        if(tempStart == startNode.name):
            start = startNode
    for goalNode in cityList:
        if(tempGoal == goalNode.name):
            goal = goalNode

    Astar(start, goal)

readFile()
readRoads()

#task1c()
task1d()



#total = current längd + fågel