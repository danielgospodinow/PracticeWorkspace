main :: IO()
main = do

    let xs = [1]

    print(head xs)
    print(tail xs)


square :: Int -> Int
square n = n * n

average :: Float -> Float -> Float
average x y = (x + y) / 2

-- Еднореден коментар
{- 
    Многореден коментар
-}

xOr :: Bool -> Bool -> Bool
xOr x y = (x || y) && not (x && y)

{-
    * div - Частно при целочислено деление, например div 14 3 е 4.
    Може да се запише и инфиксно: 14 `div` 3.
    
    * mod - Остатък при целочислено деление, например mod 14 3
    или 14 `mod` 3.

    * abs - Абсолютната стойност на дадено цяло число (числото
    без неговия знак).

    * negate - Функция, която променя знака на дадено цяло число
-}

{-
    * ceiling, float, round :: Float -> Int - конвертиране на реално 
    число в цяло чрез закръгляне нагоре, закръгляне надолу или 
    закръгляне до най-близкото цяло число

    * fromIntegral :: Int -> Float - конвертиране на цяло число
    в реално
-}

{-
offset :: Int
offset = ord 'A' - ord 'a'

toUpper :: Char -> Char
toUpper ch = chr (ord ch + offset)
-}

{-
    Kато имаме, че (ord :: Char -> Int) и (chr :: Int -> Char)
-}

{-
max :: Int -> Int -> Int
max x y
    | x >= y    = x
    | otherwise = y


max :: Int -> Int -> Int
max x y = if x >= y then x else y
-}

fact :: Int -> Int
fact n
    | n == 0    = 1
    | n > 0     = fact (n - 1) * n
    

{-
firstDigit :: String -> Char
firstDigit str = 
    case (digits str) of
        []      -> ‘\0’
        (x:_)   -> x
-}

sumLst :: [Int] -> Int
sumLst [] = 0
sumLst (x:xs) = x + sumLst xs

myelem :: Int -> [Int] -> Bool
myelem x [] = False
myelem x (y:ys) = (x == y) || (myelem x ys)

doubleAll :: [Int] -> [Int]
doubleAll xs = [2*x | x <- xs]