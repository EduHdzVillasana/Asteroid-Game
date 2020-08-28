/*
*********************************************************************************************************************************************************************************
********************************************************************ASTEROIDES 1.0**********************************************************************************
*********************************************************************************************************************************************************************************
	EDUARDO ALAN HERNANDEZ VILLASANA
	JUNIO-JULIO 2016
	TUTORIA: CODIGOFACIITO
*/
#include <stdio.h> //para caracteres, disque no salen en el teclado en iostream pero este si
#include <iostream.>// este es el bueno
#include <windows.h> //para las ventanas o handle's
#include <conio.h> //para la lecura de teclas
#include <stdlib.h>//para poner un numero random
#include <list>     //para usar las listas
#include <fstream>
#include <sstream>
#include <string>
#define ARRIBA 72 // cada tecla tiene un numero
#define IZQUIERDA 75 //Define las palabras como numeros
#define DERECHA 77 //
#define ABAJO 80 //
using namespace std;

int cx=0;
int cy=0;
int mx=0;
int my=0;
int ax=0;
int ay=0;
int h=0;
int k=0;
int vel=76;
int q=0;
int d=0;
int bandera=0;
int pausa=0;
int px=0;
int py=0;
int nmo=0;
int m=0;
string nombre;
void gotoxy (int x, int y) //funion de compilador de borlad. Los int son parametros en la funcion
{
	HANDLE hCon;//                            {                      Se agarra el id del handle      
	hCon = GetStdHandle(STD_OUTPUT_HANDLE); //{                         handle=como ventana
	COORD dwPos;//   {
	dwPos.X=x;//            se ponen las cordenadas
	dwPos.Y=y;//     }                    
	SetConsoleCursorPosition(hCon,dwPos);// se establece el cursor. 
}
void nocursor ()///// quitar cursor
{
	HANDLE hCon;                           // lo normal
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);//llama al handle
	CONSOLE_CURSOR_INFO cgi;        //llama caracteristicas del cursor
	cgi.dwSize = 1;//                 tamaño
	cgi.bVisible = FALSE;//           visibilidad
	SetConsoleCursorInfo(hCon,&cgi);//las relaciona con el handle
}
void gameover ()
{
	system("cls");
	gotoxy (5,0);
	printf ("%c%c%c%c   %c%c%c%c    %c    %c%c%c%c   %c%c%c%c   %c%c%c%c    %c%c%c     %c%c%c    %c%c%c%c   %c%c%c%c \n",201,205,205,187,  201,205,205,205,  186, 201,205,205,205, 201,205,205,187,  201,205,205,187,  205,203,205,  201,205,187,  201,205,205,205,  201,205,205,205);
	Sleep (200);
	printf ("     %c  %c   %c      %c%c%c   %c      %c  %c   %c  %c     %c      %c %c%c   %c      %c    \n",186,186,186,205,206,205,186,186,186,186,186,186,186,200,187,186,186);
	Sleep (200);
	printf ("     %c%c%c%c   %c%c%c%c    %c    %c%c%c%c   %c%c%c%c   %c  %c     %c      %c  %c   %c%c%c%c   %c%c%c%c \n",204,205,205,185,200,205,205,187,186,204,205,205,205,204,205,203,188,186,186,186,186,186,204,205,205,205,200,205,205,187);
	Sleep (200);
	printf ("     %c  %c      %c    %c    %c      %c %c%c   %c  %c     %c      %c %c%c   %c         %c  \n",186,186,186,186,186,186,200,187,186,186,186,186,201,188,186,186);
	Sleep (200);
	printf ("     %c  %c   %c%c%c%c    %c    %c%c%c%c   %c  %c   %c%c%c%c    %c%c%c     %c%c%c    %c%c%c%c   %c%c%c%c   \n",186,186,205,205,205,188,186,200,205,205,205,186,186,200,205,205,188,205,202,205,200,205,188,200,205,205,205,205,205,205,188);
	printf ("     \n                                                 CREADO POR ALAN VILLASANA");
	gotoxy(36,30);//
	printf("  %c",30);//
	gotoxy(36,31);//                               se dibuja la nave
	printf(" %c%c%c",91,207,93);//
	gotoxy(36,32);//
	printf("%c%c %c%c",30,190,190,30);//{
	gotoxy (34,13);
	printf ("PUNTOS ");
	cout <<k;
	gotoxy (34,15);
	printf ("GAME OVER");
	gotoxy (21,17);
	printf ("Precione cualquier tecla para salir");
	while (m==0)
	{	
		if (kbhit())
		{
			m=1;
		}
	}
	system ("cls");
}
void paus()
{
	gotoxy (27,14);
	printf ("            PAUSA");
	gotoxy (27,15);
	printf ("PARA CONTINUAR PRESIONA ENTER");
	if (kbhit())
	{
		pausa=0;
	}
}
void limites ()
{
	for (int i=2;i<82;i++)
	{
		gotoxy (i, 3);
		printf ("%c",205);
		gotoxy (i, 33);
		printf ("%c",205);		
	}
	for (int j=4;j<33;j++)
	{
		gotoxy (2,j);
		printf ("%c",186);
		gotoxy (81,j);
		printf ("%c",186);
	}
	gotoxy (2,3);
	printf("%c",201);
	gotoxy (2,33);
	printf("%c",200);
	gotoxy (81,3);
	printf("%c",187);
	gotoxy (81,33);
	printf("%c",188);
}
void menu ()
{
	gotoxy (5,0);
	printf ("%c%c%c%c   %c%c%c%c    %c    %c%c%c%c   %c%c%c%c   %c%c%c%c    %c%c%c     %c%c%c    %c%c%c%c   %c%c%c%c \n",201,205,205,187,  201,205,205,205,  186, 201,205,205,205, 201,205,205,187,  201,205,205,187,  205,203,205,  201,205,187,  201,205,205,205,  201,205,205,205);
	Sleep (200);
	printf ("     %c  %c   %c      %c%c%c   %c      %c  %c   %c  %c     %c      %c %c%c   %c      %c    \n",186,186,186,205,206,205,186,186,186,186,186,186,186,200,187,186,186);
	Sleep (200);
	printf ("     %c%c%c%c   %c%c%c%c    %c    %c%c%c%c   %c%c%c%c   %c  %c     %c      %c  %c   %c%c%c%c   %c%c%c%c \n",204,205,205,185,200,205,205,187,186,204,205,205,205,204,205,203,188,186,186,186,186,186,204,205,205,205,200,205,205,187);
	Sleep (200);
	printf ("     %c  %c      %c    %c    %c      %c %c%c   %c  %c     %c      %c %c%c   %c         %c  \n",186,186,186,186,186,186,200,187,186,186,186,186,201,188,186,186);
	Sleep (200);
	printf ("     %c  %c   %c%c%c%c    %c    %c%c%c%c   %c  %c   %c%c%c%c    %c%c%c     %c%c%c    %c%c%c%c   %c%c%c%c   \n",186,186,205,205,205,188,186,200,205,205,205,186,186,200,205,205,188,205,202,205,200,205,188,200,205,205,205,205,205,205,188);
	printf ("     \n                                                 CREADO POR ALAN VILLASANA");
	gotoxy(36,30);//
	printf("  %c",30);//
	gotoxy(36,31);//                               se dibuja la nave
	printf(" %c%c%c",91,207,93);//
	gotoxy(36,32);//
	printf("%c%c %c%c",30,190,190,30);//{
	gotoxy (40,33);
	while (d==0)
	{
		gotoxy (33,15);
		printf ("                 ");
		Sleep (750);
		gotoxy (33,15);
		printf ("PRESIONA ENTER");
		Sleep (750);	
		if (kbhit())
		{
			d=1;
		}
	}
	system ("cls");
	
}
void tablero ()
{
	gotoxy (50,0);
	printf ("Puntos");
	gotoxy (65,0);
	printf ("Nivel");
	gotoxy (0,0);
	printf("ASTEROIDES 1.0      Alan Villasana");
}
void lista ()
{
	gotoxy (0,0);
	printf ("INTRODUCE TU NOMBRE \n");
	cin<<nombre;
}
class nave // clase= objeto, tiene atributos=cordenadas y asi  y metodos= como reacciona ej una pelota REBOTA
{
	int cx,cy;// variables privadas, solo estan en la clase
	int vidas;
	int oportunidades;
	public: // esto es publico, puedes sacarlas y traerlas
		nave (int _x, int _y, int _vidas, int _oportunidades);// inicializa las variables de arriba en el main, y les pone valor
		int X () 
		{
			return cx;
		}
		int Y () 
		{
			return cy;
		}
		int OPO ()
		{
			return oportunidades;	
		}
		void dibujar ();//{
		void borrar ();//    metodos
		void mover ();//  {
		void nomover ();
		void vida();
		void morir();
		void VID();
};
nave::nave(int _x, int _y, int _vidas, int _oportunidades)//{
{
	
	cx=_x;//                    se ponen los valores de las variables pribadas de la clase
	cy=_y;//
	vidas=_vidas;
	oportunidades=_oportunidades;
}//
void nave::nomover()
{
	cx=px;
	cy=py;
}
void nave::VID()
{
	vidas--;
}
void nave::dibujar() //                 { funcion de la clase
{
	gotoxy(cx,cy);//
	printf("  %c",30);//
	gotoxy(cx,cy+1);//                               se dibuja la nave
	printf(" %c%c%c",91,207,93);//
	gotoxy(cx,cy+2);//
	printf("%c%c %c%c",30,190,190,30);//{
}
void nave::borrar()
{
	gotoxy ( cx, cy );
	printf("      ");
	gotoxy (cx-1,cy+1 );
	printf("       ");
	gotoxy (cx-1,cy+2 );
	printf("       ");
}
void nave::mover()
{
	h=0;
	px=cx;
	py=cy;		
	if (kbhit())// detecta si se ha picado una tecla
	{
		char t = getch();// detecta que tecla se tecleo
		borrar ();
	
		if (nmo==0)
		{
				if (t == 'a' && cx>5)//{
				{
					cx=cx-2;
				}
				if (t == 'd' && cx+6<81)
				{
					cx=cx+2;
				}
				if (t == 'w' && cy>4)//se mueven las cordenadas segun q0ue tecla se puso
				{
					cy--;
				}
				if (t == 's' && cy+3<33)
				{
					cy++;
				}
				if (t == 'p')//se mueven las cordenadas segun q0ue tecla se puso
				{
					h=1;
				}//            {
			}
			if (t == 'm')
			{
				pausa=1;
			}
			dibujar();
			vida();
	}
}

void nave::vida()
{
	gotoxy (50,2);
	printf ("VIDAS %d", oportunidades);
	gotoxy (64,2);
	printf ("Salud");
	gotoxy (70,2);
	printf ("       ");
	for (int k=0;k<vidas;k++)
	{
		gotoxy(70+k,2);
		printf("%c",3);
	}
}
void nave::morir()
{
	if(vidas==0)
	{
		borrar();
		gotoxy(cx,cy);
		printf("  *");
		gotoxy(cx,cy+1);
		printf(" ***");
		gotoxy(cx,cy+2);
		printf("  *");
		Sleep(200);
		borrar();
		gotoxy(cx,cy);
		printf("*   *");
		gotoxy(cx-1,cy+1);
		printf("   *  ");
		gotoxy(cx,cy+2);
		printf("*   *");
		Sleep(300);
		borrar();
		oportunidades--;
		vidas=3;
		vida();
		cx=36;
		cy=30;
		dibujar();
	}
}
class met
{
	int mx,my;
	public:
	met(int _x, int _y);	
	void dibujar ();
	void mover ();
	void choque(class nave &n);
	int MX()
	{
		return mx;
	}
	int MY()
	{
		return my;
	}
};
met::met(int _x, int _y)
{
	mx=_x;
	my=_y;
}
void met::dibujar()
{
	if (mx%2==1)
	{
		mx++;
	}
	gotoxy(mx,my);
	printf("%c",4);
}
void met::mover()
{
	gotoxy (mx,my);
	printf(" ");
	my++;
	if (my>32)
	{
		mx=rand()%77+3;
		my=4;
	}
	dibujar();
}
void met::choque(class nave &n)
{  
	if (mx >= n.X()&& mx <= n.X()+5&& my >= n.Y()&& my <= n.Y())
	{
		gotoxy(mx,my);
		printf ("*");
		Sleep (50);
		n.VID();
		n.borrar();
		n.dibujar();
		n.vida();
		my=4;
	}
}
  class BALA
 {
 	int ax,ay;
	public:
		BALA(int _x, int _y);
		int X() 
		{
			return ax;
		}
		int Y()
		{
			return ay;
		}
		void mover();
		bool afuera();
 };
 BALA::BALA(int _x, int _y)
 {
 	ax=_x;
 	ay=_y;
 }
 void BALA::mover()
 {
 	gotoxy(ax,ay);
 	printf(" ");
	ay--;
	gotoxy(ax,ay);
	printf("%c",18);
 }
 bool BALA::afuera()
 {
 	if (ay==4)
 	{
 		return true;	
	}
	else
	{
		return false;
	}
 }
 
 void nivel()
 {
 	if (k>=10)
 	{
 		vel=69;	
 		gotoxy (72,0);
 		printf ("2");
	}
	if (k>=20)
 	{
 		vel=62;	
 		gotoxy (72,0);
 		printf ("3");
	}
	if (k>=30)
 	{
 		vel=55;	
 		gotoxy (72,0);
 		printf ("4");
	}
 	if (k>=40)
 	{
 		vel=48;	
 		gotoxy (72,0);
 		printf ("5");
	}
	if (k>=50)
 	{
 		vel=41;	
 		gotoxy (72,0);
 		printf ("6");
	}
	if (k>=60)
 	{
 		vel=34;	
 		gotoxy (72,0);
 		printf ("7");
	}
 	if (k>=70)
 	{
 		vel=30;	
 		gotoxy (72,0);
 		printf ("8");
	}
 	if (k>=80)
 	{
 		vel=23;	
 		gotoxy (72,0);
 		printf ("9");
	}
	if (k>=90)
 	{
 		vel=16;	
 		gotoxy (72,0);
 		printf ("10");
	}
 }
 
int main()
{
	
	system("MODE CON COLS=83 LINES=35");
	system("color a");
	SetConsoleTitle("Asteroides 1.0");
	nocursor();
	menu();
	limites();
	tablero();
	nave n(36,30,3,3);
	n.dibujar();
	n.vida();
	list<met*>A;
	list<met*>::iterator itM;
	for (int l=0;l<25;l++)
	{
		A.push_back(new met (rand()%77 + 3, rand()%5 +4));
	}
	list<BALA*> B;
	list<BALA*>::iterator it;
	bool go=false;// (cuando se acaben las vidas se pone TRUE)
	gotoxy (72,0);
 	printf ("1");
	while (!go) //para que se ejecte hasta que se acabe el juego
	{
		gotoxy (58,0);
		cout <<k;
		if(h==1)
		{
			B.push_back(new BALA(n.X() + 2 , n.Y() - 1));
		}
        for(it = B.begin(); it != B.end() ; it++)
        {
            (*it)-> mover(); //el operador flecha sirve para que se meta a sus      //el puntero es la direccion donde esta guardada la direccion
        	if((*it)->afuera())
        	{
        		gotoxy((*it)->X(),(*it)->Y());
        		printf (" ");
        		delete (*it);
        		it = B.erase(it);
			}
		}
        
		for(itM= A.begin(); itM != A.end(); itM++)
		{
			(*itM)->mover();
			(*itM)->choque(n);
		}
		for(itM= A.begin(); itM != A.end(); itM++)
		{
			for(it=B.begin(); it != B.end();it++)
			{
				if ((*itM)->MX() == (*it)->X() && ( (*itM)->MY() + 1 == (*it)-> Y() || (*itM)->MY() == (*it)->Y() ))
				{
					gotoxy ((*it)->X(), (*it)->Y());
					printf("*");
					Sleep (50);
					gotoxy ((*it)->X(), (*it)->Y());
					printf(" ");
					delete (*it);
					it = B.erase(it);
					k++;
					
					A.push_back (new met (rand()%74+3,4));
					gotoxy ((*itM)->MX(), (*itM)->MY());
					printf(" ");
					delete (*itM);
					itM = A.erase(itM);
				}
			}
		}
		
		if (n.OPO()==0)
		{
			go=true;
		}
		n.morir();
		n.mover();
		if (pausa==1)
		{
			system("cls");
			gotoxy (72,0);
 			printf ("1");
 			limites();
			tablero();
			nivel ();
			n.vida();
			gotoxy (58,0);
			cout <<k;
			while (pausa==1)
			{
				paus();
			}
			system("cls");
			gotoxy (72,0);
 			printf ("1");
 			limites();
			tablero();
			nivel();
			n.vida();
			gotoxy (58,0);
			cout <<k;
		}
		nivel();
		Sleep (vel);// para que no se sature el procesador (60 FPS!)
	}	
	gameover();
	lista();
	return 0;
}
