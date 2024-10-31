#include <stdio.h>
#include <stdlib.h>
#include <string.h>    
#include "listas.h"
//#include "listas.c"

int main(){
    int escolha = 0;
    Listas *l;
    printf("Qual o tamanho da lista? ");
    int MAX;
    scanf("%d", &MAX);
    l = criar(MAX);
    while(escolha < 10){ 
        printf("\n---------------------------------------------------");
        printf("\nEscolha 1 para inserir mais um aluno");
        printf("\nEscolha 2 para ver a lista");
        printf("\nEscolha 3 para remover aluno");
        printf("\nEscolha 4 para ver aluno especifico");
        printf("\nEscolha 5 para saber se tal matricula esta na lista");
        printf("\nEscolha 6 para ver a lista reversa");
        printf("\nEscolha 7 para ver quantas matriculas iguais ha na lista");

        printf("\n=>");
        int escolha;
        scanf(" %d", &escolha);

         Aluno a;
        if(escolha == 1){
            criaAluno(&a);
            printf("\n\nAdicionar onde ?");
            printf("\n1- Inicio\n2- Posicao determinada\n3- Fim\n=>");
            int op;
            scanf("%d", &op);
            if(op ==1 ){
                int var = inserirInicio(l, a, MAX);
                if(var == 1) printf("-->A lista ja esta cheia<--");
                if(var == 2) printf("-->A lista nao existe<--");
            } else if(op == 2){
                int pos;
                printf("Qual a posicao a ser inserida ?\n=>? ");
                scanf("%d", &pos);
                int var = inserirPosicao(l, a, pos, MAX);
                if(var == 1) printf("-->A lista ja esta cheia<--");
                if(var == 2) printf("-->A lista nao existe<--");
                if(var ==-1) printf("-->Posicao invalida<--");

            } else if(op == 3) {
                int var = inserirFim(l, a, MAX);
                if(var == 1) printf("-->A lista ja esta cheia<--");
                if(var == 2) printf("-->A lista nao existe<--");
            }
        } else if( escolha == 2){
            int var = mostrar(l);
            if(var == 1) printf("-->A lista esta vazia<--");
        } else if( escolha == 3){
            printf("\n\nRemover onde ?");
            printf("\n1- Inicio\n2- Posicao determinada\n3- Fim\n4- Por matricula\n=>");
            int op;
            scanf("%d", &op);
            if(op == 1 ){
                int var = removerInicio(l);
                if(var == 1) printf("-->A lsita ja esta vazia<--");
                if(var == 2) printf("-->A lista nao existe<--");
            } else if(op == 2){
                int pos;
                printf("Qual a posicao a ser removida ?\n=>? ");
                scanf("%d", &pos);
                int var = removerPosicao(l, pos, MAX);
                if(var == 1) printf("-->A lista ja esta vazia<--");
                if(var == 2) printf("-->A lista nao existe<--");
                if(var ==-1) printf("-->Posicao invalida<--");

            } else if(op == 3) {
                int var = removerFim(l);
                if(var == 1) printf("-->A lista ja esta vazia<--");
                if(var == 2) printf("-->A lista nao existe<--");
            } else if(op == 4) {
                printf("Qual a matricula a ser excluida ? ");                int item;
                scanf("%d", &item);
                int var = removerItem(l, item, MAX);
                if(var == 1) printf("-->A lista ja esta vazia<--");
                if(var == 2) printf("-->A lista nao existe<--");
            }
        } else if (escolha == 4){
            printf("\nQual a posicao buscada? ");
            int pos;
            scanf("%d", &pos);
            printf("\nDados do aluno buscado:");
            int var = buscarPosicao(l,pos, MAX);
            if(var == 1) printf("-->A lista esta vazia<--");
            if(var == 2) printf("-->A lista nao existe<--");
            if(var ==-1) printf("-->Posição invalida<--");

        } else if(escolha == 5){
            printf("\nQual a matricula buscada? ");
            int item;
            scanf("%d", &item);
            int var = contemItem(l, item);
            if(var == 3) printf("-->A lista esta vazia<--");
            if(var == 2) printf("-->A lista nao existe<--");
            if(var == 0){
                printf("\nSim, ha algum aluno com essa matricula na lista");
            } else if(var == 1) printf("\nNao, nao ha aluno algum com essa matricula na lista");

        } else if( escolha == 6){
            int var = reversa(l);
            if(var == 1) printf("-->A lista esta vazia<--");
        } else if( escolha == 7){
            printf("\nQual a matricula buscada? ");
            int item;
            scanf("%d", &item);
            int var = contaItem(l, item);
            if(var == -1) printf("-->A lista ja esta vazia<--");
            if(var == -2) printf("-->A lista nao existe<--");
            if(var != -1 && var != -2) printf("Ha %d matriculas iguais", var);


        } else if(escolha == 10){
            //free(l->valores);
            return 0;
        }
    }       
        

        //inserirInicio(l, a);
        

        //char s = getchar();
        //char s2 = getchar();
        
    
    return 0;
    
}
