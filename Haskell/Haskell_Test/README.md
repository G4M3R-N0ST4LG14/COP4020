# COP 4020 Haskell Test

1. Test Problem One

Count from 1 to n. Each number that is even and a multiple of 5 and has a leading digit of 6 should be added to a list. Submit this as TestProblem1.hs
solveProblem1 n. Solve with list comprehension. (Helper functions can be recursive or list comprehensions).

>solveProblem1 10
> -[]
>solveProblem1 100
> -[60]
>solveProblem1 1000
> -[60,600,610,620,630,640,650,660,670,680,690]

Solve for n=10000 amd n=100000

2. test problem two, 33 points -------------------------------------------------------

Count from 1 to n and keep all primes that are palindromes. Some of the numbers remaining in the list have even digits. Add up all of the even digits. Remember, just the digit values. For instance the number 541 has a digit of 4 so you would add 4 from that number (not 40). Submit this as TestProblem2.hs. You can solve this recursively or with recursion.

solveProblem2 n

solveProblem2 10
2
solveProblem2 100
2
solveProblem2 1000
30
solveProblem2 10000
30

 Now solve for n=100000 and n=1000000

3. test problem three, 33 points ------------------------------------------------------

Count from 1 to n and create a list of prime factors for each number. (For factors do not include 1 or the number itself.) Find the sum of all prime factors when you count from 1 to n.

For instance, if n is 10 then the list of numbers is [2,3,4,5,6,7,8,9]. Then the list of all prime factors is [[],[],[2],[],[2,3],[],[2],[3]]. Note that 9 has two factors of 3 but only counts a single instance of 3--factors are distinct. The sum of this is 12.

Solve this with recursion. (Helper functions can be recursive or list comprehensions).

solveProblem3 n

solveProblem3 10
12
solveProblem3 100
1040
solveProblem3 1000
64366

Now solve for 3000