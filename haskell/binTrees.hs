main::IO()
main = do
 print bt
 print bt2
 print (btCount bt2)
 print (btInsert 6 bt2)
 print (btSort [1,5,0,2,7,3,9])
 
data BTree = NilT | Node Int BTree BTree 
deriving Show

bt::BTree
bt=NilT

bt2::BTree
bt2=Node 5 (Node 4 NilT NilT) (Node 7 NilT (Node 9 NilT NilT)) 

--брой възли
btCount::BTree->Int
btCount NilT=0
btCount (Node _ lt rt) = 1 + btCount lt + btCount rt


--сума
btSum::BTree->Int
btSum Nilt = 0
btSum (Node x lt rt) = x + btSum lt + btSum rt

--вмъкване 
btInsert::Int->BTree->BTree
btInsert x NilT=Node x NilT NilT
btInsert x (Node y lt rt)
 | x < y = Node y (btInsert x lt) rt
 | x > y = Node y lt (btInsert x rt)
 |otherwise = bt
 
--обхождане
inorder::BTree -> [Int]
inorder NilT = []
inorder (Node x lt rt) = inorder lt ++ [x] ++ inorder rt 

--сортиране на списък, чрез двоично наредено дърво
btSort::[Int]->[Int]
btSort = inorder . (foldr btInsert NilT)