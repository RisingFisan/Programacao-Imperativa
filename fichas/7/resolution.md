# 1) Considere o seguinte tipo para representar expressões inteiras.

```
data ExpInt = Const Int
            | Simetrico ExpInt
            | Mais ExpInt ExpInt
            | Menos ExpInt ExpInt
            | Mult ExpInt ExpInt
```

# Os termos deste tipo ExpInt podem ser vistos como árvores cujas folhas são inteiros e cujos nodos (não folhas) são operadores.

## a) Defina uma função `calcula :: ExpInt -> Int` que, dada uma destas expressões, calcula o seu valor.

```haskell
calcula :: ExpInt -> Int
calcula (Const num) = num
calcula (Simetrico exp) = (- calcula exp)
calcula (Mais a b) = calcula a + calcula b
calcula (Menos a b) = calcula a - calcula b
calcula (Mult a b) = calcula a * calcula b
```

## b) Defina uma função `infixa :: ExpInt -> String` de forma a que `infixa (Mais (Const 3) (Menos (Const 2) (Const 5)))` dˆe como resultado `"(3 + (2 - 5))"`.

```haskell
infixa :: ExpInt -> String
infixa (Const num) = show num -- A função pré-definida `show` converte um valor para a sua representação textual (String).
infixa (Simetrico exp) = "(-(" ++ infixa exp ++ "))"
infixa (Mais a b) = '(':infixa a ++ " + " ++ infixa b ++ ")"
infixa (Menos a b) = '(':infixa a ++ " - " ++ infixa b ++ ")"
infixa (Mult a b) = '(':infixa a ++ " * " ++ infixa b ++ ")"
```

## c) Defina uma outra função de conversão para strings `posfixa :: ExpInt -> String` de forma a que quando aplicada à expressão acima dˆe como resultado `"3 2 5 - +"`.

```haskell
posfixa :: ExpInt -> String
posfixa (Const num) = show num ++ " "
posfixa (Simetrico exp) = '-':posfixa exp
posfixa (Mais a b) = posfixa a ++ posfixa b ++ "+ "
posfixa (Menos a b) = posfixa a ++ posfixa b ++ "- "
posfixa (Mult a b) = posfixa a ++ posfixa b ++ "* "
```

# 2) Considere o seguinte tipo para representar árvores irregulares (_rose trees_).

```
data RTree a = R a [RTree a]
```

# Árvore de exemplo para testar as funções:

```
arvore = R 6 [R 4 [R 7 [R 1 [],
                        R 3 []],
                   R 9 []],
              R 3 [R 12 []],
              R 6 [],
              R 11 []]
```

# Defina as seguintes funções sobre estas árvores:

## a) `soma :: Num a => RTree a -> a` que soma os elementos da árvore.

```haskell
soma :: Num a => RTree a -> a
soma (R e []) = e
soma (R e es) = e + sum (map soma es)
```

## b) `altura :: RTree a -> Int` que calcula a altura da árvore.

```haskell
altura :: RTree a -> Int
altura (R e []) = 1
altura (R e es) = 1 + maximum (map altura es)
```

## c) `prune :: Int -> RTree a -> RTree a` que remove de uma árvore todos os elementos a partir de uma determinada profundidade.

```haskell
prune :: Int -> RTree a -> RTree a
prune 0 (R e es) = R e []
prune n (R e es) = R e (map (prune (n - 1)) es)
```

## d) `mirror :: RTree a -> RTree a` que gera a árvore simétrica.

```haskell
mirror :: RTree a -> RTree a
mirror (R e es) = R e (map mirror (reverse es))
```

## e) `postorder :: RTree a -> [a]` que corresponde à travessia postorder da árvore.

```haskell
postorder :: RTree a -> [a]
postorder (R e []) = [e]
postorder (R e es) = concatMap postorder es ++ [e]
```

# 3) Relembre a definição de árvores binárias apresentada na ficha anterior:

```
data BTree a = Empty | Node a (BTree a) (BTree a)
```

# Nestas árvores a informação está nos nodos (as _extremidades_ da árvore tˆem apenas uma marca – `Empty`). É também habitual definirem-se árvores em que a informação está apenas nas extermidades (_leaf trees_):

```
data LTree a = Tip a | Fork (LTree a) (LTree a)
```

# Árvore de exemplo para testar as funções:

```
arvore = Fork (Fork (Tip 5)
                    (Fork (Tip 6)
                          (Tip 4)))
              (Fork (Fork (Tip 3)
                          (Tip 7))
                    (Tip 5))
```

# Defina sobre este tipo as seguintes funções:

## a) `ltSum :: Num a => LTree a -> a` que soma as folhas de uma árvore.

```haskell
ltSum :: Num a => LTree a -> a
ltSum (Tip n) = n
ltSum (Fork a b) = ltSum a + ltSum b 
```

## b) `listaLT :: LTree a -> [a]` que lista as folhas de uma árvore (da esquerda para a direita).

```haskell
listaLT :: LTree a -> [a]
listaLT (Tip n) = [n]
listaLT (Fork a b) = listaLT a ++ listaLT b
```

## c) `ltHeight :: LTree a -> Int` que calcula a altura de uma árvore.

```haskell
ltHeight :: LTree a -> Int
ltHeight (Tip _) = 0
ltHeight (Fork a b) = 1 + max (ltHeight a) (ltHeight b)
``` 

# 4) Estes dois conceitos podem ser agrupados num só, definindo o seguinte tipo:

```
data FTree a b = Leaf b | No a (FTree a b) (FTree a b)
```

# Árvore de exemplo para testar as funções:

```
arvore = No 8 (No 1 (Leaf 5)
                    (No 2 (Leaf 6)
                          (Leaf 4)))
              (No 9 (No 10 (Leaf 3)
                           (Leaf 7))
                    (Leaf 5))
```

# São as chamadas _full trees_ onde a informação está não só nos nodos, como também nas folhas (note que o tipo da informação nos nodos e nas folhas não tem que ser o mesmo).

## a) Defina a função `splitFTree :: FTree a b -> (BTree a, LTree b)` que separa uma árvore com informação nos nodos e nas folhas em duas árvores de tipos diferentes.

```haskell
splitFTree :: FTree a b -> (BTree a, LTree b)
splitFTree (Leaf n) = (Empty, Tip n)
splitFTree (No a b c) = (Node a b' c', Fork b'' c'')
    where (b', b'') = splitFTree b
          (c', c'') = splitFTree c 
```

## b) Defina ainda a função `joinTrees :: BTree a -> LTree b -> Maybe (FTree a b)` que sempre que as árvores sejam compatíveis as junta numa só.

```haskell
joinTrees :: BTree a -> LTree b -> Maybe (FTree a b)
joinTrees (Empty) (Tip n) = Just (Leaf n)
joinTrees (Node e l r) (Fork a b) = Just (No e aux aux2)
    where Just aux = joinTrees l a
          Just aux2 = joinTrees r b
joinTrees _ _ = Nothing
```