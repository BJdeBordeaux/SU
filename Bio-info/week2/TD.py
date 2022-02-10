

startCodons = ('ATG')
stopCodons = ('TAA', 'TAG', 'TGA')

def afficheORF(sequence, startCodons, stopCodons):
    import re
    grp = [
        match.group()[:-3] for match in re.finditer(
            '((ATG)((?!TAA|TAG|TGA)([ACTG][ACTG][ACTG]))*(TAA|TAG|TGA))',
            sequence.upper())
    ]
    res = max(grp, key=len, default='')
    print(res.lower())

# afficheORF('atgtaccgtcgatcgtagcttgatcgatcg', startCodons, stopCodons)

background = {'A' : 0.26, 'C' : 0.24, 'G' : 0.23, 'T' : 0.27}

def probBack(sequence, background):
    res = 1.
    for nuc in sequence.upper():
        res *= background[nuc]
    print(round(res, 5))

print(probBack('acggt', background))

def countCodons(sequence, listCodons):
    li = []
    for codon in listCodons:
        li.append(sequence.lower().count(codon.lower()))
    print("(", end='')
    for i in range(len(li)-1):
        print(str(li[i])+", ", end = '')
    print(str(li[-1]) + ")")

countCodons('atgtaccgtcgatcgtagcttgatcgatcg', ('atg','ccg','gat'))

background = {'AAC' : 0.0026, 'ACG' : 0.0024, 'CGT' : 0.023, 'CAT' : 0.0027}

def probBack(sequence, background):
    res = 1.
    for i in range(len(sequence)-2):
        res *= background[sequence[i:i+3].upper()]
    strtmp = "{:.4e}".format(res)
    if strtmp[-2] == "0":
        res = strtmp[:-2] + strtmp[-1]
    print(res)

probBack('aacgt', background)
