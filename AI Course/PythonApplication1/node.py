class Node(object):
    name = ""
    x = 0
    y = 0
    successors = []
    

    def __init__ (self,namn,X,Y):
        self.name = namn
        self.x = X
        self.y = Y
