#include<stdio.h>
//Courtesy of Epameinondas Mataragas!!! still in progress!
#include<stdlib.h>
int main(void)
{
	double kostosag,kostospol;
	int x,ch,ari8,epilogi;
	char proion[50];
x = 1;
while(x==1)
{
printf("Menu\n------\nPress 1 to insert new item\n2 To delete an item\n3 Change buying price\n4 Change selling price\n5 Change quantity of items (increment or decrement)\n6 Search for a item or information about it\n");
scanf("%d",&epilogi);
while(getchar() != '\n');
if(epilogi==1)
{
	printf("Provide item name!!\n");
	gets(proion);
	printf("Provide buying price of item\n");
	scanf("%lf",&kostosag);	
	printf("Provide selling price of item\n");
	scanf("%lf",&kostospol);
	printf("Provide number of items\n");
	scanf("%d",&ari8);
	FILE *fp;
	fp = fopen(proion,"w");
	if(fp !=NULL)
	{
		fprintf(fp,"Buying Price = %.2f   Selling Price = %.2f   Number of items = %d",kostosag,kostospol,ari8);
	}
	
	if(fp == NULL)
	{
	printf("Error: File can not be opened\n");
	exit(1);	
	}
	
}
else if(epilogi == 2)
{
	printf("Provide the name of item that you want to be deleted! If you chose 2 by mistake and you don't want to delete a file type 0!\n");
	printf("Provide item name!\n");
	gets(proion);
	if(proion)
	remove(proion);
}
else if(epilogi == 3)
{
	printf("Provide item name!\n");
	gets(proion);
	FILE *fp;
	fp = fopen(proion,"r+");
	if(fp == NULL)
	{
	printf("Error: File can not be opened\n");
	exit(1);	
	}	
	printf("Provide new buying price\n");
	scanf("%lf",&kostosag);
	fseek(fp,16,SEEK_SET);
	if(fp !=NULL)
	{
		fprintf(fp,"%.2f",kostosag);
	}
	
}
else if(epilogi == 4)
{
	printf("Provide item name!\n");
	gets(proion);
	FILE *fp;
	fp = fopen(proion,"r+");
	if(fp == NULL)
	{
	printf("Error: File can not be opened\n");
	exit(1);	
	}	
	printf("Provide new selling price\n");
	scanf("%lf",&kostospol);
	fseek(fp,41,SEEK_SET);
	if(fp !=NULL)
	{
		fprintf(fp,"%.2f",kostospol);
	}
	
}
else if(epilogi == 5)
{
	printf("Provide item name!\n");
	gets(proion);
	FILE *fp;
	fp = fopen(proion,"r+");
	if(fp == NULL)
	{
	printf("Error: File can not be opened\n");
	exit(1);	
	}	
	printf("Provide new item ID\n");
	scanf("%d",&ari8);
	fseek(fp,71,SEEK_SET);
	if(fp !=NULL)
	{
		fprintf(fp,"%d",ari8);
	}
	
}
else if(epilogi == 6)
{
	printf("Dose onoma proiontos!!\n");
	gets(proion);
	FILE *fp;
	fp = fopen(proion,"r");
	if(fp == NULL)
	{
	printf("Error: File can not be opened\n");
	exit(1);	
	}
	while(1)
	{
		ch = getc(fp);
		if(ch==EOF)
			break;
		printf("%c",ch);
	}
	fclose(fp);
	printf("\n");
}
printf("If you want to restart the program press 1 if you want to kill it press 0\n");
scanf("%d",&x);
}
}
