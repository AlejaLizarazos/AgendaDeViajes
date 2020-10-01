#include "milibreria.h"
#define MAX_DB_STATEMENT_BUFFER_LENGTH 5000
char db_statement[MAX_DB_STATEMENT_BUFFER_LENGTH];
PGresult *db_result;
PGconn   *db_connection;
int row, num_rows;

void consultar_registro(){
	PGconn *conn = PQconnectdb("user=postgres password=admin dbname=viajes");

	int opcion;
        int i = 1;
	char categoria[10];
	char ciudad[20];
	char mes[20];
	char pendiente[3];

        system("clear");

        printf("Ingrese el dato que quiere filtrar:\n");
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
                       	snprintf(&db_statement[0], MAX_DB_STATEMENT_BUFFER_LENGTH-1, "SELECT ciudad,mes,pendiente FROM viajes WHERE categoria=('%s')",categoria);
			db_result = PQexec (conn, &db_statement[0]);
			if (PQresultStatus(db_result) == PGRES_TUPLES_OK)
				{
  				num_rows = PQntuples(db_result);
				printf ("\n");
            			printf ("+-----------+------------+\n");
            			printf ("|Ciudad | Mes | Pendiente |\n");
            			printf ("+-----------+------------+\n");
  				if (num_rows == 0)
  					{
    					printf ("No existe ese registro en la base de datos\n");
  					}
  				else
  					{
    					for (row = 0; row < num_rows; row++)
    						{
      						printf ("%s\t %s\t %s\t\n", PQgetvalue (db_result, row, 0), PQgetvalue (db_result, row, 1), PQgetvalue (db_result, row, 2));
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
                        snprintf(&db_statement[0], MAX_DB_STATEMENT_BUFFER_LENGTH-1, "SELECT categoria,mes,pendiente FROM viajes WHERE ciudad=('%s')",ciudad);
                        db_result = PQexec (conn, &db_statement[0]);
                        if (PQresultStatus(db_result) == PGRES_TUPLES_OK)
                                {
                                num_rows = PQntuples(db_result);
                                printf ("\n");
                                printf ("+-----------+------------+\n");
                                printf ("|Categoria | Mes | Pendiente |\n");
                                printf ("+-----------+------------+\n");
                                if (num_rows == 0)
                                        {
                                        printf ("database is empty");
                                        }
                                else
                                        {
                                        for (row = 0; row < num_rows; row++){
					{
                                                printf ("%s\t  %s\t %s\n", PQgetvalue (db_result, row, 0), PQgetvalue (db_result, row, 1), PQgetvalue (db_result, row, 2));
                                                }
                                        }
                                PQclear (db_result);
                                }
			}
	
                        i=0;
                        break;
                case 3:
			printf("Ingrese el mes\n");
			scanf("%s",mes);
			system("clear");
                       	snprintf(&db_statement[0], MAX_DB_STATEMENT_BUFFER_LENGTH-1, "SELECT categoria,ciudad,pendiente FROM viajes WHERE mes=('%s')",mes);
			db_result = PQexec (conn, &db_statement[0]);
			if (PQresultStatus(db_result) == PGRES_TUPLES_OK)
				{
  				num_rows = PQntuples(db_result);
				printf ("\n");
            			printf ("+-----------+------------+\n");
            			printf ("|Categoria | Ciudad | Pendiente |\n");
            			printf ("+-----------+------------+\n");
  				if (num_rows == 0)
  					{
    					printf ("database is empty\n");
  					}
  				else
  					{
    					for (row = 0; row < num_rows; row++)
    						{
      						printf ("%s  %s %s\n", PQgetvalue (db_result, row, 0), PQgetvalue (db_result, row, 1), PQgetvalue (db_result, row, 2));
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
                       	snprintf(&db_statement[0], MAX_DB_STATEMENT_BUFFER_LENGTH-1, "SELECT categoria,ciudad,mes FROM viajes WHERE pendiente=('%s')",pendiente);
			db_result = PQexec (conn, &db_statement[0]);
			if (PQresultStatus(db_result) == PGRES_TUPLES_OK)
				{
  				num_rows = PQntuples(db_result);
				printf ("\n");
            			printf ("+-----------+------------+\n");
            			printf ("|Categoria |Ciudad | Mes |\n");
            			printf ("+-----------+------------+\n");
  				if (num_rows == 0)
  					{
    					printf ("database is empty\n");
  					}
  				else
  					{
    					for (row = 0; row < num_rows; row++)
    						{
      						printf ("%s\t %s\t %s\t\n", PQgetvalue (db_result, row, 0), PQgetvalue (db_result, row, 1), PQgetvalue (db_result, row, 2));
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
