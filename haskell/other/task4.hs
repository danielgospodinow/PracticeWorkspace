main :: IO ()
main = do
 print (sum1[1,2,3,4,5])
 print (sum2[1,2,3,4,5])
 print (sum3[1,2,3,4,5])
 print (f1 [1,2])
 print (filter (\x->mod x 2==0) [1,2,3,4,5,6]) --da ostavi samo chetnite chisla
 print (map (\x->mod x 2==0 ) [1,2,3,4,5,6]) -- dava istina za chetnite i luja za nechetnite
 print (map (\x y -> x+y) (zip [1,2,3] [-1,-2,-3]))
 --print (zip [1,2,3] [-1,-2,-3]) --vzima 2 spisuka i vrushta spisuk ot dvoiki
 --print (t)
 print (filter (\x -> x>5) [1,2,3,4,5,6,7,8])
 print (filter (> 5) [1,2,3,4,5,6,7,8])
 print (compose (\x->x+1)(\x->x*2)) 7) 
 print (((\x -> x+1).(\x->x*2)) 7) --vgradena kompoziciq
 print (filter (\x -> even x && (5 <)) [1,2,3,4,5,6,7,8,])
 print (map ((+1).(*2)) [1,2,3]) --vzimash chisloto, *2, posle +1, posle sledvashtoto chislo..
 print (maximum [(1,1) ,(1,2),(0,3),(0,4)])
 print (minimum [(1,1) ,(1,2),(0,3),(0,4)])
 
compose :: (a->b) -> (c->a) -> (c->b)
compose f g = \x-> f (g x)
 
 
 
 {- --[Int] --spisuk
 
 t :: (Int, Double, Float) --vektor - priema tochno 3 arg ot tezi izbroeni tipove
 t= (1, 1.2, 1.5)
 
 zip1 :: [a] -> [b] -> [(a,b)]
 zip1 []_=[]
 zip1 _[]=[]
 zip1 (x:xs)(y:ys) = (x,y):zip1 xs ys-}
 
 
 
 
 f1::[Int]->Int
 f1(x:y:xs)= x:(y:[])-- dvete tochki pravqt spisuk s tozi elem
 f2 fs@(x:y:xs) = fs ++ (x:y:xs)-- @ osigurqva che fs otgovarq na shablona? 
 f3 fs@(x:_:_) = fs ++ (x:[])
 
 sum1:: [Int]->Int
 sum1 xs = if null xs then 0 else head xs + sum1 (tail xs)
 
 sum2::[Int]->Int
 sum2[]=0
 sum2 xs= head xs + sum2 (tail xs)
 
 sum3::[Int]->Int
 sum3[] = 0
 sum3 fs@(x:y:xs)= x + y + sum3 xs
 sum3 (x:xs) = x + sum xs
