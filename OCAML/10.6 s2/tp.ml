(*tp semaine 3*)
(*EX4*)
let less_divider (i: int) (n: int) : int = 
	let rec loop (a: int) (n: int) = 
		if(n mod a = 0) then a
		else loop (a+1) n
	in if ((i<2) || (n<2)) then raise(Invalid_argument "i or n can not be greater than 2 from less_divider")
	else loop i n

let prime (n: int) = 
	if ((less_divider 2 n) = n) then true
	else false

let prime_next (n: int) = 
	let rec loop (a: int) = 
		if(prime a = true) then a
		else loop (a+1)
	in loop n

let nth_prime (n: int) : int = 
	let rec loop (a: int) (p: int) = 
		if (a = 0) then p
		else loop (a-1) (prime_next (p+1))
	in loop n 2


(*EX5*)

let f a x = 
	(x+.(a/.x))/.2