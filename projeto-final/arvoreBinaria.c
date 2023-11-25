#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct noArvore {
    int chave;                
    struct noArvore *esquerda;  
    struct noArvore *direita; 
} noArvore;


noArvore* inserir(noArvore* no, int chave) {
    if (no == NULL) {
        
        noArvore* novoNo = (noArvore*)malloc(sizeof(noArvore));
        novoNo->chave = chave; 
        novoNo->esquerda = novoNo->direita = NULL; 
        return novoNo; 
    }

    if (chave < no->chave)
        no->esquerda = inserir(no->esquerda, chave);
    else if (chave > no->chave)
        no->direita = inserir(no->direita, chave);

    return no;
}

noArvore* minValorno(noArvore* no) {

    noArvore* atual = no;

    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual; 
}


noArvore* deleteno(noArvore* root, int chave) {

    if (root == NULL) return root;

    if (chave < root->chave)
        root->esquerda = deleteno(root->esquerda, chave);
    else if (chave > root->chave)
        root->direita = deleteno(root->direita, chave);
    else {
        if (root->esquerda == NULL) {
            noArvore* temp = root->direita; 
            free(root); 
            return temp; 
        } else if (root->direita == NULL) {
            noArvore* temp = root->esquerda; 
            free(root); 
            return temp; 
        }
     
        noArvore* temp = minValorno(root->direita);

        root->chave = temp->chave;
   
        root->direita = deleteno(root->direita, temp->chave);
    }
    return root; 
}

int search(noArvore* root, int chave) {

    if (root == NULL)
        return 0;
  
    if (root->chave == chave)
        return 1;

    if (root->chave < chave)
        return search(root->direita, chave);

    return search(root->esquerda, chave);
}


void percorrerOrdem(noArvore* root) {
    if (root != NULL) {
        percorrerOrdem(root->esquerda); 
        printf("%d ", root->chave); 
        percorrerOrdem(root->direita); 
    }
}


void percorrerPreOrdem(noArvore* root) {
    if (root != NULL) {
        printf("%d ", root->chave);
        percorrerPreOrdem(root->esquerda);  
        percorrerPreOrdem(root->direita); 
    }
}


void percorrerPosOrdem(noArvore* root) {
    if (root != NULL) {
        percorrerPosOrdem(root->esquerda); 
        percorrerPosOrdem(root->direita); 
        printf("%d ", root->chave); 
    }
}


int procurarMin(noArvore* no) {

    while (no->esquerda != NULL)
        no = no->esquerda;
    return no->chave; 
}


int procurarMax(noArvore* no) {
    
    while (no->direita != NULL)
        no = no->direita;
    return no->chave; 
}


void liberarMem(noArvore* no) {
    if (no != NULL) {
        liberarMem(no->esquerda);  
        liberarMem(no->direita); 
        free(no);            
    }
}


int main() {
    noArvore* root = NULL; 

   
    root = inserir(root, 50); 
    inserir(root, 30);        
    inserir(root, 20);        
    inserir(root, 40);       
    inserir(root, 70);        
    inserir(root, 60);        
    inserir(root, 80);        

  
    printf("Percorrendo em ordem: ");
    percorrerOrdem(root); 
    printf("\nPercorrendo em pré-ordem: ");
    percorrerPreOrdem(root); 
    printf("\nPercorrendo em pós-ordem: ");
    percorrerPosOrdem(root); 

   
    printf("\nBuscando o valor 40: %s", search(root, 40) ? "Encontrado" : "Não encontrado");
    sleep(3);
    
    printf("\nRemovendo o valor 20\n");
    root = deleteno(root, 20); 
    sleep(3);
    printf("Buscando o valor 20: %s", search(root, 20) ? "Encontrado\n" : "Não encontrado\n");
    printf("Percorrendo em ordem após a remoção: ");
    percorrerOrdem(root); 
    sleep(3);

   
    printf("\nValor mínimo: %d", procurarMin(root));
    printf("\nValor máximo: %d", procurarMax(root)); 
    sleep(3);
  
    liberarMem(root); 

    return 0; 
}
