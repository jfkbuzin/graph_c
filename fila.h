
struct TipoFila{
       int info;
       TipoFila* prox;
       };

TipoFila* cria_fila(void);
TipoFila* insere (TipoFila *l, int dado); //ok
int vazia (TipoFila* l);
int remove(TipoFila **l);
int tamanho(TipoFila* l);
void imprime(TipoFila* l);
TipoFila* destroi(TipoFila* l);
TipoFila* remover(TipoFila* l, int remov);
int primeiro(TipoFila* l);

