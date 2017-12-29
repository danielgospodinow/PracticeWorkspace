main :: IO()
main = do
  print(p)
  print(t)
  print(null [])
  print(null p)
  print(head p)
  print(tail p)
  print(length p)
  print(0:1:[]) -- [0, 1]
  print([0,1] ++ [2, 3]) -- [0, 1, 2, 3]
  print([0,1,2,3,4] !! 2) -- 2
  print( (\ x y -> x + y) 1 2) -- 3

  print(map (\x -> x*2) [1,2,3])
  print((filter (>5) [1,2,7,8]))
  print((map ((*2).(+1)) [1,2,3]))


t :: [Int]
t = []

p :: [Int]
p = [1,2,3,4,5,6]
