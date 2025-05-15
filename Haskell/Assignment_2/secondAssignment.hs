-- Assignment 2: Functions and List Comprehensions

-- 1. Function that will take a single integer parameter. It indicates the number of primes that will be the final list. The final solution will output a list of every other prime.
-- Helper function to check if a number is a prime
isPrime :: Int -> Bool
isPrime x
    | x < 2 = False -- Numbers less than 2 are not prime numbers
    | x == 2 = True -- 2 is a prime number
    | even x = False -- Even numbers are not prime numbers
    -- Checks to see if any odd numbers up to the square root of x can divide the number to see if it's prime
    | otherwise = null [y | y <- [3,5..floor (sqrt (fromIntegral x))], x `mod` y ==0] 

-- Main function to generate the list of every other prime
primes = filter isPrime [2..] -- Create an infinite list of primes
problem1 :: Int -> [Int]
-- Put primes in an index where the even indices starting at 0 get added to the final list and the odds get filtered
problem1 n = take n [x | (x, y) <- zip primes [0..], even y] 


-- 2. Function to indicate the maximum value of Fibonacci numbers that have a three as their right-most digit and are less than or equal to n.
problem2 :: Int -> [Int]
-- Creates Fibonacci sequence with recursion by adding a and b together and creating an infinite list where b is the next starting number in the addition
generateFibs a b = a : generateFibs b (a + b) 
fibs = generateFibs 1 2 -- Starts Fibonacci sequence at 1 and 2
hasThree x = x `mod` 10 == 3 -- Checks to see if the final digit is 3
problem2 n = filter hasThree (takeWhile (<= n) fibs) -- Filters out numbers from list that don't end with 3


-- 3. Function that finds numbers that are a multiple of five or have exactly three factors.
problem3 :: Int -> [Int]
isPerfectSquare x = floor (sqrt (fromIntegral x))^2 == x -- Check to see if square root of x is a whole number
isMultipleOfFive x = x `mod` 5 == 0 -- Check to see if x is a multiple of 5
-- If the number x has a whole square root and the square root is a prime number then it is guaranteed to have only 3 factors (1, sqrt(x), and x)
hasExactlyThreeFactors x = isPerfectSquare x && isPrime (floor (sqrt (fromIntegral x))) 
problem3 n = [x | x <- [2..n], isMultipleOfFive x || hasExactlyThreeFactors x] -- Gets all numbers up to n that are either multiples of five or have exactly three factors

main :: IO ()
main = do
    putStrLn"1. Looking for every other prime number until reaching 10 and 7 total numbers: "
    print(problem1 10)
    print(problem1 7)
    putStrLn"2. Filtering out the Fibonacci numbers that end with the digit 3 up to 100 and 10000: "
    print(problem2 100)
    print(problem2 10000)
    putStrLn"3. Generate a list of the multiples of 5 and numbers with exactly 3 factors: "
    print(problem3 100)
