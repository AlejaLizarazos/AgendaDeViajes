#include "milibreria.h"

void crear_registro(){
	int i=1;
	system("clear");
	printf("Seleccione una categoria:\n");	
	while (i==1){
		printf("1.Comida 2.Cultura 3.Lugares\n");
	        scanf("%d",&opcion);
	
        	switch(opcion)
        	{
                case 1: 
                       	strncpy(&categoria[0],"comida",CAT-1);
			printf("%s",categoria);
                       	i=0;
			break;
                case 2: 
                        strncpy(&categoria[0],"comida",CAT-1);
                        i=0;
			break;
                case 3: 
                        strncpy(&categoria[0],"comida",CAT-1);
                        i=0;
			break;
		default:
			system("clear");
			printf("Opcion incorrecta, ingrese una valida:\n");
			break;
                	 }
		}
	system("clear");
	
	printf("\nIngrese la ciudad\n");
        scanf("%s",ciudad);
	system("clear");
        
        printf("\nIngrese el mes\n");
	scanf("%s",mes);
	system("clear");
        
        printf("\npendiente\n");
        scanf("%s",pendiente);
	system("clear");
        
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
			system("clear");
        		printf("ruta:\n");
               	 	scanf("%s",ruta);
        
			downloader(url,ruta);
			i=2;
         		break;
            	case 2:
			system("clear");
        		printf("ruta:\n");
                	scanf("%s",ruta);
        
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
