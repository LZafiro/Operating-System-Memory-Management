/* Luiz Felipe Raveduti Zafiro       - RA: 120513 */
/* Leon Tenório da Silva             - RA: 120488 */
/* Alexandre Camargo Andreoli        - RA: 119943 */

#include "TMMU.h"

Tlista tabela[TAM];

tipo_identificador moldura_livre = 0;

void map_virtual_inicia(){
    for(int i=0;i<TAM;i++){
        Tlista_inicia(&(tabela[i]));
    }
}

tipo_identificador hash(tipo_identificador key){
    return key%TAM;
}

void map_virtual_insere(tipo_identificador virtual_addr){
    if(busca_map_virtual(virtual_addr)==NULL){
        tipo_identificador pagina = virtual_addr/PAGESIZE;
        uint16_t offset_moldura = virtual_addr%PAGESIZE;
        map_virtual_t* elemento_hash = criacao_no_mapa(0, 0, 0, 0, offset_moldura, moldura_livre);
        int pos = hash(pagina);
        Tlista_insere(&(tabela[pos]), tabela[pos].ultimo, pagina, elemento_hash);
        printf("Memória virtual %lu inserida na moldura %lu \n", virtual_addr, moldura_livre);
        moldura_livre++;
    }
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
    printf("Página: %lu - Moldura: %lu\n", elemento->endereco_virtual, elemento->moldura);
    printf("Flag cache: %d - Flag referenciada: %d - Flag modificada: %d - Flag proteção: %d - Offset moldura: %d\n", 
        (int)elemento->flag_cache,
        (int)elemento->flag_referenciada,
        (int)elemento->flag_modificada,
        (int)elemento->flag_protecao,
        (int)elemento->offset_moldura
    );
}