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
    visited.append(start)
    depth = {}
    depth[start] = 0
    parent = {}
    parent[start] = 0

    frontier.append(start)

    while len(frontier) > 0 :          
        node = frontier.pop()
        if node == goal :
            visited.append(goal)
            return reconstructPath(start, goal, parent)

        if (depth[node] < limit) :
                expanded += 1
                visited.append(node)

                for child in connections[node]:
                    if child not in visited:
                         depth[child] = depth[node]+1
                         parent[child] = node
                         frontier.append(child)

                del child
    print("No solution found")

def reconstructPath(start, goal, parent):
    path = []
    node = goal
    while( parent[node] != start):
        path.insert(0,parent[node])
        node = parent[node]
    
    path.insert(0,start)
    return path

def best(start, goal):
    expanded = 1
    frontier = []
    visited = []
    parent = {}
    parent[start] = 0
    closestNode = ""
    #visited.append(start)
    frontier.append(start)

    while len(frontier) > 0:    
        closestNode = frontier[0]
        #jämför avståndet mellan en nod och den föregående bästa noden för alla noder i frontier
        for n in frontier:
            if(closestToGoal(n, goal) < closestToGoal(closestNode, goal)):
                closestNode = n
        
        for asd in frontier:
            if(asd == closestNode):
               index = frontier.index(asd)
               node = frontier.pop(index)
                      
        if(node == goal):
            print("asd")
            visited.append(goal)
            #dfikjg = reconstructPath(start, goal, parent)
            #print(dfikjg)
            return reconstructPath(start, goal, parent)

        if node not in visited:
            visited.append(node)
      

        for child in connections[node]:
            if child not in visited:
                 parent[child] = node
                 frontier = [child] + frontier
                      
    print("No solution found")

def closestToGoal(tempNode ,tempGoal):
    #node = str(tempNode.name)
    #goal = str(tempGoal.name)

    for city in cityList:
        if(city.name == tempNode):           
            node1X = int(city.x.strip())
            node1Y = int(city.y.strip())

    for city2 in cityList:
        if(city2.name == tempGoal):
            goalX = int(city2.x.strip())
            goalY = int(city2.y.strip())

    x = node1X - goalX
    y = node1Y - int(city.y.strip())
    ans = math.sqrt((x*x)+(y*y))
    return ans


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
    expanded = 0
    visited = []
    frontier = []
    test = []
    bestCity = ""
    done = 0
    foundBetter = 0

    #convert X&Y-pos to integer
    startX = int(start.x.strip())
    startY = int(start.y.strip())


    bestWay.append(start.name)
    visited.append(start.name)
    costSoFar[start.name] = 0.0

    while(done != 1):
        foundBetter = 0

        #check if we've found the goal
        if(bestWay[-1] == goal.name):
            done = 1   
            
            bestWay.append(goal.name)                  
            findWay(bestWay, start.name, goal.name)

       #if we're not at the goal:
        #adds all successors to the frontier
        for successor in connections[bestWay[-1]]:
            if successor not in frontier:
                if(successor == goal.name):
                    done = 1
                    bestWay.append(goal.name)                            
                    findWay(bestWay, start.name, goal.name)

            frontier.append(successor)
                

        #creates a copy of frontier    
        frontier2 = []
        for a in frontier:
            frontier2.append(a)

        #while frontier is not empty
        while(len(frontier) > 0):
            costSoFar[frontier[-1]] = 0.0
            
            #cost between current node and the goal (straight line)
            estCostToGoal = estDist(frontier[-1], goal.name, 0)

            #adds cost from start to the current node. (not straight line)
            cost_to_node = estDist(frontier[-1], bestWay[-1], 1) 
            #add cost to the dictionary.
            costSoFar[frontier[-1]] = cost_to_node
          
            frontier.pop()
        
        #check if the earlier estimated cost is better than the new way
        #assign a start value to temp_min
        temp_min = cost_to_node
        for node in costSoFar:
            if(costSoFar[node] < cost_to_node  and costSoFar[node] < temp_min):
                if node not in visited:
                    temp_min = costSoFar[node]
                    betterway=1
        #assign lowest cost (next node) to its name.          
        for node2 in costSoFar:
            if(temp_min == costSoFar[node2] and temp_min != cost_to_node):

                if(node2 == 'Adelschlag'):
                    debug=1
           
                bestWay.append(node2)
                visited.append(node2)
                foundBetter = 1
        
        if(foundBetter == 0):
            bestCity = calcBest(frontier2)
           
            if(bestCity == 'Bergheim'):
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
            
def findWay(bestWay, start, goal):
    done=0
    x = -1
    y = -1
    correctWay = []
    while(done != 1):
        if( math.fabs(y)>(len(bestWay)-1)):
            y=0
        successor = connections[bestWay[x]]
        if start in successor:
                correctWay.append(start)
                correctWay.reverse()
                
                correctWay.append(bestWay[-1])
                print("Found best way")
                print(correctWay)
                print(len(bestWay))
                done=1

                input()
        if bestWay[y] in successor:
            #hittade successor
            correctWay.append(bestWay[y])
            x=y
            y -= 1

            if(correctWay[-1] == start):
                correctWay.reverse()
                correctWay.append(bestWay[-1])
                print("Found best way")
                print(correctWay)
                print(len(bestWay))
                done=1

                input()
        else:
            y -= 1
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
    #print("Start location? ")
    #start = input()
    #print("\nGoal location? ")
    #goal = input()
    #deepening_search(start, goal, 2)

    start = 'Neuburg'
    goal = 'Denkendorf'
    best(start, goal)


def task1c():
    #print("Start location? ")
    #tempStart = input()
    #print("\nGoal location? ")
    #tempGoal = input()
    tempStart = 'Ingolstadt'
    tempGoal = 'Neuburg'
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
    tempStart = 'Denkendorf'
    tempGoal = 'Neustadt'
    for startNode in cityList:
        if(tempStart == startNode.name):
            start = startNode
    for goalNode in cityList:
        if(tempGoal == goalNode.name):
            goal = goalNode

    Astar(start, goal)

readFile()
readRoads()
#print(deepening_search('Neuburg', 'Mindelstetten', 20))
task1b()
#task1c()
#task1d()
input()

#total = current längd + fågel