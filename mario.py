import cs50

while True:
    x = cs50.get_int("Height: ")
    if x >= 1 and x <= 8:
        break

for n in range(x):
    for j in range(x):
        if n + j >= x - 1:
            print("#", end="")
        else:
            print(" ", end="")
    print()
        