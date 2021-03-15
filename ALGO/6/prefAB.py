def operandesPref(L):
	cpt_operateurs = 0
	cpt_valeurs = 0
	i = 1
	while cpt_operateurs >= cpt_valeurs:
		if estOperateur(L[i]):
			cpt_operateurs = cpt_operateurs + 1
		else:
			cpt_valeurs = cpt_valeurs + 1
		i = i + 1
		print((L[1:i], L[i:]), i)
	return (L[1:i], L[i:])

def estOperateur(a):
	return a in ["*","-","+","/"]

def prefVersAB(L):
	x = L[0]
	if estNombre(x):
		return ABfeuille(x)
	(L1, L2) = operandesPref(L)
	return AB(x, prefVersAB(L1), prefVersAB(L2))

L0 = ["*","-",5,3,"+",7,"/",8,4]