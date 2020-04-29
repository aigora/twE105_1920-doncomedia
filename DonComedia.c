#include <stdio.h>
#include <string.h>

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

long long int tragaperras();
long long int ruleta();
long long int blackjack();
long long int atrapa();

int main()
{
	char s;
	jugador j1;
	do
	{
	printf("Bienvenido al casino de DonComedia!!! (Solo apto para mayores de edad)\n\nA continuacion introduce los siguientes datos\n\n");
	printf("Nombre completo\n");
	scanf(" %30[^\n]",j1.nombre);
	printf("Nombre: %s\n\n", j1.nombre);
	printf("Fecha de nacimiento (dd mm yyyy)\n");
	scanf(" %d %d %d",&j1.dia,&j1.mes,&j1.year);
	if (j1.dia>31 || j1.dia<1 || j1.mes>12 || j1.mes<1|| j1.year>2020)
	{
		printf("Escribe una fecha de nacimiento valida\n");
		scanf(" %d %d %d",&j1.dia,&j1.mes,&j1.year);
	}
	printf("Fecha de nacimiento: %d %d %d\n\n",j1.dia,j1.mes,j1.year);
	j1.edad=2020-j1.year;
	j1.dinero=0;
	if (j1.edad<18)
	printf("Lo siento, si eres menor de edad no puedes jugar\n\n");
	}
	while(j1.edad<18);
	
    int op,p=1;
    do
	{
    printf("Perfecto.\nAhora piense en que juego quiere participar:\n\n");
    printf("Actualmente disponemos de tragaperras(1), blackjack(2), ruleta(3) o atrapa un millon(4)\n\n");
    
		printf("Escribe el numero del juego al que quiere participar porfavor:\n\n");
        scanf("%i",&op);

        switch(op)
    	{
        case 1:
			{printf("Has decidido jugar a las tragaperras.\n\n");
			j1.dinero+=tragaperras();}
        break;
        case 2:
        	{printf("Has decidido jugar a la ruleta. Apueste a numeros rojos,negros o a un numero en concreto\n\n");
        	j1.dinero+=ruleta();}
        break;
        case 3:
        	{printf("Has decidido jugar a el blackjack.\n\n");
        	j1.dinero+=blackjack();}
        break;
        case 4:
        	{printf("Has decidido atrapa un millon,consistira en acertar 10 preguntas donde se daran 4 opciones.\nSi acierta la primera pregunta avanzara a la siguiente y lo mas importante ¡Conseguira mas dinero!\n\n");
        	j1.dinero+=atrapa();}
        break;
    
        }
	printf("dinero acumulado : %lli$\n\n",j1.dinero);
	printf("Si desea jugar de nuevo pulse '1'\n");
    scanf("%d",&p);
	}
	while(p==1);
	return 0;
}

long long int tragaperras()
{
	
}
long long int ruleta()
{
	
}
long long int blackjack()
{
	
}
long long int atrapa()
{
	preguntas p[10];
	long long int dinero=0;
	int i,n;
	FILE *pf;
	pf = fopen("preguntas.txt", "r");
	for(i=0;i<10;i++)
		fscanf(pf, " %[^\n]\n%[^;];\n%d",p[i].pregunta,p[i].respuesta,&p[i].correcta);	
	for(i=0;i<15;i++)
	{
		printf("dinero acumulado : %lli$\n\n",dinero);
		printf("%s \n\n",p[i].pregunta);
		printf("%s \n",p[i].respuesta);
		scanf("%d",&n);
		if (n==p[i].correcta)
		{
			printf("CORRECTO. Has ganado 100000$\n\n");
			dinero+=100000;
		}
		else if (n!=p[i].correcta)
		{
			printf("NO ES CORRECTO. Ha conseguido un total de %lli$\n\n",dinero);
			return dinero;
		}
	}
return dinero;
}
