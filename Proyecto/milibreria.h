#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <curl/curl.h>
#include <string.h>


#define CAT 10
#define CI 20
#define PE 3
#define MES 10
#define RU 100
#define URL 1000
#define MAX_DB_STATEMENT_BUFFER_LENGTH 5000
#define BUF 100

char buf[BUF];
char db_statement[MAX_DB_STATEMENT_BUFFER_LENGTH];
char categoria[CAT];
char ciudad[CI];
char pendiente[PE];
char mes[MES];
char ruta[RU];
char url[URL];
int opcion;
int row, num_rows;


void crear_registro();
int downloader(char *url,char *ruta);
void crear_conexion(char *categoria,char *ciudad,char *mes,char *ruta,char *pendiente);
void consultar_registro();
void visualizar_imagen();
void check();
