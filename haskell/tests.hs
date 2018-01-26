main :: IO()
main = do
    print( [1, 2, 3] )
    print( ['a', 's', 's'] )
    print( getLstLen ['a'..'z'] )
    print( getLstLen2 ['a'..'z'] )
    print( getLstSum [1..9] )
    print( getLstHead [3..6] )
    print( [p | p <- [1..20], p`mod`2 == 0] )
    print( myzip [1..20] ['a'..'g'] )
    print( (multipl 2) 3 )
    print( [x + y | (x,y) <- zip [20, 21..30] [30, 31..40]] )
    print( zipWith (\x y -> x + y) [20,21..30] [30,31..40] )
    print( [ [],[[3,2,1]]] )
    print( [x | x<-[12, 57, 6], elem x [1..20]] )


getLstLen :: [a] -> Int
getLstLen ls = foldl (\ x y -> x + 1) 0 ls

getLstSum :: [Int] -> Int
getLstSum [] = 0
getLstSum (x:xs) = x + getLstSum xs

getLstHead :: [a] -> a
getLstHead (x:_) = x

myzip :: [a] -> [b] -> [(a, b)]
myzip (x:xs) (y:ys) = (x, y) : myzip xs ys
myzip xs [] = []
myzip [] ys = []

multipl :: Int -> Int -> Int
multipl x y = x * y

getLstLen2 :: [a] -> Int
getLstLen2 xs
    | null xs   = 0
    | otherwise = 1 + getLstLen2 (tail xs)