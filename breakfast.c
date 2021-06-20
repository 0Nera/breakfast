#include <stdio.h>

int portions = 4;

int eggs = 4; // 4 яйца
int sausages = 4; // 3 сосиски
int tea = 4; // Заварка на 4 порции чая

int bread = 8; // 8 ломтиков хлеба
int oil = 1370; // Масло достаточное для приготовления завтрака
int honey = 200; // Мед для 8 бутербродов

int prepare(){
	//Загрузка данных о порциях
	FILE *fp;
	char save_portions[] = "portions.txt";
	if ((fp = fopen(save_portions, "r")) == NULL){
		printf("Error: can't open file portions.txt\nA standard amount of 4 servings was used.\n");
		getchar();
	}else{
		fscanf(fp,"%d",&portions);
	}
	fclose(fp);
	printf("Portions: %d\n", portions);
	//Определяем расход
	
	//Мед на каждого человека по 2 бутерброда, на каждый бутерброд 25 меда и 15 масла:
	//25 * 8 = 200 единиц меда
	//15 * 8 = 120 единиц масла
	//8 * 1 = 8 тостов
	
	//(сосиски) 4 * 250 + (яйца) 4 * 50 = 1250 единиц масла
	//1250 + 120 = 1370 единиц масла всего
	
	//Есть ли яйца?
	if (portions == eggs){
		printf("There are enough eggs...\n");
	}else{
		printf("Not enough eggs!\n");
		return 0;
	}
	
	//Хватает ли сосисок?
	if (portions == sausages){
		printf("There are enough sausages...\n");
	}else{
		printf("Not enough sausages!\n");
		return 0;
	}
	
	//Остался ли чай?
	if (portions == tea){
		printf("There are enough tea...\n");
	}else{
		printf("Not enough tea!\n");
		return 0;
	}
	
	//Нужен ли хлеб?
	if (portions == bread / 2){
		printf("There are enough bread...\n");
	}else{
		printf("Not enough bread!\n");
		return 0;
	}
	
	//Хватает ли масла?
	printf("Oil: %d, Need: %d\n",oil, 5 * portions * 2 + portions * 250 + portions * 50 );
	
	if (oil >= 15 * portions * 2 + portions * 250 + portions * 50 || oil == 15 * portions * 2 + portions * 250 + portions * 50 ){
		printf("There are enough oil...\n");
	}else{
		printf("Not enough oil!\n");
		return 0;
	}
	
	//Хватает ли меда?
	printf("Honey: %d, Need: %d\n",honey, 25 * portions * 2);
	
	if (oil >= 15 * portions * 2 + portions * 250 + portions * 50 || oil == 15 * portions * 2 + portions * 250 + portions * 50 ){
		printf("There are enough honey...\n");
	}else{
		printf("Not enough honey!\n");
		return 0;
	}
	return 1;
}

void menu(){
	
}

int main(){
	int user_select = 0;
	printf("\n\t\tBreakFast 1.0\n");
	menu:
	printf("Menu:\n\t0 - Start cook\n\t1 - Info\n\t9 - Exit\n");
	scanf_s("%d", &user_select);
	switch(user_select){
		case 0: printf("Preparation of ingredients...\n");
				if (prepare() == 1){
					printf("All is ready!\n");
					goto done;
				}else{
					printf("Preparation failed!\n");
				}
		case 1: printf("\n\t\tInfo\nCreated by Elchinyan Aren in 2021\n\n\tThis program uses all the basic functions of the C language\n"); goto menu;
		case 9: goto end;
		default: goto menu;
	}
	done:
	printf("Done!\n");
	end:
	getchar();
	return 1;
}