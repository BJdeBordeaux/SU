let rec cpt (xs : 'a list) : int = 
  match xs with 
  |x :: xs' -> (cpt xs') + 1
  |_ -> 0

let len_comp_3 (xs : 'a list) : int =
  let c = cpt xs
  in if (c > 3) then 1
  else if (c = 3) then 0
  else (-1)

let len_comp_32 (xs : 'a list) : int =
  match xs with
  |[a; b; c] -> 0
  |a::b::c::l -> 1
  |_ -> (-1)

let _ = assert(len_comp_3 [1; 2; 3; 4; 5] = 1)
let _ = assert(len_comp_3 [1; 2; 3] = 0)
let _ = assert(len_comp_3 [1; 2] = (-1))
let _ = assert(len_comp_3 [] = (-1))

let swap_hd_snd (xs : 'a list) : ('a list) = 
  match xs with 
  | a :: b :: xs -> [b; a] @ xs
  | _ -> xs

let _ = assert(swap_hd_snd [1; 2; 3; 4] = [2; 1; 3; 4])
let _ = assert(swap_hd_snd [1; 2; 3] = [2; 1; 3])
let _ = assert(swap_hd_snd [1; 2] = [2; 1])
let _ = assert(swap_hd_snd [1] = [1])
let _ = assert(swap_hd_snd [] = [])

let rec swap_hd_fst (xs:('a*'a) list) : ('a*'a) list = 
  match xs with 
  |(a, b) :: l -> (b, a) :: swap_hd_fst l
  |[] -> []

  let _ = assert(swap_hd_fst [(1, 2) ; (3, 4); (5, 6)] = [(2, 1) ; (4, 3); (6, 5)])
  let _ = assert(swap_hd_fst [(1, 2)] = [(2, 1)])
  let _ = assert(swap_hd_fst [] = [])

(* exo 2 *)

let rec repeat (n: int) (x: 'a) : 'a list = 
  if(n <= 0) then []  
  else x :: (repeat (n - 1) x)

  let _ = assert((repeat 7 true) = [true; true; true; true; true; true; true])
  let _ = assert((repeat 0 "Hello") = [])
  let _ = assert((repeat (-42) [1;2;3]) = [])

let rec range_i (i : int) (j : int) : (int list) = 
  if(i>j) then []
  else i :: (range_i (i+1) j)

  let _ = assert(range_i 2 4 = [2; 3; 4])

let rec intercale1 (z: 'a) (xs: 'a list) : 'a list = 
  match xs with
  | [] -> []
  | [a] -> [a]
  | a :: l -> a :: z :: (intercale1 z l)

  let _ = assert((intercale1 1 []) = [])
  let _ = assert((intercale1 0 [5]) = [5])
  let _ = assert((intercale1 0 [1;2;3]) = [1;0;2;0;3])

let rec inverse_i (xs:float list) : float list =
  match xs with 
  | []-> []
  | x :: l -> 1./.x :: inverse_i l

  let _ = assert((inverse_i [1.;2.;3.]) = [1.;1./.2.;1./.3.])

let rec list_interval (ns:int list) : int list = 
  match ns with
  | [] -> []
  | x :: l -> if (x>= (-10) && (x<=10))
    then x :: list_interval l
    else list_interval l

let _ = assert((list_interval [1; -15; -5; 20]) = [1; -5])

let rec parenthese (xs:string list) : string = 
  match xs with
  |[] -> ""
  |x :: l -> "("^x^")"^(parenthese l)

  let _ = assert((parenthese []) = "")
  let _ = assert((parenthese ["do";"re";"mi"] = "(do)(re)(mi)"))


(* list_rec_list *)
let rec intercale1 (z:'a) (xs:'a list) : 'a list =
  match xs with
  | [] -> []
  | [a] -> [a]
  | a :: l -> a :: z :: (intercale1 z l)
    
let rec intercale2 (z:'a) (xs:'a list) : 'a list =
  match xs with
  | [] -> [z] 
  | a :: l -> z :: a :: (intercale2 z l)
    
let rec begaie (xs:'a list) : ('a list) =
  match xs with
  | [] -> [] 
  | a :: l -> a :: a :: (begaie l)

let rec oublie1 (xs:'a list) : ('a list) =
  match xs with 
  | a :: b :: l -> a :: (oublie1 l)
  | [] -> []
  | [a] -> [a]


let rec oublie2 (xs:'a list) : ('a list) =  
  match xs with 
  | a :: b :: l -> b :: (oublie2 l)
  | _ -> []


  (* list_scheme_app *)

let rec inverse_f (xs:float list) : float list =
  match xs with 
  | []-> []
  | x :: l -> 1./.x :: inverse_f l
                
let rec inverse_i (ns:int list) : float list =
  match ns with
  | []-> []
  | x :: l -> 1./.(float_of_int x) :: inverse_i l

let rec ecrete (xs:int list) : int list =
  match xs with
  | [] -> []
  | x :: l -> if (x<= (-10))
      then (-10) :: ecrete l
      else if(x>=10) then 10 :: (ecrete l)
      else x :: ecrete l

let rec dpoints (xs:int list) (a:int) (b:int) : (int*int) list =
  match xs with
  | []-> []
  | x :: l -> (x, a * x + b) :: (dpoints l a b)

let rec app_list (f:'a -> 'b) (xs:'a list) : 'b list =
  match xs with
  | []-> []
  | x :: l -> (f x) :: (app_list f l)

  (* list_scheme_fil *)

let rec list_impair (ns:int list) : int list =
  match ns with
  | [] -> []
  | x :: l -> if (x mod 2 = 1)
      then x :: list_impair l
      else list_impair l

let rec list_non_nulle (xs:string list) : string list =
  match xs with
  | [] -> []
  | x :: l -> if (x = "")
      then list_non_nulle l
      else x :: list_non_nulle l

let rec list_interval (ns:int list) : int list =
  match ns with
  | [] -> []
  | x :: l -> if (x>= (-10) && (x<=10))
      then x :: list_interval l
      else list_interval l

let rec list_non_vide (xss:('a list) list) : ('a list) list =
  match xss with
  | [] -> []
  | x :: l -> if (x = [])
      then list_non_vide l
      else x :: list_non_vide l

let rec list_non_0 (nss:(int list) list) : ('int list) list =
  match nss with
  | [] -> []
  | x :: l -> if (List.mem 0 x)
      then list_non_0 l
      else x :: list_non_0 l

let rec list_sum_tuple (cs:(int * int) list) (s:int) : (int * int) list =
  match cs with
  | [] -> []
  | (a, b) :: l -> if (a+b >= s)
      then (a, b) :: list_sum_tuple l s
      else list_sum_tuple l s