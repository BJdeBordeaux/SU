let rec cpt (xs : 'a list) : int = 
  match xs with 
  |x :: xs' -> (cpt xs') + 1
  |_ -> 0

let len_eq_3 (xs : 'a list) : bool = 
  cpt xs = 3
  
let len_ge_3 (xs : 'a list) : bool = 
  cpt xs >= 3
  
let len_lt_3 (xs : 'a list) : bool = 
  cpt xs < 3

let len_comp_3 (xs : 'a list) : int =
  if (cpt xs > 3) then 1
  else if (cpt xs = 3) then 0
  else (-1)

let snd (xs:'a list) : 'a =
  match xs with
  | a:: b :: l -> b
  | _ -> raise Not_found
    
let swap_hd_snd (xs:'a list) : 'a list =
  match xs with
  | a:: b :: l -> b :: a :: l
  | _ -> xs
    
let hd_0 (xs:int list) : bool =
  match xs with
  | 0 :: l -> true
  | _ -> false
    
let eq_hd (x0:'a) (xs:'a list) : bool =
  match xs with
  | [] -> false
  | (a :: l) -> (a = x0) 

let hd_fst (xs:('a*'b) list) : 'a =
  match xs with 
  |[] -> raise Not_found
  |(a,b) :: l -> a
    
let rec swap_hd_fst (xs:('a*'a) list) : ('a*'a) list =
  match xs with
  |[] -> [] 
  |(a,b) :: xs -> (b, a) :: xs
    
let hd_hd (xs:('a list) list) : 'a =
  match xs with 
  |[] -> raise Not_found
  |it :: l -> 
      match it with
      |[] -> raise Not_found
      |itt :: ll -> itt 
      
    
let rec rem_hd_hd (xs:('a list) list) : ('a list) list =
  match xs with 
  |[] -> []
  |it :: l -> 
      match it with
      |[] -> [] :: l
      |itt :: ll -> ll :: l

(* Q1 *)
let rec repeat (n:int) (x:'a) : 'a list  = 
  if(n <= 0) then []  
  else x :: (repeat (n - 1) x)


(* Q2 *)
let rec range_i (i:int) (j:int) : (int list) =
  if(i>j) then []
  else i :: (range_i (i+1) j)

(* Q3 *)
let rec range_n (x:int) (n:int) : (int list) =
  if(n<=0) then []
  else (range_n x (n-1)) @[x+n-1]