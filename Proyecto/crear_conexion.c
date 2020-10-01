#include "milibreria.h"
#define MAX_DB_STATEMENT_BUFFER_LENGTH 5000


char db_statement[MAX_DB_STATEMENT_BUFFER_LENGTH];

void do_exit(PGconn *conn, PGresult *res) {
    
    fprintf(stderr, "%s\n", PQerrorMessage(conn));    

    PQclear(res);
    PQfinish(conn);    
    
    exit(1);
}


void crear_conexion(char *cat,char *ci,char *m,char *r,char *p){
	PGconn *conn = PQconnectdb("user=postgres password=admin dbname=viajes");
	
	if (PQstatus(conn) == CONNECTION_BAD) {
        
        	fprintf(stderr, "Connection to database failed: %s\n",
            	PQerrorMessage(conn));
            
        	PQfinish(conn);
        	exit(1);
    	}

	snprintf(&db_statement[0],MAX_DB_STATEMENT_BUFFER_LENGTH-1,"INSERT INTO viajes (categoria,ciudad,mes,ruta,pendiente) VALUES ('%s', '%s','%s','%s','%s')", cat, ci,m,r,p);

	PGresult *res = PQexec(conn,&db_statement[0]);
	if (PQresultStatus(res) != PGRES_COMMAND_OK) {
		do_exit(conn,res);
	}
	printf("Registro realizado con exito\n");
	
	PQclear(res);
}
