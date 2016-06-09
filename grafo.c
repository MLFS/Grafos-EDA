#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <assert.h>
#include "grafo.h"




typedef struct _viz Viz;
struct _viz {
	int noj;
	float peso;
	Viz*  prox;
};

struct _grafo {
	int nv;           /* numero de nos ou vertices */
	int na;           /* numero de arestas */
	char orientado;   /* 0 = nao orientado */
	Viz** viz;         /* viz[i] aponta para a lista de arestas vizinhas do no i */
};


/* aux para fila e pilha */
typedef struct _sq SQ;
struct _sq {
	int info;
	SQ* prox;
};


static SQ* push(SQ* stack, int info){
	SQ* novo = (SQ*)malloc(sizeof(SQ));
	assert(novo);
	novo->info = info;
	novo->prox = stack;
	return novo;
}

static SQ* queue(SQ* queue, int info){
	SQ* novo = (SQ*)malloc(sizeof(SQ));
	SQ* aux = queue;
	assert(novo);
	novo->info = info;
	novo->prox = NULL;
	if (!queue){
		return novo;
	}
	while (aux->prox){
		aux = aux->prox;
	}
	aux->prox = novo;
	return queue;
}

static SQ* pop(SQ* stack,int* popped_info){
	SQ* libera;
	if (!stack){
		*popped_info = -1;
		return NULL;
	}
	*popped_info = stack->info;
	libera = stack;
	stack = stack->prox;
	free(libera);
	return stack;
}



static Viz* criaViz(Viz* head, int noj, float peso) {
	Viz* no = (Viz*) malloc(sizeof(Viz));
	assert(no);
	no->noj = noj;
	no->peso = peso;
	no->prox = head;
	return no;
}


/* implemente */

Grafo* grafoCria(int nv, int na, int orientado) {

	int i;
	Grafo* g = (Grafo *) malloc(sizeof(Grafo));
	g->orientado = orientado;
	g->nv = nv;
	g->na = na;
	g->viz = (Viz **) malloc(sizeof(Viz *) * nv);
	for (i = 0; i < nv; i++)
		g->viz[i] = NULL;
	return g;
}

Grafo* grafoLe( char* filename ) {
	FILE *arq = fopen(filename,"rt");
	int nv, na, orientacao, no1, no2, i = 0;
	float peso;
	Grafo* novo;
	
	fscanf(arq, "%d %d %d", &nv, &na, &orientacao);
	novo = grafoCria(nv, na, orientacao);
	assert(novo);
	while (fscanf(arq, "%d %d %f", &no1, &no2, &peso) == 3) {
		novo->viz[no1] = criaViz(novo->viz[no1], no2, peso);
		if (!orientacao)
			novo->viz[no2] = criaViz(novo->viz[no2], no1, peso);
	}
	return novo;
}

Grafo*   grafoLibera(Grafo* grafo) {
	if (grafo) {
		int i = 0;
		Viz* no,*aux;
		for (i = 0; i < grafo->nv; i++){
			no = grafo->viz[i];
			while (no){
				aux = no->prox;
				free(no);
				no = aux;
			}
		}
		free(grafo->viz);
		free(grafo);
	}
	return NULL;
}

void grafoMostra (char* title, Grafo * grafo) {
	int i;
	if (title)
		printf("%s", title);
	if (grafo)
	{
		printf("NV: %d, NA: %d, %s\n", grafo->nv, grafo->na, (grafo->orientado!=0? "orientado": "nao orientado"));
		for (i = 0; i < grafo->nv; i++){
			Viz* viz = grafo->viz[i];
			printf("[%d]->", i);
			while (viz)
			{
				printf("{%d, %g}->", viz->noj, viz->peso);
				viz = viz->prox;
			}
			printf("NULL\n");
		}
	}
}

void grafoPercorreProfundidade(Grafo * grafo, int no_inicial){
    
    /*
    int w;
    printf("%3d", v);
    visited[v] = 1;
    for (w = 0;w < grafo->nv; w++)
        if (graph[v][w] && !visited[w])
            grafoPercorreProfundidade(w);
        
    */
    
    int i, visited[grafo->nv], j=0, no=no_inicial;
    Viz *temp;
    SQ *pilha = (SQ*) malloc(no_inicial*sizeof(SQ))
    
    if ( no_inicial => grafo->nv){
        printf("Erro: vertice maior que o numero de vertices total!")
        return;
    }
    
    for ( i=0; i<grafo->nv; i++)
        visited[i]=0;
    
    
    while (j==0){
    
        printf("%d", no);
        visited[no]=1;
        push(pilha,no)
        temp=grafo->Viz[no];
        
        
        if (grafo->Viz[no]->noj!=NULL){
            if(visited[grafo->Viz[no]->noj]==0)
                no = grafo->Viz[no]->noj;
                
        
            else
                while (temp!=NULL || visited[temp->noj]==1)
                    temp=temp->prox;
            
            
            if(temp!=NULL)
                no=temp->noj;
                
        }
        
        if(grafo->Viz[no]->noj==NULL || temp==NULL){
            
            
            while(visited[temp->noj==1])
                
        }
        
        
        j=1;
        for (i=0; i<grafo->nv; i++)
            if (visited[i]==0)
                j=0;
        
        if (j=0)
            printf(" -> ")
    
    }
    
    
    
    

}

void   grafoPercorreLargura(Grafo * grafo, int no_inicial){
}

void grafoMostraDijkstra(Grafo* grafo, int source) {

}

void   grafoMostraKruskal(Grafo* grafo) {

}