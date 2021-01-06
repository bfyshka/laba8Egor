#include <iostream>

struct abitur
{
    int number;
    char firstname[20];
    char lastname[20];
    char secondname[20];
    float mark;
};

abitur *add_structure(abitur *information, int number)
{
    if (number == 0)
        information = new abitur[number + 1];
    else
    {
        abitur *tmp = new abitur[number + 1];
        for (int i = 0; i < number; i++)
            tmp[i] = information[i];
        information = tmp;
    }
    return information;
}

void input(abitur *information, int number)
{
    information[number].number = number;
    printf("Enter the abitur's full name: ");
    scanf("%s", information[number].lastname);
    scanf("%s", information[number].firstname);
    scanf("%s", information[number].secondname);

    printf("Enter the average mark: ");
    scanf("%f", &information[number].mark);
}

void output(abitur *information, int numberr)
{
    printf("\nAbitur's number: %d\n", information[numberr].number);
    printf("Abitur's full name: %s", information[numberr].lastname);
    printf(" %s", information[numberr].firstname);
    printf(" %s\n", information[numberr].secondname);
    printf("Abitur's average mark: %f\n", information[numberr].mark);
}

void output2(abitur *information, int numberr)
{
    printf("Abitur's full name: %s", information[numberr].lastname);
    printf(" %s", information[numberr].firstname);
    printf(" %s\n", information[numberr].secondname);
    printf("Abitur's average mark: %f\n", information[numberr].mark);
}

void editstruct(abitur *information, int number)
{
    int edit;
    printf("Enter the field number to change (1 - Full name 2 - Average Mark): ");
    scanf("%d", &edit);

    switch (edit)
    {
    case 1:
        printf("Enter new abitur's full name: ");
        scanf("%s", information[number].lastname);
        scanf("%s", information[number].firstname);
        scanf("%s", information[number].secondname);
        break;

    case 2:
        printf("Enter new abitur's average mark: ");
        scanf("%f", &information[number].mark);
        break;
    }
}

void sorting(abitur *information, int number)
{
    for (int i = 0; i <= number; i++)
    {
        float tmp = information[0].mark;
        char tmpfirstname[20];
        char tmplastname[20];
        char tmpsecondname[20];
        for (int j = i + 1; j <= number; j++)
        {
            if (information[i].mark > information[j].mark)
            {
                tmp = information[i].mark;
                information[i].mark = information[j].mark;
                information[j].mark = tmp;

                for (int k = 0; k < 20; k++)
                {
                    tmpfirstname[k] = information[i].firstname[k];
                    information[i].firstname[k] = information[j].firstname[k];
                    information[j].firstname[k] = tmpfirstname[k];

                    tmplastname[k] = information[i].lastname[k];
                    information[i].lastname[k] = information[j].lastname[k];
                    information[j].lastname[k] = tmplastname[k];

                    tmpsecondname[k] = information[i].secondname[k];
                    information[i].secondname[k] = information[j].secondname[k];
                    information[j].secondname[k] = tmpsecondname[k];
                }
            }
        }
    }
    float average;
    for (int i = 0; i <= number; i++)
        average += information[i].mark;
    average /= number;

    for(int i = 0; i <= number; i++)
    {
        if(information[i].mark > average)
            output2(information, i);
    }
}

int main()
{
    int number = 0;
    abitur *information = 0;
    int add;

    do
    {
        information = add_structure(information, number);
        input(information, number);
        number++;
        printf("Do you want to continues entering abitur data? (1 - Yes, 0 - No) ");
        scanf("%d", &add);
    } while (add != 0);

    int tmp;
    do
    {
        printf("\n\n");
        printf("Choose the action with Abiturs:");
        printf("\n 0 - Exit\n 1 - Abiturs output\n 2 - Abiturs change\n");
        printf(" 3 - Add new abitur\n 4 - Sort and output\n");
        scanf("%d", &tmp);

        switch (tmp)
        {
        case 1:
            for (int i = 0; i < number; i++)
                output(information, i);
            break;

        case 2:
            int edit;
            printf("Enter abitur's number: ");
            scanf("%d", &edit);

            if (number < edit)
                printf("This client doesn't exist!");
            else
                editstruct(information, edit);
            break;

        case 3:
            information = add_structure(information, number);
            input(information, number);
            number++;
            break;

        case 4:
            sorting(information, number);
            tmp = 0;
            break;

        default:
            break;
        }
    } while (tmp != 0);
}
