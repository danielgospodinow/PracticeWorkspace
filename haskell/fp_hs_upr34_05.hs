{- C++ enum -}
-- Сезони
data Season = Spring | Summer | Autumn | Winter deriving (Read, Show)

-- Месеци
data Month = January | February | March | April | May | June | July | August | September | October | Novemer | December deriving (Read, Show)

{- C++ struct or (tagged) union -}
data Person = Person String Int
-- record syntax:
-- data Person = Person { name :: String, age :: Int }
--     deriving (Read, Show)
data Book = Book { bookTitle :: String, bookPublished :: Int, bookSales :: Int } deriving (Read, Show)

data Shape = Circle Double | Square Double  deriving (Read, Show)

{- C++ container classes -}
-- Списък от произволни елементи (от тип a)
data List a = Nil | Cons a (List a) deriving (Read, Show)

-- Tree a, описващ произволно двоично дърво, чийто стойности са от тип a.
data Tree a = Empty | Node a (Tree a) (Tree a) deriving (Read, Show)


{- Примери -}
-- Дълбочина на двоично дърво:
treeDepth :: (Num b, Ord b) => Tree a -> b
treeDepth Empty = 0
treeDepth (Node _ left right) = 1 + max (treeDepth left) (treeDepth right)

-- Брой на листата на двоично дърво:
treeCountLeaves :: (Num b) => Tree a -> b
treeCountLeaves Empty = 0
treeCountLeaves (Node _ Empty Empty) = 1
treeCountLeaves (Node _ left right) = treeCountLeaves left + treeCountLeaves right

-- Сбор на всички стойности на върховете на двоично дърво:
treeSum :: Num a => Tree a -> a
treeSum Empty = 0
treeSum (Node x left right) = x + treeSum left + treeSum right

-- Списък със стойностите на всички вървове на ниво k:
nodesOnLevel :: (Integral b) => Tree a -> b -> [a]
nodesOnLevel Empty _ = []
nodesOnLevel (Node v left right) k
    | k < 0     = []
    | k == 0    = [v]
    | otherwise = nodesOnLevel left (k-1) ++ nodesOnLevel right (k-1)  


{- Задачи -}
{-
Задача 1. Дефинирайте функцията listSpecial tree, която приема двоично дърво tree
и връща списък от тези стойности на върховете на tree, които са равни на сбора на 
стойностите на децата си.

Примери:
tree11 = (Node 3 
            (Node 1 
                (Node 1 Empty Empty)
                Empty)
            (Node 2 
                (Node 4 Empty Empty)
                (Node 7 Empty Empty)))

listSpecial tree11 -> [3, 1]
-}
listSpecial :: (Eq a, Num a) => Tree a -> [a]
listSpecial Empty                = []
listSpecial (Node _ Empty Empty) = []
listSpecial (Node x left right)
    | x == sumChildren left right = [x] ++ listSpecial left ++ listSpecial right
    | otherwise                   = listSpecial left ++ listSpecial right
        where
            sumChildren Empty Empty               = 0
            sumChildren Empty (Node x _ _)        = x
            sumChildren (Node x _ _) Empty        = x
            sumChildren (Node x _ _) (Node y _ _) = x + y


{-
Задача 2. Дефинирайте функцията areMirrorImages tree1 tree2, която приема две двойчни
дървета tree1 и tree2 и връща дали те са огледални образи едно на друго.

Примери:
tree21 = (Node 4 
            (Node 3 
                (Node 1 Empty Empty)
                (Node 2 Empty Empty))
            (Node 5 
                Empty
                (Node 6 Empty Empty)))
tree22 = (Node 4 
            (Node 5 
                (Node 6 Empty Empty)
                Empty)
            (Node 3 
                (Node 2 Empty Empty)
                (Node 1 Empty Empty)))
tree23 = (Node 4 
            (Node 5 
                (Node 6 Empty Empty)
                Empty)
            (Node 3 
                (Node 1 Empty Empty)
                (Node 2 Empty Empty)))

areMirrorImages tree21 tree22 -> True
areMirrorImages tree21 tree23 -> False    
-}
areMirrorImages :: (Eq a) => Tree a -> Tree a -> Bool
areMirrorImages Empty Empty                   = True
areMirrorImages Empty _                       = False
areMirrorImages _ Empty                       = False
areMirrorImages (Node x l1 r1) (Node y l2 r2) = x == y && areMirrorImages l1 r2 && areMirrorImages r1 l2


{-
Пордредени (сортирани) двоични дървета: 
- Всеки вътрешен възел складира ключ (и по избор и стойност свъзрана с ключа).
- Ключът във всеки възел трябва да е по-голям от всички ключове пазени влявото поддърво 
и по-малък от всички ключове пазени в дясното поддърво.
-}

{-
Задача 3. Дефинирайте функцията isBST tree, която приема двоично дърво tree и връща
дали е подредено.

Примери:
tree31 = (Node 4 
            (Node 2 
                (Node 1 Empty Empty)
                (Node 3 Empty Empty))
            (Node 5 
                Empty
                (Node 6 Empty Empty)))
tree32 = (Node 4 
            (Node 2 
                (Node 1 Empty Empty)
                (Node 3 Empty Empty))
            (Node 5 
                (Node 6 Empty Empty)
                Empty))

isBST tree31 -> True
isBST tree32 -> False
-}
isBST :: (Ord a) => Tree a -> Bool
isBST Empty = True
isBST (Node x left right)
    | (isBigger x left) && (isSmaller x right) = isBST left && isBST right
    | otherwise                                = False
        where
            isBigger _ Empty         = True
            isBigger x (Node y _ _)  = x > y
            isSmaller _ Empty        = True
            isSmaller x (Node y _ _) = x < y


{-
Задача 4. Дефнирайте функцията bstToList tree, която приема подредено 
двоично дърво tree и връща списък с ключовете на дървото подредени във
възходящ ред.

Примери: 
tree   = (Node 4 
            (Node 2 
                (Node 1 Empty Empty)
                (Node 3 Empty Empty))
            (Node 5 
                Empty
                (Node 6 Empty Empty)))

bstToList tree -> [1, 2, 3, 4, 5, 6]
-}
bstToList :: (Ord a) => Tree a -> [a]
bstToList Empty               = []
bstToList (Node x left right) = bstToList left ++ [x] ++ bstToList  right


{-
Задача 5. Дефинирайте функцията bstSearch tree value, която приема подредено
двоично дърво tree и стойност value и връща дали стойността се среща в дървото.

Примери:
tree   = (Node 4 
            (Node 2 
                (Node 1 Empty Empty)
                (Node 3 Empty Empty))
            (Node 5 
                Empty
                (Node 6 Empty Empty)))

bstSearch tree 1 -> True
bstSearch tree 4 -> True
bstSearch tree 7 -> False
-}
bstSearch :: (Ord a) => Tree a -> a -> Bool
bstSearch Empty _               = False
bstSearch (Node x left right) s = (s == x) || bstSearch left s || bstSearch right s


{-
Задача 6. Дефинирайте функцията bstInsert tree value, която приема подредено
двоично дърво tree и стойност value и добавя value в дървото (като го оставя
наредено).

Примери:
tree   = (Node 4 
            (Node 2 
                (Node 1 Empty Empty)
                (Node 3 Empty Empty))
            (Node 5 
                Empty
                (Node 6 Empty Empty)))

bstInsert tree 7 -> (Node 4 
                        (Node 2 
                            (Node 1 Empty Empty) 
                            (Node 3 Empty Empty)) 
                        (Node 5 
                            Empty 
                            (Node 6 
                                Empty 
                                (Node 7 Empty Empty))))
-}
bstInsert :: (Ord a) => Tree a -> a -> Tree a
bstInsert Empty x = Node x Empty Empty
bstInsert (Node root left right) x
    | x < root = Node root (bstInsert left x) right 
    | x > root = Node root left (bstInsert right x) 


{-
Задача 7. Дефинирайте функцията bstRemove tree value, която приема подредено
двоично дърво tree и стойност value и премахва value от дървото (като го оставя
наредено).

Примери:
tree   = (Node 4 
            (Node 2 
                (Node 1 Empty Empty)
                (Node 3 Empty Empty))
            (Node 5 
                Empty
                (Node 6 Empty Empty)))

bstRemove tree 4 -> (Node 2 
                        (Node 1 Empty Empty) 
                        (Node 3 
                            Empty 
                            (Node 5 
                                Empty 
                                (Node 6 Empty Empty))))
-}
bstRemove :: (Ord a) => Tree a -> a -> Tree a
bstRemove Empty _ = Empty
bstRemove (Node x left right) del
    | del < x   = Node x (bstRemove left del) right
    | del > x   = Node x left (bstRemove right del)
    | otherwise = joinTrees left right
        where
            joinTrees Empty right = right
            joinTrees left Empty  = left
            joinTrees Empty Empty = Empty
            joinTrees left right  = (Node (getRightmost left) (removeRightmost left) right)
                where
                    getRightmost (Node x _ Empty)       = x
                    getRightmost (Node x _ right)       = getRightmost right
                    removeRightmost (Node x _ Empty)    = Empty
                    removeRightmost (Node x left right) = (Node x left (removeRightmost right))


-- main функция с примерни извиквания на функциите от задачите.
main :: IO()
main = let
    tree11 = (Node 3 
                (Node 1 
                    (Node 1 Empty Empty)
                    Empty)
                (Node 2 
                    (Node 4 Empty Empty)
                    (Node 7 Empty Empty)))
    tree21 = (Node 4 
                (Node 3 
                    (Node 1 Empty Empty)
                    (Node 2 Empty Empty))
                (Node 5 
                    Empty
                    (Node 6 Empty Empty)))
    tree22 = (Node 4 
                (Node 5 
                    (Node 6 Empty Empty)
                    Empty)
                (Node 3 
                    (Node 2 Empty Empty)
                    (Node 1 Empty Empty)))
    tree23 = (Node 4 
                (Node 5 
                    (Node 6 Empty Empty)
                    Empty)
                (Node 3 
                    (Node 1 Empty Empty)
                    (Node 2 Empty Empty)))
    tree31 = (Node 4 
                (Node 2 
                    (Node 1 Empty Empty)
                    (Node 3 Empty Empty))
                (Node 5 
                    Empty
                    (Node 6 Empty Empty)))
    tree32 = (Node 4 
                (Node 2 
                    (Node 1 Empty Empty)
                    (Node 3 Empty Empty))
                (Node 5 
                    (Node 6 Empty Empty)
                    Empty))
    -- Зад. 4-7.
    tree   = (Node 4 
                (Node 2 
                    (Node 1 Empty Empty)
                    (Node 3 Empty Empty))
                (Node 5 
                    Empty
                    (Node 6 Empty Empty)))
    in do
        -- Задача 1.
        print $ listSpecial tree11

        -- Задача 2.
        print $ areMirrorImages tree21 tree22
        print $ areMirrorImages tree21 tree23

        -- Задача 3.
        print $ isBST tree31
        print $ isBST tree32

        -- Задача 4.
        print $ bstToList tree

        -- Задача 5.
        print $ bstSearch tree 1
        print $ bstSearch tree 4
        print $ bstSearch tree 7
        
        -- Задача 6.
        print $ bstInsert tree 7

        -- Задача 7.
        print $ bstRemove tree 4 