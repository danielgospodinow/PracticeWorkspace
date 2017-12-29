main :: IO ()
main = do
  fact(7)

fact :: Int -> Int
fact 0 = 1
fact n = n * fact(n-1)
