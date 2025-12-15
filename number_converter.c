#include <stdio.h>

int main()
{
    printf("Welcome to Number Converter\n");
    // Decimal to Binary & Octal
    printf("Commands: {decimal - d}\n          {binary  - b}\n          {octal   - o}\n");

    
    char input_type;
    printf("Enter Input Type: ");
    scanf("%c", &input_type);

    // Check Input type
    if (!(input_type == 'd' || input_type == 'b' || input_type == 'o'))
    {
        printf("%c", input_type);
        printf("You typed wrong Command! \nRead Commands Carefully!\n");
        return 1;
    }
   
    char output_type;
    printf("Enter Output Type: ");
    scanf(" %c", &output_type);

    // Check Output type
    if (!(output_type == 'd' || output_type == 'b' || output_type == 'o'))
    {
        printf("You typed wrong Command! \nRead Commands Carefully!\n");
        return 1;
    }

    int num;
    printf("Enter Number: ");
    scanf("%d", &num);

    // if input & output both return same number
    if (input_type == output_type)
    {
        printf("%d\n", num);
        return 1;
    }

    int rem;
    int newNum = 0;
    int counter = 1;
    int store = 0;

    if (input_type == 'd')
    {
        int method = 0;
        if (output_type == 'b')
            method = 2;
        else if (output_type == 'o')
            method = 8;
        while (num > 0)
        {
            rem = num % method;
            newNum += rem * counter;
            counter *= 10;
            num /= method;
        }
        printf("%d\n", newNum);
    }
    else if (input_type == 'b')
    {
        while (num > 0)
        {
            rem = num % 10;

            if(!(rem == 1 || rem == 0)){
                printf("Not Matched! - This Number is not Binary\n");
                return 2;
            }

            if (rem == 1)
                newNum += counter;
            counter *= 2;
            num /= 10;
        }

        if (output_type == 'o')
        {
            num = newNum;
            newNum = 0;
            counter = 1;
            while (num > 0)
            {
                rem = num % 8;
                newNum += rem * counter;
                counter *= 10;
                num /= 8;
            }
        }
        printf("%d\n", newNum);
    }
    else if (input_type == 'o')
    {
        while (num > 0)
        {
            rem = num % 10;

            if(rem >= 8){
                printf("Not Matched! - This Number is not Octal\n");
                return 2;
            }

            newNum += rem * counter;
            counter *= 8;
            num /= 10;
        }
        if (output_type == 'b')
        {
            num = newNum;
            newNum = 0;
            counter = 1;
            while (num > 0)
            {
                rem = num % 2;
                newNum += rem * counter;
                counter *= 10;
                num /= 2;
            }
        }
        printf("%d\n", newNum);
    }
}