#include <stdio.h>
#include <stdio.h>
#include <string.h>
#define lvup_atk 200
#define lvup_dfn 100
#define lvup_maxHp 20
#define lvup_maxMp 15
#define T 2

typedef struct pokemon{
    int id;
    char name[10];
    int level;
    int attack;
    int defense;
    int Hp;
    int Mp;
    int maxHp;
    int maxMp;
    int costMp;
}Pokemon;

// TODO: upgrade and recover the Pokémon
void level_up(Pokemon *P);

// TODO: simulate and print the process of the battle
void battle(Pokemon *A, Pokemon *B);

char thename[10][100] = {"Geodude", "Raichu", "Golbat", "Magnemite", "Exeggutor"};

void init();
void init_pokemon(int idx, int atk, int dfn, int hp, int mp, int cmp);

Pokemon myPokemon[1005];
Pokemon initPokemon[10];

int main(){
    init();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int type;
        scanf("%d", &type);
        myPokemon[i] = initPokemon[type];
    }
    int t;
    scanf("%d", &t);
    while(t--){
        int c;
        scanf("%d", &c);
        if(c == 1){
            int a;
            scanf("%d", &a);
            level_up(&myPokemon[a]);
        }
        else{
            int a, b;
            scanf("%d%d", &a, &b);
            battle(&myPokemon[a], &myPokemon[b]);
        }
    }
    return 0;
}

void init(){
    init_pokemon(0, 300, 100, 10, 20, 5);
    init_pokemon(1, 400, 50, 10, 25, 10);
    init_pokemon(2, 200, 80, 10, 15, 3);
    init_pokemon(3, 200, 50, 10, 15, 4);
    init_pokemon(4, 500, 150, 15, 20, 10);
}

void init_pokemon(int idx, int atk, int dfn, int hp, int mp, int cmp){
    strcpy(initPokemon[idx].name, thename[idx]);
    initPokemon[idx].id = idx;
    initPokemon[idx].level = 1;
    initPokemon[idx].attack = atk;
    initPokemon[idx].defense = dfn;
    initPokemon[idx].Hp = hp;
    initPokemon[idx].Mp = mp;
    initPokemon[idx].maxHp = hp;
    initPokemon[idx].maxMp = mp;
    initPokemon[idx].costMp = cmp;
}

void level_up(Pokemon *P)
{
    if(P->level < 5)
    {
        P->level++;
        P->attack += lvup_atk;
        P->defense += lvup_dfn;
        P->maxHp += lvup_maxHp;
        P->maxMp += lvup_maxMp;

        P->Hp = P->maxHp;
        P->Mp = P->maxMp;
    }
}

void battle(Pokemon *A,Pokemon *B)
{
    int turn = 1;
    Pokemon *loser;
    Pokemon *winner;
    while(A->Hp > 0 && B->Hp > 0)
    {
        Pokemon *attacker;
        Pokemon *deffense;
        if(turn%2 == 1)
        {
            attacker = A;
            deffense = B;
        }
        else
        {
            attacker = B;
            deffense = A;
        }
        if(attacker->Mp < attacker->maxMp)
        {
            if(attacker->Mp+T >= attacker->maxMp)
                attacker->Mp = attacker->maxMp;
            else
                attacker->Mp += T;
        }

        if(attacker->Mp >= attacker->costMp)
        {
            attacker->Mp -= attacker->costMp;
            int damage;
            if(attacker->attack - deffense->defense <= 0)
                damage = 0;
            else
                damage = 2*attacker->level*(attacker->attack - deffense->defense)/100;
            deffense->Hp -= damage;
            if(deffense->Hp < 0)
                deffense->Hp = 0;
            
            printf("%s used Headbutt!\n",attacker->name);
            printf("%s now has %d HP.\n",deffense->name,deffense->Hp);
        }
        else
        {
            if(attacker->Mp+T >= attacker->maxMp)
                attacker->Mp = attacker->maxMp;
            else
                attacker->Mp += T;
            printf("%s used Rest!\n",attacker->name);
            printf("%s now has %d MP.\n",attacker->name,attacker->Mp);
        }
        turn++;
    }
    if(A->Hp <= 0)
    {
        A->Hp = 0;
        loser = A;
        winner = B;
    }
            
    if(B->Hp <= 0)
    {
        B->Hp = 0;
        loser = B;
        winner = A;
    }
    printf("%s is the winner! %s died in vain...\n\n",winner->name,loser->name);
}