-- Haskell Test

-- 1. Function that creates a list from 1 to n and prints out the even numbers that are multiples of 5 with first digit of 6
solveProblem1 :: Int -> [Int]
generateList n = [x | x <- [1..n], x `mod` 5 == 0 && head (show x) == '6']
-- Filter out even numbers
solveProblem1 n = filter even (generateList n)