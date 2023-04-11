#include <stdio.h>
#include <stdlib.h>
#include "fazenda.h"
#include "animal.h"

struct animal{
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; //em KG
	int status; // 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca 
	struct animal *prox;
};

Animal *criaListaEncadeadaSimplesAnimais(){
	return NULL;
}

Animal *cadastrarAnimal(Animal *rebanho){
	Animal *new = (Animal *) malloc(sizeof(Animal)),*aux = rebanho;

	new->id_animal = rand() % 100000;
	printf("ID FAZENDA: "); scanf("%i", &new->id_fazenda);
	setbuf(stdin,NULL);
	printf("SEXO: "); scanf("%c", &new->sexo);
	setbuf(stdin,NULL);
	printf("PESO: "); scanf("%f", &new->peso);
	setbuf(stdin,NULL);
	printf("STATUS: "); scanf("%i", &new->status);
	setbuf(stdin,NULL);

	if(aux == NULL){
		new->prox = NULL;
		return new;
	}	

	new->prox = aux;

	return new;
}

Animal *permutasAnimais(Animal *RebanhoOrigem, Animal *ReabanhoDestino, int id_animal){
	int status, id_fazenda;
	Animal *aux = RebanhoOrigem, *aux2 = ReabanhoDestino;

	printf("Qual o tipo de permuta:\n1 - Venda\n2 - Troca\n- "); scanf("%d", &status);

	if(listaVaziaAnimal(RebanhoOrigem) || listaVaziaAnimal(ReabanhoDestino)){
		printf("\nUm dos reabanhos vazios!\nCadastre pelo menos um animal para permutar!\n");
		return RebanhoOrigem;
	}

	if(!buscarAnimal(RebanhoOrigem, id_animal)){
		printf("\nAnimal nao cadastrado!\n");
		return RebanhoOrigem;
	}

	if(aux->id_animal == id_animal){

		while(aux2->prox != NULL){
			aux2 = aux2->prox;
		}
		
		aux2->prox = aux;
		RebanhoOrigem = RebanhoOrigem->prox;
		aux->prox = NULL;

		aux->id_fazenda = aux2->id_fazenda;
		aux->status = status+1;
		return RebanhoOrigem;
	}

	while(aux->prox != NULL && aux->prox->id_animal != id_animal){
		aux = aux->prox;
	}

	if(aux->prox == NULL){
		printf("\nAnimal de origem nao encontrado!\n");
		return RebanhoOrigem;
	}

	while(aux2->prox != NULL){
		aux2 = aux2->prox;
	}

	aux2->prox = aux->prox;
	aux->prox = aux->prox->prox;
	aux2->prox->prox = NULL;
	aux2->prox->id_fazenda = aux2->id_fazenda;
	aux2->status = status+1;
	
	return RebanhoOrigem;
}

Animal *removerAnimal(Animal *rebanho, int id_animal){ // lista encadeada simples
	Animal *aux = rebanho, *aux2;

	if(listaVaziaAnimal(rebanho)){
		printf("\nLista vazia\n");
		return rebanho;
	}

	if(!buscarAnimal(rebanho, id_animal)){
		printf("\nAnimal nao cadastrado!\n");
		return rebanho;
	}

	if(aux->id_animal == id_animal){
		rebanho = aux->prox;
		free(aux);
		return rebanho;
	}

	while(aux->prox->id_animal != id_animal){
		aux = aux->prox;
	}

	aux2 = aux->prox;
	aux->prox = aux2->prox;
	free(aux2);

	return rebanho;
}

int listaVaziaAnimal(Animal *animais){
	return animais == NULL ? 1 : 0;
}

void mostrarAnimais(Animal *animais){
	Animal *aux = animais;

	if(listaVaziaAnimal(aux)){
		printf("\nNao ha animais nesta fazenda!\n");
		return;
	}

	printf("\n----------------ANIMAIS------------------");
	while(aux != NULL){
		printf("\nID ANIMAL: %d\n", aux->id_animal); 
		printf("ID FAZENDA: %d\n", aux->id_fazenda); 
		printf("SEXO: %c\n", aux->sexo); 
		printf("PESO: %.2f\n", aux->peso); 
		printf("STATUS: %d\n", aux->status);

		aux = aux->prox; 
	}
	printf("-------------------------------------------\n");
}

int buscarAnimal(Animal *rebanho, int id){
	Animal *aux = rebanho;

	if(listaVaziaAnimal(rebanho)){
		return 0;
	}

	while(aux != NULL && aux->id_animal != id){
		aux = aux->prox;
	}

	return aux == NULL ? 0 : 1;
}

void liberarMemoriaAnimal(Animal *animais){
	Animal *aux = animais;

	while(aux != NULL){
		aux = aux->prox;
		free(animais);
		animais = aux;
	}

	free(animais);
}

int countAnimais(Animal *animais, char sexo){
	int count = 0;

	while(animais != NULL){

		if(animais->sexo == sexo){
			count++;
		}

		animais = animais->prox;
	}

	return count;
}

float countArroba(Animal *animais){
	float soma = 0;

	while(animais != NULL){

		soma += animais->peso;

		animais = animais->prox;
	}

	return soma/15;
}

void printStatus(Animal *animais){
	Animal *aux = animais;
	for(int i = 1; i <= 3; i++){
		aux = animais;
		printf("\n------------Status %d--------------\n", i);
		while(aux != NULL){
			if(aux->status == i){
				printf("\nID ANIMAL: %d\n", aux->id_animal); 
				printf("ID FAZENDA: %d\n", aux->id_fazenda); 
				printf("SEXO: %c\n", aux->sexo); 
				printf("PESO: %.2f\n", aux->peso); 
				printf("STATUS: %d\n", aux->status);
			}

			aux = aux->prox;
		}
	}
}



