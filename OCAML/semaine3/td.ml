let rec cpt (xs : 'a list) : int = 
  match xs with 
  |x :: xs' -> (cpt xs') + 1
  |_ -> 0

let len_comp_3 (xs : 'a list) : int =
  if (cpt xs > 3) then 1
  else if (cpt xs = 3) then 0
  else (-1)

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