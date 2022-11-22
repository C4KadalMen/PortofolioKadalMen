#include <stdio.h>
#include <stdlib.h>

int width;
int tempX = 0;
int tempY = 0;
int tempCut;
int indent;
int spacer;
int choice;

void ErrHandler() //Handles Error
{
	if(width > 64)
	{
		printf("ERR_01: Width TOO LARGE!\n");
		exit(0);
	}
	if(width < 0)
	{
		printf("ERR_02: Width cannot be NEGATIVE!\n");
		exit(0);
	}
	if(width == 0)
	{
		printf("ERR_03: Width cannot be ZERO!\n");
		exit(0);
	}
}

void decideChar()
{
	if(tempX == 0)
	{
		printf("/");
	}
	else if(tempX == (tempCut * 2) - 1)
	{
		printf("\\");
	}
	else
	{
		if(tempY == (width - 1))
		{
			printf("_");
		}
		else
		{
			printf(" ");
		}
	}
}

void renderDoubleTriangle()
{
	while(tempY != width) //Decide to loop until tempY is same as width
	{
		if(spacer == 0)
		{
			decideChar();
			tempX += 1;
			if(tempX >= (tempCut * 2))
			{
				printf("\n");
				tempY += 1;
				tempX = 0;
				tempCut += 1;
				indent -= 1;
				spacer = indent;
			}
		}
		else
		{
			printf(" ");
			spacer -= 1;
		}
	}
}

int main()
{
	printf("Width(Max. 64) : ");
	scanf("%i", &width);
	ErrHandler(); // Call ErrorHandler
	tempCut = 1;
	indent = width - 1;
	spacer = indent; // To make TEMPORARY version of indent
	renderDoubleTriangle();
}