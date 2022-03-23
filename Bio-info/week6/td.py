T = 'abcd'

L = ['abcd$', 'bcd$', 'cd$', 'd$', '$']


def suffixes(T: str):
    return [T[i:]+"$" for i in range(len(T)+1)]

# print(suffixes(T))


L = ['abcd$', 'bcd$', 'cd$', 'd$', '$']

R = [(0,4), (1,3), (2,2), (3,1)]

L2 = ['cd$', 'bcd$']
R2 = [(2,2), (1,3)]

def suffixes2(T: str, L):
    T2 = T+'$'
    return [(T2.find(L[i]), len(L[i])-1) for i in range(len(L)) if len(L[i])-1 != 0]
    
print(suffixes2(T, L))
print(suffixes2(T, L2))