let rec fact (n: int) : (int) = 
	if (n>0) 
		then n* (fact (n-1))
		else 1


let rec pow (x:float) (n:int) : float = 
	if (n>0) 
		then x*.(pow x (n-1)) 
		else 1.