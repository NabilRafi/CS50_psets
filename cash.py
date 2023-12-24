import cs50,math

## Prompt user for input
while True:
    x = cs50.get_float("Change Owed: ")
    if x >= 0:
        break

## Conversion from dollars to cents
y = round(x * 100)

## Calculation
i = 25
j = 10
k = 5
l = 1
coins = 0


while y >= i:
    y = y - i
    coins += 1

while y >= j:
    y = y - j
    coins += 1
    
while y >= k:
    y = y - k
    coins += 1
    
while y >= l:
    y = y - l
    coins += 1

## Printing the coins
print(f"Coins: {coins}")
