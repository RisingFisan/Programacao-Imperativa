# 1) Apresente definições das seguintes funções de ordem superior, já pré-definidas no `Prelude` ou no `Data.List`:

## a) `any :: (a -> Bool) -> [a] -> Bool` que teste se um predicado é verdade para algum elemento de uma lista; por exemplo: `any odd [1..10] == True`.

```haskell
any :: (a -> Bool) -> [a] -> Bool
any f [] = False
any f (h:t) = f h || any f t
```

## b) `zipWith :: (a->b->c) -> [a] -> [b] -> [c]` que combina os elementos de duas listas usando uma função específica; por exemplo: `zipWith (+) [1,2,3,4,5] [10,20,30,40] == [11,22,33,44]`.

```haskell
zipWith :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith f (a:as) (b:bs) = f a b : zipWith f as bs
zipWith _ _ _ = []
```

## c) `takeWhile :: (a->Bool) -> [a] -> [a]` que determina os primeiros elementos da lista que satisfazem um dado predicado; por exemplo: `takeWhile odd [1,3,4,5,6,6] == [1,3]`.

```haskell
takeWhile :: (a -> Bool) -> [a] -> [a]
takeWhile _ [] = []
takeWhile f (h:t) | f h = h : takeWhile f t
                  | otherwise = []
```

## d) `dropWhile :: (a->Bool) -> [a] -> [a]` que elimina os primeiros elementos da lista que satisfazem um dado predicado; por exemplo: `dropWhile odd [1,3,4,5,6,6] == [4,5,6,6]`.

```haskell
dropWhile :: (a -> Bool) -> [a] -> [a]
dropWhile _ [] = []
dropWhile f (h:t) | f h = dropWhile f t
                  | otherwise = t
```

## e) `span :: (a-> Bool) -> [a] -> ([a],[a])` que calcula simultaneamente os dois resultados anteriores. Note que apesar de poder ser definida à custa das outras duas, usando a definição:

## `span p l = (takeWhile p l, dropWhile p l)`

## nessa definição há trabalho redundante que pode ser evitado. Apresente uma definição alternativa onde não haja duplicação de trabalho.

```haskell
span :: (a-> Bool) -> [a] -> ([a],[a])
span _ [] = ([],[])
span f (h:t) | f h = (h:s1,s2)
             | otherwise = ([],h:t)
    where (s1,s2) = span f t 
```

## f) deleteBy :: (a -> a -> Bool) -> a -> [a] -> [a] que apaga o primeiro elemento de uma lista que é “igual” a um dado elemento de acordo com a função de comparação que é passada como parâmetro. Por exemplo: `deleteBy (\x y -> snd x == snd y) (1,2) [(3,3),(2,2),(4,2)]`.

```haskell
deleteBy :: (a -> a -> Bool) -> a -> [a] -> [a]
deleteBy f x (h:t) | f x h = t
                   | otherwise = h : deleteBy f x t
```

## g) sortOn :: Ord b => (a -> b) -> [a] -> [a] que ordena uma lista comparando os resultados de aplicar uma função de extração de uma chave a cada elemento de uma lista. Por exemplo: `sortOn fst [(3,1),(1,2),(2,5)] == [(1,2),(2,5),(3,1)]`.

```haskell
sortOn :: (Ord b) => (a -> b) -> [a] -> [a]
sortOn f [] = []
sortOn f (h:t) = insere h (sortOn f t)
    where insere x [] = [x]
          insere x (a:b) = if f x > f a then a:insere x b else x:a:b
```

# 2) Relembre a questão sobre polinómios introduzida na Ficha 3, onde um polinómio era representado por uma lista de monómios representados por pares _(coeficiente, expoente)_

```
type Polinomio = [Monomio]
type Monomio = (Float,Int)
```

# Por exemplo, `[(2,3), (3,4), (5,3), (4,5)]` representa o polinómio 2x<sup>3</sup> + 3x<sup>4</sup> + 5x<sup>3</sup> + 4x<sup>5</sup>. Redefina as funções pedidas nessa ficha, usando agora funções de ordem superior (definidas no `Prelude` ou no `Data.List`) em vez de recursividade explícita:

## a) `selgrau :: Int -> Polinomio -> Polinomio` que seleciona os monómios com um dado grau de um polinómio.

```haskell
selgrau :: Int -> Polinomio -> Polinomio
selgrau n p = filter (\x -> snd x == n) p 
```

## b) `conta :: Int -> Polinomio -> Int` de forma a que (conta n p) indica quantos monómios de grau n existem em p.

```haskell
conta :: Int -> Polinomio -> Int
conta n p = length $ selgrau n p
```

## c) `grau :: Polinomio -> Int` que indica o grau de um polinómio.

```haskell
grau :: Polinomio -> Int
grau ps = foldl (\ac x -> max ac (snd x)) 0 ps
```

## d) `deriv :: Polinomio -> Polinomio` que calcula a derivada de um polinómio.

```haskell
deriv :: Polinomio -> Polinomio
deriv ps = filter (/= (0,0)) $ map (\(b,e) -> if e /= 0 then (b * fromIntegral e, e - 1) else (0,0)) ps
```

## e) `calcula :: Float -> Polinomio -> Float` que calcula o valor de um polinómio para uma dado valor de x.

```haskell
calcula :: Float -> Polinomio -> Float
calcula a = foldl (\ac (b,e) -> ac + b * (a ^ e)) 0
```

## f) `simp :: Polinomio -> Polinomio` que retira de um polinómio os monómios de coeficiente zero.

```haskell
simp :: Polinomio -> Polinomio
simp = filter (\(b,e) -> b /= 0) 
```

## g) `mult :: Monomio -> Polinomio -> Polinomio` que calcula o resultado da multiplicação de um monómio por um polinómio.

```haskell
mult :: Monomio -> Polinomio -> Polinomio
mult (x,y) = map (\(b,e) -> (b*x,y+e))
```

## h) `ordena :: Polinomio -> Polinomio` que ordena um polonómio por ordem crescente dos graus dos seus monómios.

```haskell
ordena :: Polinomio -> Polinomio
ordena = sortOn snd
```

## i) `normaliza :: Polinomio -> Polinomio` que dado um polinómio constrói um polinómio equivalente em que não podem aparecer varios monómios com o mesmo grau.

```haskell
normaliza :: Polinomio -> Polinomio
normaliza [] = []
normaliza ((b,e):ps) = (sum [bs | (bs,es) <- selgrau e ps] + b,e):normaliza [(bo,eo) | (bo,eo) <- ps, eo /= e]
```

## j) `soma :: Polinomio -> Polinomio -> Polinomio` que faz a soma de dois polinómios de forma que se os polinómios que recebe estiverem normalizados produz também um polinómio normalizado.

```haskell
soma :: Polinomio -> Polinomio -> Polinomio
soma p r = normaliza $ (++) p r
```

## k) `produto :: Polinomio -> Polinomio -> Polinomio` que calcula o produto de dois polinómios.

```haskell
produto :: Polinomio -> Polinomio -> Polinomio
produto p1 p2 = foldl (\ac x -> soma (mult x p2) ac) [] p1
```

## l) `equiv :: Polinomio -> Polinomio -> Bool` que testa se dois polinómios são equivalentes.

```haskell
equiv :: Polinomio -> Polinomio -> Bool
equiv p1 p2 = null (simp (soma p1 (mult (-1,0) p2)))

equiv' :: Polinomio -> Polinomio -> Bool
equiv' p1 p2 = ordena (normaliza p1) == ordena (normaliza p2)
```

# 3) Considere a sequinte definição para representar matrizes:

# `type Mat a = [[a]]`

# Por exemplo, a matriz (triangular superior)

```
| 1 2 3 |
| 0 4 5 |
| 0 0 6 |
```

# seria representada por: `[[1,2,3], [0,4,5], [0,0,6]]`.
<br>
# Defina as seguintes funções sobre matrizes (use, sempre que achar apropriado, funções de ordem superior).

## a) `dimOK :: Mat a -> Bool` que testa se uma matriz está bem construída (i.e., se todas as linhas têm a mesma dimensão).

```haskell
dimOK :: Mat a -> Bool
dimOK (h:t) = all (\x -> length h == length x) t
```

## b) `dimMat :: Mat a -> (Int,Int)` que calcula a dimensão de uma matriz.

```haskell
dimMat :: Mat a -> (Int, Int)
dimMat m = (length m, length (head m))
```

## c) `addMat :: Num a => Mat a -> Mat a -> Mat a` que adiciona duas matrizes.

```haskell
addMat :: Num a => Mat a -> Mat a -> Mat a
addMat = zipWith (zipWith (+))
``` 

## d) `transpose :: Mat a -> Mat a` que calcula a transposta de uma matriz.

```haskell
transpose :: Mat a -> Mat a
transpose m = [ [(m !! j) !! i | j <- [0..l-1] ] | i <- [0..c-1]]
    where (l,c) = dimMat m
``` 

## e) `multMat :: Num a => Mat a -> Mat a -> Mat a` que calcula o produto de duas matrizes.

```haskell
multMat :: Num a => Mat a -> Mat a -> Mat a
multMat m1 m2 = [ [ sum (zipWith (*) (m1 !! j) [ x !! i | x <- m2 ]) | i <- [0..c-1] ] | j <- [0..l-1] ]
    where (l,_) = dimMat m1
          (_,c) = dimMat m2
``` 

## f) `zipWMat :: (a -> b -> c) -> Mat a -> Mat b -> Mat c` que, à semelhança do que acontece com a função zipWith, combina duas matrizes. Use essa função para definir uma função que adiciona duas matrizes.

```haskell
zipWMat :: (a -> b -> c) -> Mat a -> Mat b -> Mat c
zipWMat = zipWith . zipWith

addMat' :: Num a => Mat a -> Mat a -> Mat a
addMat' = zipWMat (+)
```

## g) `triSup :: Num a => Mat a -> Bool` que testa se uma matriz quadrada é triangular superior (i.e., todos os elementos abaixo da diagonal são nulos).

```haskell
triSup :: Real a => Mat a -> Bool
triSup = snd . foldl (\(ac1,ac2) line -> (ac1+1, all (== 0) (take ac1 line) && ac2)) (0,True)
```

## h) `rotateLeft :: Mat a -> Mat a` que roda uma matriz 90o para a esquerda. Por exemplo, o resultado de rodar a matriz acima apresentada deve corresponder à matriz:

```
| 3 5 6 |
| 2 4 0 |
| 1 0 0 |
```

```haskell
rotateLeft :: Mat a -> Mat a
rotateLeft m = [ [ map (!! i) m !! j | j <- [0..l-1] ] | i <- [c-1,c-2..0]] 
    where (l,c) = dimMat m
```