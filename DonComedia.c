#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
	int dia,mes,year,edad;
	char nombre[30];
	long long int dinero;
}jugador;
typedef struct
{
	char pregunta[100],respuesta[100];
	int correcta;
}preguntas;

long long int tragaperras(long long int dinero);
long long int ruleta(long long int dinero);
long long int blackjack(long long int dinero);
long long int atrapa(long long int dinero);

int main()
{
	char s;
	jugador j1,*q=&j1;
	do
	{
	printf("Bienvenido al casino de DonComedia!!! (Solo apto para mayores de edad)\n\nA continuacion introduce los siguientes datos\n\n");
	printf("Nombre completo\n");
	scanf(" %30[^\n]",q->nombre);
	printf("\nJugador: %s\n\n", q->nombre);
	printf("Fecha de nacimiento (dd mm yyyy)\n");
	scanf(" %d %d %d",&q->dia,&q->mes,&q->year);
	if (q->dia>31 || q->dia<1 || q->mes>12 || q->mes<1|| q->year>2020)
	{
		printf("Escribe una fecha de nacimiento valida\n");
		scanf(" %d %d %d",&q->dia,&q->mes,&q->year);
	}
	q->edad=2020-q->year;
	q->dinero=1000;
	if (q->edad<18)
	printf("Lo siento, si eres menor de edad no puedes jugar\n\n");
	}
	while(q->edad<18);
	
    int op,p=1;
    do
	{
		system("cls");
    	printf("Perfecto.\nAhora piense en que juego quiere participar:\n\n");
    	printf("Actualmente disponemos de tragaperras(1), ruleta(2), blackjack(3) o atrapa un millon(4)\n\n");
    
		printf("Escribe el numero del juego al que quiere participar porfavor:\n\n");
    	scanf("%i",&op);

        switch(op)
    	{
    	    case 1:
			{
				printf("Has decidido jugar a las tragaperras.\n\n");
				q->dinero=tragaperras(q->dinero);
			}
    	    break;
    	    case 2:
        	{
				printf("Has decidido jugar a la ruleta. Apueste a numeros rojos,negros o a un numero en concreto\n\n");
    	    	q->dinero=ruleta(q->dinero);
			}
    	    break;
        	case 3:
        	{
				printf("Has decidido jugar a el blackjack.\n\n");
        		q->dinero=blackjack(q->dinero);
			}
        	break;
        	case 4:
        	{
				printf("Has decidido atrapa un millon,consistira en acertar 10 preguntas donde se daran 4 opciones.\nSi acierta la primera pregunta avanzara a la siguiente y lo mas importante ¡Conseguira mas dinero!\n\n");
        		q->dinero=atrapa(q->dinero);
			}
        	break;
    
        }
		printf("Dinero acumulado : %lli$\n\n",q->dinero);
		printf("Si desea jugar de nuevo pulse '1'\n");
    	scanf("%d",&p);
	}
	while(p==1);
	
	return 0;
}

long long int tragaperras(long long int dinero)
{
	system("cls");
	int a,s,d,q,w,e,z,x,c,i,avances=5;
	char p='1';
	srand (time(NULL));
	a = rand() % 10;
	s = rand() % 10;
	d = rand() % 10;
	printf("Bienvenido a la tragaperras, para ganar dinero los 3 numeros centrales deben coincidir,\n");
	printf("el premio sera proporcional a los numeros.\n");
	printf("Para hacer avanzar las ruedas hay que pulsar 'a','s' y 'd'\n");
	printf("Empezaras jugando con 5 avances\nPara comprar mas pulsa 1\n");
	printf("Para jugar pulsa 0\n");
	scanf("%s",&p);
	switch (p)
	{
		case'1':
			system("cls");
			do
			{
				printf("Tienes %lli$\n",dinero);
				printf("Cada avance cuesta 50$\n");
				printf("Cuantos quieres?");
				scanf("%d",&i);
				if (dinero<(50*i))
				{
					printf("No tienes suficiente dinero\n");
				}
				else if (dinero>=(50*i))
				{
					dinero-=(50*i);
					avances+=i;
					i=0;
				}
			}while(i!=0);
		case '0':
			do
			{
				system("cls");
				
				if (a==-1)
				{a=9;}
				if (s==-1)
				{s=9;}
				if (d==-1)
				{d=9;}
				if (a==10)
				{a=0;}
				if (s==10)
				{s=0;}
				if (d==10)
				{d=0;}
				q=a-1;w=s-1;e=d-1;z=a+1;x=s+1;c=d+1;
				if (q==-1)
				{q=9;}
				if (w==-1)
				{w=9;}
				if (e==-1)
				{e=9;}
				if (z==10)
				{z=0;}
				if (x==10)
				{x=0;}
				if (c==10)
				{c=0;}
				printf("|%d | %d | %d|\n\n",q,w,e);
				printf("|%d | %d | %d|\n\n",a,s,d);
				printf("|%d | %d | %d|\n",z,x,c);	
				if (a==s && s==d)
				{
					if (a==0)
					{
						printf("PREMIO GORDO!!!\nHas ganado 100000$\n");
						dinero+=100000;
						
					}
					else
					{
						printf("PREMIO!!!\nHas ganado %d$\n",a*s*d*10);
						dinero+=(a*s*d*10);
					}
					avances=0;
				}
				if (avances!=0)
				{		
					scanf("%s",&p);
					switch (p)
					{
						case 'a':
							a--;
						break;
						case 's':
								s--;
						break;
						case 'd':
							d--;
						break;
					}
				}
				avances--;
			}
			while(p!='1' && avances>=0);
		break;
	}
				
return dinero;	
}
long long int ruleta(long long int dinero)
{
	int tipo_apuesta,apuesta_inicial,apuesta_final,xx;
int acierto=0;
srand(time(NULL));
int num = rand() % 37;
int numero;

	
   system("cls");
   do
			{
				printf("Has decidido jugar a la ruleta. Apueste a numeros rojos,negros o a un numero en concreto\n\n");
				printf("Tienes %lli$\n\n",dinero);
				printf(" De cuanto dinero desea realizar la apuesta?\n");
			
				scanf("%d",&apuesta_inicial);
				if (dinero< apuesta_inicial )
				{
					printf("No tienes suficiente dinero\n");
				}
				else if (dinero>= apuesta_inicial )
				{
					dinero-= apuesta_inicial;
			        printf("Te quedaran %lli$\n ",dinero);
					apuesta_final = apuesta_inicial;
					apuesta_final=0;
				}
			}while(apuesta_final!=0);

     
  


printf("Seleccione a cual desea efectuar su apuesta mediante el numero indicado\n\n");

while(acierto<1)
{
  printf("Numero(1),Par(2),Impar(3):\n");
  scanf("%i",&tipo_apuesta);
 if (tipo_apuesta>3){

 printf("Numero incorrecto,seleccione de nuevo el numero que desee\n\n.");
}
 else
 {
    acierto ++;
 }
}	

    if(tipo_apuesta==1)
            {
			system("cls");
			printf("Seleccion el numero que desea:\n\n");
			scanf("%d",&numero);
			printf("El numero aleatorio salido es %d\n",num);
			if (num == numero)
			{
			printf("Ha acertado! Es usted increible. ");
			dinero+=10*apuesta_inicial;
			printf("Ahora mismo tiene %lli$\n",dinero);
		    }
		    else
		    {
		    printf("No ha acertado. Pruebe de nuevo!");
		    printf("Ahora tienes %lli$\n",apuesta_inicial,dinero);
			}
		    }
	else if(tipo_apuesta==2)
	{
	
			system("cls");
			
			printf("El numero aleatorio salido es %d\n",num);
			if (num % 2 == 0)
			{
			printf("Es par. Lo ha conseguido!");
			dinero+= 2*apuesta_inicial;
			printf("Su dinero actualmente es de %lli$\n",dinero);
	 	    }
			else
			{
			printf("No ha acertado. Pruebe de nuevo!");
		    printf("Ha perdido %d$, ahora tienes %lli$\n",apuesta_inicial,dinero);
			}
    }
	else if (tipo_apuesta == 3)
	{
	
			system("cls");
			printf("El numero aleatorio salido es %d\n",num);
			if (num % 2 != 0)
			{
			printf("Es impar! Lo ha conseguido!");
			dinero+=2*apuesta_inicial;
			printf("Su dinero actualmente es de %lli$\n",dinero);
			}
			else
			{
			printf("No ha acertado. Pruebe de nuevo!");
		    printf("A perdido %d$, ahora tienes %lli$\n",apuesta_inicial,dinero);
			}
	}

return dinero;	
}
long long int blackjack(long long int dinero)
{
	
}
long long int atrapa(long long int dinero)
{
	system("cls");
	printf("Por cada respuesta correcta acumularas 100000$\n");
	printf("Tras la pregunta 5 se te dara la oportunidad de retirar tu dinero o continuar,\n");
	printf("arriesgandote a perderlo\n\n");
	preguntas p[10];
	long long int premio=0;
	int i,n;
	FILE *pf;
	pf = fopen("preguntas.txt", "r");
	
	for(i=0;i<10;i++)
		fscanf(pf, " %[^\n]\n%[^;];\n%d",p[i].pregunta,p[i].respuesta,&p[i].correcta);	
		
	for(i=0;i<10;i++)
	{
		printf("Dinero acumulado : %lli$\n\n",premio);
		if (i==5)
		{
			printf("Puedes arriesgarte a continuar o quedarte con los %lli$\n",premio);
			printf("Pulsa 1 para retirarte\n");
			scanf("%d",&n);
			if (n==1)
			return dinero+premio;
			system("cls");
		}
		
		printf("%s \n\n",p[i].pregunta);
		printf("%s \n",p[i].respuesta);
		scanf("%d",&n);
		
		if (n==p[i].correcta)
		{
			system("cls");
			printf("CORRECTO. Has ganado 100000$\n\n");
			premio+=100000;
		}
		else if (n!=p[i].correcta)
		{
			system("cls");
			printf("NO ES CORRECTO. Has perdido tus %lli$\n\n",premio);
			return 0;
		}

	}

	return dinero+premio;
}
