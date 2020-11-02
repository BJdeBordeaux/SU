(* Allen Sobot, 28600456, TME 1 *)

(* Q1 *)
type bit = bool
type duet = bool * bool
type quartet = bool * bool * bool * bool

(* Q2 *)
let xor = (<>)

(* Q3 *)
let halfAdder (a: bit) (b: bit): duet = (xor a b, a && b)
(* Q4 *)
let adder (a: bit) (b: bit) (c: bit): duet = let (s1, r1) = halfAdder a b
                                             in let (s2, r2) = halfAdder c s1
                                                in (s2, r1 || r2)


(* Q5 *)
let _ = assert (adder false false false = (false, false))
let _ = assert (adder true false false = (true, false))
let _ = assert (adder false true false = (true, false))
let _ = assert (adder false false true = (true, false))
let _ = assert (adder true false true = (false, true))
let _ = assert (adder false true true = (false, true))
let _ = assert (adder true true true = (true, true))

(* Q6 *)
let duetAdder ((b1, a1): duet) ((b2, a2): duet) (r: bit): (duet * bit) = let (s1, r1) = adder a1 a2 r
                                                                         in let (s2, r2) = adder b1 b2 r1
                                                                            in (s2, s1), r2

(* Q7 *)
let quartetAdder ((d1, c1, b1, a1): quartet) ((d2, c2, b2, a2): quartet) (r: bit): (quartet * bit) = let ((s2, s1), r1) = duetAdder (b1, a1) (b2, a2) r
                                                                                                     in let ((s4, s3), r2) = duetAdder (d1, c1) (d2, c2) r1
                                                                                                        in (s4, s3, s2, s1), r2

(* Q8 *)
let toQuartet (number : int) : quartet = (fun f (a, b, c, d) -> (f a, f b, f c, f d)) (fun x -> number/x mod 2 = 1) (8, 4, 2, 1)

let _ = assert (quartetAdder (toQuartet 8) (toQuartet 7) false = ((toQuartet 15), false))
let _ = assert (quartetAdder (toQuartet 8) (toQuartet 8) true = ((toQuartet 1), true))
let _ = assert (quartetAdder (toQuartet 0) (toQuartet 0) true = ((toQuartet 1), false))
let _ = assert (quartetAdder (toQuartet 0) (toQuartet 0) false = ((toQuartet 0), false))
let _ = assert (quartetAdder (toQuartet 8) (toQuartet 2) false = ((toQuartet 10), false))
let _ = assert (quartetAdder (toQuartet 2) (toQuartet 8) false = ((toQuartet 10), false))
let _ = assert (quartetAdder (toQuartet 10) (toQuartet 11) false = ((toQuartet 5), true))
