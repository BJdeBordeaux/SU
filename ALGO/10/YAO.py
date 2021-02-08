1.
sommets-sommets
[0 0 0 0 0 0]
[0 0 0 1 1 0]
[0 1 0 0 1 0]
[1 0 0 0 0 0]
[0 0 0 1 0 1]

matrice sommets-arcs
ordre: (4, 1), (2, 4), (3, 2), (3, 5), (2, 5), (5, 6), (6, 5), (5, 4)
[-1  0  0  0  0  0  0  0]
[ 0  1 -1  0  1  0  0  0]
[ 0  0  1  1  0  0  0  0]
[ 1 -1  0  0  0  0  0 -1]
[ 0  0  0 -1 -1  1 -1  1]
[ 0  0  0  0  0 -1  1  0]

liste d’adjacence
L[1] = []
L[2] = [4,5]
L[3] = [2,5]
L[4] = [1]
L[5] = [4,6]
L[6] = [5]

2.

def max(T):
    if estVide(T.droit):
        return T.noeud
    else:
        return max(T.droit)

def suppMax(T):
    if estVide(T.droit):
        if estVide(T.gauche):
            T = None
        else:
            T = T.gauche
    else:
        suppMax(T.droit)