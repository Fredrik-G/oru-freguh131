from room import *
from person import *

personList = [person("-1", "asd", False, -1) for i in range(9)]
roomList = [room("-1", -1, -1) for i in range(7)]
def initLists():
    personList[0].id = 'A'
    personList[0].profession = 'Boss'
    personList[0].garlic_lover = True
    personList[0].max_visitors = 5

    personList[1].id = 'B'
    personList[1].profession = 'Secretary'
    personList[1].garlic_lover = False
    personList[1].max_visitors = 1

    personList[2].id = 'C'
    personList[2].profession = 'IT-support'
    personList[2].garlic_lover = False
    personList[2].max_visitors = 2

    personList[3].id = 'D'
    personList[3].profession = 'Boss'
    personList[3].garlic_lover = True
    personList[3].max_visitors = 5

    personList[4].id = 'E'
    personList[4].profession = 'Secretary'
    personList[4].garlic_lover = False
    personList[4].max_visitors = 1

    personList[5].id = 'F'
    personList[5].profession = 'Worker'
    personList[5].garlic_lover = False
    personList[5].max_visitors = 3

    personList[6].id = 'G'
    personList[6].profession = 'Worker'
    personList[6].garlic_lover = False
    personList[6].max_visitors = 2

    personList[7].id = 'H'
    personList[7].profession = 'Worker'
    personList[7].garlic_lover = True
    personList[7].max_visitors = 7

    personList[8].id = 'I'
    personList[8].profession = 'Worker'
    personList[8].garlic_lover = True
    personList[8].max_visitors = 1
   
    ##############roomlist
    roomList[0].id = 'T1'
    roomList[0].work_places = 2
    roomList[0].visitor_places = 5

    roomList[1].id = 'T2'
    roomList[1].work_places = 3
    roomList[1].visitor_places = 2

    roomList[2].id = 'T3'
    roomList[2].work_places = 1
    roomList[2].visitor_places = 3

    roomList[3].id = 'T4'
    roomList[3].work_places = 1
    roomList[3].visitor_places = 3

    roomList[4].id = 'T5'
    roomList[4].work_places = 2
    roomList[4].visitor_places = 5

    roomList[5].id = 'T6'
    roomList[5].work_places = 2
    roomList[5].visitor_places = 5


    roomList[6].id = 'T7'
    roomList[6].work_places = 2
    roomList[6].visitor_places = 5


    roomList[0].near.append(roomList[1])
    roomList[0].near.append(roomList[6])

    roomList[1].near.append(roomList[0])
    roomList[1].near.append(roomList[2])
    roomList[1].near.append(roomList[5])

    roomList[2].near.append(roomList[1])
    roomList[2].near.append(roomList[3])
    roomList[2].near.append(roomList[4])

    roomList[3].near.append(roomList[2])
    roomList[3].near.append(roomList[4])

    roomList[4].near.append(roomList[5])
    roomList[4].near.append(roomList[2])
    roomList[4].near.append(roomList[3])

    roomList[5].near.append(roomList[4])
    roomList[5].near.append(roomList[6])
    roomList[5].near.append(roomList[1])

    roomList[2].near.append(roomList[5])
    roomList[2].near.append(roomList[0])


def AssignPersonToRoom():
    i = 0
    for person in personList:
        if(i>5 and i<10):
            person.inroom = roomList[i-5]
            roomList[i-5].workersInRoom.append(person)
        else:
            person.inroom = roomList[i]
            roomList[i].workersInRoom.append(person)

        i += 1

    print(1)

def bossConstraints(person, room):
    #A “boss” shall sit alone in an office
    if(person.profession == 'Boss'):
        if(len(room.workersInRoom) < 1):
            return True
    else:
        if(len(room.workersInRoom) != 0):
            if(room.workersInRoom[-1].profession == 'Boss'):
                return False
            else:
                return True

def SecretaryAndITConstraints(person, room):
    #An “it-support” person shall sit in an office near to a “boss” 
    if(person.profession == 'Secretary'):
        for adjacent in room.near:
            for worker in adjacent.workersInRoom:
                if(worker.profession == 'Boss'):
                    return True

        return False    

def garlicLoverConstraints(person, room):
    #A garlic-loving person shall either sit alone or together with other garlic-lovers
    number_of_workers = len(room.workersInRoom)
    number_of_garlic_lovers = 0
    if(number_of_workers > 0):
        for worker in room.workersInRoom:
            if(worker.garlic_lover == True):
                number_of_garlic_lovers += 1
        
        if(number_of_garlic_lovers == number_of_workers):
            return True
        else:
            return False        

    else:
       return True
def visitorConstraints(person, room):
#A person with non-zero visitors shall sit in an office that provides enough space for
#the number of visitors – the maximum number of visitors of all persons in the room
#shall be smaller or equal to the possible number of visitors.     if(room.visitor_places >= person.max_visitors):        sum_of_visitors = 0        for worker in room.workersInRoom:            if(person != worker):                sum_of_visitors += worker.max_visitors        if(room.visitor_places >= (person.max_visitors + sum_of_visitors)):            return True        else:            return False

initLists()
AssignPersonToRoom()

SecretaryAndITConstraints(personList[1], roomList[1])

print(garlicLoverConstraints(personList[3], roomList[1]))
print(visitorConstraints(personList[8], roomList[5]))