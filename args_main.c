#include "sysprg_study_montis.h"


int main(int argc, char const *argv[])
{
	int number, width;
	char name[MAX_WORD];
	int x, y;


	for(int i = 0; i < argc; i++){
		
		if(strcmp(argv[i], "-r")== 0){
			if(sscanf(argv[i+1], "%dx%d", &x, &y))
				printf("grid: %dx%d\n", x, y);
			else
				printf("invalid shit\n");
		}

		else if(sscanf(argv[i], "-d %d", &number))
			printf("num: %d\n", number);

		else if(sscanf(argv[i], "width=%d", &width))
			printf("width: %d\n", width);

		else if(sscanf(argv[i], "name=%s", name))
			printf("name: %s\n", name);
		else
			printf("dio can\n");
		


		
	}


	return 0;
}