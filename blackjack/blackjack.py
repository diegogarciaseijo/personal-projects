from random import shuffle
from sys import exit

def main():
    # The deck is defined and shuffled so the cards are picked randomly
    deck = [
    "A", "A", "A", "A",
    "2", "2", "2", "2",
    "3", "3", "3", "3",
    "4", "4", "4", "4",
    "5", "5", "5", "5",
    "6", "6", "6", "6",
    "7", "7", "7", "7",
    "8", "8", "8", "8",
    "9", "9", "9", "9",
    "10", "10", "10", "10",
    "J", "J", "J", "J",
    "Q", "Q", "Q", "Q",
    "K", "K", "K", "K"
    ]
    shuffle(deck)
    playercards = []
    dealercards = []
    # The initial cards are dealt
    playercards.append(deck.pop(0))
    print(f"Your first card: {playercards[0]}")
    dealercards.append(deck.pop(0))
    print(f"dealer first card: {dealercards[0]}")
    playercards.append(deck.pop(0))
    print(f"your second card: {playercards[1]}")
    dealercards.append(deck.pop(0))
    print("dealer second card: [hidden]")
    print(f"Your hand: {playercards[0]}, {playercards[1]}")
    print(f"Your hand value: {value(playercards)}")
    # The player is asked to hit or stand while their hand is not over 21
    while (value(playercards) <= 21):
        choice = input("Do you want to hit (h) or stand (s)")
        if (choice == "s" or choice == "S"):
            print("You chose to stand")
            break
        elif (choice == "h" or choice == "H"):
            print("You chose to hit")
            card = deck.pop(0)
            playercards.append(card)
            print(f"Your card: {card}")
            print(f"Your hand: {playercards}")
            print(f"Your hand value: {value(playercards)}")
    if (value(playercards) > 21):
        print("You got over 21\nYou lose :(\nBetter luck next time :)")
        exit()
    # The second dealer card is shown and then the dealer hits until 17
    print(f"dealer second card: {dealercards[1]}")
    print(f"dealer hand: {dealercards}")
    print(f"dealer hand value: {value(dealercards)}")
    while (value(dealercards) < 17):
        print("dealer hits")
        card = deck.pop(0)
        dealercards.append(card)
        print(f"dealer card: {card}")
        print(f"dealer hand: {dealercards}")
        print(f"dealer hand value: {value(dealercards)}")
    # The final result is shown based on the values of the player's and dealer's hands
    if (value(dealercards) > 21):
        print("dealer got over 21\nYou win!\nCongratulations! :)")
        exit()
    if (value(playercards) > value(dealercards)):
        print("Your cards value is greater than the dealer\nYou win!\nCongratulations! :)")
        exit()
    if (value(playercards) == value(dealercards)):
        print("Your cards value is equal to the dealer\nIt's a tie!")
        exit()
    if (value(playercards) < value(dealercards)):
        print("The dealer's cards value is greater than yours\nYou lose :(\nBetter luck next time :)")

# A function is defined to calculate the value of a hand of cards
def value(cards):
    totalvalue = 0
    aces = 0
    for card in cards:
        if (card.isdigit()):
            totalvalue += int(card)
        elif (card == "J" or card == "Q" or card == "K"):
            totalvalue += 10
        elif (card == "A"):
            totalvalue += 11
            aces += 1
    while (totalvalue > 21 and aces > 0):
        totalvalue -= 10
        aces -= 1
    return totalvalue

main()
