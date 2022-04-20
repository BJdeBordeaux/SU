from matplotlib.pyplot import text


def goodSuffix(motif):
    '''
    Construire la goodSuffix table d'un motif
    entrée motif : le motif à chercher
    sortie goodSuffixTable: un dictionnaire ou la clé est les suffixes d'un motif et la valeur le nombre de positions à décaler pour avoir un match
    '''
    goodSuffixTable = dict()
    l = len(motif)
    for i in range(1, l):
        last_index = l - 1
        index_suffix_fix = l - i
        motif_to_add = motif[index_suffix_fix:]
        findArea = motif[:index_suffix_fix]
        index_suffix = l - i
        if len({char for char in motif_to_add}) == 1:
            goodSuffixTable[motif_to_add] = 1
        while index_suffix <= last_index:
            toFind = motif[index_suffix:]
            index_match = findArea.rfind(toFind)
            if index_match == -1:
                index_suffix += 1
                continue
            else:
                goodSuffixTable[motif_to_add] = index_suffix - index_match
                break
        if index_match == -1:
            goodSuffixTable[motif_to_add] = l
    return goodSuffixTable


def badCharacter(motif):
    '''
    Construire la badTable d'un motif
    entrée motif : le motif à chercher
    sortie badMatchTable: un dictionnaire ou la clé est un nucléotide du motif et la valeur le nombre de positions à décaler pour avoir un match
    '''
    l = len(motif)
    return {motif[i]: max(1, l - 1 - i) for i in range(l)}

# motif ="GTAGCGGCG"
# text = "GTTATAGCTGATCGCGGCGTAGCGGCGAA"

text = "CGTGCCTACTTACTTACTTACTTACGCGAA"
motif ="CTTACTTAC"

# motif ="GTTGTTAA"

gs = goodSuffix(motif)
bc = badCharacter(motif)

print(gs, bc)