#include "pch.h"
#include <stdio.h>

char note[1000];
int Record_Length = 0;

int main()
{
	char notes;
	int mode;
	printf("enter '1' to start recording the notes\n");
	scanf_s("%d",&mode);
	if (mode == 1)
	{		
		printf("start recording and to stop recording press s\n");
		for (int i = 0; i < 1000; i++)
		{
			scanf_s("%c", &notes);
			if (notes == 's')
			{
					printf("the notes that you have typed in are\n");
					if (Record_Length == 1)
					{
						printf("nothing played\n");
						break;
					}
					else
					{
						for (int i = 0; i < Record_Length; i++)
						{
							printf("%c", note[i]);
						}
						break;
					}
			}
			else
			{
				note[i] = notes;
				Record_Length+=1;
			}
		}
	}
	else
	{
		printf("thank you\n");
	}
	 
}
