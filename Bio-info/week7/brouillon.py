def profile(motifs, k, nuc):
    """
    Construire une matrice de fréquence de dimension k x |nuc|
    entrée motifs: liste de motifs
    entrée k: taille du motif
    entrée nuc: alphabet
    sortie MF: matrice de fréquence
    """
    nDict = {nuc[i]: i for i in range(len(nuc))}
    q = len(nuc)
    mf = np.ones((q, k))
    for col in range(k):
        for line in range(len(motifs)):
            # try:
            nucleotide = motifs[line][col]
            # except IndexError:
            # print(line, col, motifs)
            mf[nDict[nucleotide]][col] += 1
    return mf


def getScore(MF, k):
    """
    Renvoie le score de MF, la somme des max de chaque colonne
    entrée P: matrice de fréquence
    entrée k: taille du motif
    sortie sc: score
    """
    mf = np.mat(MF)
    maxArray = np.max(mf, axis=0)
    return np.sum(maxArray)


def printTopMotifsScore(motif_match, top):
    """
    Affiche les Top Motifs ayant les meiux scores 
    entrée1 motif_match: dictionnaire clé=sequence consensus des motifs; value= list de motifs
    entrée top: la valeur à consider pour l'affichage
    sortie None
    """

    motif_match_score = {}

    for (key, value) in motif_match.items():
        value = [motif for motif, freq in value]
        k = len(value[0])
        pwn = profile(value, len(value[0]), nuc)
        motif_match_score[key] = getScore(pwn, k)

    motif_match_score_dict = {
        k: motif_match_score[k]
        for k in sorted(
            motif_match_score, key=motif_match_score.get, reverse=True)
    }
    print(sorted(motif_match_score_dict, key=motif_match_score.get, reverse=True)[:top])

top = 50
