#include "fazenda.h"
typedef struct animal Animal;

Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastrarAnimal(Animal *rebanho);
Animal *permutasAnimais(Animal *RebanhoOrigem, Animal *ReabanhoDestino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
Animal *removerAnimal(Animal *rebanho, int id_animal);
int listaVaziaAnimal(Animal *animais);
void mostrarAnimais(Animal *animais);
int buscarAnimal(Animal *rebanho, int id);
void liberarMemoriaAnimal(Animal *animais);
int countAnimais(Animal *animais, char sexo);
float countArroba(Animal *animais);
void printStatus(Animal *animais);

/*
Desenvolva funcoes que:

- Funcao para liberar a memoria
*/