#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void print_word(int len, char hidden_word[]);

int main(void)
{
    // Use the current time as a seed for the random number generator
    srand(time(NULL));
    // List of possible words for the game
    char *words[] = {"computer", "program", "coding", "language", "string", "number", "letter", "screen", "keyboard", "mouse", "window", "folder", "memory", "button", "cursor", "binary", "system", "server", "network", "github"};
    // Generate a random number between 0 and 19
    int random = rand() % 20;
    char *secret_word = words[random];
    int len = strlen(secret_word);
    char hidden_word[len+1];
    // Set every character to '_' (unguessed)
    for (int i = 0; i < len; i++)
    {
        hidden_word[i] = '_';
    }
    hidden_word[len] = '\0';
    print_word(len, hidden_word);
    char letter;
    bool correct = false;
    bool win = false;
    bool guessed = false;
    int lives = 5;
    int guessed_count = 0;
    char guessed_letters[26];
    printf("You have %i lives. Good luck!\n", lives);
    do
    {
        // Ask the user for a letter and make it lowercase
        printf("Enter a letter: ");
        scanf(" %c", &letter);
        letter = tolower(letter);
        // Check if the user typed a letter
        if (!isalpha(letter))
        {
            printf("You can only guess letters\n");
            continue;
        }
        // Check if the letter was already guessed
        for (int i = 0; i < guessed_count; i++)
        {
            if (letter == guessed_letters[i])
            {
                guessed = true;
            }
        }
        if(guessed)
        {
            printf("You have already guessed that letter\n");
            guessed = false;
            continue;
        }
        // Update the hidden word if the guess is correct
        for (int i = 0; i < len; i++)
        {
        if (secret_word[i] == letter)
        {
        correct = true;
        hidden_word[i] = letter;
        }
        }
        // Print whether the guess is correct or not
        if (correct)
        {
        printf("Correct!\n");
        print_word(len, hidden_word);
        }
        else
        {
        printf("Incorrect!\n");
        lives--;
        printf("%i lives remaining!\n", lives);
        print_word(len, hidden_word);
        }   
        correct = false;
        win = true;
        guessed_letters[guessed_count] = letter;
        guessed_count++;
        // Check if the word is already fully guessed
        for (int i = 0; i < len; i++)
        {
        if (hidden_word[i] == '_')
        {
        win = false;
        }
        } 
    }
    while(!win && lives > 0);
    // Tell the user if they won or not
    if (win)
    {
        printf("You won! Congratulations\n");
    }
    else
    {
        printf("You lost :(\nThe word was %s\nBetter luck next time", secret_word);
    }
    
}

// Print the current state of the word
void print_word(int len, char hidden_word[])
{
    for (int i = 0; i < len; i++)
        {
            printf("%c ", hidden_word[i]);
        }
        printf("\n");
}
