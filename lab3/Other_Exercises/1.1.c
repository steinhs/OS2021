#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char s[100] = "";
    char c;
    int count = 0;

    printf("Enter a character to check:");
    scanf("%c",&c);
    printf("You have entered: %c",c);
    printf("\nEnter a string:");
    scanf(" %[^\n]s",s);
    printf("You have entered: %s\n", s);


    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == c)
        {
            count++;
        }
           
    }
    
    printf("The character %c appears %d time(s)\n",c,count);

    return 0;
}
