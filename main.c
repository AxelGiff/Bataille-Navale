#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define COL 10
#define LIN 10

#define GAGNANT true

typedef struct 
{
    int x;
    int y;
    char d;
}Position;


struct Bateau
{
     int petit;
     int moyen;
     int grand;
};

static char grille[LIN][COL];
static char grille_ennemie[LIN][COL];
static char grille_joueur1[LIN][COL];
static char grille_joueur2[LIN][COL];


static char CROIX ='***';
static char SLASH = '/';
bool p=false;

void affiche_grille();
void affiche_grille_ennemie();
void affiche_grille_joueur1();
void affiche_grille_joueur2();
void placer_bateaux(int n);
void placer_bateaux_ennemie(int n);
void resetgrille();
void resetgrille_ennemie();
void resetgrille_joueur1();
void resetgrille_joueur2();
void strike_joueur1();
void strike_joueur2();
int winner(p);
int winner_en(p);

void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

Position strToCoord(char string[], int hasDirection);
Position strToCoord_en(char string[], int hasDirection);





int main()
{

    int count,count2;
    struct Bateau Bat;
    int n;
    int joueur=1;
    int i;
     Bat.petit=2;
    Bat.moyen=3;
    Bat.grand=5;
    do{
            int count=0;


    
    joueur=(joueur %2 )? 1 : 2;
	Color(10,9);
    printf("================================\n");
	printf("        DEBUT DU COMBAT !\n");
	printf("================================\n");
	Color(7,0);
		system("color 9");

	

    resetgrille();
	resetgrille_joueur1();
	resetgrille_joueur2();
    affiche_grille();
    printf(" > Joueur %d : Place le petit bateau (%d cases) \n",joueur,Bat.petit);
    placer_bateaux(Bat.petit);
    affiche_grille();
    printf(" > Joueur %d : Place le moyen bateau (%d cases) \n",joueur,Bat.moyen);
    placer_bateaux(Bat.moyen);
    affiche_grille();
    printf(" > Joueur %d : Place le grand bateau (%d cases) \n",joueur,Bat.grand);
    placer_bateaux(Bat.grand);
    affiche_grille();
    count=1;
    if(count == 1)
    {
    joueur=2;

    resetgrille_ennemie();
    affiche_grille_ennemie();
    printf("Joueur %d : Place le petit bateau (%d cases) \n",joueur,Bat.petit);
    placer_bateaux_ennemie(Bat.petit);
    affiche_grille_ennemie();
    printf("Joueur %d : Place le moyen bateau (%d cases) \n",joueur,Bat.moyen);
    placer_bateaux_ennemie(Bat.moyen);
    affiche_grille_ennemie();
    printf("Joueur %d : Place le grand bateau (%d cases) \n",joueur,Bat.grand);
    placer_bateaux_ennemie(Bat.grand);
    affiche_grille_ennemie();
    affiche_grille();


    }
    }while(i==-1);
	strike_joueur2();
	
    

    

return 0;
}

Position strToCoord(char string[], int hasDirection) {
	Position pos;
	char strX[2 + 1];
	int i;

	if (hasDirection > 0) {
		hasDirection = 1;
		pos.d = string[strlen(string) - 1];
	} else {
		hasDirection = 0;
	}

	pos.y = string[0] - 'a';
	for (i = 0; i < strlen(string)-(1 + hasDirection); i++) {
		strX[i] = string[i + 1];
	}
	for (i + 1; i < strlen(strX); i++) {
		strX[i] = '\0';
	}

	pos.x = strtol(strX, NULL, 10) - 1;

	return pos;
}

Position strToCoord_en(char string[], int hasDirection) {
	Position pos_ennemie;
	char strX[2 + 1];
	int i;

	if (hasDirection > 0) {
		hasDirection = 1;
		pos_ennemie.d = string[strlen(string) - 1];
	} else {
		hasDirection = 0;
	}

	pos_ennemie.y = string[0] - 'a';
	for (i = 0; i < strlen(string)-(1 + hasDirection); i++) {
		strX[i] = string[i + 1];
	}
	for (i + 1; i < strlen(strX); i++) {
		strX[i] = '\0';
	}

	pos_ennemie.x = strtol(strX, NULL, 10) - 1;

	return pos_ennemie;
}


void affiche_grille()
{
 int col;
    int lgn;

    putchar('\n');

    for (col = 0; col < COL; ++col)
        printf("  %c ", col+'A');

    putchar('\n');
    putchar('+');

    for (col = 1; col <= COL; ++col)
        printf("---+");

    putchar('\n');

    for (lgn = 0; lgn < LIN; ++lgn)
    {
        putchar('|');

        for (col = 0; col < COL; ++col)
                printf(" %c |", grille[col][lgn]);
       

        putchar('\n');
        putchar('+');

        for (col = 1; col <= COL; ++col)
            printf("---+");

        putchar('\n');
    }

    for (col = 0; col < COL; ++col)
        printf("  %c ", col + 'A');

    putchar('\n');


}

void affiche_grille_joueur1(){
	int col;
    int lgn;

    putchar('\n');

    for (col = 0; col < COL; ++col)
        printf("  %c ", col+'A');

    putchar('\n');
    putchar('+');

    for (col = 1; col <= COL; ++col)
        printf("---+");

    putchar('\n');

    for (lgn = 0; lgn < LIN; ++lgn)
    {
        putchar('|');

        for (col = 0; col < COL; ++col)
                printf(" %c |", grille_joueur1[col][lgn]);
       

        putchar('\n');
        putchar('+');

        for (col = 1; col <= COL; ++col)
            printf("---+");

        putchar('\n');
    }

    for (col = 0; col < COL; ++col)
        printf("  %c ", col + 'A');

    putchar('\n');

}

void affiche_grille_joueur2(){
	int col;
    int lgn;

    putchar('\n');

    for (col = 0; col < COL; ++col)
        printf("  %c ", col+'A');

    putchar('\n');
    putchar('+');

    for (col = 1; col <= COL; ++col)
        printf("---+");

    putchar('\n');

    for (lgn = 0; lgn < LIN; ++lgn)
    {
        putchar('|');

        for (col = 0; col < COL; ++col)
                printf(" %c |", grille_joueur2[col][lgn]);
       

        putchar('\n');
        putchar('+');

        for (col = 1; col <= COL; ++col)
            printf("---+");

        putchar('\n');
    }

    for (col = 0; col < COL; ++col)
        printf("  %c ", col + 'A');

    putchar('\n');

}


void placer_bateaux(int n)
{
    struct Bateau Bat;
     Position pos;
    Bat.petit=2;
    Bat.moyen=3;
    Bat.grand=5;
    int error;
    int done;

	char c[4 + 1],reponse; // Coordonnées
					
	
	do {
		// Re-init vars
		error = 0;
		done = 0;

		printf("Position de la colonne (a-j), de la ligne (1-10), et de la direction (h/v) ex (a2h ou b5v): ");
		scanf("%s", c);

		pos = strToCoord(c, 1);


		if (pos.x < 0 || pos.y < 0 || pos.x > LIN || pos.y > COL) {
			puts(" > Mauvaises coordonnées...");
			error = 1;
		} else if (pos.d == 'h') {// Vérification placement des bateaux
			// Sortie de carte
			if (pos.y + n > COL) {
				printf(" > Vous ne pouvez pas placer votre bateau ici. Il sortirait de la carte...(y=%i)\n", pos.y);
				error = 1;
			} else {
				// Chevauchements
				for (int i = pos.y; i < pos.y + n; i++) {
					if (grille[i][pos.x] != ' ') {
						puts(" > Il y a déjà un bateau ici...");
						error = 1;

						break;
					}
				}
			}
		} else if (pos.x + n > LIN) {
			printf(" > Vous ne pouvez pas placer votre bateau ici. Il sortirait de la carte...(x=%i)\n", pos.x);
			error = 1;
		} else {
			// Chevauchements
			for (int i= pos.x; i < pos.x + n; i++) {
				if (grille[pos.y][i] != ' ') {
					puts(" > Il y a déjà un bateau ici...");
					error = 1;

					break;
				}
			}
		}

		if (error == 0) {  
			getchar();
			printf("Placement en %c:%i. Est-ce correct ? [o/N] ", pos.y + 'a', pos.x + 1);
			reponse = getchar();
			if (reponse == 'o' || reponse == 'O') {
				done = 1;
			}
		}
	} while (done == 0);

	if (pos.d == 'h') {
		for (int i = pos.y; i < pos.y + n; i++) {
			grille[i][pos.x] = CROIX;
		}
	} else {
		for (int i = pos.x; i < pos.x + n; i++) {
			grille[pos.y][i] = CROIX;
		}
	}
}

void resetgrille()
{
   for(int i = 0; i < LIN; i++)
   {
      for(int j = 0; j < COL; j++)
      {
         grille[i][j] = ' ';
      }
   }
}

void resetgrille_joueur1(){
for(int i = 0; i < LIN; i++)
   {
      for(int j = 0; j < COL; j++)
      {
         grille_joueur1[i][j] = ' ';
      }
   }
}
void resetgrille_joueur2(){
for(int i = 0; i < LIN; i++)
   {
      for(int j = 0; j < COL; j++)
      {
         grille_joueur2[i][j] = ' ';
      }
   }
}

void resetgrille_ennemie()
{
   for(int i = 0; i < LIN; i++)
   {
      for(int j = 0; j < COL; j++)
      {
         grille_ennemie[i][j] = ' ';
      }
   }
}

void affiche_grille_ennemie(){
    int col;
    int lgn;

    putchar('\n');

    for (col = 0; col < COL; ++col)
        printf("  %c ", col +'A');

    putchar('\n');
    putchar('+');

    for (col = 1; col <= COL; ++col)
        printf("---+");

    putchar('\n');

    for (lgn = 0; lgn < LIN; ++lgn)
    {
        putchar('|');

        for (col = 0; col < COL; ++col)
                printf(" %c |", grille_ennemie[col][lgn]);
       

        putchar('\n');
        putchar('+');

        for (col = 1; col <= COL; ++col)
            printf("---+");

        putchar('\n');
    }

    for (col = 0; col < COL; ++col)
        printf("  %c ", col + 'A');

    putchar('\n');

}


void placer_bateaux_ennemie(int n)
{
    struct Bateau Bat;
     Position pos;
    Bat.petit=2;
    Bat.moyen=3;
    Bat.grand=5;
    int error;
    int done;

	char c_ennemie[4 + 1],reponse; // Coordonnées
					
	
	do {
		// Re-init vars
		error = 0;
		done = 0;

		printf("Position de la colonne (a-j), de la ligne (1-10), et de la direction (h/v) ex (a2h ou b5v): ");
		scanf("%s", c_ennemie);

		pos = strToCoord(c_ennemie, 1);


		if (pos.x < 0 || pos.y < 0 || pos.x > LIN || pos.y > COL) {
			puts(" > Mauvaises coordonnées...");
			error = 1;
		} else if (pos.d == 'h') {// Vérification placement des bateaux
			// Sortie de carte
			if (pos.y + n > COL) {
				printf(" > Vous ne pouvez pas placer votre bateau ici. Il sortirait de la carte...(y=%i)\n",pos.y);
				error = 1;
			} else {
				// Chevauchements
				for (int i = pos.y; i < pos.y + n; i++) {
					if (grille_ennemie[i][pos.x] != ' ') {
						puts(" > Il y a déjà un bateau ici...");
						error = 1;

						break;
					}
				}
            }
		} else if (pos.x + n > LIN) {
			printf(" > Vous ne pouvez pas placer votre bateau ici. Il sortirait de la carte...(x=%i)\n", pos.x);
			error = 1;
		} else {
			// Chevauchements
			for (int i= pos.x; i < pos.x + n; i++) {
				if (grille_ennemie[pos.y][i] != ' ') {
					puts(" > Il y a déjà un bateau ici...");
					error = 1;

					break;
				}
			}
		}

		if (error == 0) {
			getchar();
			printf("Placement en %c:%i. Est-ce correct ? [o/N] ", pos.y + 'a', pos.x + 1);
			reponse = getchar();
			if (reponse == 'o' || reponse == 'O') {
				done = 1;
			}
		}
	} while (done == 0);

	if (pos.d == 'h') {
		for (int i = pos.y; i < pos.y + n; i++) {
			grille_ennemie[i][pos.x] = CROIX;
		}
	} else {
		for (int i = pos.x; i < pos.x + n; i++) {
			grille_ennemie[pos.y][i] = CROIX;
		}
	}
     
}


void strike_joueur1(){
	char m[3+1];
	Position pos;
	struct Bateau Bat;
	Bat.petit=2;
	Bat.moyen=3;
	Bat.grand=5;
	int n=3;
	
	int done;

	    do{
				int count=0;
				int count2=0;
					int countbat=0;


	        done=0;
		printf("> Joueur (1) -> colonne ( 1-10 ) : \n");
	    scanf("%d",&pos.x);
	    pos.x--;
	    
		printf("> Joueur (1) -> ligne ( 1-10 ) : \n");
	    scanf("%d",&pos.y);
	    pos.y--;
	    for(int i=0;i<LIN;i++)
	    {
	        for(int j=0;j<COL;j++)
	        {
	            
	        if(grille_joueur1[i][j]==SLASH)
			{
				count++;
			}
			if(grille_joueur1[i][j]==CROIX)
			{
				count2++;
			}
	    
	    if(grille_ennemie[pos.x][pos.y]==CROIX)
	    {
			grille_joueur1[pos.x][pos.y] = SLASH;
			
		}
		else if(grille_ennemie[pos.x][pos.y]==' ')
	    {
	        strike_joueur2();
	    }
	    else if(grille_joueur1[pos.x][pos.y]==SLASH)
	    {
            printf("Vous avez deja tire a cette endroit !\n");
            break;
	    }
		
		
	    else
	    {
	        done=1;
	        break;
	    }
			
	        }
	    affiche_grille_joueur1();
		
	    }
		winner(p);
			

		
		if(count==10)
		{
			printf("================================\n");
			printf("       LE JOUEUR 1 GAGNE !\n");
			printf("================================\n");
			exit(1);

			done=1;
		}
		
	    }while(done==0);
		
		
					

		

}

void strike_joueur2(){
	char m[3+1];
	Position posj1;
	int count;
	int done;

	    do{
			int count=0;
	        done=0;
		printf("> Joueur numero 2 -> colonne ( 1-10 ) : \n");
	    scanf("%d",&posj1.x);
	    posj1.x--;
	    
	    printf(">Joueur numero 2 -> ligne ( 1-10 ): \n");
	    scanf("%d",&posj1.y);
	    posj1.y--;
	    for(int i=0;i<LIN;i++)
	    {
	        for(int j=0;j<COL;j++)
	        {
	            
	        
	    
	    if(grille[posj1.x][posj1.y]==CROIX)
	    {
			grille_joueur2[posj1.x][posj1.y] = SLASH;
			
		}
		else if(grille[posj1.x][posj1.y]==' ')
	    {
	        strike_joueur1();
	    }
	    else if(grille_joueur2[posj1.x][posj1.y]==SLASH)
	    {
            printf("Vous avez deja tire a cette endroit !\n");
            break;
	    }
	    else
	    {
	        done=1;
	        break;
	    }
	        }
	    affiche_grille_joueur2();
		
	    }
		winner_en(p);
		
		if(count==10)
		{
			printf("Joueur WOW Gagnant !\n");
			done=1;
		}
	    }while(done==0);	
}

int winner(p){
	int count=0;
	for(int i=0;i<LIN;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(grille_joueur1[i][j]==grille_ennemie[i][j])
			{
				count++;
			}
			else{
				continue;
			}
		}
	}
	
	return p;
}

int winner_en(p){
	int count=0;
	for(int i=0;i<LIN;i++)
	{
		for(int j=0;j<COL;j++)
		{
			if(grille_joueur2[i][j]==SLASH && grille_joueur2[i][j]!=CROIX)
			{
				count++;
			}
			else{
				continue;
			}
		}
	}
	if(count==10)
	{
		printf("================================\n");
		printf("       LE JOUEUR 2 A GAGNE !\n");
		printf("================================\n");		
		exit(1);
	}
	return p;
}
