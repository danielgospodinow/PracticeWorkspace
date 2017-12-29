import Data.List

main:: IO ()
main = do
 print ((\ x y -> x + y) 2 5)
 print xs
 print (null xs) -- = null?
 print (null [])
 print (head xs) --1rst elem
 print (tail xs) --last elem
 print ((head fs) 4)
 print (4 : [1,2,3]) -- > [4,1,2,3] (cons)
 print ([1,2,3] ++ [4,5]) -- > concat
 print ([1,2,3,4] !! 2) -- vzima elem s index 2
-- print ((maxmize [(\x -> x-1, \x->x*2]) 5)
xs :: [Int] --list
xs = [1,2,3,4]
fs::[(Int->Int)]
fs=[(\x->x+1), (\x->x*2)]



--maxFunc::[(

{-maximize ::[(Int->Int)]->(Int->Int)
maximize lst = (\x -> getbiggest (map (\ y -> y x) lst))-}

maximize::[(Int->Int)] -> (Int ->Int) -- spisuk ot funcii-> vrushta funkciq
maximize fs = (\x ->helper (tail fs) (head fs) x)
 where
  helper :: [(Int->Int)]->(Int->Int) -> Int-> Int  --helper vrushta int
  helper fs res x
   | null fs = res x
   | abs ((head fs) x) > abs (res x) = helper (tail fs) (head fs) x
   | otherwise = helper (tail fs) res x

maximize2::[(Int->Int)]->(Int->Int)
maximize2 (f:fs) = (\x->helper fs f x)
where
 helper :: [(Int->Int)]->(Int->Int)->Int->Int
 helper [] res x = res x
 helper (f:fs) res x
  | abs (f x) >abs (res x) = helper fs f x
  |otherwise = helper fs res x

maximize3 :: [(Int->Int)] ->(Int->Int)
maximize3 fs x = snd (maximum(zip (map abs afs) afs))
 where afs = map (\f -> f x) fs


fst :: (a,b)->a
fst (x, _) = x

snd::(a,b) ->b
snd (_,y)=y

f3::(a,b,c,d,e) ->c
f3 (,,x,_,_) = x -- da vurne edi koi si (3) element ot n-orka


print (group ['a','b','b','b','c','c','d'])
print (group[1,2,2,3,3,4,4])

--zad 3 ot dom
encode :: [Char] -> [(Char, Int)]
encode fs = map(\xs -> (head xs, length xs))(group fs)

encode2 :: [Char] -> [(Char, Int)]
encode2 fs = [(head xs, length xs) | xs <- (group fs)]
