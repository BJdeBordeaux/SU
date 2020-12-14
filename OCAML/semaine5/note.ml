type 'a btree = 
  |E
  |N of ('a btree * 'a * 'a btree)

type 'a option = 
  |None
  |Some of 'a

let add (x: 'a) (xs : 'a list) : 'a list = 
  xs@[x]

let top (xs : 'a list) : 'a =
  match xs with
  |[] -> raise Not_found
  |x :: _ -> x

let pop (xs : 'a list) : 'a list = 
  match xs with
  |_ :: xs2 -> xs2
  |_ -> xs

let rec mem (x :'a) (bs : 'a btree) : bool = 
  match bs with
  |E -> false
  |N(ba, y, bb) -> (x = y) || (mem x ba) || (mem x bb)

let rec search (p : 'a -> bool) (bt : 'a btree) : 'a = 
  match  bt with
  |E -> raise Not_found
  |N(ba, x, bb) -> 
    if p x then x
    else
      try search p ba
      with Not_found -> search p bb


let bfsearch (p : 'a -> bool) (bt : 'a btree) : 'a = 
    let rec loop (bts : ('a btree) list) : bool =
      match bts with
      |[] -> raise Not_found
      |_ -> match top bts with
        |E -> loop (pop bts)
        |N(ba, x, bb) ->
          if p x then x 
          else (loop (add bb (add ba (pop bts))))
    in loop (add bt [])

