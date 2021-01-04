(* Exo I *)

(*

 u_0 = c
 u_{n+1} = (1+t)u_n - m

*)

let rec u (n:int) (c:float) (t:float) (m:float) : float =
  if (n <= 0) then c
  else ((1.0 +. t) *. (u (n-1) c t m)) -. m

(* Exo II *)

(* Q1 *)

(* -  Solution donnant le bon résultat mais effectuant deux parcours de listes *)
let nbtrue (bs:bool list) : int =
  List.length (List.filter (fun x -> x) bs)

(* - Solution standard *)
let rec nbtrue (bs:bool list) : int =
  match bs with
      [] -> 0
    | b::bs -> if b then 1+(nbtrue bs) else (nbtrue bs)

(* - variante avec l'alternative (non conseillée) *)
let rec nbtrue (bs:bool list) : int =
  match bs with
      [] -> 0
    | b::bs -> (if b then 1 else 0)+(nbtrue bs)

(* - variante avec filtrage *)
let rec nbtrue (bs:bool list) : int =
  match bs with
      [] -> 0
    | true::bs -> 1+(nbtrue bs)
    | _::bs -> (nbtrue bs)

(* - récurrence terminale *)
(* avec alternative *)
let nbtrue (bs:bool list) : int = 
  let rec loop (bs:bool list) (r:int) : int =
    match bs with 
	[] -> r
      | b::bs ->  
	  if b then (loop bs (1+r)) 
	  else (loop bs r)
  in
    (loop bs 0) 

(* avec filtrage *)
let nbtrue (bs:bool list) : int = 
  let rec loop (bs:bool list) (r:int) : int =
    match bs with 
	[] -> r 
      | true::bs -> (loop bs (1+r))
      | _::bs -> (loop bs r) 
  in
    (loop bs 0) 
      
(* - Itérateur *)
(* mise en évidence de la fonction itérée (beta expansion) *)
let rec nbtrue (bs:bool list) : int =
  match bs with
      [] -> 0
    | b::bs ->
	((fun s x -> if x then 1+s else s) (nbtrue bs) b)

(* la fonction avec itérateur *)
let nbtrue (bs:bool list) : int =
    List.fold_left (fun s x -> if x then 1+s else s) 0 bs;;


(* Q2 *)
(* Remarques sur l'égalité:
   <> (in)égalité structurelle
   != (in)égalité physique (égalité de localisation mémoire; égalité des pointeurs *)
(* définition incorrecte: semblera fonctionner sur des listes d'entiers,
   mais échoue sur des listes de listes *)
let rec sumb (xs: 'a list) (ys: 'a list) : bool list =
  match xs, ys with
      [], [] -> []
    | x::xs, y::ys -> (x != y) :: (sumb xs ys)
    | _ -> raise (Invalid_argument "sumb")

(* solution correcte *)
let rec sumb (xs: 'a list) (ys: 'a list) : bool list =
  match xs, ys with
      [], [] -> []
    | x::xs, y::ys -> (x != y) :: (sumb xs ys)
    | _ -> raise (Invalid_argument "sumb")
	
(* Q3 *)
let disth (xs:'a list) (ys:'a list) : int =
  (nbtrue (sumb xs ys))

(* Exo III *)

(* Q1 *)
(* solution standard *)
let rec list_le (x:'a) (xs:'a list) : 'a list =
  match xs with
      [] -> []
    | y::xs' -> if (y <= x) then y::(list_le x xs') else (list_le x xs')

(* - avec itérateur *)
let list_le (x:'a) (xs:'a list) : 'a list =
  List.filter (fun y -> y <= x) xs

(* - récurrence terminale: 
   l'ordre des valeurs dans le résultat n'a pas d'importance *)
let list_le (x:'a) (xs:'a list) : 'a list =
  let rec loop (xs:'a list) (r:'a list) : 'a list =
    match xs with
	[] -> r
      | y::xs' -> if (y <= x) then (loop xs' (y::r)) else (loop xs' r)
  in
    (loop xs [])

(* variante sur l'aternative *)
let list_le (x:'a) (xs:'a list) : 'a list =
  let rec loop (xs:'a list) (r:'a list) : 'a list =
    match xs with
	[] -> r
      | y::xs' ->
	  (loop xs' (if (y <= x) then y::r else r))
  in
    (loop xs [])

(* l'autre fonction demandée *)
let list_gt (x:'a) (xs:'a list) : 'a list =
  List.filter (fun y -> x < y) xs

(* Q2 *)
    (* Rappel de l'énoncé:
       (qsort (x::xs)) = (xs1 @ [x] @ xs2) 
       où xs1 est le tri des plus petits que x dans xs
       et xs2 le tri des plus grands que x dans xs *)
let rec qsort (xs:'a list) : 'a list =
  match xs with
      [] -> []
    | x::xs -> (qsort (list_le x xs)) @ (x::[]) @ (qsort (list_gt x xs))


(* - Variante du qsort (hors sujet) *)
(* Calculer à la fois `list_le` et `list_gt` *)
let rec split (x:'a) (xs:'a list) : ('a list * 'a list) =
  match xs with
      [] -> ([], [])
    | y::xs' ->
	if (y <= x) then
	  let xs1,xs2 = (split xs') in
	    (y::xs1, xs2)
	else
	  let xs1,xs2 = (split xs') in
	    (xs1, y::xs2)

(* "factorisation" du `let-in` *)
let rec split (x:a') (xs:'a list) : ('a list * 'a list) =
  match xs with
      [] -> ([], [])
    | y::xs' ->
	let xs1,xs2 = (split xs') in
	  if (y <= x) then
	    (y::xs1, xs2)
	  else
	    (xs1, y::xs2)	      

(* la fonction de tri *)
let rec qsort (xs:'a list) : 'a list =
  match xs with
      [] -> []
    | x::xs ->
	let xs1,xs2 = (split x xs) in
	  (qsort xs1) @ [x] @ (qsort xs2)


(* Exo IV *)

(* Q1 *)
(* - solution standard acceptée *)
let rec all_diff (xs:'a list) : bool =
  match xs with
      [] -> true 
    | x::xs -> if (List.mem x xs) then false else (all_diff xs)

(* - meilleure formulation (expression booléenne) *)
let rec all_diff (xs:'a list) : bool =
  match xs with
      [] -> true 
    | x::xs -> not (List.mem x xs) && (all_diff xs)

(* Remarque: ces deux définitions sont recursives erminales *)
	
(* Q2 *)
(* - solution standard *)
let rec nb_diff (xs:'a list) : int =
  match xs with
      [] -> 0
    | x::xs ->
	if (List.mem x xs) then (nb_diff xs)
	else 1+(nb_diff xs)

(* - récurrence terminale *)
let nb_diff (xs:'a list) : int =
  let rec loop (xs:'a list) (r:int) : int =
    match xs with
	[] -> r
      | x::xs' ->
	  if (List.mem x xs') then (loop xs' r)
	  else (loop xs' (1+r))
  in
    (loop xs 0)

(* Q3 *)
(* - solution standard *)
let rec at_least_n_diff (n:int) (xs:'a list) : bool =
  if (n=0) then true
  else
    match xs with
	[] -> false
      | x::xs ->
	  if (List.mem x xs) then (at_least_n_diff n xs)
	  else (at_least_n_diff (n-1) xs)

(* variante avec expression booléenne *)
let rec at_least_n_diff (n:int) (xs:'a list) : bool =
  (n-0) ||
    (match xs with
	 [] -> false
       | x::xs ->
	   if (List.mem x xs) then (at_least_n_diff n xs)
	   else (at_least_n_diff (n-1) xs))

(* variante avec filtrage (écriture plus proche de la déf. par équations) *)
let rec at_least_n_diff (n: int) (xs: 'a list) : bool =  
  match n, xs with 
      0, _ -> true 
    | _, [] -> false  
    | n, x::xs ->
	if (List.mem x xs) then (at_least_n_diff n xs)
	else (at_least_n_diff (n-1) xs)     

(* Q4 : on aura tjrs false car on n'atteint jamais 0 mais toujours [] *)

(* Q3 - variante *)
let rec at_least_n_diff (n:int) (xs:'a list) : bool =
  if (n <= 0) then true 
  else
    match xs with
	[] -> false
      | x::xs ->
	  if (List.mem x xs) then (at_least_n_diff n xs)
	  else (at_least_n_diff (n-1) xs)
	  
(* Q4 - variante: si n<à alors (at_least_n_diff n xs)=true *)


