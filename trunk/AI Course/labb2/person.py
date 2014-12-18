class person(object):
    id = ""
    profession = ""
    garlic_lover = False
    max_visitors = -1
    inroom = None
    AvailableRooms = 0

    def __init__(self, id, profession, garlic_lover, max_visitors):
        self.id = id
        self.profession = profession
        self.garlic_lover = garlic_lover
        self.max_visitors = max_visitors
        inroom = None
        AvailableRooms = 0