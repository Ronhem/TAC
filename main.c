#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

//structless player struct
char name[30];
int lv = 1;
int hp = 10;
int maxhp = 10;
int mp = 5;
int maxmp = 5;
int str = 2;
int def = 2;
int mag = 2;
int xp = 0;
int money = 100;

//pointers for the player
char* name_p = &name[30];
int* lv_p = &lv;
int* hp_p = &hp;
int* maxhp_p = &maxhp;
int* mp_p = &mp;
int* maxmp_p = &maxmp;
int* str_p = &str;
int* def_p = &def;
int* mag_p = &mag;
int* xp_p = &xp;
int* money_p = &money;

//generic enemy
struct enemies
{
    int eHp;
    int eStr;
    int eMoney;
    int eXP;
    char eName[30];
};

void fight(struct enemies* enemiesName)
{
    bool fightHappening = true;
    int optionFight;
    while(fightHappening != false)
    {
        if(enemiesName->eHp <= 0)
        {

        }
        printf("----------\n");
        printf("|%s\n", enemiesName->eName);
        printf("|1-Attack\n");
        printf("|2-Defend\n");
        printf("|3-Evade\n");
        printf("|4-Magic\n");
        printf("|5-Heal\n");
        scanf("%d", &optionFight);
        switch(optionFight)
        {
            case 1:
            enemiesName->eHp - *str_p;
            printf("--------------\n");
            printf("|Damage: %d", str_p);
            printf("--------------\n");
        }
    }
}

//creates an ID for the enemy to spawn in battle
void enemyCreator(int enemyID)
{
    int optionFightStart;
    switch(enemyID)
    {
        case 1:
        struct enemies* slime = NULL;
        slime = (struct enemies*)
        malloc(sizeof(struct enemies));
        slime->eHp = 4;
        slime->eStr = 2;
        slime->eMoney = 40;
        slime->eXP = 50;
        strcpy(slime->eName, "Slime");
        printf("-------------------\n");
        printf("|%s\n", slime->eName);
        printf("|HP: %d\n", slime->eHp);
        printf("----------\n");
        printf("|1-Fight.|\n");
        printf("|2-Run.  |\n");
        printf("----------\n");
        scanf("%d", &optionFightStart);
        if(optionFightStart == 1)
        {
            fight(slime);
        }
        else
        {
            printf("Ran away.\n");
            system("read -p 'Press Enter to continue...' var");
        }
        break;

        case 2:
        struct enemies* goblin = NULL;
        goblin = (struct enemies*)
        malloc(sizeof(struct enemies));
        goblin->eHp = 6;
        goblin->eStr = 3;
        goblin->eMoney = 60;
        goblin->eXP = 80;
        strcpy(goblin->eName, "Goblin");
        printf("-------------------\n");
        printf("|%s\n", goblin->eName);
        printf("|HP: %d\n", goblin->eHp);
        printf("|1-Fight.\n");
        printf("|2-Run.\n");
        scanf("%d", &optionFightStart);
        if(optionFightStart == 1)
        {
            fight(goblin);
        }
        else
        {
            printf("Ran away.\n");
            system("read -p 'Press Enter to continue...' var");
        }
        break;

        case 3:
        struct enemies* deathRider = NULL;
        deathRider = (struct enemies*)
        malloc(sizeof(struct enemies));
        deathRider -> eHp = 25;
        deathRider -> eStr = 5;
        deathRider -> eMoney = 80;
        deathRider -> eXP = 120;
        strcpy(deathRider->eName, "Death Rider\0");
        printf("-------------------\n");
        printf("|%s\n", deathRider->eName);
        printf("|HP: %d\n", deathRider->eHp);
        printf("|1-Fight.\n");
        printf("|2-Run.\n");
        scanf("%d", &optionFightStart);
        if(optionFightStart == 1)
        {
            fight(deathRider);
        }
        else
        {
            printf("Can't run away!\n");
            system("read -p 'Press Enter to continue...' var");
            fight(deathRider);
        }
        break;

    }
}

void sStatsMenu()
{
    printf("-----------------\n");
    printf("|Name: %s\n", name);
    printf("|HP: %i\n", *hp_p);
    printf("|MP: %i\n", *mp_p);
    printf("|Money: %i\n", *money_p);
    printf("-----------------\n");
}

void checkStats()
{
    printf("\n-----------------\n");
    printf("|STR: %i\n", *str_p);
    printf("|DEF: %i\n", *def_p);
    printf("|MAG: %i\n", *mag_p);
    printf("|XP: %i\n", *xp_p);
    printf("-----------------\n");
    system("read -p 'Press Enter to continue...' var");
}

void healingFountain()
{
    int optionHeal;
        printf("Return to full HP and MP?\n");
        printf("price: 100$\n");
        printf("1-Yes\n");
        printf("2-No\n");
        scanf("%i", &optionHeal);
        if(optionHeal == 1)
        {
            *money_p -= 100;
            *hp_p = *maxhp_p;
            *mp_p = *maxmp_p;
            printf("Healed sucessfully.\n");
            system("read -p 'Press Enter to continue...' var");
        }
}

void optionsMenu(int optionValue)
{
    printf("-----------------\n");
    printf("|1- Check Stats.|\n");
    printf("|2- Battle.     |\n");
    printf("|3- Heal.       |\n");
    printf("|4- Store.      |\n");
    printf("|5- Save.       |\n");
    printf("|0- Exit.       |\n");
    printf("-----------------\n");
    scanf("%i",&optionValue);
    switch(optionValue)
    {
        case 1:
        checkStats();
        break;

        case 2:
        enemyCreator(1);
        break;

        case 3:
        healingFountain();
        break;

        case 4:
        printf("store stil not available :(\n");
        system("read -p 'Press Enter to continue...' var");
        break;

        case 5:
        printf("Save still not available :(\n");
        system("read -p 'Press Enter to continue...' var");
        break;

        case 0:
        exit(0);
        break;

        default:
        break;
    }
}

//calls the tutorial text.
void tutorial()
{
    printf("---------------------\n");
    printf("|        TAC        |\n");
    printf("|Text Adventure in C|\n");
    printf("---------------------\n");
    printf("Welcome to TAC, the text adventure made in C. \n");
    printf("this is made for the simple purpose of me learning C\n");
    printf("and doing something dumb while I'm at it.\n");
    printf("Every single action is based on the number of the\n");
    printf("button that you input.\n\n");
    system("read -p 'Press Enter to continue...' var");
    system("clear");
    printf("Well then, how about telling me your name?\n");
    printf("Name: ");
    scanf("%s", &name);
    printf("Welcome, %s\n", name);
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

int main()
{
    int option = 1;
    bool isFirstLoop = true;
    while(option != 0)
    {
        if(isFirstLoop == true)
        {
            tutorial();
            isFirstLoop = false;
        }
        sStatsMenu();
        optionsMenu(option);
        system("clear");
    }
}
