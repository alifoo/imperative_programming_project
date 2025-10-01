// aqui eu fiz um numero/categoria por que não ta totalmente sincronizado com o menu ainda
static Categoria ler_categoria_menu(void) {
    char buf[32]; int op = 0;
    do {
        printf("\nEscolha a categoria:\n");
        printf("  1) Cereais e derivados\n");
        printf("  2) Frutas\n");
        printf("  3) Verduras e hortaliças\n");
        printf("  4) Carnes e derivados\n");
        printf("  5) Leite e derivados\n");
        printf("  6) Leguminosas e derivados\n");
        printf("  7) Outros\n> ");
        if (!fgets(buf, sizeof(buf), stdin)) return OUTROS;
        op = atoi(buf);
    } while (op < 1 || op > 7);

    switch (op) {
        case 1: return CEREAIS_DERIVADOS;
        case 2: return FRUTAS;
        case 3: return VERDURAS_HORTALICAS;
        case 4: return CARNES;
        case 5: return LATICINIOS;
        case 6: return LEGUMINOSAS;
        default: return OUTROS;
    }
}

// função e: listar top N por energia
void listar_topN_energia(const Alimento vet[], int tamanho) {
    char buf[64]; int N;
    Categoria cat = ler_categoria_menu();
    printf("Digite o valor de N (0 = todos): ");
    if (!fgets(buf, sizeof(buf), stdin)) return;
    N = atoi(buf);

    int count = 0;
    for (int i = 0; i < tamanho; i++) if (vet[i].categoria == cat) count++;
    if (count == 0) { printf("Nenhum alimento nessa categoria.\n"); return; }
    if (N <= 0 || N > count) N = count;

    Alimento *tmp = (Alimento*)malloc(sizeof(Alimento) * (size_t)count);
    if (!tmp) { perror("malloc"); return; }
    int j = 0;
    for (int i = 0; i < tamanho; i++) if (vet[i].categoria == cat) tmp[j++] = vet[i];

    for (int i = 0; i < count - 1; i++)
        for (int k = i + 1; k < count; k++)
            if (tmp[k].energia > tmp[i].energia) { Alimento t = tmp[i]; tmp[i] = tmp[k]; tmp[k] = t; }

    printf("\nTop %d por ENERGIA na categoria %s:\n", N, categoria_nome(cat));
    for (int i = 0; i < N; i++)
        printf("%d | %s | Energia: %d\n", tmp[i].numero, tmp[i].descricao, tmp[i].energia);

    free(tmp);
}

// função f:listar top N por proteína
void listar_topN_proteina(const Alimento vet[], int tamanho) {
    char buf[64]; int N;
    Categoria cat = ler_categoria_menu();
    printf("Digite o valor de N (0 = todos): ");
    if (!fgets(buf, sizeof(buf), stdin)) return;
    N = atoi(buf);

    int count = 0;
    for (int i = 0; i < tamanho; i++) if (vet[i].categoria == cat) count++;
    if (count == 0) { printf("Nenhum alimento nessa categoria.\n"); return; }
    if (N <= 0 || N > count) N = count;

    Alimento *tmp = (Alimento*)malloc(sizeof(Alimento) * (size_t)count);
    if (!tmp) { perror("malloc"); return; }
    int j = 0;
    for (int i = 0; i < tamanho; i++) if (vet[i].categoria == cat) tmp[j++] = vet[i];

    for (int i = 0; i < count - 1; i++)
        for (int k = i + 1; k < count; k++)
            if (tmp[k].proteina > tmp[i].proteina) { Alimento t = tmp[i]; tmp[i] = tmp[k]; tmp[k] = t; }

    printf("\nTop %d por PROTEÍNA na categoria %s:\n", N, categoria_nome(cat));
    for (int i = 0; i < N; i++)
        printf("%d | %s | Proteína: %.1f\n", tmp[i].numero, tmp[i].descricao, tmp[i].proteina);

    free(tmp);
}

// função g: listar top N por carboidrato
void listar_topN_carboidrato(const Alimento vet[], int tamanho) {
    char buf[64]; int N;
    Categoria cat = ler_categoria_menu();
    printf("Digite o valor de N (0 = todos): ");
    if (!fgets(buf, sizeof(buf), stdin)) return;
    N = atoi(buf);

    int count = 0;
    for (int i = 0; i < tamanho; i++) if (vet[i].categoria == cat) count++;
    if (count == 0) { printf("Nenhum alimento nessa categoria.\n"); return; }
    if (N <= 0 || N > count) N = count;

    Alimento *tmp = (Alimento*)malloc(sizeof(Alimento) * (size_t)count);
    if (!tmp) { perror("malloc"); return; }
    int j = 0;
    for (int i = 0; i < tamanho; i++) if (vet[i].categoria == cat) tmp[j++] = vet[i];

    for (int i = 0; i < count - 1; i++)
        for (int k = i + 1; k < count; k++)
            if (tmp[k].carboidrato > tmp[i].carboidrato) { Alimento t = tmp[i]; tmp[i] = tmp[k]; tmp[k] = t; }

    printf("\nTop %d por CARBOIDRATO na categoria %s:\n", N, categoria_nome(cat));
    for (int i = 0; i < N; i++)
        printf("%d | %s | Carboidrato: %.1f\n", tmp[i].numero, tmp[i].descricao, tmp[i].carboidrato);

    free(tmp);
}

/* TESTE DE FUNÇÕES: (APENAS PRA TESTE)
int main(void) {
    FILE *arquivo = fopen("alimentos.csv", "r");
    if (!arquivo) { perror("Erro ao abrir alimentos.csv"); return 1; }


    char line[MAX_LINE_SIZE];
    Alimento alimentos[MAX_LINES];
    int line_count = 0;


    if (!fgets(line, sizeof(line), arquivo)) { fclose(arquivo); return 1; } // pula cabeçalho
    while (fgets(line, sizeof(line), arquivo) && line_count < MAX_LINES)
        alimentos[line_count++] = parse_csv_line(line);
    fclose(arquivo);


    // ADICIONAR "//" NAS LISTAS QUE NÃO QUISER TESTAR
    listar_topN_energia(alimentos, line_count);
    listar_topN_proteina(alimentos, line_count);
    listar_topN_carboidrato(alimentos, line_count);
    return 0;
}
*/