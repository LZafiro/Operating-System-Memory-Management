#include "TMMU.h"

Tlista tabela[TAM];

void map_virtual_inicia(){
    for(int i=0;i<TAM;i++){
        Tlista_inicia(&(tabela[i]));
    }
}

tipo_identificador hash(tipo_identificador key){
    return key%TAM;
}

void map_virtual_insere(tipo_identificador virtual_addr){
    tipo_identificador pagina = virtual_addr/PAGESIZE;
    uint16_t offset_moldura = virtual_addr%PAGESIZE;
    map_virtual_t* elemento_hash = criacao_no_mapa(0, 0, 0, 0, offset_moldura);
    int pos = hash(pagina);
    Tlista_insere(&(tabela[pos]), tabela[pos].ultimo, pagina, elemento_hash);
}

map_virtual_t *busca_map_virtual(tipo_identificador virtual_addr){
    tipo_identificador pagina = virtual_addr/PAGESIZE;
    int pos = hash(pagina);
    Tapontador anterior = Tlista_localiza(&(tabela[pos]), pagina);
    if(anterior->prox!=NULL){
        return anterior->prox->info;
    }
    else{
        return NULL;
    }
}

void mostra_map_virtual(map_virtual_t *elemento){
    printf("Página: %llu\n", (long long unsigned int)elemento->identificador);
    printf("Flag cache: %d - Flag referenciada: %d - Flag modificada: %d - Flag proteção: %d - Offset moldura: %d\n", 
        (int)elemento->flag_cache,
        (int)elemento->flag_referenciada,
        (int)elemento->flag_modificada,
        (int)elemento->flag_protecao,
        (int)elemento->offset_moldura
    );
}