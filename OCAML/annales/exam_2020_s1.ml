(* == Exo I *)

(* -- Q1 *)
let rec list_couples (n:int) : (int*int) list =
  if (n > 0) then (n,n-1)::(list_couples (n-2))
  else []

(* -- Q2 *)
let rec rev_list_couples (nns:(int*int) list) : (int*int) list =
  match nns with
      [] -> []
    | (n1,n2)::nns -> (rev_list_couples nns)@[(n2,n1)]

let rev_list_couples (nns:(int*int) list) : (int*int) list =
  let rec loop nns r =
    match nns with
	[] -> r
      | (n1,n2)::nns -> (loop nns ((n2,n1)::r))
  in
    (loop nns [])

let rev_list_couples (nns:(int*int) list) : (int*int) list =
  List.fold_left (fun xs (x1,x2) -> (x2,x1)::xs) [] nns
    
(* == Exo II *)
type seance = (string * int * int)
type prog = seance list

let p0 = [("f1",0,1); ("f1",2,3); ("f2",0,1)]

let p1 =
  [ ("f1",0,1); ("f4",0,1); ("f3",2,3); ("f1",2,3); ("f2",0,1); ("f3",4,5); ("f2",4,5); ("f3",0,1); ("f4",6,7); ("f4",2,3); ("f2",2,3) ]
	       
let p2 =
  [ ("f1",2,3); ("f2",0,1); ("f2",2,3); ("f3",0,1); ("f3",2,3); ("f3",4,5); ("f4",0,1) ]
	       
let p3 =
  [ ("f1",2,3); ("f4",0,1); ("f2",0,1); ("f3",2,3); ("f0",0,1); ("f2",2,3); ("f3",0,1); ("f4",2,3); ("f1",0,1); ("f3",4,5) ]

let p4 = [("f1",0,1); ("f2",0,1)]

(* -- Q1 *)
let seance_film (t:string) (s:seance) : bool =
  match s with
      (t', _, _) -> (t=t')

(* -- Q2 *)
(* - de base *)
let rec liste_seance (t:string) (p:prog) : prog =
  match p with
      [] -> []
    | s::p' ->
	if (seance_film t s) then s::(liste_seance t p')
	else (liste_seance t p')

(* - terminale *)
let liste_seance (t:string) (p:prog) : prog =
  let rec loop p r =
    match p with
	[] -> r
      | s::p' ->
	  if (seance_film t s) then (loop p' (s::r))
	  else (loop p' r)
  in
    (loop p [])

(* - itérateur *)
let liste_seance (t:string) (p:prog) : prog =
  List.filter (seance_film t) p

(* -- Q3 *)
let seance_compat (s1:seance) (s2:seance) : bool =
  match s1, s2 with
      (tf1, hd1, hf1), (tf2,hd2,hf2) ->
	((hf1 < hd2) || (hf2 < hd1))

let _ = assert (seance_compat ("t1",0,1) ("t2", 3, 4))
let _ = assert (seance_compat ("t2", 3, 4) ("t1",0,1))
(*let _ = assert (not (seance_compat ("t1",0,1) ("t1", 3, 4)))*)
let _ = assert (not (seance_compat ("t1",0,2) ("t2", 1, 4)))

(* -- Q4 *)
(* - de base *)
let rec liste_compat1 (s:seance) (p:prog) : prog =
  match p with
      [] -> []
    | s'::p' ->
	if (seance_compat s s') then
	  s'::(liste_compat1 s p')
	else
	  (liste_compat1 s p')

let _ = assert ((liste_compat1 ("f", 0, 7) p1) = [])
let _ = assert ((liste_compat1 ("f1", 0, 1) p0) = [("f1", 2, 3)])
let _ = assert ((liste_compat1 ("f1", 2, 3) p0) = [("f1", 0, 1); ("f2",0,1)])

(* - terminale *)
let liste_compat1 (s:seance) (p:prog) : prog =
  let rec loop p r =
    match p with
	[] -> r
      | s'::p' ->
	if (seance_compat s s') then
	  (loop p' (s'::r))
	else
	  (loop p' r)
  in
    (loop p [])

let _ = assert ((liste_compat1 ("f", 0, 7) p1) = [])
let _ = assert ((liste_compat1 ("f1", 0, 1) p0) = [("f1", 2, 3)])
let _ = assert ((liste_compat1 ("f1", 2, 3) p0) = [("f2",0,1); ("f1", 0, 1)])

(* - itérateur *)
let liste_compat1 (s:seance) (p:prog) : prog =
  List.filter (seance_compat s) p

let _ = assert ((liste_compat1 ("f", 0, 7) p1) = [])
let _ = assert ((liste_compat1 ("f1", 0, 1) p0) = [("f1", 2, 3)])
let _ = assert ((liste_compat1 ("f1", 2, 3) p0) = [("f1", 0, 1); ("f2",0,1)])

(* -- Q5 *)
let rec map_paire (x:'a) (xs:'b list) : ('a*'b) list =
  match xs with
      [] -> []
    | x'::xs' -> (x,x')::(map_paire xs')

let map_paire (x:'a) (xs:'b list) : ('a*'b) list =
  List.map (fun x' -> (x,x')) xs

(* -- Q6 *)
(* - de base, c'est déjà bien *)
let rec liste_compat2 (p1:prog) (p2:prog) : (seance*seance) list =
  match p1 with
      [] -> []
    | s::p1' ->
	(map_paire s (liste_compat1 s p2))
	@(liste_compat2 p1' p2)

(* -- Q7 *)
let seances_possibles (t1:string) (t2:string) (p:prog) : (seance*seance) list =
  (liste_compat2 (liste_seance t1 p) (liste_seance t2 p)) 
    
(* == Exo III *)
type 'a btree =
    Empty
  | Node of ('a * ('a btree) * ('a btree))

(* -- Q1 *)
let rec max_loop (bt:'a btree) (r:'a) : 'a =
    match bt with
	Empty -> r
      | Node(x,bt1,bt2) -> (max_loop bt1 (max_loop bt2 (max x r)))

(* -- Q2 *)
let max_bt (bt:'a btree) : 'a =
  match bt with
      Empty -> raise Not_found 
    | Node(x,bt1,bt2) -> (max (max_loop bt1 x) (max_loop bt2 x))

let max_bt (bt:'a btree) : 'a =
  match bt with
      Empty -> raise Not_found 
    | Node(x,bt1,bt2) -> (max_loop bt1 (max_loop bt2 x))

(* -- Exo IV *)

(* -- Q1 *)
let rec postfix (bt:' btree) : 'a list =
  match bt with
      Empty -> []
    | Node(x,bt1,bt2) -> (postfix bt1)@(postfix bt2)@[x]


(* - Récursion terminale *)
let postfix (bt:' btree) : 'a list =
  let rec loop (bts:('a btree) list) (r:'a list) =
    match bts with
	[] -> r
      |	Empty::bts' -> (loop bts' r)
      | (Node(x,bt1,bt2))::bts' -> (loop (bt2::bt1::bts') (x::r))
  in
    (loop [bt] [])

let bt =
  Node(5,
       Node(2, 
            Node(1, Empty, Empty),
            Empty),
       Node(4,
            Empty,
            Node(3, Empty, Empty)))

type 'a gtree =
    Empty
  | Node of 'a * ('a gtree) list

(* -- Q3 *)
let rec max_loop (gt:'a gtree) (r:'a) : 'a =
  match gt with
      Empty -> r
    | Node(x,gts) -> (max_loop_forest gts (max x r))
and max_loop_forest (gts:('a gtree) list) (r:'a) : 'a =
  match gts with
      [] -> r
    | gt::gts -> (max_loop gt (max_loop_forest gts r))

let rec max_loop (gt:'a gtree) (r:'a) : 'a =
  match gt with
      Empty -> r
    | Node(x,gts) -> (max_loop_forest gts (max x r))
and max_loop_forest (gts:('a gtree) list) (r:'a) : 'a =
  match gts with
      [] -> r
    | gt::gts -> (max_loop_forest gts (max_loop gt r))

(* -- Q4 *)
let max_gt (gt:'a gtree) : 'a =
  match gt with
      Empty -> raise Not_found
    | Node(x,gts) -> (max_loop_forest gts x)


