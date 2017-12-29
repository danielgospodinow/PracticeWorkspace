main :: IO ()
main = do
 --print="abc"
 print(countDigits 0)
 print(countDigits 10)
 print(countDigits 123)
 print(5/10)
 print(div 5 10)
 --print(5 div 10)
 --print(f2 11.5 2) --грешка заради типовете
 
{-fact :: Int->Int
fact 0 = 1
fact n = n * fact(n-1)

f1 :: Int-> Bool
f1 _ = 0-}

{-f2::Float->Int->Float
f2 n k = n/k-}

{- зад 1. Да се дефинира count_digits :: Int->Int, която генерира линейно
рекурсивен процес и намира броя на цифрите на дадено естествено число n-}
countDigits::Int->Int
countDigits n = if n < 10 then 1 else 1 + countDigits (n div 10)

{-зад 2. сумата от цифрите на число-}
sumDigits::Int->Int
sumDigits n = 
 if n < 10
 then n
 else n mod 10 + sumDigits (n div 10)
 
 
{-зад 3. pow:: Double-> Int-> Double, повдига +х на степен n; х е реално , n  - естествено число-}
pow :: Double -> Int -> Double
pow _ 0 = 1 -- _ e неименуван аргумент ( първият аргумент е без значение, ще се влезе там само ако 2 арг е 0)
pow x n = x * pow x (n-1)
--pow x n = if (n == 0) then 1 else x* pow x (n - 1) -- алтернатива



{- зад 4. Зад. 4. Да се дефинира процедура sum_digits_iter :: Int -> Int, която генерира линейно
  итеративен процес и намира сумата от цифрите на дадено естествено число n.
-}
sumDigitsIter :: Int->Int
sumDigitsIter n = helper n 0
 where --локална деф на функция 
 helper::Int->Int->Int
 helper 0 res = res
 helper n res = helper (n div 10) (res + (n mod 10))

{-f3::Int->Int->Int
f3 k n = z + z
 where z = k + n-}
 
 
 {-
  Зад. 5. Да се дефинира процедура rev :: Int -> Int, която генерира линейно итеративен
  процес и по дадено естествено число n намира числото, записано със същите цифри,
  но в обратен ред.
-}

rev::Int->Int
rev n = helper n 0
 where
  helper::Int->Int->Int
  helper 0 res = res
  helper n res = helper (n div 10) ((res * 10) + (n mod 10))
  
{-
  Зад. 6. Да се дефинира предикат prime :: Int -> Bool, който проверява дали дадено естествено
  число n е просто.
  Забележка: Числото 1 не е нито просто, нито съставно.
-}

prime:: Int->Bool
prime 1 = False
prime 2 = True
prime 3 = True 
prime n = helper n 0 
 where 
 helper:: Int->Int->Int
 helper 2 = True
 helper n d 
  | n == d = True
  | mod n d == 0 = False
  | otherwise = helper n (d + 1)
