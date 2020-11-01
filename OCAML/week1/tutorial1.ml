let fst (a, b) = a
let snd (a, b) = b

let pair a b = (a, b)
let truePair a = (true, a)

let curry f x y = f (x, y)
let uncurry f (x, y) = f x y

let application f x = f x
let composition f g x = f (g x)

let fOrIdentity f x b = if b
                        then x
                        else f x
