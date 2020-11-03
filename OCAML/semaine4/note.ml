let rec map (f: 'a -> 'b) (xs: 'a list) : ('b list) = 
  match xs with
  |[] -> []
  |x::xss -> (f x) :: map f xss

let _ = assert(map (fun x -> x*x) [1; 2; 3] = [1; 4; 9])
let _ = assert(map (fun x -> x*x) [] = [])
let _ = assert(map (fun x -> 5::x) [[3]; []] = [[5; 3]; [5]])

let rec filtre (f: 'a -> bool) (l: 'a list) : ('a list) = 
  match l with 
  |[] -> []
  |x::ls -> if(f x)then x::(filtre f ls) 
    else filtre f ls

let _ = assert((filtre (fun x -> (x mod 2 = 1)) [1; 2; 3]) = [1; 3])
let _ = assert(filtre (fun x -> (x mod 3 = 0)) [] = [])

let rec fold_right (f: 'a->'b->'b) (l: 'a list) (b: 'b) : 'b = 
  match l with
  |[] -> b
  |x::ls -> f x (fold_right f ls b)

let somme (l: 'a list) : 'a = 
  match l with
  |[] -> 0
  |_ -> fold_right (fun x r -> x+r) l 0

let somme_carre (l: 'a list) : 'a = 
  match l with
  |[] -> 0
  |_ -> fold_right (fun x r -> x*x+r) l 0

let _ = assert(somme_carre [1; 2; 3] = 14)
let _ = assert(somme_carre [0] = 0)

let rec fold_left (f: 'a->'b->'a) (a: 'a) (l: 'b list) : 'a = 
  match l with
  |[] -> a
  |b::lb -> fold_left f (f a b) lb 

let somme_carre2 (l: 'a list) : 'a = 
  match l with
  |[] -> 0
  |_ -> fold_left (fun a b -> b*b+a) 0 l

let _ = assert(somme_carre2 [1; 2; 3] = 14)
let _ = assert(somme_carre2 [0] = 0)