(* == Exo I : listes *)

(* -- Q1 *)
let rec xrang (x:'a) (xs:'a list) : int =
  match xs with
      [] -> raise Not_found
    | y::xs -> if (x=y) then 0 else 1+(xrang x xs)

(* -- Q2 *)
let xrang_t (x:'a) (xs:'a list) : int =
  let rec loop xs r =
    match xs with
	[] -> raise Not_found
      | y::xs -> if (x=y) then r else (loop xs (r+1))
  in
    (loop xs 0)

(* -- Q3 *)
let rang (x:'a) (xs:'a list) : int =
  try xrang x xs with Not_found -> max_int

(* -- Q4 *)
let add (n:int) (m:int) : int =
  if ((n=max_int) || (m=max_int)) then max_int
  else (n+m)

(* -- Q5 *)
let rec sum_rangs (x:'a) (xss: 'a list list) : int =
  match xss with
      [] -> 0
    | xs::xss -> (add (rang x xs) (sum_rangs x xss))

(* -- Q6 *)
let sum_rangs (x:'a) (xss: 'a list list) : int =
  List.fold_left (fun r xs -> r+(rang x xs)) 0 xss    
    
(* -- Q7 *)
let rec list_sum_rangs (xs:'a list) (xss:'a list list) : ('a*int) list =
  match xs with
      [] -> []
    | x::xs -> (x,(sum_rangs x xss))::(list_sum_rangs xs xss)

(* -- Q8 *)
let list_sum_rangs (xs:'a list) (xss:'a list list) : ('a*int) list =
  List.map (fun x -> (x, sum_rangs x xss)) xs

(* -- Q9 *)
let min_rang (xr1:('a*int)) (xr2:('a*int)) : ('a*int) =
  match xr1, xr2 with
      (x1,r1), (x2,r2) -> if (r1<r2) then xr1 else xr2

(* -- Q10 *)
let rec min_of_list_rangs (xrs:('a*int) list) : ('a*int) =
  match xrs with
      [] -> raise Not_found
    | [xr] -> xr
    | xr::xrs -> min_rang xr (min_of_list_rangs xrs)

(* réc. term. *)
let min_of_list_rangs (xrs:('a*int) list) : ('a*int) =
  let rec loop xrs xr =
    match xrs with
	[] -> xr
      | xr'::xrs -> loop xrs (min_rang xr xr')
  in
    match xrs with
	[] -> raise Not_found
      | xr::xrs -> (loop xrs xr)

(* et aussi *)
let rec min_of_list_rang (xrs:('a*int) list) : ('a*int) =
  match xrs with
      [] -> raise Not_found
    | [xr] -> xr
    | xr1::xr2::xrs -> min_of_list_rang ((min_rang xr1 xr2)::xrs)
	  
(* == Exo II : arbres binaires *)
type 'a btree =
    Empty
  | Node of 'a * 'a btree * 'a btree
type mark = Oui | Non
type bin = O | I
    
(* -- Q1 *)
let rec btree_of_bin (m:bin list) : mark btree =
  match m with
      [] -> Node(Oui, Empty, Empty)
    | I::m -> Node(Non, btree_of_bin m, Empty)
    | O::m -> Node(Non, Empty, btree_of_bin m)

(* -- Q2 *)
let rec appartient (m:bin list) (bt:mark btree) : bool =
  match m, bt with
      _, Empty -> false
    | [], Node(x,_,_) -> (x=Oui)
    | I::m, Node(_,bt1,_) -> appartient m bt1
    | O::m, Node(_,_,bt2) -> appartient m bt2

(* ou, avec filtrage *)
let rec appartient (m:bin list) (bt:mark btree) : bool =
  match m, bt with
      _, Empty -> false
    | [], Node(Oui,_,_) -> true
    | [], Node(Non,_,_) -> false
    | I::m, Node(_,bt1,_) -> appartient m bt1
    | O::m, Node(_,_,bt2) -> appartient m bt2

(* -- Q3 *)
let rec ajout (m:bin list) (bt:mark btree) : mark btree = 
  match bt with
      Empty -> btree_of_bin m
    | Node(x,bt1,bt2) -> (
	match m with
	    [] -> Node(Oui, bt1, bt2)
	  | I::m -> Node(x, ajout m bt1, bt2)
	  | O::m -> Node(x, bt1, ajout m bt2)
      )

(* -- Q4 *)
let rec retrait (m:bin list) (bt:mark btree) : (mark btree) =
  match bt with
      Empty -> Empty
    | Node(Oui,bt1,bt2) -> (
	match m with
	    [] -> Node(Non, bt1, bt2)
	  | I::m -> Node(Oui, retrait m bt1, bt2)
	  | O::m -> Node(Oui, bt1, retrait m bt2)
      )
    | Node(Non,bt1,bt2) -> (
	match m with
	    [] -> Node(Non, bt1, bt2)
	  | I::m -> Node(Non, retrait m bt1, bt2)
	  | O::m -> Node(Non, bt1, retrait m bt2)
      )
let rec retrait (m:bin list) (bt:mark btree) : (mark btree) =
  match bt with
      Empty -> Empty
    | Node(x,bt1,bt2) -> (
	match m with
	    [] -> (
	      match x with
		  Oui -> Node(Non, bt1, bt2)
		| Non -> bt
	    )
	  | I::m -> Node(x, retrait m bt1, bt2)
	  | O::m -> Node(x, bt1, retrait m bt2)
      )
	
let rec retrait (m:bin list) (bt:mark btree) : (mark btree) =
  match bt, m with
      Empty, _ -> Empty
    | Node(Oui,bt1,bt2), [] -> Node(Non, bt1, bt2)
    | Node(_,_,_), [] -> bt
    | Node(x, bt1, bt2), I::m -> Node(x, retrait m bt1, bt2)
    | Node(x, bt1, bt2), O::m -> Node(x, bt1, retrait m bt2)
	
(* sol étu *)
let rec retrait (m:bin list) (bt:mark btree) : (mark btree) =
  match bt with
      Empty -> Empty
    | Node(x,bt1,bt2) -> (
	match m with
	    [] -> Node(Non,bt1,bt2)
	  | I::m -> Node(x, retrait m bt1, bt2)
	  | O::m -> Node(x, bt1, retrait m bt2)
      )
