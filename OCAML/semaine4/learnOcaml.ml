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