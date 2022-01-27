```haskell
enumFromTo :: Int -> Int -> [Int]
enumFromTo start end 
    | start > end = []
    | otherwise = start : enumFromTo (start + 1) end
```