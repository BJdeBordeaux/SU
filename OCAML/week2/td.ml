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

let sum_u2 n =
  let rec go n a b =
    if n = 0 then  (a + b)
    else go (n - 1) (3 * a + 4) (a + b)
  in
  if n < 0 then
    raise (Invalid_argument "Argument can't be negative")
  else
    go n 42 0

let rec sum_inter (a: int) (b: int) : int = 
	let rec loop (n: int) (m: int) = 
		if (n > a) then (loop (n-1) (m+n))
		else (m + n)
	in 	if (a > b) then raise(Invalid_argument "a can not be greater than b from sum_inter")
		else loop b 0

let _ = assert(sum_inter 4 6 = 15)
let _ = assert(sum_inter 0 3 = 6)
let _ = assert(sum_inter (-5) 5 = 0)
let _ = assert(sum_inter (-5) 0 = -15)

let rec sum1_inter (k: int) (a :int) (b: int) : int = 
	let rec loop (n: int) (m: int) = 
		if (n > a) then loop (n-1) (k+n+m)
		else k+n+m
	in if(a > b) then raise(Invalid_argument "a can not be greater then b sum1_inter")
	else loop b 0

let sum2_inter (a: int) (b: int) = 
  let rec loop (n: int) (m:int) = 
    if (n<=b) then loop (n+1) ((sum1_inter n a b) + m)
    else  m
  in if(a>b) then 0
  else loop a 0

let _ = assert(sum2_inter 0 2 = 12)
let _ = assert(sum2_inter (-2) 1 = -10)
let _ = assert(sum2_inter 2 2 = 4)