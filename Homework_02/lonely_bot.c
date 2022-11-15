
#include <stdio.h>
#include <stdlib.h>

/**
* chat_bot
*
* This function enables the communication with the user
* as specified in the homework sheet
*
*/
void chat_bot(){
    printf("Hi, I am Boris, the chat bot. Do you wanna be my friend?\n");

    //YOUR CODE STARTS HERE

    char ans1[2] = {0};
    fgets(ans1, 2, stdin);
    fflush(stdin);

    switch (ans1[0]) {
      case 'Y':
      case 'y':
        printf("Cool! Do you wanna hang out sometime?\n");
        break;
      default:
        printf("Oh. Well, then I will ask someone else. Bye.\n");
        return;
    }

    char ans2[2] = {0};
    fgets(ans2, 2, stdin);
    fflush(stdin);

    switch (ans2[0]) {
      case 'Y':
      case 'y':
        printf("Awesome. See ya!\n");
        break;
      default:
        printf("Well, what do I need a friend for, if I am lonely anyway. Bye.\n");
        return;
    }

    //END OF YOUR CODE
}
