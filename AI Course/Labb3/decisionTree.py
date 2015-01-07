class DecisionFork:
    """A fork of a decision tree holds an attribute to test, and a dictionary
    of branches, one for each of the attribute's values."""

    def __init__(self, attribute, branches):
        "Initialize by saying what attribute this node tests."
        self.attribute = attribute
        self.branches = branches

    def get(self, example):
        "Given an example, return the current branch given the attribute-value"
        "combinations in this example"
        "I assume that also the example is a dictionary with the attributes "
        "as keys and the values as values"
        attrvalue = example[self.attribute]
        return self.branches[attrvalue]

    def add(self, val, subtree):
        "Add a branch for a particular value; a branch is hereby either a "
        "DecisionLeaf or another DecisionFork"
        self.branches[val] = subtree

    def display(self, indent=0):
        name = self.attribute
        print(' '*4*indent, name)
        for (val, subtree) in self.branches.items():
            print(' '*4*(indent+1), '=', val, '==>')
            subtree.display(indent + 2)

    def __repr__(self):
        return ('DecisionFork(%r, %r)'
                % (self.attribute, self.branches))



class DecisionLeaf:
    "A leaf of a decision tree holds just a result."

    def __init__(self, result):
        self.result = result

    def get(self, example):
        return self.result

    def display(self, indent=1):
        print(' '*4*indent, 'RESULT =', self.result)

    def __repr__(self):
        return repr(self.result)


theTree = DecisionFork("safety",
    {"low": DecisionFork("buying",
                         {"vhigh": DecisionLeaf("unacc"), 
                          "high":   DecisionLeaf("unacc"), 
                          "med": DecisionLeaf("unacc"),
                          "low": DecisionLeaf("acc")}),
     "med": DecisionFork("buying",
                         {"vhigh": DecisionLeaf("unacc"), 
                          "high":   DecisionLeaf("unacc"), 
                          "med": DecisionLeaf("unacc"),
                          "low": DecisionLeaf("acc")}),
     "high": DecisionFork("persons",
                         {"2": DecisionLeaf("acc"), 
                          "4":   DecisionLeaf("good"), 
                          "more": DecisionLeaf("vgood")})
     })

#theTree.display()

# the DecisionFork constructor gets as a first element the attribut (e.g. the string from the perception) that causes the branching.
# The second element of the DecisionFork constructor is a dictionary that takes the different values (whatever type) in the 
# example above it is a string "ok", "low" or "high". There is no restriction on data type, so it could be also a number. 
# the entry that forms the value for the attribute-value-key is then again a DecisionFolk if the tree is branching further down
# or a DecisionLeaf if there is a result of the classification (action).


