from cs50 import get_int


def main():
    while True:
        height = get_int("Height: ")
        if height >= 1 and height <= 8:
            break
        else:
            continue
    make_blocks(height)


def make_blocks(height):
    for a in range(height):
        print(" " * (height - (a + 1)), end="")
        print("#" * (a + 1) + "  " + "#" * (a + 1))


main()
