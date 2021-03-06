/*******************************************************************************
* File Name          : Dice roll.c
* Description        : this program is for simulation of 6 dices rolled for number of times untill it gets same number, "winiteration" times and also 
*						shows the number of times the dices rolled to meet the above condition
* Author:              Santhosh Nagendran
* Date:                Mar 15, 2019
******************************************************************************
*/

#include "pch.h"
#include <stdio.h>
#include<stdlib.h>
#include<time.h>

#define winiteration 4  //total number of dices to be showed the same numbers out of 6 <this should be 1 to 6>



// FUNCTION      : rolldice
// DESCRIPTION   :
//   this function is used to roll 6 dices all togather to get the random numbers
// PARAMETERS    :
//   count - number of times, set of dices rolled
//
// RETURNS       :
//   count value
int rolldice(int count)
{
	int i, n = 7, a[6],flag1=0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0, flag6 = 0;
	time_t t;
	srand((unsigned)time(&t)); //generates random number with irrespect of time, to make sure that it is totally generating different numbers every time
	for (i = 1; i < n; i++)
	{
		a[i] = rand() % 6;
		if (a[i] == 0)
		{
			a[i] = 6;
		}
		printf("the lucky number in dice %d is %d\n", i, a[i]);
	}
	count++;
	printf("the count of 6 dices rolled is %d\n", count);
	for (int i = 0; i < 10; i++)
	{
		if (a[i] == 1)
		{
			flag1++;
		}
		else if (a[i] == 2)
		{
			flag2++;
		}
		else if (a[i] == 3)
		{
			flag3++;
		}
		else if (a[i] == 4)
		{
			flag4++;
		}
		else if (a[i] == 5)
		{
			flag5++;
		}
		else if (a[i] == 6)
		{
			flag6++;
		}
	}
	if (flag1  >= winiteration)
	{
		printf("you won\n");
		printf("with the number '1' which repeated more than or equal to %d times\n", winiteration);
		count = 1001;
		return count;
	}
	else if (flag2 >= winiteration)
	{
		printf("you won\n");
		printf("with the number '2' which repeated more than or equal to %d times\n", winiteration);
		count = 1001;
		return count;
	}
	else if (flag3 >= winiteration)
	{
		printf("you won\n");
		printf("with the number '3' which repeated more than or equal to %d times\n", winiteration);
		count = 1001;
		return count;
	}
	else if (flag4 >= winiteration)
	{
		printf("you won\n");
		printf("with the number '4' which repeated more than or equal to %d times\n", winiteration);
		count = 1001;
		return count;
	}
	else if (flag5 >= winiteration)
	{
		printf("you won\n");
		printf("with the number '5' which repeated more than or equal to %d times\n", winiteration);
		count= 1001;
		return count;
	}
	else if (flag6 >= winiteration)
	{
		printf("you won\n");
		printf("with the number '6' which repeated more than or equal to %d times\n", winiteration);
		count= 1001;
		return count;
	}
	else
	{
		return count;
	}
	
}

int main()
{
	int a,count=0;
	a = rolldice(count);
	for(a;a<1000;a++)
	{
		a = rolldice(a);
		a = a - 1;
	}

}
