# 1) A classe Random da biblioteca System.Random agrupa os tipos para os quais é possível gerar valores aleatórios. Algumas das funções declaradas nesta classe são:

- `randomIO :: Random a => IO a` que gera um valor aleatório do tipo `a`;
- `randomRIO :: Random a => (a,a) -> IO a` que gera um valor aleatório do tipo `a` dentro de uma determinada gama de valores.

# Usando estas funções implemente os seguintes programas:

## a) `bingo :: IO ()` que sorteia os números para o jogo do bingo. Sempre que uma tecla é pressionada é apresentado um número aleatório entre 1 e 90. Obviamente, não podem ser apresentados números repetidos e o programa termina depois de gerados os 90 números diferentes.

```haskell
bingo :: IO ()
bingo = do nl <- acumularNumeros []
           print nl

acumularNumeros :: [Int] -> IO [Int]
acumularNumeros l | length l == 90 = do return l
                  | otherwise = do v <- randomRIO (1,90)
                                   print v
                                   getChar
                                   let nl = if v `elem` l then l else v:l in acumularNumeros nl
```

## b) `mastermind :: IO ()` que implementa uma variante do jogo de descodificação de padrões Mastermind. O programa deve começar por gerar uma sequência secreta de 4 dígitos aleatórios que o jogador vai tentar descodificar. Sempre que o jogador introduz uma sequência de 4 dígitos, o programa responde com o número de dígitos com o valor correcto na posição correcta e com o número de dígitos com o valor correcto na posição errada. O jogo termina quando o jogador acertar na sequência de dígitos secreta.

```haskell

mastermind :: IO ()
mastermind = do (n1,n2,n3,n4) <- getKey
                doGuess (n1,n2,n3,n4)
                return ()
                                

getKey :: IO (Int,Int,Int,Int)
getKey = do a <- randomRIO (0,9)
            b <- randomRIO (0,9)
            c <- randomRIO (0,9)
            d <- randomRIO (0,9)
            return (a,b,c,d)

getGuess :: IO (Int,Int,Int,Int)
getGuess = do x <- getLine
              if length x /= 4 || not $ all isDigit x
              then getGuess
              else return (let (a:b:c:d:resto) = x in (read [a],read [b],read [c],read [d]))

doGuess :: (Int,Int,Int,Int) -> IO ()
doGuess (n1,n2,n3,n4) = do
    let listaNums = [n1,n2,n3,n4]
    (g1,g2,g3,g4) <- getGuess
    let numsC = 0 + (if n1 == g1 then 1 else 0) + (if n2 == g2 then 1 else 0) + (if n3 == g3 then 1 else 0) + (if n4 == g4 then 1 else 0)
    let numsS = 0 + (if n1 /= g1 && g1 `elem` (listaNums \\ [g2,g3,g4]) then 1 else 0) + 
                    (if n2 /= g2 && g2 `elem` (listaNums \\ [g3,g4]) then 1 else 0) + 
                    (if n3 /= g3 && g3 `elem` (listaNums \\ [g4]) then 1 else 0) + 
                    (if n4 /= g4 && g4 `elem` (listaNums \\ []) then 1 else 0)
    if numsC == 4 then print "Ganhaste, parabens!" else print $ "Valores corretos: " ++ show numsC ++ "   Valores no sitio errado: " ++ show numsS
    if numsC == 4 then return () else doGuess (n1,n2,n3,n4)
```

# 2) Uma aposta do **EuroMilhões** corresponde à escolha de 5 _Números_ e 2 _Estrelas_. Os _Números_ são inteiros entre 1 e 50. As _Estrelas_ são inteiros entre 1 e 9. Para modelar uma aposta destas definiu-se o seguinte tipo de dados: 

```
data Aposta = Ap [Int] (Int,Int)
```

## a) Defina a função `valida :: Aposta -> Bool` que testa se uma dada aposta é válida (i.e. tem os 5 números e 2 estrelas, dentro dos valores aceites e não tem repetições).

```haskell
valida :: Aposta -> Bool
valida (Ap (a:b:c:d:e:[]) (f,g)) = and [x `elem` [1..50] | x <- [a,b,c,d,e]] && all (\x -> x `elem` [1..12]) [f,g]
valida _ = False
```

## b) Defina a função `comuns :: Aposta -> Aposta -> (Int,Int)` que dada uma aposta e uma chave, calcula quantos números e quantas estrelas existem em comum nas duas apostas.

```haskell
comuns :: Aposta -> Aposta -> (Int,Int)
comuns (Ap a1@(a:b:c:d:e:[]) (f,g)) (Ap a2@(h:i:j:k:l:[]) (m,n)) = (contaNums,contaEstr)
    where contaNums = length [x | x <- a1, x `elem` a2]
          contaEstr = length [y | y <- [f,g], y `elem` [m,n]]
```

## c) Use a função da alínea anterior para:

### i. Definir `Aposta` como instância da classe `Eq`.

```haskell
instance Eq Aposta where
    (==) a b = comuns a b == (5,2)
```

### ii. Definir a função `premio :: Aposta -> Aposta -> Maybe Int` que dada uma aposta e a chave do concurso, indica qual o prémio que a aposta tem.

### Os prémios do EuroMilhões são:

| Números | Estrelas | **Prémio** |
| ------- | -------- | ---------- |
| 5 | 2 | 1  |
| 5 | 1 | 2  |
| 5 | 0 | 3  |
| 4 | 2 | 4  |
| 4 | 1 | 5  |
| 4 | 0 | 6  |
| 3 | 2 | 7  |
| 2 | 2 | 8  |
| 3 | 1 | 9  |
| 3 | 0 | 10 |
| 1 | 2 | 11 |
| 2 | 1 | 12 |
| 2 | 0 | 13 |

```haskell
premio :: Aposta -> Aposta -> Maybe Int
premio ap ch = case comuns ap ch of (5,n) -> Just (3 - n)
                                    (4,n) -> Just (6 - n)
                                    (3,n) -> Just (10 - n - (if n == 2 then 1 else 0))
                                    (2,2) -> Just 8
                                    (1,2) -> Just 11
                                    (2,n) -> Just (13 - n)
                                    _ -> Nothing
```

## d) Para permitir que um apostador possa jogar de forma interactiva:

### i. Defina a função `leAposta :: IO Aposta` que lê do teclado uma aposta. Esta função deve garantir que a aposta produzida é válida.

```haskell
unspace :: String -> [String]
unspace str = map Text.unpack (Text.split (==' ') (Text.pack str))

leAposta :: IO Aposta
leAposta = do
    print "Introduza os numeros (separados por um espaco):"
    nums <- getLine
    print "Introduza as estrelas (separadas por um espaco):"
    stars <- getLine
    let bet = Ap (map read (unspace nums)) (let (a:b:r) = unspace stars in (read a, read b))
    if valida bet then return bet else do print "Aposta invalida, tente novamente!"; leAposta
```

### ii. Defina a função `joga :: Aposta -> IO ()` que recebe a chave do concurso, lê uma aposta do teclado e imprime o prémio no ecrã.

```haskell
joga :: Aposta -> IO ()
joga ch = do
    ap <- leAposta
    print ((++) "Premio: " $ show $ fromMaybe 0 (premio ap ch))
```

## e) Defina a função `geraChave :: IO Aposta` que gera uma chave válida de forma aleatória.

```haskell
geraChave :: IO Aposta
geraChave = do
    nums <- generate 'N' []
    [star1,star2] <- generate 'S' []
    return (Ap nums (star1,star2))

generate :: Char -> [Int] -> IO [Int]
generate c l = do
    n <- randomRIO (1,if c == 'N' then 50 else 12)
    if length l == 5 && c == 'N' || length l == 2 && c == 'S' then return l 
    else if n `elem` l then generate c l else generate c (n:l)
```

## f) Pretende-se agora que o programa main permita jogar várias vezes e dê a possiblidade de simular um novo concurso (gerando uma nova chave). Complete o programa definindo a função `ciclo :: Aposta -> IO ()`.

```
main :: IO ()
main = do ch <- geraChave
          ciclo ch

menu :: IO String
menu = do { putStrLn menutxt
          ; putStr "Opcao: "
          ; c <- getLine
          ; return c
          }
    where menutxt = unlines ["",
        "Apostar ........... 1",
        "Gerar nova chave .. 2",
        "",
        "Sair .............. 0"]
```

```haskell
ciclo :: Aposta -> IO ()
ciclo ch = do
    menuOpt <- menu
    case menuOpt of "1" -> do joga ch; ciclo ch
                    "2" -> do putStrLn "Nova chave gerada"; main
                    "0" -> return ()
```