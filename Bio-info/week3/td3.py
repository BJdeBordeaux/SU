import numpy as np
#0.00126
#0.00054

freq = np.array([[1,7,1,1,1,1,1,2,3],[7,1,7,1,1,1,3,1,1],[1,1,1,7,1,6,5,6,3],[1,1,1,1,7,2,1,1,3]])
MPP = np.array([[0.1,0.7,0.1,0.1,0.1,0.1,0.1,0.2,0.3],[0.7,0.1,0.7,0.1,0.1,0.1,0.3,0.1,0.1],[0.1,0.1,0.1,0.7,0.1,0.6,0.5,0.6,0.3],[0.1,0.1,0.1,0.1,0.7,0.2,0.1,0.1,0.3]])

def matricePoidsPosition(freq, MPP):
    return((freq/(freq[:,0].sum()))==MPP).all()

#MPP2 = np.array([[0.08333333, 0.75, 0.08333333,0.08333333, 0.08333333, 0.08333333, 0.08333333, 0.16666667, 0.25],[0.75, 0.08333333,0.75,0.08333333,0.08333333,0.08333333,0.25,0.08333333,0.25],[0.08333333,0.08333333,0.08333333,0.75,0.08333333,0.5,0.41666667,0.5,0.25],[0.08333333,0.08333333,0.08333333,0.08333333,0.75,0.33333333,0.25,0.25,0.25]])
MPP = np.array([[0.1,0.7,0.1,0.1,0.1,0.1,0.1,0.2,0.3],[0.7,0.1,0.7,0.1,0.1,0.1,0.3,0.1,0.1],[0.1,0.1,0.1,0.7,0.1,0.6,0.5,0.6,0.3],[0.1,0.1,0.1,0.1,0.7,0.2,0.1,0.1,0.3]])

def nulModel(MPP):
    taille = len(MPP[0])
    return (list(np.round(list(map(lambda ligne:ligne.sum()/taille, MPP)), 2)))


# Question 3
def compare_intervalles(intervalle_1, intervalle_2):
    """Renvoi la matrice de confusion.
    entrée1 intervalle_1: Liste binaire representant un genome de reference
    entrée2 intervalle_2: Liste binaire representant un les predictions de genes
    sortie1 matrix: matrice de confusion
    >>> compare_intervalles([0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0],[0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0])
    [[7, 0], [4, 11]]
    """
    assert(len(intervalle_1) == len(intervalle_2))
    vn = fp = fn = vp = 0
    for i in range(len(intervalle_1)):
        annote = intervalle_1[i]
        predit = intervalle_2[i]
        vrai = annote == predit
        positif = predit == 1
        if vrai and positif:
            vp += 1
        elif vrai:
            vn += 1
        elif not vrai and positif:
            fp += 1
        else:
            fn += 1
    matrix = [[vn, fp], [fn, vp]]
    return matrix

intv1 = [0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, ]
intv2 = [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, ]
print(matricePoidsPosition(freq, MPP))
print(compare_intervalles(intv1, intv2))
print(nulModel(MPP))