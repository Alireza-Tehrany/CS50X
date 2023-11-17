from cs50 import get_int, get_string


def main():
    card = get_input()
    find_card(card)


def get_input():
    while True:
        global CN
        CN = get_string("number: ")
        if CN.isnumeric():
            break
        else:
            continue
    return CN


def find_card(card):
    odds = 0
    evens = 0

    reversed_card = reversed([int(digit) for digit in card])

    for i, digit in enumerate(reversed_card):
        if (i + 1) % 2 == 0:
            odd_digit = digit * 2
            if odd_digit > 9:
                odds += int(odd_digit / 10) + odd_digit % 10
            else:
                odds += odd_digit
        else:
            evens += digit

    fsum = odds + evens
    cardlen = len(CN)
    start = int(CN[0:2])
    if fsum % 10 == 0:
        if start in [34, 37] and cardlen == 15:
            print("AMEX")
        elif start in range(51, 56) and cardlen == 16:
            print("MASTERCARD")
        elif (int(CN[0]) == 4) and cardlen in [13, 16]:
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


main()
