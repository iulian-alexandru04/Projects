#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include <limits.h>
#include<cmath>


int n,jucatori,nivel_nisip,REZULTAT,m, piese[5], indicatori[8][2],jet;//n carti de nisip
char j_tab[19][50],j_abil[6][51];






struct tab {
  int abil, niv_nis, nr_jucatori,ab_viz, piese_t[5];
} t[6][6];

struct jucator{
  int abil,niv_apa, col_p, lin_p,numar, numar_mutari,b1,b2;
  char  *nume;
} j[7];

int * random (int n)
{
  int *v = (int *) malloc ( (n + 1) * sizeof(int) );
  int i, r, d;
  for ( i = 1; i <= n; i++) v[i]=i;
  for (i = n; i > 1; i--) {
    r = 1 + rand() % (i);
    d = v[i];
    v[i] = v[r];
    v[r] = d;
  }
  return v;
}

void jos(int i)
{
   t[j[i].lin_p][j[i].col_p].nr_jucatori--;
   t[j[i].lin_p+1][j[i].col_p].nr_jucatori++;
   j[i].lin_p++;
   j[i].numar_mutari--;}

void dreapta(int i)
{
t[j[i].lin_p][j[i].col_p].nr_jucatori--;
   t[j[i].lin_p][j[i].col_p+1].nr_jucatori++;
   j[i].col_p++;
   j[i].numar_mutari--; }

void sus(int i)
{ t[j[i].lin_p][j[i].col_p].nr_jucatori--;
   t[j[i].lin_p-1][j[i].col_p].nr_jucatori++;
   j[i].lin_p--;
   j[i].numar_mutari--;}

void stanga(int i)
{

   t[j[i].lin_p][j[i].col_p].nr_jucatori--;
   t[j[i].lin_p][j[i].col_p-1].nr_jucatori++;
   j[i].col_p--;
   j[i].numar_mutari--;
}



void afisare(){

	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",char(201),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(203),char(205),char(205),char(205));
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(203),char(205),char(205),char(205),char(205),char(205),char(205),char(205));
	printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(203),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205));
	printf("%c%c%c%c%c",char(205),char(205),char(205),char(205),char(203));printf("%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205));
	printf("%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205));printf("%c%c%c%c",char(205),char(205),char(205),char(187));
	printf("\n");printf("%c",char(186));

	for(int i=1;i<=5;i++){
		for(int k=1;k<=5;k++)
			if(t[i][k].abil==17)
			{printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
			else
				printf("\t\t%c",char(186));



		//##############################


		if(jucatori==1){

			for(int k=1;k<=5;k++){
				if(t[i][k].abil!=17)
					if(t[i][k].nr_jucatori)

						if(j[1].lin_p==i && j[1].col_p==k)
							printf(" %s\t%c",j[1].nume,char(186));
						else printf("\t\t%c",char(186));
					else printf("\t\t%c",char(186));
				else {printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
			}

			for(int j=1;j<=5;j++)if(t[i][j].abil==17)
			{printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
			else
				printf("\t\t%c",char(186));}


		else if(jucatori==2){
			for(int hh=1;hh<=2;hh++)
				for(int k=1;k<=5;k++){
					if(t[i][k].abil!=17)
						if(t[i][k].nr_jucatori)

							if(j[hh].lin_p==i && j[hh].col_p==k)
								printf(" %s\t%c",j[hh].nume,char(186));
							else printf("\t\t%c",char(186));
						else printf("\t\t%c",char(186));
					else {printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
				}

				for(int j=1;j<=5;j++)if(t[i][j].abil==17)
				{printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
				else
					printf("\t\t%c",char(186));}


		else if(jucatori==3){
			for(int hh=1;hh<=3;hh++)
				for(int k=1;k<=5;k++){
					if(t[i][k].abil!=17)
						if(t[i][k].nr_jucatori)

							if(j[hh].lin_p==i && j[hh].col_p==k)
								printf(" %s\t%c",j[hh].nume,char(186));
							else printf("\t\t%c",char(186));
						else printf("\t\t%c",char(186));
					else {printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
				}

				for(int j=1;j<=5;j++)if(t[i][j].abil==17)
				{printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
				else
					printf("\t\t%c",char(186));}

		else if(jucatori==4){
			for(int hh=1;hh<=4;hh++)
				for(int k=1;k<=5;k++){
					if(t[i][k].abil!=17)
						if(t[i][k].nr_jucatori)

							if(j[hh].lin_p==i && j[hh].col_p==k)
								printf(" %s\t%c",j[hh].nume,char(186));
							else printf("\t\t%c",char(186));
						else printf("\t\t%c",char(186));
					else {printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
				}

				for(int j=1;j<=5;j++)if(t[i][j].abil==17)
				{printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
				else
					printf("\t\t%c",char(186));}

		else if(jucatori==5){
			for(int hh=1;hh<=5;hh++)
				for(int k=1;k<=5;k++){
					if(t[i][k].abil!=17)
						if(t[i][k].nr_jucatori)

							if(j[hh].lin_p==i && j[hh].col_p==k)
								printf(" %s\t%c",j[hh].nume,char(186));
							else printf("\t\t%c",char(186));
						else printf("\t\t%c",char(186));
					else {printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
				}

				for(int j=1;j<=5;j++)if(t[i][j].abil==17)
				{printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
				else
					printf("\t\t%c",char(186));}






	//############################################

	for(int j=1;j<=5;j++)
		if(t[i][j].abil==17)
		{printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
		else if(t[i][j].abil==0)
			printf("\t\t%c",char(186));
		else if(t[i][j].ab_viz==1)printf("Abilitate: \t%c",char(186));
		else if(t[i][j].ab_viz==0) printf("\t\t%c",char(186));


		for(int j=1;j<=5;j++){
			if(t[i][j].abil==17){printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
			else if(t[i][j].abil==0)printf("\t\t%c",char(186));
			else if(t[i][j].ab_viz==1)printf("%s\t%c",j_tab[t[i][j].abil],char(186));
			else printf("\t\t%c",char(186));}
		for(int j=1;j<=5;j++)
			if(t[i][j].abil==17){printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
			else
				printf("\t\t%c",char(186));
		for(int j=1;j<=5;j++)if(t[i][j].abil==17){printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}

		else printf("Nivel nisip: %d\t%c",t[i][j].niv_nis,char(186));
		for(int j=1;j<=5;j++)
			if(t[i][j].abil==17){printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
			else
				printf("\t\t%c",char(186));

		for(int j=1;j<=5;j++)if(t[i][j].abil==17){printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219));printf("%c%c%c%c%c%c",char(219),char(219),char(219),char(219),char(219),char(186));}
		else
			if(j==5)
			{if(t[i][j].niv_nis<=1)printf("Acces: permis\t%c",char(204));
			else printf("Acces:imposibil%c",char(204));}
			else {if(t[i][j].niv_nis<=1)printf("Acces: permis\t%c",char(186));
			else printf("Acces:imposibil%c",char(186));}

			if(i<5){printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(206),char(205),char(205),char(205));
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(206),char(205),char(205),char(205),char(205),char(205),char(205),char(205));
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(206),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205));
			printf("%c%c%c%c%c",char(205),char(205),char(205),char(205),char(206));printf("%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205));
			printf("%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205));printf("%c%c%c%c",char(205),char(205),char(205),char(205));
			printf("\n");printf("%c",char(186));}
			else{printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(202),char(205),char(205),char(205));
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(202),char(205),char(205),char(205),char(205),char(205),char(205),char(205));
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(202),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205),char(205));
			printf("%c%c%c%c%c",char(205),char(205),char(205),char(205),char(202));printf("%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205));
			printf("%c%c%c%c%c",char(205),char(205),char(205),char(205),char(205));printf("%c%c%c%c",char(205),char(205),char(205),char(205));
			printf("\n");}

	}printf("\n");


	for(int i=1;i<=jucatori;i++){
		printf("Jucator %d: %s\t: ",i,j[i].nume);

		if(j[i].niv_apa>0)
			printf("NIVEL APA: ");
		for(int k=1;k<=j[i].niv_apa;k++)
			printf("%c ",char(219));

		printf("Abilitate %s",j_abil[j[i].abil]);

		printf("\n");printf("\n");}




	if(nivel_nisip>0){printf("NIVELUL NISIPULUI: ");
	for(int i=1;i<=nivel_nisip;i++)
		printf("%c ",char(178));}
	printf("\n\n");

	printf("Piese descoperite: ");
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			for(int k=1;k<=4;k++)
				if(t[i][j].piese_t[k]==1 )
					printf("%s (%d,%d)\t",j_tab[k+10],i,j);







	for(int i=1;i<=5;i++)
		if(piese[1]||piese[2]||piese[3]||piese[4])
			printf("Piese colectate: ");
	for(int i=1;i<=4;i++)
		if(piese[i])printf("%s\t",j_tab[i+10]);
	printf("\n");
	}


	


void stanga_jos(int i)
{
   t[j[i].lin_p][j[i].col_p].nr_jucatori--;
   t[j[i].lin_p+1][j[i].col_p-1].nr_jucatori++;
   j[i].lin_p++;
   j[i].col_p--;
   j[i].numar_mutari--;
afisare();}

void dreapta_jos(int i)
{
t[j[i].lin_p][j[i].col_p].nr_jucatori--;
   t[j[i].lin_p+1][j[i].col_p+1].nr_jucatori++;
   j[i].lin_p++;
   j[i].col_p++;
   j[i].numar_mutari--;afisare(); }

void dreapta_sus(int i)
{ t[j[i].lin_p][j[i].col_p].nr_jucatori--;
   t[j[i].lin_p-1][j[i].col_p+1].nr_jucatori++;
   j[i].lin_p--;
   j[i].col_p++;
   j[i].numar_mutari--;afisare();}

void stanga_sus(int i)
{

   t[j[i].lin_p][j[i].col_p].nr_jucatori--;
   t[j[i].lin_p-1][j[i].col_p-1].nr_jucatori++;
   j[i].lin_p--;
   j[i].col_p--;
   j[i].numar_mutari--;afisare();}
  int deplasare(int i)
{ if(j[i].lin_p==1&&j[i].col_p==1&&t[j[i].lin_p+1][j[i].col_p+1].abil==17)
    {printf("Imposibil!\n"); return 0;}//colt1

   else if(j[i].lin_p==1&&j[i].col_p==1&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis<2)
    {dreapta_jos(i);return 1;}//colt1 si se poate muta pe diagonala

    else if(j[i].lin_p==1&&j[i].col_p==1 &&t[j[i].lin_p+1][j[i].col_p+1].niv_nis>=2)
    {printf("Imposibil!\n"); return 0;}//colt 1 si nu se poate muta pe diagonala

     else if(j[i].lin_p==1&&j[i].col_p==5&&t[j[i].lin_p+1][j[i].col_p-1].abil==17)
     {printf("Imposibil!\n");return 0;}//colt2 si tornada pe diagonala

    else if(j[i].lin_p==1&&j[i].col_p==5&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis<2)
{stanga_jos(i);return 1;}//colt dreapta sus si se poate muta pe diagonala

else if(j[i].lin_p==1&&j[i].col_p==5&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis>=2)
{printf("Imposibil!\n");return 0;}//colt2 si nu se poate muta pe diagonala

else if(j[i].lin_p==1&&t[j[i].lin_p+1][j[i].col_p+1].abil==17&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis<2)
{stanga_jos(i); return 1;}//prima linie si diagonala din dreapta e indisponibila si cea din stanga disponibila

else if(j[i].lin_p==1&&t[j[i].lin_p+1][j[i].col_p+1].abil==17&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis>=2)
{printf("Imposibil\n");return 0;}//pe o diagonala e furtuna si cealalta e indisponibila

else if(j[i].lin_p==1&&t[j[i].lin_p+1][j[i].col_p-1].abil==17&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis<2)
{dreapta_jos(i); return 1;}//prima lini stanga furtuna si dreapta disponibil

else if(j[i].lin_p==1&&t[j[i].lin_p+1][j[i].col_p-1].abil==17 &&t[j[i].lin_p+1][j[i].col_p+1].niv_nis>=2)
{printf("Imposibil\n");return 0;}//ambele diagonale indisponibile

else if(j[i].lin_p==1)
{  printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta jos\n");
        printf("2.Diagonala stanga jos\n");
        int r;
         scanf("%d",&r);
         if(r==1&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis<2)
         {dreapta_jos(i);return 1;}
else   if(r==1&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis>=2)
{printf("Imposibil!"); return 0;}
      else if(r==2&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis<2)
         {stanga_jos(i); return 1;}
else if(r==2&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis>=2)
    {printf("Imposibil\n"); return 0;}
}//celelalte cazuri pt linia 1


else if(j[i].lin_p==5&&j[i].col_p==1&&t[j[i].lin_p-1][j[i].col_p+1].abil==17)
{printf("Imposibil!\n");return 0;}//colt3 si furtuna pe diagonala

else if(j[i].lin_p==5&&j[i].col_p==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis<2)
{dreapta_sus(i); return 1;}//colt 3 si diagonala disponibila

else if(j[i].lin_p==5&&j[i].col_p==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis>=2)
{printf("Imposibil!\n"); return 0;}//diagonala indisponibila

else if( j[i].col_p==1&& t[j[i].lin_p-1][j[i].col_p+1].abil==17&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis<2)
{dreapta_jos(i); return 1;}//col 1 si diagonala sus indisponibila

else if( j[i].col_p==1&& t[j[i].lin_p-1][j[i].col_p+1].abil==17&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis>=2)
{printf("Imposibil\n");return 0; }//col 1 si diagonala sus cu furtuna si cea de jos indisponibila

else if( j[i].col_p==1&&t[j[i].lin_p+1][j[i].col_p+1].abil==17&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis<2)
{dreapta_sus(i); return 1;}//col 1 sus disponibil jos furtuna

else  if( j[i].col_p==1&&t[j[i].lin_p+1][j[i].col_p+1].abil==17&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis>=2)
{printf("Imposibil!\n"); return 0;}//col 1 sus si jos indisp

else if(j[i].col_p==1)
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala dreapta jos\n");
        int r;
         scanf("%d",&r);
         if(r==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis<2)
{dreapta_sus(i); return 1;}
else  if(r==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis>=2)
return 0;
else if(r==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis<2)
{dreapta_jos(i); return 1;}
else  if(r==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis>=2)
return 0;
}// se verifica celelalte cazuri pt col 1

else if(j[i].lin_p==5&&j[i].col_p==5&&t[j[i].lin_p-1][j[i].col_p-1].abil==17)
{printf("Imposibil!\n");return 0;}//colt4 si diagonala indisponibila

else if(j[i].lin_p==5&&j[i].col_p==5&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis<2)
{stanga_sus(i);return 1;}//colt 4 si diagonala indisponibila

else if(j[i].lin_p==5&&j[i].col_p==5&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis>=2)
{printf("Imposibil!\n");return 0;}//colt 4 si diag indisponibila

else if(j[i].lin_p==5&&t[j[i].lin_p-1][j[i].col_p-1].abil==17&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis<2)
{dreapta_sus(i); return 1;}//linia 5 si diagonala stanga idisp si cea din dreapta disp

 else if(j[i].lin_p==5&&t[j[i].lin_p-1][j[i].col_p-1].abil==17&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis>=2)
 {printf("Imposibil!\n");return 0;}//linia 5 si diagonala stanga idisp si cea din dreapta indisp

else if (j[i].lin_p==5&&t[j[i].lin_p-1][j[i].col_p+1].abil==17&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis<2)
{stanga_sus(i);return 1;}//dreapta bloca si stanga disp

else if (j[i].lin_p==5&&t[j[i].lin_p-1][j[i].col_p+1].abil==17&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis>=2)
{printf("Imposibil!\n");return 0;}//ambele indisp

else if(j[i].lin_p==5)
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala stanga sus\n");
        int r;
         scanf("%d",&r);
if(r==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis<2)
{dreapta_sus(i); return 1;}
else  if(r==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis>=2)
{printf("Imposibil!\n");return 0;}
else if(r==2 &&t[j[i].lin_p-1][j[i].col_p-1].niv_nis<2)
{stanga_sus(i);return 1;}
else if(r==2 &&t[j[i].lin_p-1][j[i].col_p-1].niv_nis>=2)
{printf("Imposibil!\n"); return 0;}}//celelalte cazuri

else if(j[i].col_p==5 && t[j[i].lin_p+1][j[i].col_p-1].abil==17&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis<2)
{stanga_sus(i); return 1;}//col 5 stanga jos indisponibil si stanga sus disp

else if(j[i].col_p==5 && t[j[i].lin_p+1][j[i].col_p-1].abil==17&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis>=2)
{printf("Imposibil\n");return 0;}//ambele indisp

else if(j[i].col_p==5 && t[j[i].lin_p-1][j[i].col_p-1].abil==17&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis<2)
{stanga_jos(i); return 1;}

else if(j[i].col_p==5 && t[j[i].lin_p-1][j[i].col_p-1].abil==17&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis>=2)
{printf("Imposibil\n"); return 0;}

else if(j[i].col_p==5)
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala stanga sus\n");
        printf("2.Diagonala stanga jos\n");
        int r;
         scanf("%d",&r);
         if(r==1 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis<2)
{stanga_sus(i); return 1;}
else if(r==1 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
else if(r==2&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis<2)
{stanga_jos(i); return 1;}
else  if(r==2&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
}

else if(t[j[i].lin_p-1][j[i].col_p-1].abil==17)//furtuna e in stanga sus
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala dreapta jos\n");
        printf("3.Diagonala stanga jos\n");
        int c;
        scanf("%d",&c);
        if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis<2)
         {dreapta_sus(i); return 1;}
else   if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis>=2)
{printf("Imposibil!\n");return 0;}
        else if(c==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis<2)
        {dreapta_jos(i);return 1;}
else if(c==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis>=2)
{printf("Imposibil");return 0;}
        else if(c==3 &&t[j[i].lin_p+1][j[i].col_p-1].niv_nis<2){ stanga_jos(i);return 1;}
else if(c==3 &&t[j[i].lin_p+1][j[i].col_p-1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
}

else if(t[j[i].lin_p+1][j[i].col_p+1].abil==17)//dreapta jos
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala stanga sus\n");
        printf("3.Diagonala stanga jos\n");
        int c;
        scanf("%d",&c);
        if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis<2)
       {dreapta_sus(i); return 1;}
else if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
       if(c==2&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis<2)
{stanga_sus(i); return 1;}
else if(c==2&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
else if(c==3&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis<2)
{stanga_jos(i); return 1;}
else  if(c==3&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
}

else if (t[j[i].lin_p-1][j[i].col_p+1].abil==17)//dreapta sus
        {   printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala stanga sus\n");
        printf("2.Diagonala dreapta jos\n");
        printf("3.Diagonala stanga jos\n");
        int c;
        scanf("%d",&c);
        if(c==1 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis<2)
        {stanga_sus(i);return 1;}
         else if(c==1 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis>=2)
        {printf("Imposbil!\n"); return 0;}
        else if(c==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis<2)
        {dreapta_jos(i);return 1;}
else  if(c==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
        else if(c==3&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis<2)
        {stanga_jos(i);return 1;}
        else if(c==3&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
}

else  if (t[j[i].lin_p+1][j[i].col_p-1].abil==17)//stanga jos
{  printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala stanga sus\n");
        printf("3.Diagonala dreapta jos\n");
        int c;
        scanf("%d",&c);
        if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis<2)
       {dreapta_sus(i); return 1;}
else  if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
else if(c==2 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis<2)
        {stanga_sus(i); return 1;}
else if(c==2 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis>=2)
    {printf("Imposbil!\n");return 0;}
else if(c==3&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis<2)
        {dreapta_jos(i); return 1;}
else if(c==3&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
}
else
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala stanga sus\n");
        printf("3.Diagonala dreapta jos\n");
        printf("4.Diagonala stanga jos\n");
        int c;
        scanf("%d",&c);
        if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis<2)
{dreapta_sus(i); return 1;}
else  if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
else if(c==2&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis<2)
{stanga_sus(i);
return 1;}
else if(c==2&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis<2)
{printf("Imposbil!\n");return 0;}
else if(c==3&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis<2)
{dreapta_jos(i); return 1;}
else if(c==3&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis>=2)
{printf("Imposbil!\n");return 0;}
else if(c==4&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis<2)
{stanga_jos(i); return 1;}
else if(c==4&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis<2)
{printf("Imposbil!\n");return 0;}
}} //###############################################################


int verif_a (int a, int b)
{
  if (t[a][b].abil != 0) return 0;
  int i, c = 0, l = 0;
  for (i = 1; i <= 5; i++) {
    if (t[a][i].abil != 0) l++;
    if (t[i][b].abil != 0) c++;
  }
  if (l > 3 || c > 3) return 0;
  return 1;
}
void afisare2(){
	printf("Introduceti gradul de dificultate al jocului(nivelul nisipului)\n");
	scanf("%d",&nivel_nisip);
	printf("\n");
	printf(" \t\t\t---ABILITATI---\n");
	for(int i=1;i<=jucatori;i++)
		if(j[i].abil==1)printf("\tJucatorul %d: Arheologul poate curata 2 carti de nisip in schimbul a unei singure mutari de pe orice patratica. \n",i);
		else if(j[i].abil==2)printf("\tJucatorul %d: Exploratorul se poate deplasa sau poate curata nisip pe diagonala \n",i);
		else if(j[i].abil==3)printf("\tJucatorul %d: Baiatul cu apa poate lua 2 unitati de apa daca a fost descoperita o fantana in schimbul a unei singure mutari.El, de asemenea, poate da jucatorilor din jurul lui o unitate de apa. Aceasta abilitate ii permite jucatorului care o poseda sa inceapa cu 5 unitati de apa. \n",i);
		else if(j[i].abil==4)printf("\tJucatorul %d: Cataratorul poate sa se deplaseze pe o patratica blocata( nivelul de nisip fiind mai mare sau egal cu 2).De asemenea,poate lua cu el alt jucator dupa ce se deplaseaza. \n",i);
		else printf("\tJucatorul %d: Navigatorul poate deplasa un jucator cu pana la 3 patratele neblocate schimbul a unei singure mutari. \n",i);
	printf("\n");

}

void players(){int *v;
	system("color 70");
	printf("Introduceti numarul de jucatori: ");
	scanf("%d",&jucatori);getchar();
	for(int i=1;i<=jucatori;i++){
	    j[i].numar=i;
	    j[i].numar_mutari=4;
		printf("Jucator %d: ",i);
		j[i].nume=(char *)malloc(20);

		fgets(j[i].nume,20,stdin);
		j[i].nume[strlen(j[i].nume)-1]='\0';

	}v=random(5);

	for(int i=1;i<=jucatori;i++)
		j[i].abil=v[i];

	free(v);
}



void tabla()
{
  int i, a, b, k, *v;
  t[3][3].abil = 17;
  t[1][3].niv_nis = t[2][2].niv_nis = t[3][1].niv_nis = t[4][2].niv_nis = 1; // rombul de nisip
  t[5][3].niv_nis = t[4][4].niv_nis = t[3][5].niv_nis = t[2][4].niv_nis = 1;
  


  t[3][2].nr_jucatori = jucatori;
  for(i=1;i<=jucatori;i++)
	  j[i].col_p=2,j[i].lin_p=3;
  // asezarea jucatorilor, n = numarul jucatorilor;
  //#################################################################################
  i = 1;
  //srand(time(NULL));
  while (i <= 4) {             // la inceput pun piesele si indicatorii pe tabla
    do {                      // piesele navei
      a = 1 + rand() % 5;// j= 1 + rand() % (b - a + 1);
      b = 1 + rand() % 5;
    } while (verif_a(a, b) == 0);
    t[a][b].abil = i+10;      // legatura dintre i si pozitia din vectorul abilitatilor a piesei
    do {                         // indicator linie
      k = 1 + rand() % 5;
    } while (t[a][k].abil != 0);
    t[a][k].abil = i + i + 2;// legatura dintre i si pozitia din vector a indicatorului
    do {                         // indicator coloana
      k = 1 + rand() % 5;
    } while (t[k][b].abil != 0);
    t[k][b].abil = i + i + 1;// legatura dintre i si pozitia din vector a indicatorului
    i++;
	t[a][b].abil=0;
  }
  //################################################################################
  v = random(13);   //restul jetoamelor
  i = a = k = 1;
    for (i = 1; i <= 5; i++)
      for (a = 1; a <= 5; a++)
        if (t[i][a].abil == 0) {
          if (v[k] == 1) t[i][a].abil = 18;
          if (v[k] == 2) t[i][a].abil = 1;
          if (v[k] == 3) t[i][a].abil = 2;
          if (v[k] >= 4 && v[k] <= 6) t[i][a].abil = 15;
          if (v[k] == 7) t[i][a].abil = 16;
          if (v[k] >= 8) t[i][a].abil = 0;
          k++;
        }
  free (v);
}

void mutare_furtuna(int **var1,int **var2,int optiune){
	if (optiune==1){
		if(t[**var1][(*(*var2))+1].nr_jucatori!=0){ for(int i=1;i<=jucatori;i++)
				if(j[i].col_p==(*(*var2))+1 && j[i].lin_p==**var1)
					j[i].col_p--;}
		//se muta la dreapta cu o patratica ,mutare pentru fiecare camp in parte (3/3)
		t[**var1][**var2].abil=t[**var1][**var2].abil^t[**var1][(*(*var2))+1].abil;
		t[**var1][**var2].niv_nis=t[**var1][**var2].niv_nis^t[**var1][(*(*var2))+1].niv_nis;
		t[**var1][**var2].nr_jucatori=t[**var1][**var2].nr_jucatori^t[**var1][(*(*var2))+1].nr_jucatori;
		   for(int i=1;i<=4;i++){
			   t[**var1][**var2].piese_t[i]=t[**var1][(*(*var2))-1].piese_t[i]^t[**var1][**var2].piese_t[i];
			   t[**var1][(*(*var2))+1].piese_t[i]=t[**var1][**var2].piese_t[i]^t[**var1][(*(*var2))+1].piese_t[i];
			   t[**var1][**var2].piese_t[i]=t[**var1][**var2].piese_t[i]^t[**var1][(*(*var2))+1].piese_t[i];

		   }
		t[**var1][(*(*var2))+1].abil=t[**var1][**var2].abil^t[**var1][(*(*var2))+1].abil;
		t[**var1][(*(*var2))+1].niv_nis=t[**var1][**var2].niv_nis^t[**var1][(*(*var2))+1].niv_nis;
		t[**var1][(*(*var2))+1].nr_jucatori=t[**var1][**var2].nr_jucatori^t[**var1][(*(*var2))+1].nr_jucatori;


		t[**var1][**var2].ab_viz=t[**var1][**var2].ab_viz^t[**var1][(*(*var2))+1].ab_viz;
			t[**var1][(*(*var2))+1].ab_viz=t[**var1][**var2].ab_viz^t[**var1][(*(*var2))+1].ab_viz;
			t[**var1][**var2].ab_viz=t[**var1][**var2].ab_viz^t[**var1][(*(*var2))+1].ab_viz;


		t[**var1][**var2].abil=t[**var1][**var2].abil^t[**var1][(*(*var2))+1].abil;
		t[**var1][**var2].niv_nis=t[**var1][**var2].niv_nis^t[**var1][(*(*var2))+1].niv_nis;
		t[**var1][**var2].nr_jucatori=t[**var1][**var2].nr_jucatori^t[**var1][(*(*var2))+1].nr_jucatori;
		t[**var1][**var2].niv_nis++;

		

		(*(*var2))++;
		}
	else if(optiune==2){
			if(t[(*(*var1))-1][**var2].nr_jucatori!=0){ for(int i=1;i<=jucatori;i++)
				if(j[i].col_p==**var2 && j[i].lin_p==(*(*var1))-1)
					j[i].lin_p++;}
		t[**var1][**var2].abil=t[**var1][**var2].abil^t[(*(*var1))-1][**var2].abil;
		t[**var1][**var2].niv_nis=t[**var1][**var2].niv_nis^t[(*(*var1))-1][**var2].niv_nis;
		t[**var1][**var2].nr_jucatori=t[**var1][**var2].nr_jucatori^t[(*(*var1))-1][**var2].nr_jucatori;

		t[**var1][**var2].ab_viz=t[**var1][**var2].ab_viz^t[(*(*var1))-1][**var2].ab_viz;
		
		t[(*(*var1))-1][**var2].ab_viz=t[**var1][**var2].ab_viz^t[(*(*var1))-1][**var2].ab_viz;
		t[**var1][**var2].ab_viz=t[**var1][**var2].ab_viz^t[(*(*var1))-1][**var2].ab_viz;

		for(int i=1;i<=4;i++){
			t[**var1][**var2].piese_t[i]=t[**var1][**var2].piese_t[i]^t[(*(*var1))-1][**var2].piese_t[i];
			t[(*(*var1))-1][**var2].piese_t[i]=t[**var1][**var2].piese_t[i]^t[(*(*var1))-1][**var2].piese_t[i];
			t[**var1][**var2].piese_t[i]=t[**var1][**var2].piese_t[i]^t[(*(*var1))-1][**var2].piese_t[i];}


		t[(*(*var1))-1][**var2].abil=t[**var1][**var2].abil^t[(*(*var1))-1][**var2].abil;
		t[(*(*var1))-1][**var2].niv_nis=t[**var1][**var2].niv_nis^t[(*(*var1))-1][**var2].niv_nis;
		t[(*(*var1))-1][**var2].nr_jucatori=t[**var1][**var2].nr_jucatori^t[(*(*var1))-1][**var2].nr_jucatori;

		t[**var1][**var2].abil=t[**var1][**var2].abil^t[(*(*var1))-1][**var2].abil;
		t[**var1][**var2].niv_nis=t[**var1][**var2].niv_nis^t[(*(*var1))-1][**var2].niv_nis;
		t[**var1][**var2].nr_jucatori=t[**var1][**var2].nr_jucatori^t[(*(*var1))-1][**var2].nr_jucatori;
		//sus
		t[**var1][**var2].niv_nis++;
	
		(*(*var1))--;
			}
	else if(optiune==3){
		if(t[**var1][(*(*var2))-1].nr_jucatori!=0){ for(int i=1;i<=jucatori;i++)
				if(j[i].col_p==(*(*var2))-1 && j[i].lin_p==**var1)
					j[i].col_p++;}

		t[**var1][**var2].abil=t[**var1][(*(*var2))-1].abil^t[**var1][**var2].abil;
		t[**var1][**var2].niv_nis=t[**var1][(*(*var2))-1].niv_nis^t[**var1][**var2].niv_nis;
		t[**var1][**var2].nr_jucatori=t[**var1][(*(*var2))-1].nr_jucatori^t[**var1][**var2].nr_jucatori;


		t[**var1][**var2].ab_viz=t[**var1][(*(*var2))-1].ab_viz^t[**var1][**var2].ab_viz;
		t[**var1][(*(*var2))-1].ab_viz=t[**var1][**var2].ab_viz^t[**var1][(*(*var2))-1].ab_viz;
		t[**var1][**var2].ab_viz=t[**var1][**var2].ab_viz^t[**var1][(*(*var2))-1].ab_viz;



		for(int i=1;i<=4;i++){
			t[**var1][**var2].piese_t[i]=t[**var1][(*(*var2))-1].piese_t[i]^t[**var1][**var2].piese_t[i];
			t[**var1][(*(*var2))-1].piese_t[i]=t[**var1][**var2].piese_t[i]^t[**var1][(*(*var2))-1].piese_t[i];
			t[**var1][**var2].piese_t[i]=t[**var1][**var2].piese_t[i]^t[**var1][(*(*var2))-1].piese_t[i];}



		t[**var1][(*(*var2))-1].abil=t[**var1][**var2].abil^t[**var1][(*(*var2))-1].abil;
		t[**var1][(*(*var2))-1].niv_nis=t[**var1][**var2].niv_nis^t[**var1][(*(*var2))-1].niv_nis;
		t[**var1][(*(*var2))-1].nr_jucatori=t[**var1][**var2].nr_jucatori^t[**var1][(*(*var2))-1].nr_jucatori;

		t[**var1][**var2].abil=t[**var1][**var2].abil^t[**var1][(*(*var2))-1].abil;
		t[**var1][**var2].niv_nis=t[**var1][**var2].niv_nis^t[**var1][(*(*var2))-1].niv_nis;
		t[**var1][**var2].nr_jucatori=t[**var1][**var2].nr_jucatori^t[**var1][(*(*var2))-1].nr_jucatori;

		//stanga
		t[**var1][**var2].niv_nis++;

		
	    (*(*var2))--;
			}
	else{
		if(t[(*(*var1))+1][**var2].nr_jucatori!=0){ for(int i=1;i<=jucatori;i++)
				if(j[i].col_p==**var2 && j[i].lin_p==(*(*var1))+1)
					j[i].lin_p--;}
		t[**var1][**var2].abil=t[**var1][**var2].abil^t[(*(*var1))+1][**var2].abil;
		t[**var1][**var2].niv_nis=t[**var1][**var2].niv_nis^t[(*(*var1))+1][**var2].niv_nis;
		t[**var1][**var2].nr_jucatori=t[**var1][**var2].nr_jucatori^t[(*(*var1))+1][**var2].nr_jucatori;


		t[**var1][**var2].ab_viz =t[**var1][**var2].ab_viz^t[(*(*var1))+1][**var2].ab_viz;
		t[(*(*var1))+1][**var2].ab_viz=t[**var1][**var2].ab_viz^t[(*(*var1))+1][**var2].ab_viz;
		t[**var1][**var2].ab_viz=t[**var1][**var2].ab_viz^t[(*(*var1))+1][**var2].ab_viz;


		for(int i=1;i<=4;i++){
			t[**var1][**var2].piese_t[i]=t[**var1][**var2].piese_t[i]^t[(*(*var1))+1][**var2].piese_t[i];
			t[(*(*var1))+1][**var2].piese_t[i]=t[**var1][**var2].piese_t[i]^t[(*(*var1))+1][**var2].piese_t[i];
			t[**var1][**var2].piese_t[i]=t[**var1][**var2].piese_t[i]^t[(*(*var1))+1][**var2].piese_t[i];}



		t[(*(*var1))+1][**var2].abil=t[**var1][**var2].abil^t[(*(*var1))+1][**var2].abil;
		t[(*(*var1))+1][**var2].niv_nis=t[**var1][**var2].niv_nis^t[(*(*var1))+1][**var2].niv_nis;
		t[(*(*var1))+1][**var2].nr_jucatori=t[**var1][**var2].nr_jucatori^t[(*(*var1))+1][**var2].nr_jucatori;

		t[**var1][**var2].abil=t[**var1][**var2].abil^t[(*(*var1))+1][**var2].abil;
		t[**var1][**var2].niv_nis=t[**var1][**var2].niv_nis^t[(*(*var1))+1][**var2].niv_nis;
		t[**var1][**var2].nr_jucatori=t[**var1][**var2].nr_jucatori^t[(*(*var1))+1][**var2].nr_jucatori;


	//jos
		
		t[**var1][**var2].niv_nis++;
        (*(*var1))++;
	}
}





void carti_de_nisip(int v1[],int *n,int *var1,int *var2){//transmit prin referinta var1 si var2 reprezentand pozitia uraganului ca sa nu il mai caut initial se va apela cu 3 si 3 k reprezinta nr cartilor care se extrag

	int u,k;
	int i=*n;


		if(v1[i]>=1&&v1[i]<=4){//daca dau de o carte sun beats down scad nivelul tuturor jucatorilor cu 1 mai putin celor care se afla in tunel
			for(u=1;u<=jucatori;u++)
				if(t[j[u].lin_p][j[u].col_p].abil!=15 ||t[j[u].lin_p][j[u].col_p].ab_viz!=1)
				{j[u].niv_apa--;if(j[u].niv_apa==-1)REZULTAT=0,u=jucatori;}}

		else if(v1[i]>=5&&v1[i]<=7){//daca dau de o carte storm picks up cresc nivelul nisipului cu 1
			 nivel_nisip++;//variabila globala---->dificultatea (nivelul de la care se incepe jocul)

				 if(nivel_nisip==16)REZULTAT=0;}//rezultat=0=>joc pierdut
		else {
			if(v1[i]>=8&&v1[i]<=9 && *var2<5)jet--,mutare_furtuna(&var1,&var2,1);

			else if(v1[i]>=10&&v1[i]<=11 && *var1>1)jet--,mutare_furtuna(&var1,&var2,2);

			else if(v1[i]>=12&&v1[i]<=13 && *var2>1)jet--,mutare_furtuna(&var1,&var2,3);

			else if(v1[i]>=14&&v1[i]<=15 && *var1<5)jet--,mutare_furtuna(&var1,&var2,4);

			else if(v1[i]>=16&&v1[i]<=17)
				for(int h=*var2;h<5;h++)
					jet--,mutare_furtuna(&var1,&var2,1);

			else if(v1[i]>=18&&v1[i]<=19)
				for(int h=*var1;h>1;h--)
					jet--,mutare_furtuna(&var1,&var2,2);

			else if(v1[i]>=20&&v1[i]<=21)
				for(int h=*var2;h>1;h--)
					jet--,mutare_furtuna(&var1,&var2,3);

			else if(v1[i]>=22&&v1[i]<=23)
				for(int h=*var1;h<5;h++)
					jet--,mutare_furtuna(&var1,&var2,4);

			else if(v1[i]==24 || v1[i]==25)
				for(int h=*var2;h<5;h++)
					jet--,mutare_furtuna(&var1,&var2,1);

			else if(v1[i]>=26&&v1[i]<=27)
				for(int h=*var1;h>1;h--)
					jet--,mutare_furtuna(&var1,&var2,2);

			else if(v1[i]>=28&&v1[i]<=29)
				for(int h=*var2;h>1;h--)
					jet--,mutare_furtuna(&var1,&var2,3);

			else
				for(int h=*var1;h<5;h++)
					jet--,mutare_furtuna(&var1,&var2,4);}
					
			(*n)--;

		if(!jet)REZULTAT=0;
}









	 void Water_Carrier(int i, int m)
    {
    char t[4];
    printf("Doriti sa folositi abilitatea speciala?\n");
    scanf("%s",t);

    if (strcmp("da",t)==0)
    {  printf("Introduceti cifra corespunsadoare abilitatii pe care doriti sa o folositi:\n");
        printf("1.Aprovizionare cu 2 unitati de apa\n");
        printf("2.Doneaza apa coechipierilor\n");
        int b;
        scanf("%d",&b);
        if(b==1)
        {
            if(m==0)
            {
                printf("Imposibil! Inca nu a fost descoperita o alta sursa de apa\n");
                     Water_Carrier(i,m);
            }
            else
           {

            j[i].niv_apa+=2;
            j[i].numar_mutari--;

        }

    }
    else if(b==2)
    {    if(j[i].niv_apa>=2)
       {

        int ok=0;
        for(int k=1;k<=n;k++)                                                                // n=nr de jucatori
        if(k!=i)
        {if((j[k].lin_p==j[i].lin_p+1 || j[k].lin_p==j[i].lin_p-1)&&(j[k].col_p==j[i].col_p+1 || j[k].col_p==j[i].lin_p-1))
        {printf("Puteti dona apa jucatorului %d \n",i);
        ok=1;
    }}
    if(ok==0)
    printf("Nu se afla niciun jucator in apropiere\n");
    else { printf("Jucatorul caruia ii donati o unitate de apa este:\n");
    int f;
    scanf("%d",&f);
int r=0;
while(j[r].numar!=f) r++;
    j[r].niv_apa++;
    j[i].niv_apa--;
    }
    }
    else {printf("Nu aveti suficienta apa pentru a dona\n");
              Water_Carrier(i,m); }}}}


int neblocat(int i)
{  if(j[i].lin_p==1&&j[i].col_p==1&&t[j[i].lin_p][j[i].col_p+1].abil==17)
    {jos(i);return 1;}
else   if(j[i].lin_p==1&&j[i].col_p==1&&t[j[i].lin_p+1][j[i].col_p].abil==17)
    {dreapta(i);return 1;}
else if(j[i].lin_p==1&&j[i].col_p==1)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Dreapta\n");
        printf("2.Jos\n");
int w;
scanf("%d",&w);
if(w==1)
{dreapta(i); return 1;}
else
{jos(i); return 1;}} //colt stanga sus


 else if(j[i].lin_p==5&&j[i].col_p==5&&t[j[i].lin_p][j[i].col_p-1].abil==17)
    {sus(i); return 1;}
 else if(j[i].lin_p==5&&j[i].col_p==5&&t[j[i].lin_p-1][j[i].col_p].abil==17)
    {stanga(i);return 1;}
else if(j[i].lin_p==5&&j[i].col_p==5)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Sus\n");
        printf("2.Stanga\n");
int w;
scanf("%d",&w);
if(w==1)
{sus(i); return 1;}
else
{stanga(i);return 1;}} //colt dreapta jos;


else if(j[i].lin_p==1&&j[i].col_p==5&&t[j[i].lin_p][j[i].col_p-1].abil==17)
     {jos(i);return 1;}
else if(j[i].lin_p==1&&j[i].col_p==5&&t[j[i].lin_p+1][j[i].col_p].abil==17)
     {stanga(i);return 1;}
else if(j[i].lin_p==1&&j[i].col_p==5)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Stanga\n");
int w;
scanf("%d",&w);
if(w==1)
{jos(i); return 1;}
else
{stanga(i);return 1;}} //colt dreapta sus;


else if(j[i].lin_p==1 && t[j[i].lin_p+1][j[i].col_p].abil==17)
{  printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Dreapta\n");
        printf("2.Stanga\n");
int w;
scanf("%d",&w);
if(w==1)
{dreapta(i); return 1;}
else
{stanga(i);return 1;}}//cazul prima linie si piesa de jos furtuna

else if(j[i].lin_p==1 && t[j[i].lin_p][j[i].col_p+1].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Stanga\n");
int w;
scanf("%d",&w);
if(w==1)
{jos(i);return 1;}
else
{stanga(i);return 1;}}//cazul prima linie si piesa din dreapta furtuna

else if(j[i].lin_p==1 && t[j[i].lin_p][j[i].col_p-1].abil==17)
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Dreapta\n");
int w;
scanf("%d",&w);
if(w==1)
{jos(i); return 1;}
else
{dreapta(i);return 1;}}// cazul prima linie si piesa din stanga furtuna

else if(j[i].lin_p==1)
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Dreapta\n");
        printf("3.Stanga\n");

int w;
scanf("%d",&w);
if(w==1)
{jos(i); return 1;}
else if(w==2)
{dreapta(i);return 1;}
else if(w==3)
{stanga(i);return 1;}} //cazul prima linie fara furtuna in preajma

else if(j[i].lin_p==5&&j[i].col_p==1&&t[j[i].lin_p-1][j[i].col_p].abil==17)
{dreapta(i); return 1;}
else if (j[i].lin_p==5&&j[i].col_p==1&&t[j[i].lin_p][j[i].col_p+1].abil==17)
{sus(i); return 1;}
else if(j[i].lin_p==5&&j[i].col_p==1)
 {printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Sus\n");
        printf("2.Dreapta\n");
int w;
scanf("%d",&w);
if(w==1)
{sus(i); return 1;}
else
{dreapta(i);return 1;}}//colt stanga jos

else if(j[i].col_p==1&& t[j[i].lin_p-1][j[i].col_p].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Dreapta\n");
int w;
scanf("%d",&w);
if(w==1)
{jos(i);return 1;}
else
{dreapta(i);return 1;}}//prima coloana si furtuna se afla sus

else if(j[i].col_p==1&& t[j[i].lin_p][j[i].col_p+1].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Sus\n");
int w;
scanf("%d",&w);
if(w==1)
{jos(i);return 1;}
else
{sus(i);return 1;}}//prima coloana si furtuna se afla in dreapta

else if(j[i].col_p==1&& t[j[i].lin_p+1][j[i].col_p].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Dreapta\n");
        printf("2.Sus\n");
int w;
scanf("%d",&w);
if(w==1)
{dreapta(i);return 1;}
else
{sus(i);return 1;}}//prima coloana si furtuna se afla jos

else if (j[i].col_p==1)
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Dreapta\n");
        printf("3.Sus\n");

int w;
scanf("%d",&w);
if(w==1)
{jos(i); return 1;}
else if(w==2)
{dreapta(i);return 1;}
else if(w==3)
{sus(i);return 1;}}//coloana 1 fara tornada prin preajma

else if(j[i].col_p==5 && t[j[i].lin_p+1][j[i].col_p].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Sus\n");
        printf("2.Stanga\n");
int w;
scanf("%d",&w);
if(w==1)
{sus(i);return 1;}
else if(w==2)
{sus(i);return 1;}} //coloana 5 furtuna jos

else if(j[i].col_p==5 && t[j[i].lin_p-1][j[i].col_p].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Stanga\n");
int w;
scanf("%d",&w);
if(w==1)
{jos(i);return 1;}
else
{sus(i);return 1;}} //coloana 5 si furtuna se afla sus

else if(j[i].col_p==5 && t[j[i].lin_p][j[i].col_p-1].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Sus\n");
int w;
scanf("%d",&w);
if(w==1)
{jos(i);return 1;}
else
{sus(i);return 1;}}//coloana 5 si furtuna se afla in stanga

else if (j[i].col_p==5)
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Stanga\n");
        printf("3.Sus\n");

int w;
scanf("%d",&w);
if(w==1)
{jos(i); return 1;}
else if(w==2)
{dreapta(i);return 1;}
else if(w==3)
{sus(i);return 1;}}//coloana 5 fara tornada prin preajma

else if(j[i].lin_p==5 && t[j[i].lin_p][j[i].col_p-1].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Dreapta\n");
        printf("2.Sus\n");
int w;
scanf("%d",&w);
if(w==1)
{dreapta(i);return 1;}
else
{sus(i);return 1;}} //linia 5 si tornada se afla in stanga

else if(j[i].lin_p==5 && t[j[i].lin_p][j[i].col_p+1].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Stanga\n");
        printf("2.Sus\n");
int w;
scanf("%d",&w);
if(w==1)
{stanga(i);return 1;}
else
{sus(i);return 1;}}//linia 5 furtuna se afla in dreapta

else if(j[i].lin_p==5 && t[j[i].lin_p-1][j[i].col_p].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Stanga\n");
        printf("2.Dreapta\n");
int w;
scanf("%d",&w);
if(w==1)
{stanga(i);return 1;}
else
{dreapta(i);return 1;}}//linia 5 furtuna se afla sus

else if(j[i].lin_p==5)
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Sus\n");
        printf("2.Dreapta\n");
        printf("3.Stanga\n");

int w;
scanf("%d",&w);
if(w==1)
{sus(i); return 1;}
else if(w==2)
{dreapta(i);return 1;}
else if(w==3)
{stanga(i);return 1;}} //linia 5 fara tornada

else if( t[j[i].lin_p-1][j[i].col_p].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Dreapta\n");
        printf("3.Stanga\n");

int w;
scanf("%d",&w);
if(w==1)
{jos(i); return 1;}
else if(w==2)
{dreapta(i);return 1;}
else if(w==3)
{stanga(i);return 1;}} // in mijloc si tornada sus

else if( t[j[i].lin_p+1][j[i].col_p].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Sus\n");
        printf("2.Dreapta\n");
        printf("3.Stanga\n");

int w;
scanf("%d",&w);
if(w==1)
{sus(i); return 1;}
else if(w==2)
{dreapta(i);return 1;}
else if(w==3)
{stanga(i);return 1;}} //furtuna jos

else if( t[j[i].lin_p][j[i].col_p+1].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Sus\n");
        printf("3.Stanga\n");

int w;
scanf("%d",&w);
if(w==1)
{jos(i); return 1;}
else if(w==2)
{sus(i);return 1;}
else if(w==3)
{stanga(i);return 1;}}//furtuna dreapta

else if( t[j[i].lin_p][j[i].col_p-1].abil==17)
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Dreapta\n");
        printf("3.Sus\n");

int w;
scanf("%d",&w);
if(w==1)
{jos(i); return 1;}
else if(w==2)
{dreapta(i);return 1;}
else if(w==3)
{sus(i);return 1;}}//furtuna stanga

else{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Jos\n");
        printf("2.Dreapta\n");
        printf("3.Sus\n");
        printf("4.Stanga\n");

int w;
scanf("%d",&w);
if(w==1)
{jos(i); return 1;}
else if(w==2)
{dreapta(i);return 1;}
else if(w==3)
{sus(i);return 1;}
else if(w==4)
{stanga(i);return 1;}}}

void muta_jucator(int i)
{ printf("Introduceti numarul jucatorului pe care doriti sa il mutati:");
   int z,po;
   scanf("%d",&z);
   po=1;
while(j[po].numar!=z)
po++;
t[j[po].lin_p][j[po].col_p].nr_jucatori--;
t[j[i].lin_p][j[i].col_p].nr_jucatori++;
j[po].lin_p=j[i].lin_p;}

void Climber(int i)
{  char t[4];
    printf("Doriti sa folositi abilitatea speciala?da/nu\n");
    scanf("%s",t);

    if (strcmp("da",t)==0)
{ if(neblocat(i)==1)
     printf("Doriti sa mutati un alt jucator in casuta in care va situati? da/nu\n");
     char x[4];
      scanf("%s",x);

     if (strcmp("da",x)==0)
     muta_jucator(i);
	system("CLS");
	afisare();}}


void Archeologist(int i)
{    char h[4];
    printf("Doriti sa folositi abilitatea speciala?da/nu\n");
    scanf("%s",h);
    //getchar();
    if (strcmp("da",h)==0)
    {
    int x,y;
    printf("Introduceti linia si coloana patratului pe care doriti sa il curatati de doua straturi de nisip\n");
    printf("Linia:\n");
    scanf("%d",&x);
    printf("Coloana:\n");
    scanf("%d",&y);
 if(t[x][y].niv_nis>=2)
    {t[x][y].niv_nis-=2;
    j[i].numar_mutari--;}
else{ printf("Imposibil!\n"); Archeologist(i);system("CLS");
	afisare();}}
}








void curata_stanga_jos(int i)
{

   t[j[i].lin_p+1][j[i].col_p-1].niv_nis--;

   j[i].numar_mutari--;}

void curata_dreapta_jos(int i)
{

   t[j[i].lin_p+1][j[i].col_p+1].niv_nis--;

   j[i].numar_mutari--; }

void curata_dreapta_sus(int i)
{
   t[j[i].lin_p-1][j[i].col_p+1].niv_nis--;
   j[i].numar_mutari--;}

void curata_stanga_sus(int i)
{


   t[j[i].lin_p-1][j[i].col_p-1].niv_nis--;
   j[i].numar_mutari--;}

int curatare_nisip(int i)
{ if(j[i].lin_p==1&&j[i].col_p==1&&t[j[i].lin_p+1][j[i].col_p+1].abil==17)//daca e in coltul din stanga al tablei si pe diagonala se afla furtuna
    {printf("Imposibil!\n");return 0;}//colt1

else if(j[i].lin_p==1&&j[i].col_p==1&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis!=0)//daca e in coltul din stanga sus si pe diagonala se afla o patratica cu nisip
    {curata_dreapta_jos(i);return 1;}

else if(j[i].lin_p==1&&j[i].col_p==1 &&t[j[i].lin_p+1][j[i].col_p+1].niv_nis==0)
    {printf("Imposibil!\n"); return 0;}

     else if(j[i].lin_p==1&&j[i].col_p==5&&t[j[i].lin_p+1][j[i].col_p-1].abil==17)//daca e in coltul din dreapta sus si pe diagonala se afla furtuna
     {printf("Imposibil!\n");return 0;}//colt2

else if(j[i].lin_p==1&&j[i].col_p==5&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis!=0)//daca e in coltul din dreapta sus si pe diagonala se afla o patratica cu nisip
{curata_stanga_jos(i);return 1;}

else if(j[i].lin_p==1&&j[i].col_p==5&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(j[i].lin_p==1&&t[j[i].lin_p+1][j[i].col_p+1].abil==17&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_jos(i); return 1;}
else  if(j[i].lin_p==1&&t[j[i].lin_p+1][j[i].col_p+1].abil==17&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(j[i].lin_p==1&&t[j[i].lin_p+1][j[i].col_p-1].abil==17&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis!=0)
{curata_dreapta_jos(i); return 1;}
else if(j[i].lin_p==1&&t[j[i].lin_p+1][j[i].col_p-1].abil==17&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis==2)
 {printf("Imposibil!\n");return 0;}
else if(j[i].lin_p==1){  printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta jos\n");
        printf("2.Diagonala stanga jos\n");
        int r;
         scanf("%d",&r);
         if(r==1&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis!=0)
         {curata_dreapta_jos(i);return 1;}
else   if(r==1&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
      else if(r==2&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis!=0)
         {curata_stanga_jos(i); return 1;}
else if(r==2&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis==0)
    {printf("Imposibil!\n"); return 0;}
}

else if(j[i].lin_p==5&&j[i].col_p==1&&t[j[i].lin_p-1][j[i].col_p+1].abil==17)
{printf("Imposibil!\n");
   return 0;}//colt3
else if(j[i].lin_p==5&&j[i].col_p==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis!=0)
{curata_dreapta_sus(i); return 1;}
else if(j[i].lin_p==5&&j[i].col_p==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis==2)
 {printf("Imposibil!\n");return 0;}
else if( j[i].col_p==1&& t[j[i].lin_p-1][j[i].col_p+1].abil==17&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis!=0)
{curata_dreapta_jos(i); return 1;}
else if( j[i].col_p==1&& t[j[i].lin_p-1][j[i].col_p+1].abil==17&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis==2)
 {printf("Imposibil!\n"); return 0;}
  else if( j[i].col_p==1&&t[j[i].lin_p+1][j[i].col_p+1].abil==17&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis!=0)
{curata_dreapta_sus(i); return 1;}
else  if( j[i].col_p==1&&t[j[i].lin_p+1][j[i].col_p+1].abil==17&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}

else if(j[i].col_p==1)
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala dreapta jos\n");
        int r;
         scanf("%d",&r);
         if(r==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis!=0)
{curata_dreapta_sus(i); return 1;}
else  if(r==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(r==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis!=0)
{curata_dreapta_jos(i); return 1;}
else  if(r==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis!=0)
 {printf("Imposibil!\n");return 0;}
}
else if(j[i].lin_p==5&&j[i].col_p==5&&t[j[i].lin_p-1][j[i].col_p-1].abil==17)
{printf("Imposibil!\n");
   return 0;}//colt4
else if(j[i].lin_p==5&&j[i].col_p==5&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_sus(i);
return 1;}
else if(j[i].lin_p==5&&j[i].col_p==5&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(j[i].lin_p==5&&t[j[i].lin_p-1][j[i].col_p-1].abil==17&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis!=0)
{curata_dreapta_sus(i); return 1;}
 else if(j[i].lin_p==5&&t[j[i].lin_p-1][j[i].col_p-1].abil==17&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis==0)
  {printf("Imposibil!\n");return 0;}
else if (j[i].lin_p==5&&t[j[i].lin_p-1][j[i].col_p+1].abil==17&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_sus(i);
return 1;}
else if (j[i].lin_p==5&&t[j[i].lin_p-1][j[i].col_p+1].abil==17&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(j[i].lin_p==5)
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala stanga sus\n");
        int r;
         scanf("%d",&r);
         if(r==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis!=0)
         {curata_dreapta_sus(i); return 1;}
else  if(r==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(r==2 &&t[j[i].lin_p-1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_sus(i);
return 1;}
else if(r==2 &&t[j[i].lin_p-1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}}
else if(j[i].col_p==5 && t[j[i].lin_p+1][j[i].col_p-1].abil==17&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_sus(i); return 1;}
else if(j[i].col_p==5 && t[j[i].lin_p+1][j[i].col_p-1].abil==17&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(j[i].col_p==5 && t[j[i].lin_p-1][j[i].col_p-1].abil==17&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_jos(i); return 1;}
else if(j[i].col_p==5 && t[j[i].lin_p-1][j[i].col_p-1].abil==17&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(j[i].col_p==5)
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala stanga sus\n");
        printf("2.Diagonala stanga jos\n");
        int r;
         scanf("%d",&r);
         if(r==1 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_sus(i); return 1;}
else if(r==1 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(r==2&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_jos(i); return 1;}
else  if(r==2&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
}
else if(t[j[i].lin_p-1][j[i].col_p-1].abil==17)//furtuna e in stanga sus
{printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala dreapta jos\n");
        printf("3.Diagonala stanga jos\n");
        int c;
        scanf("%d",&c);
        if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis!=0)
         {curata_dreapta_sus(i); return 1;}
else   if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
        else if(c==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis!=0)
        {curata_dreapta_jos(i);return 1;}
else if(c==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
        else if(c==3 &&t[j[i].lin_p+1][j[i].col_p-1].niv_nis!=0)
       { curata_stanga_jos(i);return 1;}
else if(c==3 &&t[j[i].lin_p+1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
}
else if(t[j[i].lin_p+1][j[i].col_p+1].abil==17)//dreapta jos
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala stanga sus\n");
        printf("3.Diagonala stanga jos\n");
        int c;
        scanf("%d",&c);
        if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis!=0)
       {curata_dreapta_sus(i); return 1;}
else
     if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
       if(c==2&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_sus(i); return 1;}
else if(c==2&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(c==3&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_jos(i); return 1;}
else  if(c==3&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
}
else if (t[j[i].lin_p-1][j[i].col_p+1].abil==17)//dreapta sus
        {   printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala stanga sus\n");
        printf("2.Diagonala dreapta jos\n");
        printf("3.Diagonala stanga jos\n");
        int c;
        scanf("%d",&c);
        if(c==1 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis!=0)
        {curata_stanga_sus(i);
          return 1;}
         else if(c==1 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis==0)
          {printf("Imposibil!\n");return 0;}
        else if(c==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis!=0)
        {curata_dreapta_jos(i);return 1;}
else  if(c==2&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
        else if(c==3&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis!=0)
        {curata_stanga_jos(i);return 1;}
        else if(c==3&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
}
else  if (t[j[i].lin_p+1][j[i].col_p-1].abil==17)//stanga jos
{  printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala stanga sus\n");
        printf("3.Diagonala dreapta jos\n");
        int c;
        scanf("%d",&c);
        if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis!=0)
       {curata_dreapta_sus(i); return 1;}
else  if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(c==2 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis!=0)
        {curata_stanga_sus(i); return 1;}
else if(c==2 && t[j[i].lin_p-1][j[i].col_p-1].niv_nis==0)
     {printf("Imposibil!\n");return 0;}
else if(c==3&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis!=0)
        {curata_dreapta_jos(i); return 1;}
else if(c==3&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
}
else
{ printf("Introduceti cifra corespunzatoare patratului pe care doriti sa va mutati:\n");
        printf("1.Diagonala dreapta sus\n");
        printf("2.Diagonala stanga sus\n");
        printf("3.Diagonala dreapta jos\n");
        printf("4.Diagonala stanga jos\n");
        int c;
        scanf("%d",&c);
        if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis!=0)
{curata_dreapta_sus(i); return 1;}
else  if(c==1&&t[j[i].lin_p-1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n"); return 0;}
else if(c==2&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_sus(i);
return 1;}
else if(c==2&& t[j[i].lin_p-1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(c==3&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis!=0)
{curata_dreapta_jos(i); return 1;}
else if(c==3&&t[j[i].lin_p+1][j[i].col_p+1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
else if(c==4&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis!=0)
{curata_stanga_jos(i); return 1;}
else if(c==4&&t[j[i].lin_p+1][j[i].col_p-1].niv_nis==0)
 {printf("Imposibil!\n");return 0;}
}}



void Explorer(int i)
{  char t[4];
    printf("Doriti sa folositi abilitatea speciala?\n");

    scanf("%s",t);
    if (strcmp("da",t)==0)
    {   printf("Introduceti cifra corespunzatoare abilitatii pe care doriti sa o folositi:\n");
        printf("1.Deplasare pe diagonala\n");
        printf("2.Curatare nisip pe diagonala\n");
        int b;
        scanf("%d",&b);
        if(b==1)
        {if(deplasare(i)==0)
             { printf("Imposibil!\n");
          Explorer(i);}}

        else{ if (curatare_nisip(i)==0)
                {printf("Imposibil!\n"); Explorer(i);system("CLS");
	afisare();}
        }}

}



 void Navigator( int i)
{char h[4];
    printf("Doriti sa folositi abilitatea speciala?\n");
    scanf("%s",h);

    if (strcmp("da",h)==0)
{ int c;
printf("Introduceti numarul jucatorului pe care doriti sa il mutati:\n");
scanf("%d",&c);
int p=1;
while(j[p].numar!=c)
p++;
int a,b;
printf("Introduceti linia si coloana patratului pe care doriti sa mutati jucatorul\n");
    printf("Linia:\n");
    scanf("%d",&a);
    printf("Coloana:\n");
    scanf("%d",&b);
if(t[a][b].niv_nis<2&&(abs(a-j[p].lin_p)<=3)&&abs(b-j[p].col_p)<=3)
{t[j[p].lin_p][j[p].col_p].nr_jucatori--;


j[p].lin_p=a;
j[p].col_p=b;
t[a][b].nr_jucatori++;

j[i].numar_mutari--;}
else{ printf("Incorect!\n");
         Navigator(i);system("CLS");
	afisare();}}}




int * niv_nis_dir (int i)   //functia returneaza un pointer la un vector ce retine niv nisipului de pe cele 4 pozitii fata de pion
{                       // in cazul in care pionul este in colt pe pozitia respectiva vectorul retine -1
  int d, a, b;
  int *l = (int *) malloc(4 * sizeof(int));
  for (d = 3; d >= 0; d--)
    l[d] = 0;
  if (j[i].lin_p == 1) l[0] = -1;  //sus
  if (j[i].col_p == 5) l[1] = -1;  //dreapta
  if (j[i].lin_p == 5) l[2] = -1;  //jos
  if (j[i].col_p == 1) l[3] = -1;  //stanga
  d = 0;
  while (d < 4) {
    a = j[i].lin_p;
    b = j[i].col_p;
    if (l[d] == 0) {
      if(d == 0) {
        if (t[--a][b].abil == 17) l[d] = 1000;
          else l[d] = t[a][b].niv_nis;
      }
      if (d == 1) {
        if (t[a][++b].abil == 17) l[d] = 1000;
          else l[d] = t[a][b].niv_nis;
      }
      if (d == 2) {
        if (t[++a][b].abil == 17) l[d] = 1000;
          else l[d] = t[a][b].niv_nis;
      }
      if (d == 3) {
        if (t[a][--b].abil == 17) l[d] = 1000;
          else l[d] = t[a][b].niv_nis;
      }
      //l[d] retine nr de jetoane de nisip din jurul jucatorului i
    }
	d++;
  }
  return l;
}

int deplasare2 (int i)
{
  int * posib = niv_nis_dir(i);
  int a, b, k = 0;
  for (a = 0; a < 4; a++) {
    if (posib[a] < 2 && posib [a] != -1) {
       if (k == 0) printf ("Alegeti cifra corespunzatoare directiei dorite \n");
       if (a == 0) printf ("0 = Sus\n");
       if (a == 1) printf ("1 = Dreapta\n");
       if (a == 2) printf ("2 = Jos\n");
       if (a == 3) printf ("3 = Stanga\n");
       k = 1;
    }
  }
  free (posib);
  if (k == 0) {
    printf ("Deplasare imposibila\n");
    return 0;
  }
  printf ("Cifra aleasa =");
  scanf ("%d", &k);
  a = j[i].lin_p;
  b = j[i].col_p;
  t[a][b].nr_jucatori --;
  if (k == 0) a--;
  if (k == 1) b++;
  if (k == 2) a++;
  if (k == 3) b--;
  t[a][b].nr_jucatori ++;
  j[i].col_p = b;
  j[i].lin_p = a;
  return 1;
}

int curata_nis (int i)
{
  int * posib = niv_nis_dir(i);
  int a, b, k = 0;
  for (a = 0; a < 4; a++) {
    if (posib[a] > 0 && posib[a] != 1000) {
       if (k == 0) printf ("Alegeti cifra corespunzatoare casutei dorite \n");
       if (a == 0) printf ("0 = Sus\n");
       if (a == 1) printf ("1 = Dreapta\n");
       if (a == 2) printf ("2 = Jos\n");
       if (a == 3) printf ("3 = Stanga\n");
       k = 1;
    }
  }
 // free (posib);
  a = j[i].lin_p;
  b = j[i].col_p;
  if (t[a][b].niv_nis > 0) {
    printf ("4 = Casuta actuala in care te afli\n");
    k = 1;
  }
  if (k == 0) {
	printf("Nivelul de nisip este 0");
    return 0;
  }
  printf ("Cifra aleasa =");
  scanf ("%d", &k);
  if (k == 0) a--;
  if (k == 1) b++;
  if (k == 2) a++;
  if (k == 3) b--;
  t[a][b].niv_nis --;
  return 1;
}

int afla_piesa (int k)
{
  if (k == 0 || k == 1) return 1;
  if (k == 2 || k == 3) return 2;
  if (k == 4 || k == 5) return 3;
  if (k == 6 || k == 7) return 4;
  return 0;
}

void pune_piesa (int k)
{
  int a, b, c;
  c = afla_piesa (k);
  if(k % 2 == 0) {
    b = indicatori [k][1];
    a = indicatori [k+1][0];
    t[a][b].piese_t[c]++;
    return;
  }
  a = indicatori [k][0];
  b = indicatori [k-1][1];
  if(c) t[a][b].piese_t[c]++;
}

void f_indic (int i)
{
  int a, b, k;
  a = j[i].lin_p;
  b = j[i].col_p;
  k = t[a][b].abil - 3;
  indicatori[k][0] = a;
  indicatori[k][1] = b;
  if (k % 2 == 0 && indicatori[k+1][0] != 0) {
    pune_piesa (k);
    return;
  }
  if (k % 2 == 1 && indicatori[k-1][0] != 0) {
    pune_piesa (k);
    return;
  }
}

int desc_ab(int i)
{
  int a, b;
  a = j[i].lin_p;
  b = j[i].col_p;
  if (t[a][b].ab_viz == 1) {
    printf ("Abilitate deja vizibila!\n");
    return 0;
  }
  if (t[a][b].niv_nis != 0) {
    printf ("Nivelul nisipului este prea mare!\n");
    return 0;
  }
  t[a][b].ab_viz = 1;
  if (t[a][b].abil == 1) return 2;
  if (t[a][b].abil > 2 && t[a][b].abil < 11) f_indic(i);
  return 1;
}

int ex_piesa (int i)
{
  int a, b, k = 0, r;
  a = j[i].lin_p;
  b = j[i].col_p;
  for (r = 1; r <= 4; r++)
    if (t[a][b].piese_t[r] == 1){
      piese[r] ++;
      k = 1;
    }
  if (k != 0) return 1;
  printf ("Piesa nu se afla aici\n");
  return 0;
}

void mutari(int i){
afisare();
printf("\n\t%s : \n\n \n",j[i].nume);
  while (j[i].numar_mutari) {
    if (j[i].abil == 1) Archeologist(i);
    if (j[i].abil == 2) Explorer(i);
    if (j[i].abil == 3) Water_Carrier(i,m);
    if (j[i].abil == 4) Climber(i);
    if (j[i].abil == 5) Navigator(i);
    if (j[i].numar_mutari) {
      int k, a;
      printf ("Alege cifra:\n");
      printf ("1 = Deplasare pe tabla\n");
      printf ("2 = Curatare nisip\n");
      printf ("3 = Intoarcere piesa\n");
      printf ("4 = Extrage piesa avionului\n");
	  if (t[j[i].lin_p][j[i].col_p].niv_nis == 0 && (t[j[i].lin_p][j[i].col_p].abil == 1 || t[j[i].lin_p][j[i].col_p].abil == 18))
        printf("5 = Ia apa\n");
      printf ("Cifra aleasa = ");
      scanf ("%d", &k);
      if (k == 1) a = deplasare2 (i);          // a=0 daca nu are unde sa se mute, 1 altfel
      if (k == 2) a = curata_nis (i);        // a=1 daca are de unde sa curete nisip, 0 altfel
      if (k == 3) a = desc_ab (i);           // daca a == 2 ab descoperita e de apa;
      if (k == 4) a = ex_piesa (i);          // a=1 daca exista piesa gasita in jur, 0 altfel


	  if (k == 5) {
	    a = 1;
		if(j[i].b1 == 0 && t[j[i].lin_p][j[i].col_p].abil == 1 && t[j[i].lin_p][j[i].col_p].ab_viz == 1) {
			for(int ku = 1; ku <= jucatori; ku++)
				if(t[j[ku].lin_p][j[ku].col_p].abil == 1){
					j[ku].niv_apa += 2;
					j[ku].b1 = 1;
					a = 1;}
		  
		} else if(j[i].b2 == 0 && t[j[i].lin_p][j[i].col_p].abil == 18 && t[j[i].lin_p][j[i].col_p].ab_viz == 1){
			for(int ku = 1; ku <= jucatori; ku++)
				if(t[j[ku].lin_p][j[ku].col_p].abil == 18){
					j[ku].niv_apa += 2;
					j[ku].b2 = 1;
					a = 1;
				}
			
		}}

      if (a) {
        j[i].numar_mutari --;afisare();
        if (a == 2) m++;
      }
    }
  }
  for(int i=1;i<=jucatori;i++)j[i].numar_mutari=4;
}


int main()
{int nrzv,ok=1,i;
	int var1,var2,*v1;
	srand ((unsigned int)time(NULL));
	v1=random(31);
	
	strcpy(j_tab[1], "fantana ");
  strcpy(j_tab[2], "miraj   ");
  strcpy(j_tab[3], "elice1  ");
  strcpy(j_tab[4], "elice2  ");
  strcpy(j_tab[5], "motor1  ");
  strcpy(j_tab[6], "motor2  ");
  strcpy(j_tab[7], "cristal1");
  strcpy(j_tab[8], "cristal2");
  strcpy(j_tab[9], "carma1  ");
  strcpy(j_tab[10], "carma2  ");
  strcpy(j_tab[11], "elice   ");
  strcpy(j_tab[12], "motor   ");
  strcpy(j_tab[13], "cristal ");
  strcpy(j_tab[14], "carma   ");
  strcpy(j_tab[15], "tunel   ");
  strcpy(j_tab[16], "puntea  ");
  strcpy(j_tab[17], "furtuna ");
  strcpy(j_tab[18], "fantana ");

  strcpy(j_abil[1], "Arheolog");
  strcpy(j_abil[2], "Explorator");
  strcpy(j_abil[3], "Baiatul cu apa");
  strcpy(j_abil[4], "Catarator");
  strcpy(j_abil[5], "Navigator");

  srand ((unsigned int)time(NULL) );
 
  REZULTAT=1;
  players();
  
  tabla();
  
  
 
  afisare2();

  system("pause");
  for(int i=1;i<=jucatori;i++){
	  if(j[i].abil==3)j[i].niv_apa=5;
	  else j[i].niv_apa =4;
	  j[i].numar=i;}


	system("color 70");

	

  var1=3;
  var2=3;

	n=31;

	jet=48;
	nrzv=1;
	
	while(REZULTAT&&ok!=2){
		
		
		if(nrzv==jucatori+1)nrzv=1;
		system("CLS");


	   mutari(nrzv);nrzv++;
	   afisare();


	   for(int i=1;i<=1+nivel_nisip/4;i++){
		   if(!jet)v1=random(31);
		   carti_de_nisip(v1,&n,&var1,&var2);
		  if(!REZULTAT)i=17;

	}
	if(REZULTAT)
		{for(int i=1;i<=4;i++)
			if(!piese[i])ok=0,i=4;
	    if(ok)
			for(int i=1;i<=jucatori;i++)
				if(t[j[i].lin_p][j[i].col_p].abil!=16)
					ok=0,i=jucatori+1;
		if(ok){
			ok=2;
			printf("\t\t\t---JOC CASTIGAT---\n");
		}


	}}

	if(!REZULTAT)printf("\t\t\t---JOC PIERDUT---\n ");



	afisare();


	system("pause");
	free(v1);
	return 0;}

