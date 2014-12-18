class room(object):
    id = ""
    work_places = -1
    visitor_places = -1
    near = []
    workersInRoom = []
    possibleOptions = 0

    def __init__(self, id, work_places, visitor_places, possible):
        self.id = id
        self.work_places = work_places
        self.visitor_places = visitor_places
        self.near = []
        self.workersInRoom = []
        self.possibleOptions = 0