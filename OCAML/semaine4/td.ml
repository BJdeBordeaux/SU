(* Exo1 *)

type 'a btree = 
    Empty
  | Node of ('a * 'a btree * 'a btree)

let exemple = 
  Node(1, 
    Node(2,
     Node(3, Empty, Empty),
     Node(4, 
      Node(5, Empty, Empty),
      Empty)),
    Node(6, Empty,
      Node(7, Empty,
        Node(8, Empty, Empty))))

let max_int (a : int) (b : int) : int = 
  if a >= b then a
  else b

let rec hauteur (bt : 'a btree) : int = 
  match bt with
  |Empty -> 0
  |Node(a, g, d) -> 1 + max_int (hauteur g) (hauteur d)

let _ = assert(hauteur exemple = 4) 
let _ = assert(hauteur Empty = 0) 

let list_by_depth (bt: 'a btree) (n: int) : 'a list = 
  let rec loop (bt: 'a btree) (n: int) (l : 'a list) = 
    match bt with
    |Empty -> l
    |Node(a, g, d) -> 
      if n = 0 then a::l
      else (loop g (n-1) l)@(loop d (n-1) l)
  in loop bt n []

let _ = assert(list_by_depth Empty 5 = []) 
let _ = assert(list_by_depth exemple 0 = [1]) 
let _ = assert(list_by_depth exemple 2 = [3; 4; 7]) 

let to_list (bt: 'a btree) : 'a list = 
  let rec loop (bt: 'a btree) (l : 'a list) = 
    match bt with
    |Empty -> l
    |Node(a, g, d) -> [a]@(loop g l)@(loop d l)
  in loop bt []

let _ = assert(to_list exemple = [1; 2; 3; 4; 5; 6; 7; 8])

(* Exo 2 *)

type 'a ubtree = 
  Empty2 
  |Leaf of 'a
  |Node2 of 'a ubtree * 'a * 'a ubtree

(* Q1 *)
let rec taille (ubt: 'a ubtree) : int = 
  match ubt with
  |Empty2 -> 0
  |Leaf x -> 1
  |Node2(g, x, d) -> 1 + (taille g) + (taille d)

(* Q2 *)
  let rec hauteur (ubt : 'a ubtree) : int = 
    match ubt with
    |Empty2 -> 0
    |Leaf x -> 1
    |Node2(g, x, d) -> 1 + max_int (hauteur g) (hauteur d)

(* Q3 *)
let rec leaves (ubt: 'a ubtree) : 'a list = 
  match ubt with
  |Empty2 -> []
  |Leaf x -> [x]
  |Node2(g, x, d) -> (leaves g)@(leaves d)

(* Q4 *)
let rec bt_to_ubt (bt : 'a btree) : 'a ubtree = 
  match bt with
  |Empty -> Empty2
  |Node(a, Empty, Empty) -> Leaf a
  |Node(a, g, d) -> Node2(bt_to_ubt g, a, bt_to_ubt d)

(* EXO3 *)
let exa = 
  Node(5, 
    Node(2,
      Node(1, Empty, Empty),
      Node(4, 
        Node(3, Empty, Empty),
        Empty)),
    Node(6, Empty,
      Node(7, Empty,
        Node(8, Empty, Empty))))

let rec lt_btree (bt : 'a btree) (x: 'a) : bool = 
  match bt with
  |Empty -> true
  |Node(a, g, d) -> (a < x) && lt_btree g x && lt_btree d x

let _ = assert(lt_btree exa 9 == true)
let _ = assert(lt_btree exa 5 == false)
let _ = assert(lt_btree Empty 5 == true)

let rec ge_btree (bt : 'a btree) (x: 'a) : bool = 
  match bt with
  |Empty -> true
  |Node(a, g, d) -> (a >= x) && ge_btree g x && ge_btree d x

let _ = assert(ge_btree exa 9 == false)
let _ = assert(ge_btree exa 5 == false)
let _ = assert(ge_btree Empty 5 == true)

let rec is_abr (bt : 'a btree) : bool = 
  match bt with
  |Empty -> true
  |Node(a, g, d) -> lt_btree g a && ge_btree d a && is_abr g && is_abr d

let rec mem (bt : 'a btree) (x : 'a) : bool = 
  match bt with
  |Empty -> false
  |Node(a, g, d) ->
    if x = a then true
    else if x > a then mem d x
    else mem g x

let rec insert (x: 'a) (bt : 'a btree) : 'a btree = 
  if mem bt x then bt
  else
    match bt with
    |Empty -> Node(x, Empty, Empty)
    |Node(a, g, d) ->
      if x > a then Node(a, g, insert x d)
      else Node(a, insert x g, d)

let _ = assert((insert 3 (Node(4, Node(2, Empty, Empty), Empty))) = Node(4, Node(2, Empty, Node(3, Empty, Empty)), Empty))
let _ = assert((insert 5 (Node(4, Node(2, Empty, Empty), Empty))) = Node(4, Node(2, Empty, Empty), Node(5, Empty, Empty)))
let _ = assert(insert 5 exa = exa)
let _ = assert(insert 2 (Node(1, Empty, Empty)) = Node(1, Empty, Node(2, Empty, Empty)))


let from_list (xs : 'a list) : 'a btree = 
  let rec loop (xs : 'a list) (bt : 'a btree) : 'a btree = 
    match xs with
    |[] -> bt
    |x :: xs2 -> loop xs2 (insert x bt)
  in loop xs Empty 

let _ = assert(from_list [] = Empty)
let _ = assert(from_list [1] = Node(1, Empty, Empty))
let _ = assert(from_list [1; 2] = Node(1, Empty, Node(2, Empty, Empty)))
let _ = assert(from_list [1;2;3] = Node(1, Empty, Node(2, Empty,  Node(3, Empty, Empty))))

let from_list2 (xs : 'a list) : 'a btree = 
  List.fold_left (fun bt x -> insert x bt) Empty xs

let _ = assert(from_list2 [] = Empty)
let _ = assert(from_list2 [1] = Node(1, Empty, Empty))
let _ = assert(from_list2 [1; 2] = Node(1, Empty, Node(2, Empty, Empty)))
let _ = assert(from_list2 [1;2;3] = Node(1, Empty, Node(2, Empty,  Node(3, Empty, Empty))))

let rec to_list (bt : 'a btree) : 'a list = 
  match bt with
  |Empty -> []
  |Node(a, g, d) -> (to_list g)@[a]@(to_list d)

let _ = assert(to_list Empty = [])
let _ = assert(to_list (Node(1, Empty, Empty)) = [1])
let _ = assert(to_list exa = [1; 2; 3; 4; 5; 6; 7; 8])
let _ = assert(to_list (Node(2, Node(1, Empty, Empty), Empty)) = [1; 2])
let _ = assert(to_list (Node(2, Node(1, Empty, Empty), Node(3, Empty, Empty))) = [1; 2; 3])
let _ = assert(to_list (Node(2,Node(1, Empty, Empty),Node(4, Node(3, Empty, Empty), Empty))) = [1; 2; 3; 4])

(* let exa = 
  Node(5, 
    Node(2,
      Node(1, Empty, Empty),
      Node(4, 
        Node(3, Empty, Empty),
        Empty)),
    Node(6, Empty,
      Node(7, Empty,
        Node(8, Empty, Empty)))) *)

let tri (xs : 'a list) : 'a list = 
  to_list (from_list xs)

let _ = assert(tri [] = [])
let _ = assert(tri [2; 1; 3; 5; 4; 6; 7; 8] = [1; 2; 3; 4; 5; 6; 7; 8])