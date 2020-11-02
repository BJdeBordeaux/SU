type bit = bool
type duet = bit * bit
type quartet = bit * bit * bit * bit

let xor (a : bit) (b : bit) : bit =
  match(a,b) with (true,true)->false|
    (false,false)->false|
    (true,false)->true|
    (false,true)->true

let half_adder (a : bit) (b : bit) : duet =
  ((xor a b), (a && b))

let adder (a : bit) (b : bit) (c : bit) : duet =
  let (s1, r1) = (half_adder a b) 
  in  let (s2, r2) = (half_adder c s1) 
      in (s2, (xor r1 r2))

let _ = assert (adder false false false = (false, false))
let _ = assert (adder true false false = (true, false))
let _ = assert (adder false true false = (true, false))
let _ = assert (adder false false true = (true, false))
let _ = assert (adder true false true = (false, true))
let _ = assert (adder false true true = (false, true))
let _ = assert (adder true true true = (true, true))

let duet_adder (a : duet) (b: duet )(c : bit): (duet * bit) =
  let ((ra, sa),(rb, sb)) = (a,b) in
  let (s1, r1) = (adder c sa sb) in
  let (s2, r2) = (adder r1 rb ra) in
  ((s2,s1),r2)

let quartetAdder (a : quartet) (b:quartet) (c : bit) : quartet * bit = 
  let(a1,a2,a3,a4)= a in
  let(b1,b2,b3,b4)= b in
  let ((s3,s4),r1)= (duet_adder (a3,a4) (b3,b4) c) in
  let ((s1,s2),r2)= (duet_adder (a1,a2) (b1,b2) r1) in 
  ((s1,s2,s3,s4),r2);;


(quartetAdder (true, false, false, false) (true, false, false, false) true)

let toQuartet (n:int) : quartet = (fun f (a,b,c,d) ->(f a, f b, f c, f d)) (fun x -> (((n mod (x*2)) / x) = 1)) (8, 4, 2, 1)

let _ = assert (quartetAdder (toQuartet 8) (toQuartet 7) false = ((toQuartet 15), false))
let _ = assert (quartetAdder (toQuartet 8) (toQuartet 8) true = ((toQuartet 1), true))
let _ = assert (quartetAdder (toQuartet 0) (toQuartet 0) true = ((toQuartet 1), false))
let _ = assert (quartetAdder (toQuartet 0) (toQuartet 0) false = ((toQuartet 0), false))
let _ = assert (quartetAdder (toQuartet 8) (toQuartet 2) false = ((toQuartet 10), false))
let _ = assert (quartetAdder (toQuartet 2) (toQuartet 8) false = ((toQuartet 10), false))
let _ = assert (quartetAdder (toQuartet 10) (toQuartet 11) false = ((toQuartet 5), true))
