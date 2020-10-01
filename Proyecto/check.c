#include "milibreria.h"
#define MAX_DB_STATEMENT_BUFFER_LENGTH 5000
char db_statement[MAX_DB_STATEMENT_BUFFER_LENGTH];
PGresult *db_result;
PGconn   *db_connection;
int row, num_rows;

void check(){
	PGconn *conn = PQconnectdb("user=postgres password=admin dbname=viajes");

        int opcion;
        int i = 1;
        char categoria[10];
        char ciudad[20];
        char mes[20];
        char pendiente[3];
	system("clear");
	printf("Ingrese la categoria:\n");	
	scanf("%s",categoria);
	printf("\nIngrese la ciudad\n");
        scanf("%s",ciudad);
        
        printf("\nIngrese el mes\n");
        scanf("%s",mes);
        system("clear");
        snprintf(&db_statement[0], MAX_DB_STATEMENT_BUFFER_LENGTH-1, "UPDATE viajes SET pendiente='no' WHERE categoria=('%s') and ciudad=('%s') and mes=('%s')",categoria,ciudad,mes);
	db_result = PQexec (conn, &db_statement[0]);
	if (PQresultStatus(db_result) != PGRES_COMMAND_OK)
                  {
                    printf("Postgres UPDATE error: %s\n", PQerrorMessage(db_connection));
                  }
                  
	else {
		printf("Registro actualizado con exito\n");
		}
	PQclear(db_result);

}
