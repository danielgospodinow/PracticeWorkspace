main :: IO()
main = do 
 print "123"
 print ((\ x -> x) 4) -- lambda
 print ((\ x y z -> x + y + z) 4 5 6 ) --lambda
 print (f1 4 5 6)
 print (f2 5 f3)
 print (f2 5 (\ x -> x +1))
 
 
f1 :: Int -> Int ->Int ->Int
f1 = (\ x y z -> x + y + z)  -- nelambda

f3 ::Int->Int
f3 x = 2 * x

f2:: Int->(Int->Int) -> Int --взима число и функция и връща число 
f2 n func = func (n + 1)

--f4::Int -> (Int->(Int->Int)) еквивалентни са 
--f4::Int->Int->Int->Int

--fun koqto vrushta fun 
f5 ::Int-> Int-> (Int->Int) -- vse taq dali shte ima skobi ili ne, no ako tr da vurnem fun - taka e
f5 k n = (\ x -> (k + n) * x) --s lambda
f5 k n x = (k + n) * x   -- bez lambda
