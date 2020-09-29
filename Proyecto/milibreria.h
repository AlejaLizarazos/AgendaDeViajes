#include <stdio.h>
#include <stdlib.h>
#include <libpq-fe.h>
#include <curl/curl.h>
#include <string.h>

void crear_registro();
int downloader(char *url,char *ruta);
void crear_conexion(char *categoria,char *ciudad,char *mes,char *ruta,char *pendiente);
void consultar_registro();
void visualizar_imagen();
void check();
