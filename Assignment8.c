# Filehandling

/* Name : Shubham Santosh Gholave
Roll no : SYITA139*/

#include <stdio.h>
#include <string.h>
int n;

struct Student
{
  char Address[20];
  char name[15];
  int roll;
  char Div;
};

void acceptdata(struct Student e[], int n)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the Name , Roll Number , Division , Address of the Student : ");
        scanf(" %s %d %c %s", e[i].name, &e[i].roll, &e[i].Div , e[i].Address);
    }
    n++;
}
void writetofile(struct Student e[], int n)
{
    FILE *fp;
    fp = fopen("Student.txt", "a");
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fprintf(fp, "%s %d %c %s", e[i].name, e[i].roll , e[i].Div , e[i].Address);
            fputs("\n", fp);
        }
    }
    fclose(fp);
}

void readfile(int n)
{
    FILE *fp;
    fp = fopen("Student.txt", "r");
    struct Student StuData;
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else 
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%s %d %c %s", StuData.name, &StuData.roll, &StuData.Div , StuData.Address);
            fputs("\n", fp);
            printf("%s %d %c %s \n", StuData.name, StuData.roll, StuData.Div , StuData.Address);
        }
    }
    fclose(fp);
}

void search(int n)
{
    FILE *fp;
    fp = fopen("Student.txt", "r");
    struct Student StuData[10];
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            fscanf(fp, "%s %d %c %s", StuData[i].name, &StuData[i].roll, &StuData[i].Div, StuData[i].Address);
        }
    }
    fclose(fp);
    char name[15];
    printf("Enter the name of Student : ");
    scanf("%s", name);
    for (int i = 0; i < n; i++)
    {
        if (strcmp(StuData[i].name, name) == 0)
        {
            printf("%s %d %c %s.\n", StuData[i].name, StuData[i].roll , StuData[i].Div , StuData[i].Address);
        }
    }
}

void delete ()
{
	int i,j;
    FILE *fp;
    fp = fopen("Student.txt", "r");
    struct Student StuData[50];
    if (fp == NULL)
    {
        printf("Error");
        return;
    }
    else
    {	i=0;
        while(fscanf(fp, "%s %d %c %s", StuData[i].name, &StuData[i].roll, &StuData[i].Div , StuData[i].Address)!=EOF)
        {
            i++;
        }
    }
    fclose(fp);
    
    for (j = 0; j < i; j++){
    	printf("\n%s %d %c %s\n",StuData[j].name, StuData[j].roll , StuData[j].Div , StuData[i].Address);
	}
    
    
    char name[15];
    printf("Enter the name of Student : ");
    scanf("%s", name);
    FILE *f2;
    f2 = fopen("Student.txt", "w");
    if (f2 == NULL)
    {
        printf("Error");
        return;
    }
    else
    {
        for (j = 0; j < i; j++){
            if (strcmp(StuData[j].name, name) == 0)
            {
                continue;
            }
            else
            {
                fprintf(f2, "%s %d %c %s", StuData[j].name, StuData[i].roll , StuData[i].Div , StuData[i].Address);
                fputs("\n", f2);
            } 
        }

    }
    fclose(f2);
    n--;
}


int main()
{
    struct Student e[50];
    int r = 1;
    printf("\n");
    printf(" Enter the total number of Students : ");
    scanf("%d", &n);
    while (r)
    {
        printf(" 1:Accept the data\n 2:Write to the file\n 3:Read the file\n 4:Search in the file\n 5:Delete from the file\n");
        printf("\nEnter the choice : ");

        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            acceptdata(e,n);
            break;
        case 2:
            writetofile(e,n);
            break;
        case 3:
            readfile(n);
            break;
        case 4:
            search(n);
            break;
        case 5:
            delete(e,n);
            break;
        default :
            printf("Wrong choice");
            break;
        }

        printf("Do you want to perform another operation (1) or (0) : ");
        scanf("%d", &r);
    }
    
    return 0;
}
