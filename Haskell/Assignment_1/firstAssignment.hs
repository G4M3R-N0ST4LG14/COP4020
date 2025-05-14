-- Asignment 1: Functions and List Comprehensions

-- 1. Function that multiplies two numbers
multTwo :: Integer -> Integer -> Integer
multTwo x y = x * y

-- 2. Function that multiplies three numbers
multThree :: Integer -> Integer -> Integer -> Integer
multThree x y z = x * y * z

-- 3. Funtion that finds every number from 1 to n that is a multiple of 6 or a multiple of 11.
first_a :: Integer -> [Integer]
first_a n = [x | x <- [1..n], x `mod` 6 == 0 || x `mod` 11 == 0]

-- 4. Function that is the same as #3 but uses a helper function.
isMult6Or11 :: Integer -> Bool
isMult6Or11 x = x `mod` 6 == 0 || x `mod` 11 == 0

first_b :: Integer -> [Integer]
first_b n = [x | x <- [1..n], isMult6Or11 x]

-- 5. Funtion that finds every number from 1 to n that is a palindrome that starts with the digit 3
second_a :: Integer -> [Integer]
second_a n = [x | x <- [1..n], show x == reverse (show x) && head (show x) == '3']

-- 6. Function that is the same as #5 but uses a helper function.
isPalindromeThatStartsWithDigit3 :: Integer -> Bool
isPalindromeThatStartsWithDigit3 x = let s = show x in s == reverse s && head s == '3'

second_b :: Integer -> [Integer]
second_b n = [x | x <- [1..n], isPalindromeThatStartsWithDigit3 x]

main = do
    putStrLn "1. The multiplication of two numbers where x = 3 and y = 5:"
    print(multTwo 3 5)
    putStrLn "2. The multiplication of three numbers where x = 3, y = 5 and z = 7:"
    print(multThree 3 5 7)
    putStrLn "3. The multiples of 6 and 11 from 1 to n where n is 365:"
    print(first_a 365)
    putStrLn "4. The multiples of 6 and 11 from 1 to n where n is 200:"
    print(first_b 200)
    putStrLn "5. The Palindromes in between 1 and n where n is 500 and that starts with the digit 3:"
    print(second_a 500)
    putStrLn "6. The Palindromes in between 1 and n where n is 4000 and that starts with the digit 3 "
    print(second_b 4000)