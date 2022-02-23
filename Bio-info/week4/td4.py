motifs = ['ATG', 'TGT', 'CCC', 'GGA']
sequence = 'AATGTCGGACGGA'

import re
def chercheMotif(sequence, motifs):
    res = dict()
    for motif in motifs:
        key = motif
        value = [match.start() for match in re.finditer(motif.lower(), sequence.lower())]
        if len(value)==0:
            value = [-1]
        res[key] = value
    return res


nucIndex = {'A':0, 'C':1, 'G':2, 'T':3 }

matrix = [[0, 0, 1, 0], [0, 0, 0, 1], [1, 0, 0, 0], [0, 1, 0, 0]]

# def calculeScore(matrix, seq1, seq2):
def calculeScore(seq1, seq2):
    assert(len(seq1) == len(seq2))
    return sum([matrix[nucIndex[seq1[i]]][nucIndex[seq2[i]]] for i in range(len(seq1))])

def hamming(u, v):
    return sum([0 if u[i] == v[i] else 1 for i in range(len(u))])