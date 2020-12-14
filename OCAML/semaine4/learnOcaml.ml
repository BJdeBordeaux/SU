(* tp4_ex1_liste *)
(* Exercice n°1 *)

(* Q1 *)
let rec drop (n : int) (xs : 'a list) : 'a list = 
  if n <= 0 then xs
  else 
    match xs with
    |[] -> []
    |x :: xs' -> drop (n-1) xs'
                   
(* Q2 *)
let take (n:int) (xs: 'a list) : ('a list)= 
  let rec loop (n:int) (xs: 'a list) (s : 'a list) =
    if n <= 0 then s
    else 
      match xs with
      |[] -> s
      |x :: xs' -> loop (n-1) xs' (s@[x])
  in loop n xs []

(* Q3 *)
let sub (xs: 'a list) (start:int) (len:int) : ('a list) = 
  take len (drop start xs)

(* tp4_ex2_sublist *)
(* Exercice n°2 *)

(* Q1 *)
let rec sublac (xs : 'a list) (ys : 'a list) : bool = 
  match xs with
  |[] -> true
  |x :: xs' -> 
      match ys with 
      |[] -> false
      |y :: ys' -> 
          if y <> x then sublac xs ys'
          else sublac xs' ys'    

(* Q2 *)
let rec sublying (xs : int list) (ys : int list) : bool = 
  match xs, ys with
  |[], [] -> true
  |x :: xs', y :: ys' -> 
      (x = y || x = 0) && sublying xs' ys'
  |_ -> raise (Invalid_argument "subl")

(* Q3 *)
(* Exercice n°2 *)

(* Q1 *)
let rec sublac (xs : 'a list) (ys : 'a list) : bool = 
  match xs with
  |[] -> true
  |x :: xs' -> 
      match ys with 
      |[] -> false
      |y :: ys' -> 
          if y <> x then sublac xs ys'
          else sublac xs' ys'    

(* Q2 *)
let rec sublying (xs : int list) (ys : int list) : bool = 
  match xs, ys with
  |[], [] -> true
  |x :: xs', y :: ys' -> 
      (x = y || x = 0) && sublying xs' ys'
  |_ -> raise (Invalid_argument "subl")

(* Q3 *)
let rec rev (xs : 'a list) : 'a list = 
  match xs with
  |[] -> []
  |x :: xs' -> (rev xs')@[x]
    
let stretch (xs:'a list) (ys:'a list) : 'a list = 
  let rec loop (xs:'a list) (ys:'a list) (res : 'a list) : 'a list = 
    match xs, ys with
    |[], [] -> res
    |[], y :: ys' -> loop xs ys' (res@[0])
    |x :: xs', y :: ys' -> 
        if x != y then loop xs ys' (res@[0])
        else loop xs' ys' (res@[x])
    |_ -> raise (Invalid_argument "stretch")
  in loop xs ys []


(* tp4_ex3_assoc *)
(* Exercice n°3 *)

(* Q1 *)
let nb_ingredients (rdic:dico) (r:string) : int = 
  List.length (List.assoc r rdic)

(* Q2 *)
let recette_avec (rdic:dico) (i:string) : string list = 
  let rec loop (d : dico) (res : string list) = 
    match d with
    |[] -> res
    |(r, is) :: d' -> 
        if (List.mem i is) then loop d' (r::res)
        else loop d' res
  in loop rdic []

(* Q3 *)
let recette_sans (rdic:dico) (i:string) : string list =
  let rec loop (d : dico) (res : string list) = 
    match d with
    |[] -> res
    |(r, is) :: d' -> 
        if (List.mem i is) then loop d' res
        else loop d' (r::res)
  in loop rdic []

(* Q4 *)
let rec union (xs:'a list) (ys:'a list) : 'a list =
  match xs with 
  |[] -> ys
  |x :: xs' -> 
      if List.mem x ys then union xs' ys
      else union xs' (x::ys)
  

(* Q5 *)
let tous_ingredients (rdic:dico) : string list = 
  let rec loop (d : dico) (res : string list) : string list = 
    match d with 
    |[] -> res
    |(r, is) :: d' -> loop d' (union res is)
  in loop rdic []
    
(* Q6 *)
let dico_ingredients (rdic : dico) : dico = 
  List.fold_left (fun res i -> (i, (recette_avec rdic i)) :: res) [] (tous_ingredients rdic)

(* Q7 *)
let ingredient_principal (idic : dico) : string = 
  let (ingredient, nombre) = List.fold_left (fun (str, max) (i, rs) -> if ((List.length rs) >= max) then (i, List.length rs) else (str, max)) ("", -1) idic
  in if idic = [] then raise (Invalid_argument "idic")
  else ingredient

(* list_iter *)

(* Q1 *)
let rec inverse_i (xs:int list) : float list =
  List.map (fun x -> if x = 0 then 0. else 1./.(float_of_int x)) xs

(* Q2 *)
let list_sum_tuple (cs:(int*int) list) (s:int) : (int*int) list =
  List.filter (fun (xa, xb) -> (xa+xb >= s)) cs

(* Q3 *)
let rec parenthese (xs:string list) : string =
  List.fold_right (fun x res -> "("^x^")"^res) xs ""

(* Q4 *)
let rec list_non_0 (nss:(int list) list) : (int list) list =
  List.filter (fun l -> not (List.mem 0 l)) nss
(* Q5 *)
let rec dpoints (xs:int list) (a:int) (b:int) : (int*int) list =
  List.map  (fun x -> (x, x*a + b)) xs

(* Q6 *)
let prod_sum_tuple (cs:(int*int) list) : int =
  List.fold_left (fun res (ca, cb) -> (ca+cb) * res) 1 cs
    
