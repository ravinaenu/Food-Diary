#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>


#include "linkedList.h"
#include "parseAndPrint.h"



int main(int argc, char *argv[])
{
    Food * head = NULL;
    Food * food;
    FILE * ptrFile;
    char buffer[75];
    char * foodName, * foodGroup;
    double foodCalories = 0;
    char foodType, temp;

    // vegfruit, meat, dairy, grains, fat
    if (argc != 2)
    {
        printf("File name is not specified in command line argument");
        exit(1);

    }
    if ((ptrFile=fopen(argv[1],"r"))==NULL){
       printf("Error in reading file, please check the path specified");
       exit(1);         /* Program exits if file pointer returns NULL. */
    }

    while (fgets(buffer, sizeof buffer, ptrFile) != NULL) /* Read a line from the file, until the end */
    {
       if (buffer[(strlen(buffer)-1)] == '\n')
       {
           buffer[(strlen(buffer)-1)] = '\0'; /* Remove new line */
       }

       parseAndGetEachFoodElements(buffer,&foodName,&foodGroup,&foodCalories,&foodType);
       food = createRecord(foodName, foodGroup, foodCalories, foodType);

       temp = tolower(food->type);

       if (temp == 'h')
       {
           head = addToFront(head, food);
       }
       else if (temp == 'j')
       {
           head = addToBack(head, food);
       }

      free(foodName);
      free(foodGroup);
    }

    fclose(ptrFile);
    printTotalCalories(head);
    printCaloriesPerItem(head);
    printList(head);

    destroyList(head);
   
   

    return 0;
}