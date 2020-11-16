let rec iter (n:int) (f: 'a -> 'a) (a:'a) : 'a =
  if (n > 0) then (iter (n-1) f (f a))
  else a



(* Exercice I : Factorielle *)

(* Q1 *)
let rec fact (n:int) : int =
  if (n = 0) then 1
  else n * (fact (n-1))

let rec fact_1 (n:int) : int =
  if (n <= 0) then 1
  else n * (fact (n-1))

let fact_2 (n:int) : int =	(* appel terminal *)
  let rec loop n r =
    if (n > 0) then (loop (n-1) (r * n))
    else r
  in (loop n 1)

let fact_3 (n:int) : int * int =	(* avec iter *)
  let f (x, p) : int * int = (x - 1, x * p) in
  iter n f (n, 1)	(* ==> (0, n!) et snd (0, n!) ==> n! *)


(* Exercice II : Sommes *)

(* Q1 *)
let rec sum_n (n:int) : int =
  (* Hypothese : n >= 0 *)
  if (n = 0) then 0
  else n + (sum_n (n - 1))

let sum_n_t (n:int) : int =
  let rec loop n r =
    if (n = 0) then r
    else loop (n-1) (r + n)
  in loop n 0

let sum_n_iter (n:int) : int * int =
  let f ((x, s) : int * int) : int * int = (x-1, s + x) in
  iter n f (n, 0)	(* ==> (0, somme) et snd (0, somme) ==> somme *)

(* Q2 *)
let sum_n_1 (n:int) : int =
  let rec aux (n: int) : int =
    if (n = 0) then 0
    else n + (aux (n - 1))
  in
  if (n < 0) then raise (Invalid_argument "sum_n_1")
  else (aux n)
      
(* Q3 *)
let rec sum_p (n:int) : int =
  (* Hypothese : n >= 0 *)
  if (n = 0) then 0
  else (n * 2) + (sum_p (n - 1))

let sum_p_t (n:int) : int =
  (* Hypothese : n >= 0 *)
  let rec loop (n : int) (s : int) : int =
    if (n = 0) then s
    else loop (n - 1) (s + n * 2)
  in loop n 0

let sum_p_iter (n:int) : int * int =
  (* Hypothese : n >= 0 *)
  let f ((n, s) : int * int) : int * int = (n-1, s + n * 2)
  in iter n f (n, 0)	(* ==> (0, somme_p) et snd (0, somme_p) ==> somme_p *)

(* Q4 *)
let rec sum_f (f:int -> int) (n:int) : int =
  (* Hypothese : n >= 0 *)
  if (n = 0) then (f 0)
  else (f n) + (sum_f f (n - 1))

let sum_p (n:int) : int =
  (* Hypothese : n >= 0 *)
  sum_f (fun x -> x * 2) n
      
let sum_f_t (f:int -> int) (n:int) : int =
  (* Hypothese : n >= 0 *)
  let rec loop (n : int) (r : int) : int =
    if (n = 0) then r
    else loop (n-1) ((f n) + r)
  in loop n 0
      

let sum_f_iter (f:int -> int) (n:int) : int * int =
  (* Hypothese : n >= 0 *)
  let f ((n, s) : int * int) : int * int = (n-1, s + (f n))
  in iter n f (n, 0)	(* ==> (0, somme_f et snd (0, somme_f) ==> somme_f *)
      

(* Exercice III : Termes d'une suite *)

(* Q1 *)
let rec u (n:int) : int =
  (* Hypothese : n >= 0 *)
  if (n = 0) then 42
  else  3 * (u (n-1)) + 4
      
(* Q2 *)
let rec sum_u (n:int) : int =
  (* Hypothese : n >= 0 *)
  if (n = 0) then (u 0)
  else (u n) + (sum_u (n-1))
      
(* Q3 *)
let rec loop (n:int) (t:int) : int =
  if (n = 0) then t
  else t + loop (n-1) (3 * t + 4)

let sum_u (n:int) : int = loop n 42
      
let sum_u_1 (n:int) : int =
  (* Hypothese : n >= 0 *)
  let rec loop (n:int) (t:int) : int =
    if (n = 0) then t
    else t + (loop (n-1) (3 * t + 4))
   in loop n 42
      
let sum_u_2 (n:int) : int =
  (* Hypothese : n >= 0 *)
  let rec loop (n:int) (t:int) (s:int) : int =
    if (n = 0) then s + t
    else loop (n-1) (3 * t + 4) (s + t)
   in loop n 42 0
      
let sum_u_2_iter (n:int) : int * int * int =
  (* Hypothese : n >= 0 *)
  let f ((n, t, s) : int * int * int) : int * int * int =
    if (n = 0) then (0, t, s + t)
    else (n-1, 3 * t + 4, s + 3 * t + 4)
  in iter n f (n, 42, 42)	(* ==> (0, t, sum_u *)
      

(* Exercice IV : Recurrence sur un intervalle *)

(* Q1 *)
let rec sum_inter (a:int) (b:int) : int =
  (* Hypothese : a <= b *)
  if (a = b) then a
  else a + (sum_inter (a+1) b)

(* ou sans hypothese *)
let rec sum_inter_1 (a:int) (b:int) : int =
  if (a > b) then 0
  else a + (sum_inter_1 (a+1) b)

(* Q2 *)
let rec sum1_inter (k:int) (a:int) (b:int) : int =
  (* Hypothese : a <= b *)
  if (a = b) then k + a
  else (k+a) + sum1_inter k (a+1) b

(* Q3 *)
let sum2_inter (a:int) (b:int) : int =
  (* Hypothese : a <= b *)
  let rec aux (x:int) : int =
    if (x = b) then sum1_inter x a b
    else (sum1_inter x a b) + (aux (x+1))
  in aux a

let sum2_inter_1 (a:int) (b:int) : int =
  (* Hypothese : a <= b *)
  let rec loop (x:int) (r:int) : int =
    if (x = b) then r + (sum1_inter x a b)
    else loop (x+1) (r + (sum1_inter x a b))
  in loop a 0

let sum2_inter_iter (a:int) (b:int) : int * int =
  (* Hypothese : a <= b *)
  let f ((x, r) : int * int) : int * int =  (x + 1, r + (sum1_inter x a b))
  in iter (b - a + 1) f (a, 0)
    
