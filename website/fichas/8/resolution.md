# 1) Considere o seguinte tipo de dados para representar frações

```
data Frac = F Integer Integer
```

## a) Defina a função `normaliza :: Frac -> Frac` que dada uma fracção calcula uma fracção equivalente, irredutível, e com o denominador positivo. Por exemplo, `normaliza (F (-33) (-51))` deve retornar `F 11 17` e `normaliza (F 50 (-5))` deve retornar `F (-10) 1`. Sugere-se que comece por definir primeiro a função `mdc :: Integer -> Integer -> Integer` que calcula o máximo divisor comum entre dois números, baseada na seguinte propriedade (atribuida a Euclides): `mdc x y == mdc (x+y) y == mdc x (y+x)`

```haskell
mdc :: Integer -> Integer -> Integer
mdc a b = last [n | n <- [1..(min a b)] , a `mod` n == 0, b `mod` n == 0]

normaliza :: Frac -> Frac
normaliza (F a b) = F ((abs a) `div` x) (bX `div` x)
    where x = mdc (abs a) (abs b) * (if a * b < 0 then (-1) else 1)
          bX | a < 0 = -b
             | otherwise = b
```

## b) Defina `Frac` como instância da classe `Eq`.

```haskell
instance Eq Frac where
    (F a b) == (F c d) = a * d == c * b
```

## c) Defina `Frac` como instância da classe `Ord`.

```haskell
instance Ord Frac where
    (F a b) <= (F c d) = a * d <= c * b
```

## d) Defina `Frac` como instância da classe `Show`, de forma a que cada fracção seja apresentada por _(numerador/denominador)_.

```haskell
instance Show Frac where
    show (F a b) = show a ++ "/" ++ show b
```

## e) Defina `Frac` como instância da classe `Num`. Relembre que a classe `Num` tem a seguinte definição:

```
class (Eq a, Show a) => Num a where
    (+), (*), (-) :: a -> a -> a
    negate, abs, signum :: a -> a
    fromInteger :: Integer -> a
```

```haskell
instance Num Frac where
    -- (+), (*), (-) :: a -> a -> a
    -- negate, abs, signum :: a -> a
    -- fromInteger :: Integer -> a
    (F a b) + (F c d) | b == d = normaliza $ F (a + c) b
                      | otherwise = normaliza $ F (a * d + b * c) (b * d)
    x - y = x + negate y
    (F a b) * (F c d) = F (a * c) (b * d)
    negate (F a b) = F (-a) b
    abs (F a b) = F (abs a) (abs b)
    signum (F a b) | a == 0 = 0
                   | a * b > 0 = 1
                   | otherwise = -1
    fromInteger x = F x 1
```

## f) Defina uma função que, dada uma fracção `f` e uma lista de fracções `l`, selecciona de `l` os elementos que são maiores do que o dobro de `f`.

```haskell
maioresQueDobro :: Frac -> [Frac] -> [Frac]
maioresQueDobro f l = filter ((<) (2 * f)) l
```

# 2) Relembre o tipo definido na Ficha 7 para representar expressões inteiras. Uma possível generalização desse tipo de dados, será considerar expressões cujas constantes são de um qualquer tipo numérico (i.e., da classe `Num`).

```
data Exp a = Const a
| Simetrico (Exp a)
| Mais (Exp a) (Exp a)
| Menos (Exp a) (Exp a)
| Mult (Exp a) (Exp a)
```

## a) Declare `Exp a` como uma instância de `Show`.

```haskell
instance Show a => Show (Exp a) where
    show (Const a) = show a
    show (Simetrico a) = "(- " ++ show a ++ ")"
    show (Mais a b) = "(" ++ show a ++ " + " ++ show b ++ ")"
    show (Menos a b) = "(" ++ show a ++ " - " ++ show b ++ ")"
    show (Mult a b) = "(" ++ show a ++ " * " ++ show b ++ ")"
```

## b) Declare `Exp a` como uma instância de `Eq`.

```haskell
valorDe :: (Num a) => Exp a -> a
valorDe (Const a) = a
valorDe (Simetrico a) = - (valorDe a)
valorDe (Mais a b) = valorDe a + valorDe b
valorDe (Menos a b) = valorDe a - valorDe b
valorDe (Mult a b) = valorDe a * valorDe b

instance (Num a,Eq a) => Eq (Exp a) where
    x == y = valorDe x == valorDe y
```

## c) Declare `Exp a` como instância da classe `Num`.

```haskell
instance (Num a, Eq a) => Num (Exp a) where
    x + y = Const (valorDe x + valorDe y)
    --
    x - y = Const (valorDe x - valorDe y)
    --
    x * y = Const (valorDe x * valorDe y)
    --
    negate (Const a) = Const (- a)
    negate (Simetrico a) = a
    negate (Mais a b) = Mais (- a) (- b)
    negate (Menos a b) = Menos b a
    negate (Mult a b) = Mult (-a) b
    fromInteger x = Const (fromInteger x)
    abs (Const a) = Const (abs a)
    abs (Simetrico a) = abs a
    abs (Mais a b) = abs (a + b)
    abs (Menos a b) = abs (a - b)
    abs (Mult a b) = abs (a * b)
    signum (Const a) = Const (if abs a == a then if a == 0 then 0 else 1 else (-1))
    signum (Simetrico a) = - signum a
    signum (Mais a b) = Const (if abs (a + b) == a + b then if a + b == 0 then 0 else 1 else (-1))
    signum (Menos a b) = Const (if abs (a - b) == a - b then if a - b == 0 then 0 else 1 else (-1))
    signum (Mult a b) = Const (if abs (a * b) == a * b then if a * b == 0 then 0 else 1 else (-1))
```

# 3) Relembre o exercício da Ficha 3 sobre contas bancárias, com a seguinte declaração de tipos:

```
data Movimento = Credito Float | Debito Float
data Data = D Int Int Int
data Extracto = Ext Float [(Data, String, Movimento)]
```

## a) Defina `Data` como instância da classe `Ord`.

```haskell
instance Ord Data where
    compare (D dia1 mes1 ano1) (D dia2 mes2 ano2) 
        | ano1 > ano2 || ano1 == ano2 && (mes1 > mes2 || mes1 == mes2 && dia1 > dia2) = GT
        | ano1 == ano2 && mes1 == mes2 && dia1 == dia2 = EQ
        | otherwise = LT
```

## b) Defina `Data` como instância da classe `Show`.

```haskell
instance Show Data where 
    show (D dia mes ano) = intercalate "/" $ map show [dia,mes,ano]
```

## c) Defina a função `ordena :: Extracto -> Extracto`, que transforma um extrato de modo a que a lista de movimentos apareça ordenada por ordem crescente de data.

```haskell
ordena :: Extracto -> Extracto
ordena (Ext n l) = Ext n (sort l)
``` 

## d) Defina `Extracto` como instância da classe `Show` de forma a que a apresentação do extracto seja por ordem de data do movimento, com o seguinte aspeto:

```
Saldo anterior: 300
---------------------------------------
Data Descricao Credito Debito
---------------------------------------
2010/4/5 DEPOSITO 2000
2010/8/10 COMPRA 37,5
2010/9/1 LEV 60
2011/1/7 JUROS 100
2011/1/22 ANUIDADE 8
---------------------------------------
Saldo atual: 2294,5
```

```haskell
saldo :: Extracto -> Float
saldo (Ext x lm) = foldl (\acc (_,_,mov) -> case mov of Credito n -> acc + n; Debito n -> acc - n) x lm

instance Show Extracto where
    show (Ext n l) = "Saldo anterior: " ++ show n ++
                     "\n---------------------------------------" ++
                     "\nData       Descricao   Credito   Debito" ++
                     "\n---------------------------------------\n" ++ concatMap (\(dat,str,_) -> show dat ++ replicate (11 - length (show dat)) ' ' ++ map toUpper str ++ "    \n") l ++
                     "---------------------------------------" ++
                     "\nSaldo atual: " ++ show (saldo (Ext n l))
``` 