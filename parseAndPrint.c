#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <ctype.h>
#include <math.h>

#include "linkedList.h"
#include "parseAndPrint.h"

void parseAndGetEachFoodElements(char buffer[],char ** foodName,char ** foodGroup,double * foodCalories, char * foodType)
{

    char * strToken;

    strToken = strtok(buffer," , ");
    *foodName = malloc(sizeof(char)*(strlen(strToken)+1));
    strcpy(*foodName,strToken);

    strToken = strtok(NULL," , ");
    *foodGroup = malloc(sizeof(char)*(strlen(strToken)+1));
    strcpy(*foodGroup,strToken);

    strToken = strtok(NULL," , ");
    sscanf(strToken, "%lf", foodCalories);

    strToken = strtok(NULL," , ");
    *foodType = strToken[0];

    free(strToken);


}



void printTotalCalories(Food * head)
{
    double totalCalories = 0;

    if (!(isEmpty(head)))
    {
        do
        {

            totalCalories += head->calories;
            head = head->next;
        } while (head != NULL);

        totalCalories = ceilf(totalCalories);
        printf("%.0f \n",totalCalories);
    }



}




void printCaloriesPerItem(Food * head)
{
    /* vegfruit, meat, dairy, grains, fat */
    double calories[5] = {0.0};
    int count[5] = {0};
    char temp[10];
    int i = 0;
    if (!(isEmpty(head)))
    {

        do
        {

            strcpy(temp,head->foodGroup);
            for (i = 0;i < (strlen(temp)); i++)
            {
                temp[i] = tolower(temp[i]);
            }


            if (strcmp(temp,"vegfruit") == 0)
            {
                calories[0] += head->calories;
                count[0] = count[0] + 1;

            }
            else if (strcmp(temp,"meat") == 0)
            {

                calories[1] += head->calories;
                count[1] = count[1] + 1;

            }
            else if (strcmp(temp,"dairy") == 0)
            {

                calories[2] += head->calories;
                count[2] = count[2] + 1;

            }
            else if (strcmp(temp,"grains") == 0)
            {

                calories[3] += head->calories;
                count[3] = count[3] + 1;

            }
            else if (strcmp(temp,"fat") == 0)
            {

                calories[4] += head->calories;
                count[4] = count[4] + 1;

            }


            head = head->next;
        } while (head != NULL);

        for (i=0; i<5; i++)
        {
            if (count[i] > 0)
            {
                calories[i] = ceilf((calories[i] / (count[i])) * 100) / 100;
                printf("%.2f \n",calories[i]);
            }
			else
            {
                printf("0.00 \n");
            }

        }

    }




}

