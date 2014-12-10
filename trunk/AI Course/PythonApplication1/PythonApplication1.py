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

def deepening_search(start, goal, limit):
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
            print("Found best way:")
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
    path.append(goal)
    return path
def reconstructPath2(start, goal):
    if goal == start:
        print(goal.name)
    else:
        print(goal.name)
        reconstructPath2(start, goal.parent[0])
def best_first_search(start, goal):
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
            print("Found best way:")
            visited.append(goal)
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

def stringToNode(name):
    for city in cityList:
        if(city.name == name):
            return city

def calcDist(fran, to):
    for asd in cityList:
        if (to.name == asd.name):
            toX = int(asd.x.strip())
            toY = int(asd.y.strip())

    for city in cityList:
        if(fran.name == city.name):
            franX = int(city.x.strip())
            franY = int(city.y.strip())
   
    return math.sqrt(((franX-toX)*(franX-toX))+((franY-toY)*(franY-toY)))


def Astar(start, goal):
    frontier = []
    explored = []

    startNode = stringToNode(start)
    goalNode = stringToNode(goal)
    startNode.cost_to_goal = calcDist(startNode, goalNode)

    frontier.append(startNode)

    while len(frontier) > 0:
        closestNodeToGoal = frontier[0]

        
        for city in frontier:
            if(city.cost_to_goal + city.cost_so_far) < (closestNodeToGoal.cost_to_goal + closestNodeToGoal.cost_so_far):
                closestNodeToGoal = city

        currentNode = closestNodeToGoal
        frontier.remove(closestNodeToGoal)

        if currentNode not in explored:
            explored.append(currentNode)
        if (currentNode == goalNode):
            print("Found best way:")
            reconstructPath2(startNode, currentNode)
            return [currentNode]

        for next in connections[currentNode.name]:
            nextNode = stringToNode(next)

            if nextNode in explored:
                #check if score is better than before
                if(nextNode.cost_so_far > currentNode.cost_so_far + calcDist(currentNode, nextNode)):
                    nextNode.parent = [currentNode]
                    nextNode.cost_so_far = currentNode.cost_so_far + calcDist(currentNode, nextNode)
                    #remove next from explored,
                    #add next to frontier
                    explored.remove(nextNode)
                    frontier.append(nextNode)

            elif nextNode in frontier:
                if(nextNode.cost_so_far > currentNode.cost_so_far + calcDist(currentNode, nextNode)):
                    nextNode.parent = [currentNode]
                    nextNode.cost_so_far = currentNode.cost_so_far + calcDist(currentNode, nextNode)
           
            else:
            #add next to frontier
                frontier = [nextNode] + frontier
                nextNode.cost_so_far = currentNode.cost_so_far + calcDist(currentNode, nextNode)
                nextNode.parent = [currentNode]


    print("No solution found")

def task1b():
    print("Start location? ")
    start = input()
    print("\nGoal location? ")
    goal = input()


#    start = 'Ingolstadt'
 #   goal = 'Neuburg'
    print(deepening_search(start, goal, 20))


def task1c():
    print("Start location? ")
    start = input()
    print("\nGoal location? ")
    goal = input()
 #   start = 'Ingolstadt'
#    goal = 'Neuburg'

    print(best_first_search(start, goal))

def task1d():
    print("Start location? ")
    start = input()
    print("\nGoal location? ")
    goal = input()
   # start = 'Denkendorf'
   # goal = 'Neustadt'

    Astar(start, goal)

readFile()
readRoads()


print("Choose search method:")
print("   1. Iterative deepening search ")
print("   2. Best-first search ")
print("   3. A* search ")
choice=input()
if(choice == '1'):
    task1b()
elif(choice == '2'):
    task1c()
elif(choice == '3'):
    task1d()


