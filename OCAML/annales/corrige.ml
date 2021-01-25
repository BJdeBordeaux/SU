(* == Exo 1 *)

(* = Q1 *)
let f1 x =
  let rec g x y =
    if (x < 0) then y
    else x + (g (x-1) y)
  in
    (g x 0)
      (* n'est pas récursive terminale *)

(* = Q2 *)
let f2 x =
  let rec g x y =
    if (x < 0) then y
    else (g (x-1) (x+y))
  in
    (g x 0)
      (* est récursive terminale *)

(* == Exo 2 *)

(* = Q1 *)
let rec u (n:int) : int =
  if (n = 0) then 5
  else (n*n) + (u (n-1))

(* - ou *)
let rec u (n:int) : int =
  if (n > 0) then (n*n) + (u (n-1))
  else 5

(* = Q2 *)
let u (n:int) : int =
  let rec loop n =
    if (n=0) then 5
    else (n*n) + (loop (n-1))
  in
    if (n < 0) then raise (Invalid_argument "u")
    else (loop n)

(* = Q3 *)
let u (n:int) : int =
  let rec loop n r =
    if (n=0) then r
    else (loop (n-1) ((n*n) + r))
  in
    if (n < 0) then raise (Invalid_argument "u")
    else (loop n 5)

(* == Exo 3 *)

let eq_list xs ys =
  (List.length xs) = (List.length ys)
  && (List.for_all (fun y -> List.mem y xs) ys)
  && (List.for_all (fun x -> List.mem x ys) xs)
  
(* = Q1 *)
(* - version non terminale *)
let rec add_item (x:'a) (xs:'a list) =
  match xs with
      [] -> [x]
    | x1::xs' ->
	if (x=x1) then x1::xs' (* ou xs *)
	else x1::(add_item x xs')

let _ = assert (eq_list (add_item 0 []) [0])
let _ = assert (eq_list (add_item 0 [1]) [0;1])
let _ = assert ((add_item 0 [0]) = [0])

(* - version terminale *)
let add_item (x:'a) (xs:'a list) =
  let rec loop xs r =
    match xs with
	[] -> x::r
      | x1::xs' ->
	  if (x=x1) then (List.rev_append xs r)
	  else (loop xs' (x1::r))
  in
    (loop xs [])

let _ = assert (eq_list (add_item 0 []) [0])
let _ = assert (eq_list (add_item 0 [1]) [0;1])
let _ = assert (eq_list (add_item 0 [0])  [0])
let _ = assert (eq_list (add_item 0 [1;2]) [0;1;2])
let _ = assert (eq_list (add_item 2 [1;2]) [1;2])
let _ = assert (eq_list (add_item 2 [1;2;3]) [1;2;3])
let _ = assert (eq_list (add_item 2 [1;3]) [1;2;3])

(* - Utilisation de List.mem *)
let add_item (x:'a) (xs:'a list) =
  if (List.mem x xs) then xs
  else x::xs

let _ = assert (eq_list (add_item 0 []) [0])
let _ = assert (eq_list (add_item 0 [1]) [0;1])
let _ = assert (eq_list (add_item 0 [0]) [0])

(* = Q2 *)
(* - Naturellement terminale *)
let rec add_list (xs:'a list) (ys:'a list) : 'a list =
  match xs with
      [] -> ys
    | x::xs -> (add_list xs (add_item x ys))

let _ = assert (eq_list (add_list [] [1;2;3]) [1;2;3])
let _ = assert (eq_list (add_list [1;2;3] [])  [1;2;3])
let _ = assert (eq_list (add_list [1;2] [1;2;3]) [1;2;3])
let _ = assert (eq_list (add_list [1;2] [1;3])  [1;2;3])
let _ = assert (eq_list (add_list [1;2] [3;4;5]) [1;2;3;4;5])

(* - Avec itérateur *)
let add_list (xs:'a list) (ys:'a list) : 'a list =
  List.fold_left (fun zs z -> add_item z zs) ys xs
	
let _ = assert (eq_list (add_list [] [1;2;3]) [1;2;3])
let _ = assert (eq_list (add_list [1;2;3] [])  [1;2;3])
let _ = assert (eq_list (add_list [1;2] [1;2;3]) [1;2;3])
let _ = assert (eq_list (add_list [1;2] [1;3])  [1;2;3])
let _ = assert (eq_list (add_list [1;2] [3;4;5]) [1;2;3;4;5])

(* = Q3 *)
(* - de base *)
let rec add_list_list (xss:('a list) list) : 'a list =
  match xss with
      [] -> []
    | xs::xss -> add_list xs (add_list_list xss)

let _ = assert (eq_list (add_list_list []) [])
let _ = assert (eq_list (add_list_list [[1;2;3]])  [1;2;3])
let _ = assert (eq_list (add_list_list [[1;2;3];[4;5]]) [1;2;3;4;5])
let _ = assert (eq_list (add_list_list [[1;2;3]; [4;3]]) [1;2;3;4])

(* - terminale *)
let add_list_list (xss:('a list) list) : 'a list =
  let rec loop xss r =
    match xss with
	[] -> r
      | xs::xss -> (loop xss (add_list xs r))
  in
    (loop xss [])
  
let _ = assert (eq_list (add_list_list []) [])
let _ = assert (eq_list (add_list_list [[1;2;3]])  [1;2;3])
let _ = assert (eq_list (add_list_list [[1;2;3];[4;5]]) [1;2;3;4;5])
let _ = assert (eq_list (add_list_list [[1;2;3]; [4;3]]) [1;2;3;4])

(* - avec itérateur non terminale *)
let add_list_list (xss:('a list) list) : 'a list =
  List.fold_right add_list xss []
    
let _ = assert (eq_list (add_list_list []) [])
let _ = assert (eq_list (add_list_list [[1;2;3]]) [1;2;3])
let _ = assert (eq_list (add_list_list [[1;2;3];[4;5]]) [1;2;3;4;5])
let _ = assert (eq_list (add_list_list [[1;2;3]; [4;3]]) [1;2;3;4])

(* - avec itérateur terminal *)
let add_list_list (xss:('a list) list) : 'a list =
  List.fold_left (fun zs xs -> (add_list zs xs)) [] xss
  
let _ = assert (eq_list (add_list_list []) [])
let _ = assert (eq_list (add_list_list [[1;2;3]])  [1;2;3])
let _ = assert (eq_list (add_list_list [[1;2;3];[4;5]]) [1;2;3;4;5])
let _ = assert (eq_list (add_list_list [[1;2;3]; [4;3]])  [1;2;3;4])

(* == Exo 4 *)
type cat = (string * float) list
    
let tarifs1 =
  [("lait", 2.35);
   ("beurre", 5.30);
   ("cornichons", 3.80);
   ("concombre", 7.21);
   ("raviolis", 5.75);
   ("poisson", 17.4);
   ("carottes", 4.95)]

let eq_eps (x:float) (y:float) : bool =
  (abs_float (x -. y)) < 0.00000000001

(* = Q1 *)
(* - de base  *)
let rec prix_list (xs:string list) (tarifs: cat) : float =
  match xs with
      [] -> 0.0
    | x::xs ->
	(List.assoc x tarifs) +. (prix_list xs tarifs)

let _ = assert ((prix_list [] tarifs1) = 0.0)
let _ = assert (eq_eps (prix_list ["beurre"; "poisson"] tarifs1) 22.7)

(* - terminale (non demandé) *)
let prix_list (xs:string list) (tarifs: cat) : float =
  let rec loop xs r =
    match xs with
	[] -> r
      | x::xs' -> (loop xs' ((List.assoc x tarifs) +. r))
  in
    (loop xs 0.0)

let _ = assert ((prix_list [] tarifs1) = 0.0)
let _ = assert (eq_eps (prix_list ["beurre"; "poisson"] tarifs1) 22.7)
let _ = assert (eq_eps (prix_list ["lait"; "beurre"; "poisson"] tarifs1) 25.05)

(* - itérateur et terminale (non demandé) *)
let prix_list (xs:string list) (tarifs: cat) : float =
  List.fold_left (fun r x -> (List.assoc x tarifs) +. r) 0.0 xs
    
let _ = assert ((prix_list [] tarifs1) = 0.0)
let _ = assert (eq_eps (prix_list ["beurre"; "poisson"] tarifs1) 22.7)
let _ = assert (eq_eps (prix_list ["lait"; "beurre"; "poisson"] tarifs1) 25.05)

let tarifs2 =
  [("lait", 2.55);
   ("beurre", 5.30);
   ("cornichons", 3.80);
   ("concombre", 7.21);
   ("raviolis", 5.45);
   ("poisson", 18.4);
   ("carottes", 4.95)]

(* = Q2 *)
(* - sans min, non terminale (non demandé) *)
let rec min_prix_list (xs:string list) (tarifs1: cat) (tarifs2: cat) : float =
  match xs with
      [] -> 0.0
    | x::xs ->
	let prix1 = List.assoc x tarifs1 in
	let prix2 = List.assoc x tarifs2 in
	  if (prix1 < prix2) then 
	    prix1 +. (min_prix_list xs tarifs1 tarifs2)
	  else
	    prix2 +. (min_prix_list xs tarifs1 tarifs2)

	    let _ = assert ((min_prix_list [] tarifs1 tarifs2) = 0.0)
let _ = assert (eq_eps (min_prix_list ["beurre"; "poisson"] tarifs1 tarifs2) 22.7)
let _ = assert (eq_eps (min_prix_list ["lait"; "beurre"; "poisson"] tarifs1 tarifs2) 25.05)

(* - avec min, non terminale (demandé) *)
let rec min_prix_list (xs:string list) (tarifs1: cat) (tarifs2: cat) : float =
  match xs with
      [] -> 0.0
    | x::xs ->
	(min (List.assoc x tarifs1) (List.assoc x tarifs2))
	+. (min_prix_list xs tarifs1 tarifs2)

let _ = assert ((min_prix_list [] tarifs1 tarifs2) = 0.0)
let _ = assert (eq_eps (min_prix_list ["beurre"; "poisson"] tarifs1 tarifs2) 22.7)
let _ = assert (eq_eps (min_prix_list ["lait"; "beurre"; "poisson"] tarifs1 tarifs2) 25.05)

(* - avec min, terminale (non demandé) *)
let min_prix_list (xs:string list) (tarifs1: cat) (tarifs2: cat) : float =
  let rec loop xs r =
    match xs with
	[] -> r
      | x::xs' ->
	  (loop xs' ((min (List.assoc x tarifs1) (List.assoc x tarifs2)) +. r))
  in
    (loop xs 0.0)
	    
let _ = assert ((min_prix_list [] tarifs1 tarifs2) = 0.0)
let _ = assert (eq_eps (min_prix_list ["beurre"; "poisson"] tarifs1 tarifs2) 22.7)
let _ = assert (eq_eps (min_prix_list ["lait"; "beurre"; "poisson"] tarifs1 tarifs2) 25.05)

(* - itérateur, terminale (non demandé) *)
let min_prix_list (xs:string list) (tarifs1: cat) (tarifs2: cat) : float =
  List.fold_left
    (fun r x -> (min (List.assoc x tarifs1) (List.assoc x tarifs2)) +. r)
    0.0
    xs

let _ = assert ((min_prix_list [] tarifs1 tarifs2) = 0.0)
let _ = assert (eq_eps (min_prix_list ["beurre"; "poisson"] tarifs1 tarifs2) 22.7)
let _ = assert (eq_eps (min_prix_list ["lait"; "beurre"; "poisson"] tarifs1 tarifs2) 25.05)

(* = Q3 *)
(* - non terminale *)
let rec split_list (xs:string list) (tarifs1: cat) (tarifs2: cat) : (string list * string list) =
  match xs with
      [] -> ([],[])
    | x::xs' -> (
	let r = split_list xs' tarifs1 tarifs2 in
	  match r with
	      (xs1, xs2) ->
		if (List.assoc x tarifs1) < (List.assoc x tarifs2) then
		  (x::xs1, xs2)
		else
		  (xs1, x::xs2)
      )

let _ = assert ((split_list [] tarifs1 tarifs2) = ([],[]))
let _ = assert ((split_list ["lait";"poisson";"raviolis"] tarifs1 tarifs2) = (["lait";"poisson"],["raviolis"]))

(* - terminale (demandé) *)
let split_list (xs:string list) (tarifs1: cat) (tarifs2: cat) : (string list * string list) =	  
  let rec loop xs xs1 xs2 =
    match xs with
	[] -> (xs1, xs2)
      | x::xs ->
	  if (List.assoc x tarifs1) < (List.assoc x tarifs2) then
	    (loop xs (x::xs1) xs2)
	  else
	    (loop xs xs1 (x::xs2))
  in
    (loop xs [] [])

let _ = assert ((split_list [] tarifs1 tarifs2) = ([],[]))
let _ = assert ((split_list ["lait";"poisson";"raviolis"] tarifs1 tarifs2) = (["poisson";"lait"],["raviolis"]))

  (* - avec itérateur, terminale (non demandé) *)
let split_list (xs:string list) (tarifs1: cat) (tarifs2: cat) : (string list * string list) =
  let f (xs1,xs2) x =
    if (List.assoc x tarifs1) < (List.assoc x tarifs2) then
      ((x::xs1), xs2)
    else
      (xs1, (x::xs2))
  in
    List.fold_left f ([],[]) xs

let _ = assert ((split_list [] tarifs1 tarifs2) = ([],[]))
let _ = assert ((split_list ["lait";"poisson";"raviolis"] tarifs1 tarifs2) = (["poisson";"lait"],["raviolis"]))      


(* == Exo 5 *)

(* = Q1 *)
(* de base *)
let rec list_diff (xs:float list) (m:float) : float list =
    match xs with
	[] -> []
      | x::xs -> (x -. m)::(list_diff xs m)

let _ = assert ((list_diff [] 42.0) = [])
let _ = assert ((list_diff [7.5; 2.0; 3.5] 3.5) = [4.; -1.5; 0.0])

(* avec map *)
let list_diff (xs:float list) (m:float) : float list =
  List.map (fun x -> x -. m) xs
	  
let _ = assert ((list_diff [] 42.0) = [])
let _ = assert ((list_diff [7.5; 2.0; 3.5] 3.5) = [4.; -1.5; 0.0])

(* = Q2 *)
(* de base *)
let rec list_inter (xs:float list) (m1:float) (m2:float) : float list =
  match xs with
      [] -> []
    | x::xs ->
	if (m1 <= x) && (x <= m2) then x::(list_inter xs m1 m2)
	else (list_inter xs m1 m2)

let _ = assert ((list_inter [] 0.0 1.0) = [])
let _ = assert ((list_inter [1.5; 0.5; 2.0; 0.99; 0.01] 0.0 1.0) = [0.5;0.99;0.01])

(* avec filter *)
let list_inter (xs:float list) (m1:float) (m2:float) : float list =
  List.filter (fun x -> (m1 <= x) && (x <= m2)) xs

let _ = assert ((list_inter [] 0.0 1.0) = [])
let _ = assert ((list_inter [1.5; 0.5; 2.0; 0.99; 0.01] 0.0 1.0) = [0.5;0.99;0.01])
    
(* = Q3 *)
(* de base *)
let rec sum_square (xs : float list) : float =
  match xs with
      [] -> 0.0
    | x::xs -> (x *. x) +. (sum_square xs)

let _ = assert ((sum_square []) = 0.)
let _ = assert ((sum_square [5.;6.;7.]) = 25.+.36.+.49.)
	
(* ou *)
let rec sum_square (xs : float list) : float =
  match xs with
      [] -> 0.0
    | x::xs -> (x ** 2.) +. (sum_square xs)
	
let _ = assert ((sum_square []) = 0.)
let _ = assert ((sum_square [5.;6.;7.]) = 25.+.36.+.49.)
		
(* avec List.fold *)
let sum_square (xs : float list) : float =
  List.fold_right (fun x r -> (x ** 2.) +. r) xs 0.0

let _ = assert ((sum_square []) = 0.)
let _ = assert ((sum_square [5.;6.;7.]) = 25.+.36.+.49.)
	
(* ou *)
let sum_square (xs : float list) : float =
  List.fold_left (fun r x -> (x ** 2.) +. r) 0.0 xs
    
let _ = assert ((sum_square []) = 0.)
let _ = assert ((sum_square [5.;6.;7.]) = 25.+.36.+.49.)
	