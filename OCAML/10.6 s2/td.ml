let rec fact (n: int) : (int) = 
	if (n>0) 
		then n* (fact (n-1))
		else 1


let rec pow (x:float) (n:int) : float = 
	if (n>0) 
		then x*.(pow x (n-1)) 
		else 1.

let rec sum_ (n: int) : int = 
	if(n > 0) then n+(sum_ (n-1)) else 0

let sum_n (n: int) : int = 
	let rec loop (n:int) = 
		if(n>0) then n+(loop (n-1)) else 0
	in  if(n<0) then raise(Invalid_argument "sum_n") 
		else n+(loop (n-1))

let sum_p (n: int) : int = 
	let rec loop (n : int) : int = 
		if(n>0) then n + (loop (n-2)) else 0
	in  if(n<0 || (n mod 2=1)) then raise(Invalid_argument "sum_p")
		else n+(loop (n-2))

let sum_f (f: int->int) (n: int) : int =
	let rec loop (f: int->int) (n : int) : int = 
		if(n>0) then (f n) + (loop f (n-1)) else (f 0)
	in  if(n<0) then raise(Invalid_argument "sum_f")
		else (loop f n)

let rec u (n: int) : int = 
	let rec loop (n: int) = 
		if(n>0) then (3*(loop (n-1))+4) else 42
	in  if(n<0) then raise(Invalid_argument "n should be positive")
		else (loop n)

let u_n (n: int) : int = 
	sum_f u n

let sum_u (n: int) = 
	let rec loop n = 
		if(n>0) then (u n) + (loop (u (n-1)))
		else u_n 0
	in  if(n<0) then raise(Invalid_argument "Negative ???")
		else loop n