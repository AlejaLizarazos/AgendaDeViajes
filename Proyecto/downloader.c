#include "milibreria.h"

int downloader(char *url,char *ruta) {
	CURL *curl;
	FILE *fp;
	int result;

	fp = fopen(ruta,"wb");

	curl = curl_easy_init();

	curl_easy_setopt(curl,CURLOPT_URL,url);
	curl_easy_setopt(curl,CURLOPT_WRITEDATA,fp);
	curl_easy_setopt(curl,CURLOPT_FAILONERROR,1L);	

	
	result = curl_easy_perform(curl);

	if(result == CURLE_OK)
		printf("\nDowload succesfull!\n");
	else
		printf("ERROR: %s\n",curl_easy_strerror(result));
	
	fclose(fp);
	curl_easy_cleanup(curl);
	return 0;
}

