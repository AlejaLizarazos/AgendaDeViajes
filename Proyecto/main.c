#include "milibreria.h"
int main(){
	int opcion;
	int i = 1;

	system("clear");

        printf("Bienvenido a tus agenda de viajes, escoja una opcion:\n");
	while (i==1) {
		printf("1.Crear un nuevo registro\n2.Consultar viajes especificos\n3.Visualizar imagen\n4.Check\n5.Salir\n "); 
        	scanf("%d",&opcion);
        	switch(opcion)
        	{
                case 1: 
                        crear_registro();
                        i=0;
			break;
                case 2:
			consultar_registro();
                        i=0;
                        break;
                case 3:
			visualizar_imagen();
			i=0;
                        break;
		case 4:
			check();
			i=0;
			break;
		case 5: 
			i=0;
			break;
		default:
			system("clear");
			printf("Opcion incorrecta, escoja una valida:\n");
        	}
	}
	return(0);
}


	
