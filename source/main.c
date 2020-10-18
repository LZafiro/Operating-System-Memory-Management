#include <stdio.h>
#include <stdlib.h>
#include "Tlista.h"
#include "TMMU.h"

#define QUANTIDADE_CONSULTAS 10
#define N_ENTRADAS 10

int main(){
    int i;
    int temp;

    map_virtual_inicia();

    //leitura dos address para adicionar
    for(i=0;i<N_ENTRADAS;i++){
        //scanf("%d",&temp);  //tem que fazer cast por o C nao eh capaz de fazer leitura por scanf de unit64
        map_virtual_insere((tipo_identificador)rand());
    }
    
    for(i=0;i<QUANTIDADE_CONSULTAS;i++){
        scanf("%d", &temp);
        map_virtual_t* consulta = busca_map_virtual((tipo_identificador)temp);
        if(consulta==NULL){
            printf("Page miss\n");
        }
        else{
            mostra_map_virtual(consulta);
        }
    }

    return 0;
}