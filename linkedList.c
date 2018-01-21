#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include <math.h>

#include "linkedList.h"






/*This function takes in two strings for name and food group, the number of calories
the food contained and a single character representing the type of food (h for healthy, j for junk).
The function allocates memory for the struct, initializes the variables to the supplied
values, initializes the next pointer to null and returns a pointer to the allocated memory.
Returns NULL on failure.The value for name and group are copied into newly allocated memory.
The passed-in memory for name and group must be freed elsewhere in the program.
Memory for the struct must be freed elsewhere in the program.
*/
Food * createRecord(char * name, char * group, double calories, char theType)
{
   Food* foodPtr;

   foodPtr = malloc(sizeof(Food));

   if (foodPtr == NULL)
   {
       return NULL;
       /*
       printf("Error while allocating memory.");
       exit(0);
       */

   }
   foodPtr->name = malloc(sizeof(char)*(strlen(name)+1));
   if (foodPtr->name == NULL)
   {
        return NULL;
       /*
       printf("Error while allocating memory.");
       exit(0);
       */
   }
   foodPtr->foodGroup = malloc(sizeof(char)*(strlen(group)+1));
   if (foodPtr->foodGroup == NULL)
   {
       return NULL;
       /*
       printf("Error while allocating memory.");
       exit(0);
       */
   }

   /* To DO
      Handle, in case of 'name' or 'foodGroup' is NULL
   */
   strcpy(foodPtr->name,name);
   strcpy(foodPtr->foodGroup,group);
   foodPtr->calories = calories;
   foodPtr->type = theType;
   foodPtr->next = NULL;


   return foodPtr;
}


/*This function takes a pointer to a food linked list element and returns a pointer to a string
that contains the information from the struct formatted
in the following manner: "Name (Food Group):calories[type] The string should not
contain a newline. Calories should be reported to two decimal places, padding where necessary.
The string memory is allocated in this function and must be freed elsewhere in
the program.
*/
char * printRecord(Food * toPrint)
{

       char * strToPrint;
       double temp;
       char tempChar[50];
       char charStr[2] = "\0";

       temp = ceilf(toPrint->calories * 100) / 100;
       snprintf(tempChar,50,"%.2f",temp);

        if ((toPrint->name != NULL) && (toPrint->foodGroup != NULL))
        {
            strToPrint = malloc(sizeof(char)*((strlen(toPrint->name)+1)+(strlen(toPrint->foodGroup)+1)+(50+1)+(strlen(charStr))));

        }
        else
        {
            if ((toPrint->name == NULL) && (toPrint->foodGroup == NULL))
            {
                strToPrint = malloc(sizeof(char)*(1+1+(strlen(tempChar)+1)+(strlen(charStr))));
            }
            else
            {
                if (toPrint->name == NULL)
                {
                   strToPrint = malloc(sizeof(char)*((1)+(strlen(toPrint->foodGroup)+1)+(strlen(tempChar)+1)+(strlen(charStr))));

                }
                else
                {
                 strToPrint = malloc(sizeof(char)*((strlen(toPrint->name)+1)+(1)+(strlen(tempChar)+1)+(strlen(charStr))));

                }

            }

        }

       strcpy(strToPrint, "");
       if (toPrint->name == NULL)
       {
         strcat(strToPrint," ");
       }
       else
       {
         strcat(strToPrint,toPrint->name);
       }

       strcat(strToPrint," (");



       if (toPrint->foodGroup == NULL)
       {
         strcat(strToPrint," ");
       }
       else
       {
         strcat(strToPrint,toPrint->foodGroup);
       }

       strcat(strToPrint,"):");


       strcat(strToPrint,tempChar);
       strcat(strToPrint,"[");

       charStr[0] = toPrint->type;
       strcat(strToPrint,charStr);
       strcat(strToPrint,"]");


      return strToPrint;

}


/*Takes a pointer to a list element and frees the memory for the internal variables.
the struct itself must be freed separately */
void destroyElement(Food * theElement)
{

    free(theElement->name);
    theElement->name = NULL;
    free(theElement->foodGroup);
    theElement->foodGroup = NULL;



}


/*addToFront(Food * theList, Food * toBeAdded)
Takes a pointer to the head of the list and an initialized list
element. Adds the element to the front of the linked list and
returns a pointer to the new head of the list. */
Food * addToFront(Food * theList, Food * toBeAdded)
{

    /* To DO
       Use isEmpty function to check

    */
    if (toBeAdded != NULL)
    {
         if (isEmpty(theList))
        {

            theList = toBeAdded;
            toBeAdded->next = NULL;
        }
        else
        {
            toBeAdded->next = theList;
            theList = toBeAdded;

        }


    }

    return theList;
}


/*addToBack(Food * theList, Food * toBeAdded)
Takes a pointer to the head of the list and an initialized list
element. Adds the element to the back of the linked list and
returns a pointer to the head of the list. */
Food * addToBack(Food * theList, Food * toBeAdded)
{
    Food * tempFood;
    tempFood = theList;

    /* To DO
       Use isEmpty function to check

    */
    if (toBeAdded != NULL)
    {

        if (isEmpty(theList))
        {

            theList = toBeAdded;
            toBeAdded->next = NULL;
        }
        else
        {

            while (tempFood->next != NULL)
            {

                tempFood = tempFood->next;

            }

            tempFood->next = toBeAdded;

            toBeAdded->next = NULL;
        }
    }

    return theList;

}


/*removeFromFront(Food * theList)
Takes a pointer to the head of the list. Removes the front
item from the head of the list. Does not free the memory for
the item removed. Returns a pointer to the head of the list.
Returns NULL if the list is empty*/
Food * removeFromFront(Food * theList)
{

    Food * tempFoodOne;


    /* To DO
       Use isEmpty function to check

    */
    if (isEmpty(theList))
    {

       return NULL;
    }

    tempFoodOne = theList;
    theList = theList->next;

    tempFoodOne->next = NULL;

    return theList;

}


/*removeFromBack(Food * theList)
Takes a pointer to the head of the list. Removes the last
item from the head of the list. Does not free the memory for
the item removed. Returns a pointer to the head of the list.
Returns NULL if the list is empty.
*/
Food * removeFromBack(Food * theList)
{

     Food * tempFood;
     Food * newLast;
     newLast = tempFood = theList;

     /* To DO
       Use isEmpty function to check

    */
     if (isEmpty(theList))
    {

       return NULL;
    }
    while (tempFood->next != NULL)
    {
        newLast = tempFood;
        tempFood = tempFood->next;

    }
    newLast->next = NULL;
    tempFood->next = NULL;

    return theList;


}


/*getLastItem(Food * theList)
Takes a pointer to the head of the list. Returns
a pointer to the item at the end of the list.
Returns NULL if the list is empty.
*/
Food * getLastItem(Food * theList)
{
    Food * tempFood;
    tempFood = theList;
    /* To DO
       Use isEmpty function to check

    */
    if (isEmpty(theList))
    {

       return NULL;
    }

     while (tempFood->next != NULL)
     {

        tempFood = tempFood->next;

     }

     return tempFood;
}

/*isEmpty(Food * theList)
Takes a pointer to the head of the list. Returns
true if the list is empty and false
if the list has elements.
*/
bool isEmpty(Food * theList)
{

    if (theList == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }

}


/*printList(Food * theList)
Takes a pointer to the head of the list. Prints to stdout
 all of the elements of the list (formatted
as specified for the printRecord function) separated by newlines.
*/
void printList(Food * theList)
{
    char * stringToPrint = NULL;

    if (!(isEmpty(theList)))
    {
        do
        {
            stringToPrint = printRecord(theList);
            printf("%s \n",stringToPrint);
            free(stringToPrint);
            stringToPrint = NULL;
            theList = theList->next;
        } while (theList != NULL);

    }


}


/*destroyList(Food * theList)
Takes a pointer to the list and frees the memory for each struct in the list.
Handles an empty list gracefully.
*/
void destroyList(Food * theList)
{
    Food * tempList;

    if (!(isEmpty(theList)))
    {
        do
        {

            tempList = theList->next;
            destroyElement(theList);
            free(theList);
            theList = NULL;
            theList = tempList;
        } while (theList != NULL);

    }

}



