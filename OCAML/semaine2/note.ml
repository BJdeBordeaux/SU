let (x:int) = 3
let f (n:int) : int = n + x
let _ = (f x)

let aire_triangle (a:float) (b:float) (c:float) : float = 
	let s = (a+.b+.c)/.2. in 
	sqrt(s*.(s-.a)*.(s-.b)*.(s-.c)) 

(* recursive function * remenber to use "let rec "**)
let rec pow (x:float) (n:int) : float = 
	if (n>0) 
		then x*.(pow x (n-1)) 
		else 1.

(* this is a different function *)
let rec pow2 (x:float) (n:int) : float = 
	if (n<0) then raise (Invalid_argument "pow2")
	else if (n = 0) then 1. 
	else x*.(pow2 x (n-1)) 

let pow3 (x:float) (n:int) : float = 
	let rec loop (x:float) (n:int) : float = 
		(* if (n<0) then 1. else 1. *)
		if(n < 0) then 1. 
		else x*.(loop x (n-1))
	in 
	(* look first at "in" section, if sth missed, turn to "let" *)
		if(n < 0) then raise (Invalid_argument "pow3")
		else x*.(loop x (n-1)) 
