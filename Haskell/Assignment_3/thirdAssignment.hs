-- Assignment 3: Hogher Order Functions and Modules

-- 1. Function to double the numbers in a list
multiplyByTwo :: [Int]
multiplyByTwo = map (*2) [1, 5, -18, 99]

-- 2. Function to filter out all even numbers from 1-100
filterEvens :: [Int]
filterEvens = filter even [1..100]

-- 3. Function that uses a map to triple numbers
multiplyByThree :: [Int]
multiplyByThree = map (*3) [1,3..77]

-- 4. Function calculate the sum of the squares of all odd numbers in a list
sumOdds :: Int
filterOdds = filter odd [1,2,3,4,5,7,8,1,43,25,65,22]
squareOdds = map (^2) filterOdds
sumOdds = sum squareOdds

main :: IO ()
main = do
    putStrLn "1. Double the numbers in this list [1,5,-18,99]:"
    print multiplyByTwo
    putStrLn "2. Filter out all even numbers from 1-100:"
    print filterEvens
    putStrLn "3. Triple the numbers in this list [1, 3..77]:"
    print multiplyByThree
    putStrLn "4. Find the sum of the squares of the odd numbers in this list [1,2,3,4,5,7,8,1,43,25,65,22]:"
    print sumOdds


