#include "Tlista.h"

map_virtual_t* criacao_no_mapa(
	int flag_cache,
	int flag_referenciada,
	int flag_modificada,
	int flag_protecao,
	int offset_moldura
){
    map_virtual_t* apontador = (map_virtual_t*)malloc(sizeof(map_virtual_t));
	apontador->flag_cache = flag_cache;
	apontador->flag_referenciada = flag_referenciada;
	apontador->flag_modificada = flag_modificada;
	apontador->flag_protecao = flag_protecao;
	apontador->offset_moldura = offset_moldura;
    return apontador;
}

void Tlista_inicia(Tlista *lista){
    Tapontador sentinela;
	sentinela=(Tapontador)malloc(sizeof(Tcelula));
	if(sentinela==NULL)
		exit(-1);
	sentinela->prox=NULL;
	lista->primeiro = sentinela;
    lista->ultimo = sentinela;
    lista->tamanho=0;
	sentinela=NULL;
}

void Tlista_insere(Tlista *lista,Tapontador anterior, tipo_identificador id, map_virtual_t *x){
	Tapontador novo;
	novo=(Tapontador)malloc(sizeof(Tcelula));
	if(novo==NULL)
		exit (-1);
	novo->info=x;
    novo->info->identificador = id;
	novo->prox=anterior->prox;
	anterior->prox=novo;
	lista->tamanho++;
	if(anterior==lista->ultimo){
		lista->ultimo = novo;
	}
}

Tapontador Tlista_localiza(Tlista *lista, tipo_identificador id){
    Tapontador aux = lista->primeiro;
	int i=0;
	while(i<lista->tamanho){
		if(aux->prox->info->identificador==id){
			return aux;
		}
		i++;
		aux = aux->prox;
	}
	return aux;
}