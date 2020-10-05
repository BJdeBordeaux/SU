let fst (a:'a*'b) = 
	let (c,d) = a in
	c

let pair a b = (a,b)

let curry (f:'a*'b->'c) : 'a->'b->'c = 
	let g a b = f (a,b) in
	g

let uncurry (g:('a->'b->'c)) :  (('a*'b)->'c) = 
	let f (a,b) = (g a b) in
	f