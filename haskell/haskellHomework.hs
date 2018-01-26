import Data.List

main :: IO()
main = do
    print(calcLuhnChecksum 7992739871)
    print(gameOfLife [(0,0),(0,1),(1,0),(1,1)])
    print(gameOfLife [(0,-1),(0,0),(0,1)])
    print(gameOfLife [(0,1),(1,2),(2,0),(2,1),(2,2)])


{-Task 1-}
calcLuhnChecksum :: Integer -> Integer
calcLuhnChecksum n = (sum (multiplyIndices (reverse (getNumDigs n))) * 9) `mod` 10
    where
        getNumDigs n
            | n < 0            = getNumDigs(abs n)
            | n >= 0 && n <= 9 = [n]
            | otherwise        = (n `mod`10) : (getNumDigs (n `div` 10))
        multiplyIndices ns     = fixTen [if (fst x) `mod` 2 == 0 then (snd x) * 2 else (snd x) | x <- (zip [1..(length ns)] ns)]
        fixTen ys              = [if x > 9 then sum (getNumDigs x) else x | x <- ys]


{-Task 2-}
gameOfLife :: [(Int, Int)] -> [(Int, Int)]
gameOfLife board = getNewBoard livingCells
    where
        getNewBoard = helper []
            where
                helper checked [] = checked
                helper checked (x:rest)
                    | x `elem` checked = helper checked rest
                    | otherwise     = helper (checked ++ [x]) rest

        livingCells = [pos | pos <- [(i + genI, j + genJ) | (i, j) <- board, genI <- [-1..1], genJ <- [-1..1]], getNewStatus pos]
            where
                getNewStatus (x, y)
                    | length neigh == 3 || length neigh == 4 = True
                    | otherwise                              = False
                        where
                            neigh           = [elem | elem <- board, validate elem]
                            validate (i, j) = i >= x - 1 && i <= x + 1 && j >= y - 1 && j <= y + 1
            

{-Task 3-}
data Tree a = Empty | Node a (Tree a) (Tree a) deriving (Read, Show)
isBalanced :: Tree a -> Int -> Bool
isBalanced Empty _               = True
isBalanced (Node _ left right) k = (abs ((getDepth left) - (getDepth right)) <= k) && (isBalanced left k) && (isBalanced right k)
    where
        getDepth Empty               = 0
        getDepth (Node _ left right) = 1 + max (getDepth left) (getDepth right)