from room import *
from person import *

personList = [person("-1", "asd", False, -1) for i in range(9)]
roomList = [room("-1", -1, -1, 0) for i in range(7)]
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
    personList[7].max_visitors = 0

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

    roomList[6].near.append(roomList[0])
    roomList[6].near.append(roomList[5])


def bossConstraints(person, room):
    #A boss shall sit alone in an office
    if(person.profession == 'Boss'):
        if(len(room.workersInRoom) > 1):
            return False

    else:
        for worker in room.workersInRoom:
            if(worker.profession == 'Boss'):
                return False

    return True

def SecretaryConstraints(person, room):
    #A secretary person shall sit in an office near to a ?boss? 
    if(person.profession != 'Secretary'):
        return True
    for adjacent in room.near:
        for worker in adjacent.workersInRoom:
            if(worker.profession == 'Boss'):
                return True

        return False

def ITConstraints(person, room):
    #An ?it-support? person shall sit in an office near to a ?boss? 
    if(person.profession != 'IT-support'):
        return True
    for adjacent in room.near:
        for worker in adjacent.workersInRoom:
            if(worker.profession == 'Boss'):
                return True

        return False

def garlicLoverConstraints(person, room):
    #A garlic-loving person shall either sit alone or together with other garlic-lovers
    for worker in room.workersInRoom:
        if(person.garlic_lover != worker.garlic_lover):
            return False

    return True

def visitorConstraints(person, room):
#A person with non-zero visitors shall sit in an office that provides enough space for
#the number of visitors ? the maximum number of visitors of all persons in the room
#shall be smaller or equal to the possible number of visitors. 
    
    count=0
    if(person.max_visitors > 0):
        for worker in room.workersInRoom:
            count = count + worker.max_visitors

    count = count + person.max_visitors

    if(count>room.visitor_places):
        return False
    else:
        return True

    #if(room.visitor_places >= person.max_visitors):
    #    sum_of_visitors = 0
    #    for worker in room.workersInRoom:
    #        if(person != worker):
    #            sum_of_visitors += worker.max_visitors

    #    if(room.visitor_places >= (person.max_visitors + sum_of_visitors)):
    #        return True
    #    else:
    #        return False

def allocate(persons, rooms):
    for person in persons:
        for room in rooms:
            if(AssignPersonToRoom(person, room)):
                break

def CheckConstraints(person, room):
    if(bossConstraints(person, room) and 
    SecretaryConstraints(person, room) and 
    ITConstraints(person, room) and 
    garlicLoverConstraints(person, room) and 
    visitorConstraints(person, room)):
        return True

    return False
#############################################################################################################

def CheckBossAlone(person,room,personinroom):
    if(person.profession == "Boss"):
        for key, value in personinroom.items():
            if(value == room):
                return False

    for key, value in personinroom.items():
        if(value == room):
            if(key.profession == "Boss"):
                return False
    return True

def CheckSecretaryNearBoss(person,room,personinroom):
    if(person.profession == "Secretary"):
        for key,value in personinroom.items():
            if(key.profession == "Boss"):
                for x in value.near:
                    if(x.id == room.id):
                        return True
        return False
    else:
        return True

def CheckITSupportNearBoss(person,room,personinroom):
    if(person.profession == "IT-support"):
        for key,value in personinroom.items():
            if(key.profession == "Boss"):
                for x in value.near:
                    if(x.id == room.id):
                        return True
        return False
    else:
        return True

def CheckGarlicLover(person, room, personinroom):
    if(person.garlic_lover == True):
        for key,value in personinroom.items():
            if(room == value):
                if(key.garlic_lover == False):
                    return False
    else:
        for key,value in personinroom.items():
            if(room == value):
                if(key.garlic_lover == True):
                    return False
    return True

def CheckVisitorSpace(person, room, personinroom):
    count = 0
    if(person.max_visitors > 0):
        for key, value in personinroom.items():
            if(room == value):
                count = count + key.max_visitors
    count = count + person.max_visitors

    if(count > room.visitor_places):
        return False
    else:
        return True

def CheckPlace(person,room,personinroom):
    count = 0
    for key, value in personinroom.items():
        if(room == value):
            count = count + 1
    count = count + 1

    if(count > room.work_places):
        return False
    else:
        return True 

def CheckAllConstraints(person,room,personinroom):
    return (CheckBossAlone(person,room,personinroom) and
            CheckSecretaryNearBoss(person,room,personinroom) and
            CheckITSupportNearBoss(person,room,personinroom) and
            CheckGarlicLover(person,room,personinroom) and
            CheckVisitorSpace(person, room, personinroom) and
            CheckPlace(person,room,personinroom))








###################################################################################################################
def AllocateBacktracking():
    i = 0
    #select unassigned variable(someone who's not in a room)
    while(personList[i].inroom != None):
        i += 1
        if(i >= len(personList)):
            #alla är i ett rum, return complete
            return True

    for room in roomList:
        personList[i].inroom = room
        room.workersInRoom.append(personList[i])

        #kolla om personen kan vara i det rummet
        #ta  bort om den inte kan vara där
        if not CheckConstraints(personList[i], room):
            personList[i].inroom = None
            room.workersInRoom.remove(personList[i])

        #fortsätt med nästa person
        elif AllocateBacktracking():
            return True

        #ta bort denna persons rum om det blev ett fel längre fram
        else:
            personList[i].inroom = None
            room.workersInRoom.remove(personList[i])

    return False

def NumberOfPossibleRooms(person, rooms):
    numberOfRooms = 0
    for room in rooms:
        if(CheckConstraints(person, room)):
            numberOfRooms += 1

    return numberOfRooms


#def GetSortedRoomList(person, rooms, unassignedPersons):
#    eval = {}
#    for room in rooms:
#        if(CheckConstraints(person, room)):
#            assign()

#        blah=0
#        for p in unassignedPersons:
#            blah=blah+len(possibleRooms)
        
#        eval[r] = blah
        
#        return sort unassigned

#def GetPossibleRoom(person, rooms):
#    bla=[]
#    for room in rooms:
#        if(CheckConstraints(person, room)):
#            bla.append(room)

#    return bla


PersonInRoom = {}


def SelectUnassignedVariable(personlist,roomlist,personinroom):
    #Ta fram person med flest constraints (kan vara i minst antal rum)
    TempPersonList = []
    if(len(personinroom) == 0):
        for person in personlist:
            if(person.profession == "Boss"):
                return person

    for person in personlist:
        if person not in personinroom:
            count = 0
            for x in roomlist:
                if(CheckConstraints(person,x)):
                    count = count + 1

            person.AvailableRooms = count
            TempPersonList.append(person)

    if(len(TempPersonList) != 0):
        return min(TempPersonList, key = lambda x: x.AvailableRooms)
    else:
        return None
def OrderDomainValues(person,roomlist,personinroom,personlist):
    tempRoomList = []

    for room in roomlist:
        PossibleOptions = 0
        #Lägg in personen man skickar med i ett rum
        #Testa sedan (test-allocation) att lägga in resterande personer i ett rum
        #och kolla hur många som "får" vara där.
        personinroom[person] = room

        for testperson in personlist:
            if testperson not in personinroom:
                count = 0
                for room2 in roomlist:
                    if(CheckAllConstraints(testperson, room2, personinroom)):
                        count += 1

                PossibleOptions += count

        room.possibleOptions = PossibleOptions
        del personinroom[person]

    TempRoomList = roomlist
    sortedRoomList = []

    while(len(TempRoomList) != 0):
        #Sorterar listan i storlektsordning med avseende på possibleOption
        BestRoom = max(TempRoomList, key = lambda room: room.possibleOptions)
        sortedRoomList.append(BestRoom)
        TempRoomList.remove(BestRoom)

    return sortedRoomList
        
def RecursiveAllocate(personlist,roomlist,personinroom):
    #Smart tilldelning för att minska antal steg (backtracking).
    #Utgå från person med flest constraints och rum med flest antal möjliga arbetare

    #Ta fram person med flest constraints
    person = SelectUnassignedVariable(personlist,roomlist,personinroom)
    if(person == None):
        return personinroom
    #Ta fram en sorterad rumlista med rummet med flest antal möjliga arbetare först.
    roomlist = OrderDomainValues(person,roomlist,personinroom,personlist)
    for room in roomlist:
        if(CheckConstraints(person,room) == True):
            #Lägg in den "bästa" personen om den kan vara där
           personinroom[person] = room
           room.workersInRoom.append(person)
           result = RecursiveAllocate(personlist,roomlist,personinroom)

           if (result != False):
               return result

           del personinroom[person]
           room.workersInRoom.remove(person)

    return False

def PrintDict(personinroom):
    print("(ID,Profession,Garlic Lover,Max visitors,rum-ID)")
    for key,value in personinroom.items():
        print("(",key.id,",",key.profession,",",key.garlic_lover,",",key.max_visitors,")",":",value.id)
        


initLists()
#AssignPersonToRoom()

#allocate(personList, roomList)

#print(AllocateBacktracking())

#AllocateHeuristics()


#PersonInRoom[personList[0]] = roomList[0]
#asd=SelectUnassignedVariable(PersonInRoom)
#OrderDomainValues(personList[0])


PrintDict(RecursiveAllocate(personList, roomList, PersonInRoom))



print('\n\n\n\n')

#SecretaryAndITConstraints(personList[1], roomList[1])

#print(garlicLoverConstraints(personList[3], roomList[1]))
#print(visitorConstraints(personList[8], roomList[5]))