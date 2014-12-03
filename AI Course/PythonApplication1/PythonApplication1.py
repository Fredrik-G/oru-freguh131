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


costSoFar = {}
bestWay = []
def Astar(start, goal):
    #räkna ut fågelväg för start->goal
    #sen alla starts successor och deras fågelväg
    
    visited = []
    frontier = []
    bestCity = ""
    done = 0
    foundBetter = 0

    #convert X&Y-pos to integer
    startX = int(start.x.strip())
    startY = int(start.y.strip())

    #calculate distance from start pos to goal
    #####estimate = calcDist(startX, startY, goal.name)

    bestWay.append(start.name)
    visited.append(start.name)
    costSoFar[start.name] = 0.0

    while(done != 1):
        foundBetter = 0
        #check if we've found the goal
        if(bestWay[-1] == goal.name):
            bestWay.append(goal.name)
            print("Found best way with  expanded nodes")
            
            print(bestWay)
                
            done = 1

       #if we're not at the goal:
        #adds all successors to the frontier
        for successor in connections[bestWay[-1]]:
            if successor not in frontier:

                if(successor == goal.name):
                    bestWay.append(goal.name)
                    print("Found best way with  expanded nodes")   
                    print(bestWay)
                    print("\n\n")
                    print(visited)                
                    done = 1

                    #pause
                    input()

                frontier.append(successor)

        #creates a copy of frontier    
        frontier2 = []
        for a in frontier:
            frontier2.append(a)

        #while frontier is not empty
        while(len(frontier) > 0):
            costSoFar[frontier[-1]] = 0.0
            
            estCostToGoal = estDist(frontier[-1], goal.name, 0)
            asd = estDist(frontier[-1], bestWay[-1], 1) 

            costSoFar[frontier[-1]] = asd
          
            parentName = frontier.pop()

        temp_min = asd
        for node in costSoFar:
            if(costSoFar[node] < asd and costSoFar[node] < temp_min):
                if node not in visited:
                    temp_min = costSoFar[node]
                  #  min = temp_min

        for node2 in costSoFar:
            if(temp_min == costSoFar[node2] and temp_min != asd):

                if(node2 == 'Grossmehring'):
                    debug=1

               # bestWay.pop()              
                bestWay.append(node2)
                visited.append(node2)
                foundBetter = 1
        
        if(foundBetter == 0):
            bestCity = calcBest(frontier2)

            if(bestCity == 'Mindelstetten'):
                debug=1

            bestWay.append(bestCity)
            visited.append(bestCity)

def calcBest(nodes):
    tempTotal = 99999999.0
    bestCity = ""

    for node in nodes:
        for city in cityList:
            if(node == 'Vohburg' and city.name == 'Vohburg'):
                debug = 1
            if(node == city.name):
                city.total = city.cost_so_far + city.cost_to_goal

                if(city.total < tempTotal and city.cost_so_far != 0.0):
                    tempTotal = city.total
                    bestCity = city.name
                
    return bestCity

def estDist(fran, to, franStart):
    for asd in cityList:
        if (to == asd.name):
            toX = int(asd.x.strip())
            toY = int(asd.y.strip())

    for city in cityList:
        if(fran == city.name):
            franX = int(city.x.strip())
            franY = int(city.y.strip())

            if(franStart == 0):
                city.cost_to_goal = math.sqrt( (franX-toX)*(franX-toX) + (franY-toY)*(franY-toY) )
                return city.cost_to_goal

            elif(franStart == 1):

                if(city.name == 'Gaimersheim'):
                    debug=1

                city.cost_so_far += math.sqrt( (toX-franX)*(toX-franX) + (toY-franY)*(toY-franY) )
                city.cost_so_far += costSoFar[bestWay[-1]]
                return city.cost_so_far
            

def calcDist(startX, startY, node):
    for city in cityList:
        if(node == city.name):
            x = int(city.x.strip())
            y = int(city.y.strip())
            break
    #y är "tvärtom"
   # print(asd)
    temp = math.sqrt( (x-startX)*(x-startX) + (y-startY)*(y-startY) )
    return temp

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
    tempStart = 'Bergheim'
    tempGoal = 'Pforring'
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
    tempStart = 'Bergheim'
    tempGoal = 'Pforring'
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
input()

#total = current längd + fågel