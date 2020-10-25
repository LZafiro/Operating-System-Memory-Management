/* Luiz Felipe Raveduti Zafiro       - RA: 120513 */
/* Leon Tenório da Silva             - RA: 120488 */
/* Alexandre Camargo Andreoli        - RA: 119943 */

#include "Tlista.h"

#define TAM 65536
#define PAGESIZE 4096

Tlista tabela[TAM];

void map_virtual_inicia();

tipo_identificador hash(tipo_identificador key);

void map_virtual_insere(tipo_identificador virtual_addr);

map_virtual_t *busca_map_virtual(tipo_identificador virtual_addr);

void mostra_map_virtual(map_virtual_t *elemento);