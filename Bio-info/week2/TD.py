from ast import Try
from gettext import find


seq = 'atgtaccgtcgatcgtagcttgatcgatcg'

startCodons = ('ATG')
stopCodons = ('TAA', 'TAG', 'TGA')

def validLen(start, end):
	if (end-start+1)//3 == 0:
		return True
	return False

def scan3(sequence, pos):
	return sequence[pos:pos+3]

def compare3(str1, str2):
	return str1.lower() == str2.lower()

def scanSequenceBase(sequence, startCodons, stopCodons):
	start = end = -1
	pos = 0
	try:
		for index in range(len(sequence)//3):
			pos = 3*index
			if start == -1:
				for startCodon in startCodons:
					if compare3(scan3(sequence, pos).lower(), startCodon) :
						start = pos
			if end == -1:
				
	start = sequence.find(startCodons)
	for stopCodon in stopCodons:
		endTmp = sequence.find(stopCodon)
		if validLen(start, endTmp):
			

		ends.append()

	for i in range(len(sequence[start+3:])):
	return (start, end)
