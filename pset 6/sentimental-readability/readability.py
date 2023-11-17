import string
from cs50 import get_string


def main():
    text = get_string("Text: ")
    letters = compute_characters(text)
    words = compute_words(text)
    sentences = compute_sentences(text)

    wordsentence = words / 100
    l = letters / wordsentence
    s = sentences / wordsentence
    index = round((0.0588 * l) - (0.296 * s) - 15.8)

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


def compute_characters(text):
    letters = 0
    for i in text:
        if i.isalpha():
            letters += 1
    return letters


def compute_words(text):
    words = len(text.split())
    return words


def compute_sentences(text):
    sentences = 0
    for j in text:
        if j in ["!", ".", "?"]:
            sentences += 1
    return sentences


main()
