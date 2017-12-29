main :: IO()
main = do
    print(count_digits testNum)
    print(sum_digits testNum)
    print(sum_digits_iter testNum)
    print(pow 2 3)
    print(rev testNum)
    print(prime 11)


testNum = 339 :: Int

{-
  Зад. 1. Да се дефинира процедура count_digits :: Int -> Int, която генерира линейно
  рекурсивен процес и намира броя на цифрите на дадено цяло число n.
-}

count_digits :: Int -> Int
count_digits num
    | num < 0              = count_digits (abs num)
    | num >= 0 && num <= 9 = 1
    | otherwise            = 1 + count_digits (num `div` 10)

{-
  Зад. 2. Да се дефинира процедура sum_digits :: Int -> Int, която генерира линейно
  рекурсивен процес и намира сумата от цифрите на дадено естествено число n.
-}

sum_digits :: Int -> Int
sum_digits num
    | (num >= 0 && num <= 9) = num
    | otherwise              = (num `mod` 10) + sum_digits (num `div` 10)

{-
  Зад. 3. Да се дефинира процедура pow :: Double -> Int -> Double, която генерира линейно рекурсивен
  процес и намира x на степен n, където x е реално, а n - естествено число.
-}

pow :: Double -> Int -> Double
pow x num
    | num == 0  = 1
    | otherwise = x * (pow x (num-1))

{-
  Зад. 4. Да се дефинира процедура sum_digits_iter :: Int -> Int, която генерира линейно
  итеративен процес и намира сумата от цифрите на дадено естествено число n.
-}

sum_digits_iter :: Int -> Int
sum_digits_iter num = helper num 0
    where
        helper :: Int -> Int -> Int
        helper num sum
            | num == 0  = sum
            | otherwise = helper (num `div` 10) (sum + (num `mod` 10)) 

{-
  Зад. 5. Да се дефинира процедура rev :: Int -> Int, която генерира линейно итеративен
  процес и по дадено естествено число n намира числото, записано със същите цифри,
  но в обратен ред.
-}

rev :: Int -> Int
rev num = helper num ((count_digits num) - 1) 0
    where
        helper :: Int -> Int -> Int -> Int
        helper num numLen currNum
            | num == 0  = currNum
            | otherwise = helper (num `div` 10) (numLen - 1) (currNum + (num `mod` 10) * 10 ^ numLen)

{-
  Зад. 6. Да се дефинира предикат prime :: Int -> Bool, който проверява дали дадено естествено
  число n е просто.
  Забележка: Числото 1 не е нито просто, нито съставно.
-}

prime :: Int -> Bool
prime num = helper 2 (ceiling (sqrt (fromIntegral num))) num
    where
        helper :: Int -> Int -> Int -> Bool
        helper from to num
            | from == (to + 1)    = True
            | num `mod` from == 0 = False
            | otherwise           = helper (from + 1) to num