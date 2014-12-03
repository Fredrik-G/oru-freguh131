class Node(object):
    name = ""
    x = 0
    y = 0
    cost_so_far = 0.0
    cost_to_goal = 0.0
    total = 0.0
    parent = []

    def __init__ (self,namn,X,Y):
        self.name = namn
        self.x = X
        self.y = Y
