#question 1
infectDict = {"A" : 3, "C" : 4, "G" : 4, "T" : 3}

def bactInfect(u, v) :
	ui = vi = 0
	while vi < len(v):
		nucleotide = v[vi]
		repeat = infectDict[nucleotide]
		if u[ui:ui+repeat] == repeat*nucleotide:
			print(True)
			return
		elif u[ui] == nucleotide:
			ui += 1
		else:
			print(u[ui:] + ", " + v[vi:] + "; u,v =" + str(ui) + "," + str(vi))
			raise Exception("Unexpected nucleotide")
		vi += 1
	print(False)
	return

def bactInfect2(u, v):
	ui = vi = 0
	while vi < len(v):
		nucleotide = v[vi]
		repeat = infectDict[nucleotide]
		if u[ui:ui+repeat] == repeat*nucleotide:
			return True
		elif u[ui] == nucleotide:
			ui += 1
		else:
			print(u[ui:] + ", " + v[vi:] + "; u,v =" + str(ui) + "," + str(vi))
			raise Exception("Unexpected nucleotide")
		vi += 1
	return False

#question 2
import random
P={'A':0.2,'C': 0.5,'G': 0.3,'T': 0.1}

def genereBactInfect(u, P):
	virus = ""
	for i in range(len(u)):
		nucleotideOrig = u[i]
		nucleotideNouv = infectDict[nucleotideOrig]*nucleotideOrig if random.uniform(0, 1) < P[nucleotideOrig] else nucleotideOrig
		virus += nucleotideNouv
	return virus