let fac n = 
  let rec go n a =
    if n = 0 then a
    else go (n - 1) (n * a)
  in
    if n < 0 then
      raise (Invalid_argument "Argument can't be negative")
    else 
      go n 1

let sumTo n =
  let rec go n a =
    if n = 0 then a
    else go (n - 1) (n + a)
  in
    if n < 0 then
      raise (Invalid_argument "Argument can't be negative")
    else
      go n 0

let sumMap f n =
  let rec go n a =
    if n = 0 then a
    else go (n - 1) (f n + a)
  in
    if n < 0 then
      raise (Invalid_argument "Argument can't be negative")
    else
      go n 0

let sumEven n = sumMap (fun x -> x * 2) n

let u n =
  let rec go n a =
    if n = 0 then a
    else go (n - 1) (3 * a + 4)
  in
    if n < 0 then
      raise (Invalid_argument "Argument can't be negative")
    else
      go n 42

let sum_u n =
  let rec go n a b =
    if n = 0 then  (a + b)
    else go (n - 1) (3 * a + 4) (a + b)
  in
    if n < 0 then
      raise (Invalid_argument "Argument can't be negative")
    else
      go n 42 0

let sumBetweenWithOffset k a b = (b + 1 - a)*k + (b - a)*a + sumTo (b - a - 1) + b
let sumBetween = sumBetweenWithOffset 0
let sumCouplesBetween a b =
  let rec go n acc =
    if n = b then acc + sumBetweenWithOffset n a b
    else go (n + 1) (acc + sumBetweenWithOffset n a b)
  in
    if a > b then
      raise (Invalid_argument "First argument can't be larger than the second")
    else if a = b then a + b
    else
      go a 0
