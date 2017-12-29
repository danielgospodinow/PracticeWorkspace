main :: IO()
main = do
  print( (maxi [(\ x -> (-x)), (\ x -> x * 2)]) 4 )

maxi :: [(Int -> Int)] -> (Int -> Int)
maxi fs = (\ x -> helper (tail fs) (head fs) x)
  where
    helper :: [(Int -> Int)] -> (Int -> Int) -> Int -> Int
    helper fs res x
      | null fs = res x
      | abs((head fs) x) > abs(res x) = helper (tail fs) (head fs) x
      | otherwise = helper (tail fs) res x
