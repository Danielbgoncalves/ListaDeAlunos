//#ifndef LISTAS_C_INCLUDED
//#define LISTAS_C_INCLUDED

#include "listas.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listas {
    int total;
    Aluno valores[]; 
}Listas;


void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

Aluno *criaAluno(Aluno *a){
    
    printf("\nQual eh o nome do aluno ? ");
    limparBuffer();
    fgets(a->nome, 30, stdin);
    int len = strlen(a->nome);
    if (len > 0 && a->nome[len-1] == '\n') 
        a->nome[len-1] = '\0';

    printf("A matricula de %s: ", a->nome);
    int matri;
    scanf("%d", &matri);
    limparBuffer();
    a->mat = matri;

    printf("A nota de %s: ", a->nome);
    int n1;
    scanf("%d", &n1);
    a->n1 = n1;

    return a;
}

Listas *criar(int MAX){
    Listas *l;
    l = (Listas*)malloc(sizeof(Listas));
    if( l == NULL) printf("\nERRO\n");
    if(l != NULL) l -> total = 0;
    l->valores[MAX];
    return l;
}

void limpar(Listas *l){
    if(l != NULL) l->total = 0;
}

int inserirInicio(Listas *l, Aluno it, int MAX){
    if(l == NULL) return 2;
    if(listaCheia(l, MAX) == 0)return 1;
    for(int i = l->total; i > 0; i--){
        l->valores[i] = l->valores[i-1];
    }
    l->valores[0] = it;
    l->total ++;
    return 0;
}

int inserirFim(Listas *l, Aluno it, int MAX){
    if(l == NULL) return 2;
    if(listaCheia(l, MAX) == 0)return 1;

    l->valores[l->total] =it;
    l->total ++;
    return 0;
}

int inserirPosicao(Listas *l, Aluno it, int pos, int MAX){
    if(l == NULL) return 2;
    if(listaCheia(l, MAX) == 0) return 1;
    if(pos<0 || pos> MAX-1) return -1; // retorna erro pois esta fora do escopo
    if(pos>= l->total){
        inserirFim(l, it, MAX);
    } else {
        l->valores[pos] = it;
        for(int i = l->total; i > pos; i--){
            l->valores[i] = l->valores[i-1]; 
        }
        l->total ++;
    }
   
    return 0;
}

int buscarItemChave(Listas *l, int chave, Aluno *retorno){
    if(l == NULL) return 2;
    if(listaVazia(l) == 0)return 1;
    for(int i = 0; i < l->total; i++){
        if(l->valores[i].mat == chave){
            *retorno = l->valores[i];
            return 0;
        }
    }
    return -1;
}

int listaVazia(Listas *l){
    if(l == NULL) return 2;
    if(l->total == 0) return 0;
    else return 1;
}

int removerInicio(Listas *l){
    if(l == NULL) return 2;
    if(listaVazia(l) == 0)return 1;
    for(int i = 0; i < l->total; i++){
        l->valores[i] = l->valores[i+1];
    }    
    l->total--;
    return 0;
}

int removerFim(Listas *l){
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    l->total--;
    return 0;
}

int listaCheia(Listas *l, int MAX){
    if(l == NULL) return 2;
    if(l->total == MAX) return 0;
    else return 1;
}

int mostrar(Listas *l){
    if(listaVazia(l) == 0) return 1;
    if(l != NULL){
        printf("[");
        for(int i = 0; i < l->total; i++){
            printf(" {%d, ", l->valores[i].mat);
            printf("%s, ", l->valores[i].nome);
            printf("%.2f} ", l->valores[i].n1);
        }
        printf("]\n");
    }
    return 0;
}

int removerPosicao(Listas *l, int pos, int MAX){ 
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    if(pos < 0 || pos > MAX-1) return -1;
    for(int i = pos; i < l->total; i++){
        l->valores[i] = l->valores[i+1];
    }
    l->total--;
    return 0;
}

int removerItem(Listas *l, int item, int MAX){
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    for(int i = 0; i < l->total; i++){
        if(l->valores[i].mat == item){
            removerPosicao(l, i+1, MAX);
            //printf("O i passado como argumento eh: %d", i);
        }
    }      
    return 0;        
}

int buscarPosicao(Listas *l, int pos, int MAX){
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 1;
    if(pos < -1 || pos > MAX-1) return -1;
    printf("\nNome.....: %s", l->valores[pos].nome);
    printf("\nMatricula: %d", l->valores[pos].mat);
    printf("\nNota.....: %.2f", l->valores[pos].n1);
    return 0;
}

int contemItem(Listas *l, int item){
    if(l == NULL) return 2;
    if(listaVazia(l) == 0) return 3;
    for(int i = 0; i < l->total; i ++)
        if(l->valores[i].mat == item)
            return 0;
    
    return 1;
}

int reversa(Listas *l){
    if(listaVazia(l) == 0) return 1;
    if(l != NULL){
        printf("[");
        for(int i = l->total-1; i >= 0; i--){
            printf(" {%d, ", l->valores[i].mat);
            printf("%s, ", l->valores[i].nome);
            printf("%.2f} ", l->valores[i].n1);
        }
        printf("]\n");
    }
    return 0;
}

int contaItem(Listas *l, int item){
    if(l == NULL) return -2;
    if(listaVazia(l) == 0) return -1;
    int cont = 0;
    for(int i = 0; i < l->total; i++)
        if(l->valores[i].mat == item)
            cont++;
    return cont;   

}

//#endif // LISTAS_C_INCLUDED
