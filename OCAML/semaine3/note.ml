let is_empty (xs : 'a list) : bool =
	match xs with
	| [] -> true
	| _ -> false

let pop (xs : int list) : (int list) = 
	match xs with
		xa :: xb :: xs -> (xa + xb) :: xs
	| _ -> xs

let rec somme (l : int list) : int = 
	match l with 
	[] -> 0
	| x :: xs  -> x + (somme xs)

let somme2 (l: int list) : int = 
	let rec loop (l: int list) (acc: int) : int = 
		match l with
		| [] -> acc
		| x :: xs -> loop xs (acc+x)
	in (loop l 0)

let rec app (la : 'a list) (lb: 'a list) : 'a list = 
	match la with 
	| [] -> lb
	| x :: xs -> x :: (app xs lb)

let app2 (la : 'a list) (lb: 'a list) : 'a list = 
	let rec loop (l : 'a list) (r: 'a list) : 'a list = 
		match l with 
		| [] -> r
		| x :: xs -> x :: (loop xs r)
	in loop la lb

let rec mem (a: 'a) (l: 'a list) : bool = 
	match l with 
	|[] -> false
	|x :: l2 -> (a=x) || mem a l2

let _ = assert(mem 5 [] = false)
let _ = assert(mem 5 [5] = true)
let _ = assert(mem 5 [1; 4; 5] = true)
let _ = assert(mem 5 [1; 4; 3] = false)

let nth (l: 'a list) (n: int) : 'a = 
	let rec loop (l: 'a list) (n: int) = 
		match l with 
		|[] -> raise(Failure "nth")
		|x :: ls -> if(n=0)then x else loop ls (n-1)
	in if(n<0)then raise(Invalid_argument "n can not be less than 0")
	else loop l n
	

let rec rev (l: 'a list) : 'a list = 
	match l with 
	| [] -> l
	| x :: xs -> (rev xs)@[x]