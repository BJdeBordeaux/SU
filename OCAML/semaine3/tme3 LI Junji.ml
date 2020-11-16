let rec merge (xs:'a list) (ys:'a list) : 'a list = 
  match (xs, ys) with
  |([], yss) -> yss
  |(xss, []) -> xss
  |(x :: xss, y :: yss) -> if(x < y) 
    then x :: merge xss ys
    else y :: merge xs yss

    let _ = assert((merge [8; 5; 7] []) = [8; 5; 7])
    let _ = assert((merge [] [8; 5; 7]) = [8; 5; 7])
    let _ = assert((merge [1] [3; 6; 2]) = [1; 3; 6; 2]) 
    let _ = assert((merge [5] [3; 6; 2]) = [3; 5; 6; 2]) 
    let _ = assert((merge [1; 5] [3; 6; 2]) = [1; 3; 5; 6; 2])
    let _ = assert(merge [0;2;4;8] [1;3;5;7] = [0; 1; 2; 3; 4; 5; 7; 8])

let rec split (xs:'a list) : ('a list) * ('a list) = 
  match xs with
  |[] -> [], []
  |[x] -> ([x],[])
  |x :: y :: xss-> let (a, b) = split xss 
    in x :: a, y :: b

  let _ = assert((split [1]) = ([1],[]))
  let _ = assert((split [1;2]) = ([1],[2]))
  let _ = assert((split [1;2;3]) = ([1;3],[2]))

let rec merge_sort (xs:'a list) : 'a list = 
  match xs with 
  |[] -> []
  |[a] -> [a]
  |_ -> let la, lb = split xs in
    merge (merge_sort la) (merge_sort lb)

let rec merge_sort_v2 (xs:'a list) : 'a list = 
  match xs with 
  |[] -> []
  |a :: l -> merge [a] (merge_sort l)

let _ = assert(merge_sort [4; 1; 7; 2; 3; 0; 5; 8] = [0; 1; 2; 3; 4; 5; 7; 8])

let rec merge2 (cmp: 'a -> 'a -> bool) (xs:'a list) (ys:'a list) : 'a list = 
  match (xs, ys) with
  |([], yss) -> yss
  |(xss, []) -> xss
  |(x :: xss, y :: yss) -> if(cmp x y) 
    then x :: merge2 cmp xss ys
    else y :: merge2 cmp xs yss

let _ = assert(merge2 (fun x y -> x >= y) [2;5] [3;1] =  [3; 2; 5; 1])

let rec merge_sort2 (cmp:'a -> 'a -> bool) (xs:'a list) : 'a list =
  match xs with 
  |[] -> []
  |a :: l -> merge2 cmp [a] (merge_sort2 cmp l)

  (* EX6 Q3 *)
let _ = assert(merge_sort2 (fun (a, b) (c, d) -> (a+b < c+d)) [(1, 5); (2, 3)] = [(2, 3); (1, 5)])