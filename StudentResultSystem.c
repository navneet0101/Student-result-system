#include<stdio.h>
#include<stdlib.h>
int rollNo, marks[3], total;
char name[15];
float percentage;
FILE *f;
void add_new_student_details()
{
    int ch;
    f = fopen("SRS.txt", "a");
    do
    {
        system("cls");
        int i;
        printf("\nEnter roll number of student\n");
        scanf("%d", &rollNo);
        fprintf(f, "%d ", rollNo);
        printf("\nEnter name\n");
        scanf("%s", name);
        fprintf(f, "%s ", name);
        total = 0;
        for(i = 0; i <= 2; i++)
        {
            printf("\nEnter marks of subject %d\n", i + 1);
            scanf("%d", &marks[i]);
            fprintf(f, "%d ", marks[i]);
            total += marks[i];
        }
        fprintf(f, "%d ", total);
        percentage = (float)total / 300 * 100;
        fprintf(f, "%f ", percentage);
        printf("\nEnter 1 to add another student details\n");
        scanf("%d", &ch);
    }
    while(ch == 1);
    fclose(f);
    printf("\nStudent(s) details are added successfully\n");
}
void view_all_student_details()
{
    system("cls");
    f = fopen("SRS.txt", "r");
    if (f != NULL)
    {
        int i;
        printf("\nDetails of all students\n");
        while(fscanf(f, "%d%s", &rollNo, name) != EOF)
        {
            printf("\nRoll Number: %d\nName: %s\n", rollNo, name);
            for(i = 0; i <= 2; i++)
            {
                fscanf(f, "%d", &marks[i]);
                printf("Marks of subject %d: %d\n", i + 1, marks[i]);
            }
            fscanf(f, "%d%f", &total, &percentage);
            printf("Total: %d\nPercentage: %.2f\n", total, percentage);
        }
    }
    else
    {
        printf("\nNo student details to view\n");
    }
}
void search_student_details()
{
    system("cls");
    f = fopen("SRS.txt", "r");
    if(f != NULL)
    {
        int i, r, found = 0;
        printf("\nEnter student roll number\n");
        scanf("%d", &r);
        while(fscanf(f, "%d%s", &rollNo, name) != EOF)
        {
            for(i = 0; i <= 2; i++)
            {
                fscanf(f, "%d", &marks[i]);
            }
            fscanf(f, "%d%f", &total, &percentage);
            if(rollNo == r)
            {
                found = 1;
                printf("\nRoll Number: %d\nName: %s\n", rollNo, name);
                for(i = 0; i <=2; i++)
                {
                    printf("Marks of subject %d: %d\n", i + 1, marks[i]);
                }
                break;
            }
        }
        if(!found)
        {
            printf("\nStudent of %d roll number does not exist\n", r);
        }
    }
    else
    {
        printf("\nNo student details to search\n");
    }
}
int main()
{
    int ch;
    do
    {
        system("cls");
        printf("\nEnter 1 to add new student details\n");
        printf("Enter 2 to view all students details\n");
        printf("Enter 3 to search student details\n");
        printf("Enter 4 to exit from application\n");
        printf("\nEnter your choice\n");
        scanf("%d", &ch);
        switch(ch)
        {
        case 1:
            add_new_student_details();
            break;
        case 2:
            view_all_student_details();
            break;
        case 3:
            search_student_details();
            break;
        case 4:
            exit(0);
        }
        printf("\nEnter 1 to goto main menu\n");
        scanf("%d", &ch);
    }
    while(ch == 1);
    return 0;
}
