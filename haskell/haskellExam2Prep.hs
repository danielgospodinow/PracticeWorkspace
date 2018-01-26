main :: IO()
main = do

    {- Task 02 Tests -}
    print (sumUnique [[1,2,3,2], [-4,-4], [5]])
    print (sumUnique [[2,2,2], [3,3,3], [4,4,4]])
    print (sumUnique [[1,2,3], [4,5,6], [7,8,9]])

    {- Task 03 Tests -}
    let store1=[("bread",1),("milk",2.5),("lamb",10),("cheese",5),("butter",2.3)]
    let store2=[("bread",1),("cheese",2.5),("bread",1),("cheese",5),("butter",2.3)]
    print (closestToAverage store1)
    print (cheaperAlternative store2)

    {- Task 04 Tests-}
    print (minDistance [(1.0, 1.0, 1.0), (2.0, 2.0, 3.0), (0.0, 0.0, 0.0), (4.0, 7.0, 9.0), (0.5, 0.5, 0.5)])

    {- Task 05 Tests-}
    let fn = maximize [(\x -> x*x*x), (\x -> x+1)]
    print(fn 0.5)
    print(fn (-2))

    {- Task 06 Tests-}
    print (inverseFun (\x -> x+1) (\x -> x-1) 5 10)
    print (inverseFun (\x -> x*x) (\x -> x^3) 0 1)
    print (inverseFun (\x -> x+1) (\x -> x+2) 0 1)

    {- Task 07 Tests -}


sumUnique :: [[Int]] -> Int
sumUnique xs = sum(getUnique(flatten xs))
    where
        flatten xs
            | null xs   = []
            | otherwise = (head xs) ++ (flatten (tail xs))
        getUnique xs = [x | x <- xs, (getFreq x xs) == 1]
            where
                getFreq x xs
                    | null xs        = 0
                    | (head xs) == x = 1 + getFreq x (tail xs)
                    | otherwise      = 0 + getFreq x (tail xs)
        sum xs = foldl (\ x y -> x + y) 0 xs


type Product = (String, Double)
type StoreAvailability = [Product]
closestToAverage :: StoreAvailability -> String
closestToAverage sa = getClosest sa (getAverage sa 0 0)
    where
        getAverage sa currSum totalNums
            | null sa   = if (totalNums /= 0) then currSum / totalNums else 0
            | otherwise = getAverage (tail sa) (currSum + (snd (head sa))) (totalNums + 1)
        getClosest sa avg = if null sa then "NULL" else helper sa avg (head sa)
            where
                helper lst avg best
                    | null lst                                            = (fst best)
                    | abs((snd (head lst)) - avg) < abs((snd best) - avg) = helper (tail lst) avg (head lst)
                    | otherwise                                           = helper (tail lst) avg best


cheaperAlternative :: StoreAvailability -> Int
cheaperAlternative sa = length ([s | s <- sa, (hasCheaper sa s)])
    where
        hasCheaper sa s
            | null sa                                                   = False
            | (fst (head sa)) == (fst s) && (snd (head sa)) < (snd (s)) = True
            | otherwise                                                 = hasCheaper (tail sa) s


type PointTD = (Double, Double, Double)
minDistance :: [PointTD] -> Double
minDistance pts = minimum (flat ([(getDistances p pts) | p <- pts]))
    where
        flat ls
            | null ls   = []
            | otherwise = (head ls) ++ (flat (tail ls))
        getDistances p pts
            | null pts  = []
            | otherwise = if (distance p (head pts)) /= 0 then distance p (head pts) : getDistances p (tail pts) else getDistances p (tail pts)
                where 
                    distance p q = ((sel1 p) - (sel1 q)) ** 2 + ((sel2 p) - (sel2 q)) ** 2 + ((sel3 p) - (sel3 q)) ** 2
                        where
                            sel1 (x, _, _) = x
                            sel2 (_, x, _) = x
                            sel3 (_, _, x) = x


maximize :: (Ord a, Num a) => [(a -> a)] -> (a -> a)
maximize fs = (\ y -> snd (maximum [(abs fr, fr) | fr <- [f y | f <- fs]]))


inverseFun :: (Int -> Int) -> (Int -> Int) -> Int -> Int -> Bool
inverseFun f g a b
    | a > b     = True
    | otherwise = (f (g a)) == (g (f a)) && (f (g a)) == a && inverseFun f g (a+1) b
-- или по-кратко: all (\x -> (g.f)x == x && (f.g)x == x) [a..b]