from node import *
from link import *
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
        cityList[n].name = temp[0][:-1]
        cityList[n].x = temp[1]
        cityList[n].y = temp[2][:-1]
#    for y in range(23):
#        print(cityList[y+1].name, cityList[y+1].x, cityList[y+1].y)                 
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
    min_distance = 0
    frontier = []
    for successor in connections[goal]:
         frontier.append(successor)
    for node in cityList:
        if (frontier[-1] == node.name):
            print(node.name)

            #expanda från mål till start, räkna fågelavstånd.

readFile()
readRoads()

#best_first_search('Neuburg', 'Denkendorf')


print("Start location? ")
start = input()
print("\nGoal location? ")
goal = input()
deepening_search(start, goal, 2)
