#include "milibreria.h"


PGresult *db_result;
PGconn   *db_connection;


void visualizar_imagen(){
	PGconn *conn = PQconnectdb("user=postgres password=admin dbname=viajes");
	int i=1;
        system("clear");

        printf("Ingrese la columna de las imagenes que desea visualizar:\n");
        while (i==1) {
                printf("1.Categoria\n2.Ciudad\n3.Mes\n4.Pendiente\n");
                scanf("%d",&opcion);
		system("clear");
                switch(opcion)
                {
                case 1: 
			printf("Ingrese la categoria\n");
			scanf("%s",categoria);
			system("clear");
                       	snprintf(&db_statement[0], MAX_DB_STATEMENT_BUFFER_LENGTH-1, "SELECT ruta FROM viajes WHERE categoria=('%s')",categoria);
			db_result = PQexec (conn, &db_statement[0]);
			if (PQresultStatus(db_result) == PGRES_TUPLES_OK)
				{
  				num_rows = PQntuples(db_result);
  				if (num_rows == 0)
  					{
    					printf ("No existe ese registro en la base de datos\n");
  					}
  				else
  					{
    					for (row = 0; row < num_rows; row++)
    						{
      						printf ("%s\t\n",PQgetvalue (db_result, row, 0) );
						snprintf(&buf[0],BUF-1,"gnome-open %s",PQgetvalue (db_result, row, 0));
						system(&buf[0]);                                                
						}
  					}
  				PQclear (db_result);
				}
                        i=0;
                        break;
                case 2:
			printf("Ingrese la ciudad\n");
                        scanf("%s",ciudad);
			system("clear");
                        snprintf(&db_statement[0], MAX_DB_STATEMENT_BUFFER_LENGTH-1, "SELECT ruta FROM viajes WHERE ciudad=('%s')",ciudad);
                        db_result = PQexec (conn, &db_statement[0]);
                        if (PQresultStatus(db_result) == PGRES_TUPLES_OK)
                                {
                                num_rows = PQntuples(db_result);
                                if (num_rows == 0)
                                        {
                                        printf ("No existe ese registro en la base de datos\n");
                                        }
                                else
                                        {
                                        for (row = 0; row < num_rows; row++){
					{
                                                printf ("%s\t \t\n", PQgetvalue (db_result, row, 0));
						snprintf(&buf[0],BUF-1,"gnome-open %s",PQgetvalue (db_result, row, 0));
						system(&buf[0]);
                                                }
                                        }
                                PQclear (db_result);
                                }
			}
	
                        i=0;
                        break;
                case 3:
			printf("Ingrese el mes\n");
			scanf("%s",categoria);
			system("clear");
                       	snprintf(&db_statement[0], MAX_DB_STATEMENT_BUFFER_LENGTH-1, "SELECT ruta FROM viajes WHERE mes=('%s')",mes);
			db_result = PQexec (conn, &db_statement[0]);
			if (PQresultStatus(db_result) == PGRES_TUPLES_OK)
				{
  				num_rows = PQntuples(db_result);
  				if (num_rows == 0)
  					{
    					printf ("No existe ese registro en la base de datos\n");
  					}
  				else
  					{
    					for (row = 0; row < num_rows; row++)
    						{
      						printf ("%s\t \t\n", PQgetvalue (db_result, row, 0));
    						snprintf(&buf[0],BUF-1,"gnome-open %s",PQgetvalue (db_result, row, 0));
						system(&buf[0]);
						}
  					}
  				PQclear (db_result);
				}
                        i=0;
			break;
		case 4:
			printf("Pediente por visitar?\n");
			scanf("%s",pendiente);
			system("clear");
                       	snprintf(&db_statement[0], MAX_DB_STATEMENT_BUFFER_LENGTH-1, "SELECT ruta FROM viajes WHERE pendiente=('%s')",pendiente);
			db_result = PQexec (conn, &db_statement[0]);
			if (PQresultStatus(db_result) == PGRES_TUPLES_OK)
				{
  				num_rows = PQntuples(db_result);
  				if (num_rows == 0)
  					{
    					printf ("No existe ese registro en la base de datos\n");
  					}
  				else
  					{
    					for (row = 0; row < num_rows; row++)
    						{
      						printf ("%s\t\n", PQgetvalue (db_result, row, 0));
    						snprintf(&buf[0],BUF-1,"gnome-open %s",PQgetvalue (db_result, row, 0));
						system(&buf[0]);
						}
  					}
  				PQclear (db_result);
				}
			i=0;
			break;
		default:
			system("clear");
			printf("Opcion incorrecta, ingrese una valida\n");
			i=1;
			break;
		}

	}
}

