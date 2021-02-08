def estABvide(ab):
    return (ab==[])

def listePlusPetits(T, x): 
    if estABvide(T):
        return []
    if x <= T.clef:
        return listePlusPetits(T.gauche, x)
    return ABinfixe(T.gauche) + [T.clef] + listePlusPetits(T.droit, x)

def ABinfixe(T): 
    if estABvide(T):
        return [] 
    else:
        return ABinfixe(T.gauche) + [T.clef] + ABinfixe(T.droit)

def estCroissante(L):
    if len(L) == 0 or len(L) == 1:
        return True
    return (L[0] < L[1]) and estCroissante(L[1:])


def estABR1(T):
    return estCroissante(ABinfixe(T))

#print(ABinfixe([5,[1,[],[3,[],[4]]],[7,[6],[8]]]))

print([1]+[2]+[3])


1: ABinfixe(T.gauche) + [5] + ABinfixe(T.droit)
2: ABinfixe(T.gauche.gauche) + [1] + ABinfixe(T.gauche.droit) + [5] + ABinfixe(T.droit.gauche) + [7] + ABinfixe(T.droit.droit)
3: [] + [1] + ABinfixe(T.gauche.droit.gauche) + [3] + ABinfixe(T.gauche.droit.droit) + [5] + [6] + [7] + [8]
4: [] + [1] + [] + [3] + [4] + [5] + [6] +[7] + [8] = [1,3,4,5,6,7,8]


Montrer que listePlusPetits(T, x) se termine et retourne la liste des clés de T qui sont inférieures à x, rangée en ordre croissant.

Notons P(T) la propriété : pour tout x, listePlusPetits(T, x) se termine et retourne la liste des clés de T qui sont inférieures à x, rangée en ordre croissant.

Montrons P(T) par induction.

Base 
P(∅) est vérifiée : 
terminaison immédiate et renvoi de l’arbre réduit à la feuille x. 

Induction 
Soit T = (c, G, D) un ABR, supposons que P(G) et P(D) soient vraies.
— Si x = c alors listePlusPetits(T,x) se termine immédiatement et retourne T qui est un ABR dont les clés sont x et les clés de T, puisque x est une clé de T.
— Si x<c alors listePlusPetits(T,x) fait un appel à listePlusPetits(G,x) qui, par hypothèse, se termine et retourne un ABR G' dont les clés sont x et les clés de G. Par conséquent listePlusPetits(T,x) se termine et retourne un arbre binaire T′ = (c,G′,D), qui est un ABR et dont les clés sont x et les clés de T .
— Le cas x > c est analogue au précédent.
Conclusion La propriété P(T) est vérifiée pour tout ABR T.