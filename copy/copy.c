#include <stdio.h>

const int BUFFER_SIZE = 1024;

int main(int argc, char *argv[])
{
    // Check that the input is correct
    if (argc != 3)
    {
        printf("Usage: ./copy input output\n")
        return 1;
    }

    // Opens the files
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        fclose(input);
        return 1;
    }

    // Copies the text
    size_t total_copied = 0;
    char buffer[BUFFER_SIZE];
    size_t n = 0; 
    while((n = fread(buffer, sizeof(char), BUFFER_SIZE, input)) != 0)
    {
        fwrite(buffer, sizeof(char), n, output);
        total_copied += n;
    }
    
    // Prints the result
    printf("File copied successfully\nBytes copied: %zu\n", total_copied);

    // Closes the files
    fclose(input);
    fclose(output);
}
