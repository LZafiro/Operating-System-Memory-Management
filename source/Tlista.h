#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>


typedef uint64_t tipo_identificador;

struct map_virtual_t{
    uint8_t flag_cache:1;
    uint8_t flag_referenciada:1;
    uint8_t flag_modificada:1;
    uint8_t flag_protecao:3;
    uint8_t flag_padding:2; // inutilizado,apenas para preenchimento
    uint16_t offset_moldura:12;
    uint16_t offset_padding:4; // inutilizado, apenas para preenchimento
	tipo_identificador identificador;
};

typedef struct map_virtual_t map_virtual_t;

typedef struct Scelula *Tapontador;

typedef struct Scelula{
	map_virtual_t *info;
	Tapontador prox;
}Tcelula;

typedef struct{
	unsigned int tamanho;
	Tapontador primeiro, ultimo;
}Tlista;

map_virtual_t* criacao_no_mapa(
	int flag_cache,
	int flag_referenciada,
	int flag_modificada,
	int flag_protecao,
	int offset_moldura
);

void Tlista_inicia(Tlista *lista);

void Tlista_insere(Tlista *lista, Tapontador anterior, tipo_identificador id, map_virtual_t *x);

Tapontador Tlista_localiza(Tlista *lista, tipo_identificador id);