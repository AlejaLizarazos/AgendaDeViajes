#include "milibreria.h"

void crear_registro(){
	char categoria[10];
	char ciudad[20];
	char pendiente[2];
	char mes[20];
	char ruta[100];
	char url[1000];

	int opcion;
	int i=1;
	system("clear");
	printf("Seleccione una categoria:\n");	
	while (i==1){
		printf("1.Comida 2.Cultura 3.Lugares\n");
	        scanf("%d",&opcion);
	
        	switch(opcion)
        	{
                case 1: 
                       	strcat(categoria,"comida");
                       	i=0;
			break;
                case 2: 
                        strcat(categoria,"cultura");
                        i=0;
			break;
                case 3: 
                        strcat(categoria,"lugares");
                        i=0;
			break;
		default:
			system("clear");
			printf("Opcion incorrecta, ingrese una valida:\n");
			break;
                	 }
		}
	system("clear");
	printf("%s",categoria);
	printf("\nIngrese la ciudad\n");
        scanf("%s",ciudad);
	system("clear");
        printf("%s",ciudad);
        printf("\nIngrese el mes\n");
	scanf("%s",mes);
	system("clear");
        printf("%s",mes);
        printf("\npendiente\n");
        scanf("%s",pendiente);
	system("clear");
        printf("%s",pendiente);
        printf("\nSeleccione ruta de imagen:\n");
        
	while(i==0){
		printf("1.url\t 2.ruta:\n");
		scanf("%d",&opcion);
        	switch(opcion)
        	{
            	case 1: 	
			system("clear");
                	printf("url:\n");
                	scanf("%s",url);
                	printf("%s",url);
			system("clear");
                	printf("\nruta:\n");
               	 	scanf("%s",ruta);
                	printf("%s",ruta);
			downloader(url,ruta);
			i=2;
         		break;
            	case 2:
			system("clear");
                	printf("\n ruta:");
                	scanf("%s",ruta);
                	printf("%s\n",ruta);
			i=2;
                	break;
		default:
			system("clear");
			printf("Opcion incorrecta,ingrese una valida\n");
			break;
            	}
	}	
	crear_conexion(categoria,ciudad,mes,ruta,pendiente);
    }
