#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "criador.h"
#include "fazenda.h"

int main(){
    Criador *lista, *criador, *criador2;
    Fazenda *fazenda;
    int option, id, value, destiny;

    lista = criarListaDuplaCriadores();

    srand(time(NULL));

    while(1){
        printf("\n1 - Cadastrar criador\n2 - Remover criador\n3 - Mostrar criadores\n4 - Cadastrar fazenda\n5 - Mostrar Fazendas");
        printf("\n6 - Remover fazenda\n7 - Alterar fazenda\n8 - Cadastrar animal\n9 - Mostrar rebanho\n10 - Remover animal\n11 - Permutar animal");
        printf("\n12 - Numero de animais por sexo\n13 - Total de arrobas de uma fazenda\n14 - Valor Total da fazenda\n15 - Listar animais por status");
        printf("\n16 - Sair");

        printf("\nInsira uma opcao: "); scanf("%d", &option);

        switch(option){
            case 1:
                lista = cadastrarCriador(lista);
                break;

            case 2:
                printf("\nInsira o id do criador: "); scanf("%d", &id);
                lista = removerCriador(lista, id);
                break;

            case 3:
                mostrarCriadores(lista);
                break;

            case 4:
                printf("\nInsira seu ID de criador: "); scanf("%d", &id);
                cadastrarFazendas(lista, id);
                break;

            case 5:
                printf("\nInsira seu ID de criador: "); scanf("%d", &id);
                criador = getCriador(lista, id);
                if(criador){
                    mostrarTodasFazendas(criador);
                }else{
                    printf("\nCriador inexistente!\n");
                }
                
                break;

            case 6:
                printf("Insira seu ID de criador: "); scanf("%d", &id);
                criador = getCriador(lista, id);
                if(criador){
                    removerFazendas(criador);
                    
                }else{
                    printf("\nCriador inexistente!\n");
                }
                
                break;
            
            case 7:
                printf("Insira seu ID de criador: "); scanf("%d", &id);
                criador = getCriador(lista, id);
                if(criador){
                    alterarFazendas(criador);
                }else{
                    printf("\nCriador inexistente!\n");
                }

                break;
            
            case 8:
                printf("\nInsira o ID do criador: "); scanf("%d", &id);
                criador = getCriador(lista, id);

                if(criador){
                    cadastrarCriadorFazendaRebanho(criador);
                    
                }else{
                    printf("\nCriador inexistente!\n");
                }
                
                break;
                
            case 9:
                printf("\nInsira o ID do criador: "); scanf("%d", &id);
                criador = getCriador(lista, id);

                if(criador){
                    mostrarCriadorFazendaAnimais(criador);
                }else{
                    printf("\nCriador inexistente!\n");
                }

                break;
            
            case 10:
                printf("\nInsira o ID do criador: "); scanf("%d", &id);
                criador = getCriador(lista, id);

                if(criador){
                    removerCriadorFazendaAnimal(criador);
                }else{
                    printf("\nCriador inexistente!\n");
                }

                break;
            
            case 11:
                printf("\nInsira o ID do criador de origem: "); scanf("%d", &id);
                printf("\nInsira o ID do criador de destino: "); scanf("%d", &destiny);
                criador = getCriador(lista, id);
                criador2 = getCriador(lista, destiny);

                if(criador && criador2){
                    permutarCriadorFazendaAnimal(criador, criador2);
                }else{
                    printf("\nCriador inexistente!\n");
                }
                
                break;

            case 12:
                printf("\nInsira o ID do criador: "); scanf("%d", &id);
                criador = getCriador(lista, id);

                if(criador){
                    quantSexoCriadorAnimais(criador);
                }else{
                    printf("\nCriador inexistente!\n");
                }

                break;

            case 13:
                printf("\nInsira o ID do criador: "); scanf("%d", &id);
                criador = getCriador(lista, id);

                if(criador){
                    printArrobaTotal(criador);
                }else{
                    printf("\nCriador inexistente!\n");
                }

                break;

            case 14:
                printf("\nInsira o ID do criador: "); scanf("%d", &id);
                criador = getCriador(lista, id);

                if(criador){
                    printValorTotal(criador);
                }else{
                    printf("\nCriador inexistente!\n");
                }

                break;

            case 15:
                printf("\nInsira o ID do criador: "); scanf("%d", &id);
                criador = getCriador(lista, id);

                if(criador){
                    printListaStatusAnimais(criador);
                }else{
                    printf("\nCriador inexistente!\n");
                }

                break;

            case 16:
                printf("\nLiberando memoria...\n");
                liberarMemoriaFull(lista);
                return 0;

            default:
                printf("\nInsira uma opcao valida!\n");
        }
    
    }

    return 0;
}

