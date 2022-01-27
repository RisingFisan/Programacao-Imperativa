# 1) Indique como é que o interpretador de haskell avalia as expressões das alíneas que se seguem, apresentando a cadeia de redução de cada uma dessas expressões (i.e., os vários passos intermédios até se chegar ao valor final).

## a) Considere a seguinte definição:

```
funA :: [Double] -> Double
funA [] = 0
funA (y:ys) = y^2 + (funA ys)
```

## Diga, justificando, qual é o valor de `funA [2,3,5,1]`.

```haskell
funA [2,3,5,1] = funA (2:[3,5,1]) 
               = 2^2 + funA [3,5,1]
               = 4 + funA (3:[5,1])
               = 4 + 3^2 + funA [5,1]
               = 13 + funA (5:[1])
               = 13 + 5^2 + funA [1] 
               = 38 + funA (1:[])
               = 38 + 1^2 + funA []
               = 39 + 0 = 39
```

## b) Considere a seguinte definição:

```
funB :: [Int] -> [Int]
funB [] = []
funB (h:t) = if (mod h 2)==0 then h : (funB t)
                             else (funB t)
```

## Diga, justificando, qual é o valor de `funB [8,5,12]`.

```haskell
funB [8,5,12] = funB (8:[5,12]) 
              = 8:funB [5,12] 
              = 8:funB (5:[12]) 
              = 8:funB [12] 
              = 8:funB (12:[]) 
              = 8:12:funB [] 
              = 8:12:[] = [8,12]
```

## c) Considere a seguinte definição:

```
funC (x:y:t) = funC t
funC [x] = []
funC [] = []
```

## Diga, justificando, qual é o valor de `funC [1,2,3,4,5]`.

```haskell
funC [1,2,3,4,5] = funC (1:2:[3,4,5]) 
                 = funC [3,4,5] 
                 = funC (3:4:[5]) 
                 = funC [5] = []
```

## d) Considere a seguinte definição:

```
funD l = g [] l
g l [] = l
g l (h:t) = g (h:l) t
```

## Diga, justificando, qual é o valor de `funD "otrec"`.

```haskell
funD "otrec" = g [] "otrec" 
             = g [] 'o':"trec" 
             = g 'o':[] "trec" 
             = g ['o'] 't':"rec" 
             = g 't':['o'] "rec" 
             = g "to" 'r':"ec" 
             = g 'r':"to" "ec" 
             = g "rto" 'e':['c'] 
             = g 'e':"rto" ['c'] 
             = g "erto" 'c':[] 
             = g 'c':"erto" [] = "certo"
```

# 2) Defina recursivamente as seguintes funções sobre listas:

## a) `dobros :: [Float] -> [Float]` que recebe uma lista e produz a lista em que cada elemento é o dobro do valor correspondente na lista de entrada.

```haskell
dobros :: [Float] -> [Float]
dobros [] = []
dobros (h:t) = 2*h : dobros t
```

## b) `numOcorre :: Char -> String -> Int` que calcula o número de vezes que um caracter ocorre numa string.

```haskell
numOcorre :: Char -> String -> Int
numOcorre _ [] = 0
numOcorre x (c:str) = if x == c then 1 + numOcorre x str 
                                else numOcorre x str
```

## c) `positivos :: [Int] -> Bool` que testa se uma lista só tem elementos positivos.

```haskell
positivos :: [Int] -> Bool
positivos [] = True
positivos (n:ns)
    | n < 0 = False
    | otherwise = positivos ns
```

## d) `soPos :: [Int] -> [Int]` que retira todos os elementos não positivos de uma lista de inteiros.

```haskell
soPos :: [Int] -> [Int]
soPos [] = []
soPos (n:ns)
    | n < 0 = soPos ns
    | otherwise = n : soPos ns
```

## e) `somaNeg :: [Int] -> Int` que soma todos os números negativos da lista de entrada.

```haskell
somaNeg :: [Int] -> Int
somaNeg [] = 0
somaNeg (n:ns) = if n < 0 then n + somaNeg ns 
                          else somaNeg ns
```

## f) `tresUlt :: [a] -> [a]` devolve os últimos três elementos de uma lista. Se a lista de entrada tiver menos de três elementos, devolve a própria lista.

```haskell
tresUlt :: [a] -> [a]
tresUlt l = case l of (_:b:c:d:xs) -> tresUlt (b:c:d:xs)
                      _ -> l
```

## g) `segundos :: [(a,b)] -> [b]` que calcula a lista das segundas componentes dos pares.

```haskell
segundos :: [(a,b)] -> [b]
segundos [] = []
segundos ((_,b):l) = b : segundos l
```

## h) `nosPrimeiros :: (Eq a) => a -> [(a,b)] -> Bool` que testa se um elemento aparece na lista como primeira componente de algum dos pares.

```haskell
nosPrimeiros :: (Eq a) => a -> [(a,b)] -> Bool
nosPrimeiros x [(a,_)] = x == a
nosPrimeiros x (s:ss) = x == fst s || nosPrimeiros x ss
```

## i) `sumTriplos :: (Num a, Num b, Num c) => [(a,b,c)] -> (a,b,c)` soma uma lista de triplos componente a componente.

## Por exemplo, `sumTriplos [(2,4,11), (3,1,-5), (10,-3,6)] = (15,2,12)`

```haskell
sumTriplos :: (Num a, Num b, Num c) => [(a,b,c)] -> (a,b,c)
sumTriplos [(x,y,z)] = (x,y,z)
sumTriplos ((x,y,z):ts) = (x + sumX, y + sumY, z + sumZ)
        where (sumX, sumY, sumZ) = sumTriplos ts
```

# 3) Recorrendo a funções do módulo `Data.Char`, defina recursivamente as seguintes funções sobre strings:

## a) `soDigitos :: [Char] -> [Char]` que recebe uma lista de caracteres, e seleciona dessa lista os caracteres que são algarismos.

```haskell
soDigitos :: [Char] -> [Char]
soDigitos [] = []
soDigitos (h:t)
        | isDigit h = h : soDigitos t
        | otherwise = soDigitos t
```

## b) `minusculas :: [Char] -> Int` que recebe uma lista de caracteres, e conta quantos desses caracteres são letras minúsculas.

```haskell
minusculas :: [Char] -> Int
minusculas [] = 0
minusculas (c:str) = if isLower c then 1 + minusculas str
                                  else minusculas str
```

## c) `nums :: String -> [Int]` que recebe uma string e devolve uma lista com os algarismos que ocorrem nessa string, pela mesma ordem.

```haskell
nums :: [Char] -> [Int]
nums [] = []
nums (c:str) = if isDigit c then digitToInt c : nums str 
                            else nums str
``` 

# 4) Uma forma de representar polinómios de uma variável é usar listas de monómios representados por pares _(coeficiente, expoente)_

# `type Polinomio = [Monomio]`
# `type Monomio = (Float,Int)`

# Por exemplo, `[(2,3), (3,4), (5,3), (4,5)]` representa o polinómio 2x<sup>3</sup> + 3x<sup>4</sup> + 5x<sup>3</sup> + 4x<sup>5</sup>. Defina as seguintes funções:

## a) `conta :: Int -> Polinomio -> Int` de forma a que `(conta n p)` indica quantos monómios de grau `n` existem em `p`.

```haskell
conta :: Int -> Polinomio -> Int
conta _ [] = 0
conta n ((_,e):ps) = if e == n then 1 + conta n ps 
                               else conta n ps
```

## b) `grau :: Polinomio -> Int` que indica o grau de um polinómio.

```haskell
grau :: Polinomio -> Int
grau [(b,e)] = e
grau ((b,e):ps) = if e > grau ps then e else grau ps
```

## c) `selgrau :: Int -> Polinomio -> Polinomio` que seleciona os monómios com um dado grau de um polinómio.

```haskell
selgrau :: Int -> Polinomio -> Polinomio
selgrau _ [] = []
selgrau n ((b,e):ps)
    | n == e = (b,e) : selgrau n ps
    | otherwise = selgrau n ps
``` 

## d) `deriv :: Polinomio -> Polinomio` que calcula a derivada de um polinómio.

```haskell
deriv :: Polinomio -> Polinomio
deriv [] = []
deriv ((b,e):ps) = if e > 0 then (b*fromIntegral e, e-1) : deriv ps 
                            else deriv ps
-- a função `fromIntegral` converte um valor inteiro num valor de vírgula flutuante
-- em haskell, é necessário que ambos os fatores de uma multiplicação sejam do mesmo tipo, ele não converte automaticamente
``` 

## e) `calcula :: Float -> Polinomio -> Float` que calcula o valor de um polinómio para um dado valor de x.

```haskell
calcula :: Float -> Polinomio -> Float
calcula x [] = 0
calcula x ((b,e):ps) = b*(x^e) + calcula x ps
``` 

## f) `simp :: Polinomio -> Polinomio` que retira de um polinómio os monómios de coeficiente zero.

```haskell
simp :: Polinomio -> Polinomio
simp [] = []
simp ((b,e):ps) = if e < 1 then simp ps 
                           else (b,e) : simp ps
```

## g) `mult :: Monomio -> Polinomio -> Polinomio` que calcula o resultado da multiplicação de um monómio por um polinómio.

```haskell
mult :: Monomio -> Polinomio -> Polinomio
mult _ [] = []
mult (b,e) ((bp,ep):ps) = (b*bp,e+ep) : mult (b,e) ps
```

## h) `normaliza :: Polinomio -> Polinomio` que dado um polinómio constrói um polinómio equivalente em que não podem aparecer varios monómios com o mesmo grau.

```haskell
normaliza :: Polinomio -> Polinomio
normaliza [] = []
normaliza ((b,e):ps) = (sum [bs | (bs,es) <- selgrau e ps] + b,e) : normaliza [(bo,eo) | (bo,eo) <- ps, eo /= e]
-- Nesta função, começamos por selecionar da cauda da lista todos os monómios com o mesmo grau da cabeça da lista e fazemos a soma dos seus coeficientes, colocando esta soma num novo monómio com o grau da cabeça da lista. Depois, apenas precisamos de normalizar os monómios de grau diferente ao da cabeça da lista, por isso filtramos da cauda da lista todos os monómios com expoente diferente do expoente da cabeça e chamamos a função recursivamente com esta nova lista.

-- Em alternativa, esta versão não usa compreensão de listas, mas é mais complexa:

normaliza' :: Polinomio -> Polinomio
normaliza' [] = []
normaliza' [(b,e)] = [(b,e)]
normaliza' ((b, e) : (b2, e2) : ps)
  | e == e2 = normaliza' ((b + b2, e) : ps)
  | conta e ps == 0 = (b, e) : normaliza' ((b2, e2) : ps)
  | otherwise = normaliza' ((b, e) : ps ++ [(b2, e2)])
```

## i) `soma :: Polinomio -> Polinomio -> Polinomio` que faz a soma de dois polinómios de forma que se os polinómios que recebe estiverem normalizados produz também um polinómio normalizado.

```haskell
soma :: Polinomio -> Polinomio -> Polinomio
soma p1 p2 = normaliza (p1 ++ p2)

-- Esta primeira versão é mais "preguiçosa". Se quisermos respeitar a 100% o enunciado, podemos defini-la da seguinte forma:

soma' :: Polinomio -> Polinomio -> Polinomio
soma' [] p = p
soma' p [] = p
soma' ((b1,e1):p1) p2 = adiciona (b1,e1) (soma' p1 p2)
    where adiciona :: Monomio -> Polinomio -> Polinomio
          adiciona p [] = p
          adiciona (b,e) ((bp,ep):p)
              | e == ep = (b + bp, e) : p
              | otherwise = (bp,ep) : adiciona (b,e) p
```

## j) `produto :: Polinomio -> Polinomio -> Polinomio` que calcula o produto de dois polinómios.

```haskell
produto :: Polinomio -> Polinomio -> Polinomio
produto [] _ = []
produto (p:p1) p2 = soma (mult p p2) (produto p1 p2) 
```

## k) `ordena :: Polinomio -> Polinomio` que ordena um polonómio por ordem crescente dos graus dos seus monómios.

```haskell
ordena :: Polinomio -> Polinomio
ordena [] = []
ordena ((b,e):ps) = ordena (maisAltos ps) ++ [(b,e)] ++ ordena (maisBaixos ps)
    where maisAltos [] = []
          maisAltos ((bx,ex):xs) = if ex > e || (ex == e && bx >= b) then (bx,ex) : maisAltos xs else maisAltos xs
          maisBaixos [] = []
          maisBaixos ((bx,ex):xs) = if ex < e || (ex == e && bx < b) then (bx,ex) : maisBaixos xs else maisBaixos xs
-- A este método de ordenar listas chamamos "quick sort"
```

## l) `equiv :: Polinomio -> Polinomio -> Bool` que testa se dois polinómios são equivalentes.

```haskell
equiv :: Polinomio -> Polinomio -> Bool
equiv p1 p2 = ordena (normaliza p1) == ordena (normaliza p2)

-- Para ir de acordo à ficha, esta função deveria estar definida de forma recursiva, mas, visto que esta definição apenas usa funções recursivas, seria fácil replicá-la de forma recursiva. Por uma questão de simplicidade, não incluo essa definição nesta resolução.

-- Um método alternativo de resolver esta alínea seria definir uma função que subtrai um polinómio do outro e, se o resultado fosse zero, os polinómios seriam equivalentes.
```