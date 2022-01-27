# 1) Para cada uma das expressões seguintes, exprima por enumeração a lista correspondente. Tente ainda, para cada caso, descobrir uma outra forma de obter o mesmo resultado.

## a) `[x | x <- [1..20], mod x 2 == 0, mod x 3 == 0]`

```haskell
[6,12,18]

[x | x <- [1..20], mod x 6 == 0]
```

## b) `[x | x <- [y | y <- [1..20], mod y 2 == 0], mod x 3 == 0]`

```haskell
[6,12,18]

[x | x <- [1..20], mod x 6 == 0]
```

## c) `[(x,y) | x <- [0..20], y <- [0..20], x+y == 30]`

```haskell
[(10,20),(11,19),(12,18),(13,17),(14,16),(15,15),(16,14),(17,13),(18,12),(19,11),(20,10)]

[(x, 30 - x) | x <- [10..20]]
```

## d) `[sum [y | y <- [1..x], odd y] | x <- [1..10]]`

```haskell
[1,1,4,4,9,9,16,16,25,25]

[ x^2 | x <- [1..5], y <- [1..2]]
```

# 2) Defina cada uma das listas seguintes por compreensão.

## a) `[1,2,4,8,16,32,64,128,256,512,1024]`

```haskell
[ 2^x | x <- [0..10]]
```

## b) `[(1,5),(2,4),(3,3),(4,2),(5,1)]`

```haskell
[(x,y) | x <- [1..5], y <- [1..5], x + y == 6]
```

## c) `[[1],[1,2],[1,2,3],[1,2,3,4],[1,2,3,4,5]]`

```haskell
[[1..x] | x <- [1..5]]
```

## d) `[[1],[1,1],[1,1,1],[1,1,1,1],[1,1,1,1,1]]`

```haskell
[ replicate x 1 | x <- [1..5]]
```

## e) `[1,2,6,24,120,720]`

```haskell
[ product [y | y <- [1..x]] | x <- [1..6]]

-- A função `product` calcula o produto de todos os elementos da lista.
```

# 3) Defina a função `digitAlpha :: String -> (String,String)`, que dada uma string, devolve um par de strings: uma apenas com as letras presentes nessa string, e a outra apenas com os números presentes na string. Implemente a função de modo a fazer uma única travessia da string. Relembre que as funções `isDigit`, `isAlpha :: Char -> Bool` estão já definidas no módulo `Data.Char`.

```haskell
digitAlpha :: String -> (String,String)
digitAlpha "" = ("","")
digitAlpha (h:t)
    | isAlpha h = (h:letters, digits)
    | isDigit h = (letters, h:digits)
    | otherwise = (letters, digits)
    where (letters, digits) = digitAlpha t
```

# 4) Defina a função `nzp :: [Int] -> (Int,Int,Int)` que, dada uma lista de inteiros, conta o número de valores nagativos, o número de zeros e o número de valores positivos, devolvendo um triplo com essa informação. Certifique-se que a função que definiu percorre a lista apenas uma vez.

```haskell
nzp :: [Int] -> (Int,Int,Int)
nzp [] = (0,0,0)
nzp (h:t)
    | h < 0 = (n + 1, z, p)
    | h == 0 = (n, z + 1, p)
    | otherwise = (n, z, p + 1)
    where (n, z, p) = nzp t
```

# 5) Defina a função `divMod :: Integral a => a -> a -> (a, a)` que calcula simultaneamente a divisão e o resto da divisão inteira por subtrações sucessivas.

```haskell
divMod :: Integral a => a -> a -> (a, a)
divMod x y 
    | x <= 0 = if y < 0 then divMod (-x) (-y) else (0, x)
    | y < 0 = let (q', r') = divMod x (-y) in (-q', r')
    | x >= y = (1 + q, 0)
    | otherwise = (q, x)
    where (q, r) = divMod (x - y) y

-- Esta função infelizmente não devolve o resultado correto se o denominador for negativo, visto que usamos o denominador nulo ou negativo como indicador do caso de paragem. Para corrigir este problema, teríamos que ter uma função auxiliar que invertesse o sinal do denominador antes de correr a função principal, e que no fim inverteria o sinal do quociente.
```

# 6) Utilizando uma função auxiliar com um acumulador, otimize a seguinte definição recursiva que determina qual o número que corresponde a uma lista de digitos.

```
fromDigits :: [Int] -> Int
fromDigits [] = 0
fromDigits (h:t) = h*10^(length t) + fromDigits t
```

# Note que `fromDigits [1,2,3,4]` = 1 * 10<sup>3</sup> + 2 * 10<sup>2</sup> + 3 * 10<sup>1</sup> + 4 * 10<sup>0</sup> = 4 + 10 (3 + 10 (2 + 10 (1 + 10 * 0)))

```haskell
fromDigits :: [Int] -> Int
fromDigits l = fromDigitsAux l 0

fromDigitsAux :: [Int] -> Int -> Int
fromDigitsAux [] acc = acc
fromDigitsAux (h:t) acc = fromDigitsAux t (h + 10 * acc)
```

# 7) Utilizando uma função auxiliar com acumuladores, otimize seguinte definição que determina a soma do segmento inicial de uma lista com soma máxima.

```
maxSumInit :: (Num a, Ord a) => [a] -> a
maxSumInit l = maximum [sum m | m <- inits l]
```

```haskell
maxSumInit :: (Num a, Ord a) => [a] -> a
maxSumInit (h:t) = maxSumInitAux l h h

maxSumInitAux :: (Num a, Ord a) => [a] -> a -> a -> a
maxSumInitAux [] _ x = x
maxSumInitAux (h:t) prevSum prevMax = maxSumInitAux t newSum (if newSum > prevMax then newSum else prevMax)
    where newSum = prevSum + h
```

# 8) Otimize a seguinte definição recursiva da função que calcula o n-ésimo número da sequência de Fibonacci, usando uma função auxiliar com 2 acumuladores que representam, respectivamente, o n-ésimo e o n+1-ésimo números dessa sequência.

```
fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n-1) + fib (n-2)
```

```haskell
fib :: Int -> Int
fib n = fibAux n 0 1

fibAux :: Int -> Int -> Int -> Int
fibAux 0 n _ = n
fibAux n fib_n fib_n_plus_1 = fibAux (n - 1) fib_n_plus_1 (fib_n + fib_n_plus_1)
```
