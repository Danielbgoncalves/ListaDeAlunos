//#define MAX 100

typedef struct aluno{
    int mat;
    char nome[30];
    float n1;
}Aluno;

typedef struct listas Listas;
void limparBuffer();
Aluno *criaAluno(Aluno *a);
Listas *criar();
void limpar(Listas *l);
int inserirInicio(Listas *l, Aluno it, int MAX);
int inserirFim(Listas *l, Aluno it, int MAX);
int inserirPosicao(Listas *l, Aluno it, int pos, int MAX);
int buscarItemChave(Listas *l, int Chave, Aluno *retorno);
int listaVazia(Listas *l);
int removerInicio(Listas *l);
int removerFim(Listas *l);
int listaCheia(Listas *l, int MAX);
int mostrar(Listas *l);
int removerPosicao(Listas *l, int pos, int MAX);
int removerItem(Listas *l, int item, int MAX);
int buscarPosicao(Listas *l, int pos, int MAX);
int contemItem(Listas *l, int item);
int reversa(Listas *l);
int contaItem(Listas *l, int item);

//olha o whats  
