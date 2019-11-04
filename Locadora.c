// Esse programa é uma Locadora de Roupas e Fantasias

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct cliente Cliente;
typedef struct vestuario Vestuario;


struct cliente {
    char cpf[12];
    char nome[81];
    char nasc[11];
    char end[121];
    char fone[21];
    char sexo;
    char status;
};


struct vestuario {
    int cod;
    char descricao[51];
    char tam[5];
    float preco;
    char status;
};


char menuPrincipal(void);
char menuCliente(void);
char menuRoupaFantasia(void);
void telaInicio(void);
void telaFim(void);
void sobre(void);
void pause(void);
void limpaBuffer(void);
void telaMenuCliente(void);
void cadastraCliente(void);
void pesquisaCliente(void);
void atualizaCliente(void);
void excluiCliente(void);
void listaClientes(void);
void gravaCliente(Cliente*);
void exibeCliente(Cliente*);

void telaMenuRoupaFantasia(void);
void cadastraRoupaFantasia(void);
void pesquisaRoupaFantasia(void);
void atualizaRoupaFantasia(void);
void excluiRoupaFantasia(void);
void listaRoupaFantasia(void);
void exibeRoupaFantasia(Vestuario*);
void gravaRoupaFantasia(Vestuario*);


int main(void) {
    telaInicio();
    char opcao;
    opcao = menuPrincipal();
    while (opcao != '0') {
        switch (opcao) {
        case '1': telaMenuCliente();
                break;
        case '2': telaMenuRoupaFantasia();
                break;
        case '3': sobre();
                break;
        default:
                printf("\nEscolha uma opção válida!\n");
                pause();
                break;
        }
        limpaBuffer();
        opcao = menuPrincipal();

    }
    telaFim();
    return 0;
}


void telaMenuCliente(void) {
    limpaBuffer();
    char opcao;
    opcao = menuCliente();
    while (opcao != '0') {
        switch (opcao) {
        case '1': cadastraCliente();
                break;
        case '2': pesquisaCliente();
                break;
        case '3': atualizaCliente();
                break;
        case '4': excluiCliente();
                break;
        case '5': listaClientes();
                break;
        default:
                printf("\nEscolha uma opção válida!\n");
                pause();
                break;
        }
        opcao = menuCliente();
    }
}


void telaMenuRoupaFantasia(void) {
    limpaBuffer();
    char opcao;
    opcao = menuRoupaFantasia();
    while (opcao != '0') {
        switch (opcao) {
        case '1': cadastraRoupaFantasia(); 
                break;
        case '2': pesquisaRoupaFantasia();
                break;
        case '3': atualizaRoupaFantasia();
                break;
        case '4': excluiRoupaFantasia();
                break;
        case '5': listaRoupaFantasia();
                break;
        default:
                printf("\nEscolha uma opção válida!\n");
                pause();
                break;
        }
        opcao = menuRoupaFantasia();
    }
}


void telaInicio(void) {
    //system ("cls || clear");
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-          B E M - V I N D O           -\n");
    printf("-                                      -\n");
    printf("-             .--=   =--.              -\n");
    printf("-            / |  \\./  | \\             -\n");
    printf("-           (__|   :   |__)            -\n");
    printf("-              |   :   |               -\n");
    printf("-              |   :   |               -\n");
    printf("-              |___:___|               -\n");
    printf("-                                      -\n");
    printf("-     Que seu dia seja um sucesso!     -\n");
    printf("========================================\n");
    pause();
}


char menuPrincipal(void) {
	system ("cls || clear");
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-     M E N U    P R I N C I P A L     -\n");
    printf("-                                      -\n");
    printf("-          1 - Cliente                 -\n");
    printf("-          2 - Roupa/Fantasia          -\n");
    printf("-          3 - Sobre                   -\n");
    printf("-          0 - Sair                    -\n");
    printf("========================================\n");
    char opcao;
    printf("\nEscolha uma opção: ");
    scanf("%c", &opcao);
    return opcao;
}


void sobre(void) {
    system ("cls || clear");
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-              S O B R E               -\n");
    printf("-                                      -\n");
    printf("-            DESENVOLVEDOR:            -\n");
    printf("-            Elizeu Martins            -\n");
    printf("-                                      -\n");
    printf("-                EMAIL:                -\n");
    printf("-         elizeugm25@gmail.com         -\n");
    printf("-                                      -\n");
    printf("-                GITHUB:               -\n");
    printf("-     https://github.com/elizeugm      -\n");
    printf("-                                      -\n");
    printf("-                CONTATO:              -\n");
    printf("-            (84) 98812-1155           -\n");
    printf("========================================\n");
    printf("   _____ __    __ _____ _____ __   __   \n");
    printf("  |   __|  |  |  |__   |   __|  | |  |  \n");
    printf("  |  |__|  |  |  | /  /|  |__|  | |  |  \n");
    printf("  |   __|  |  |  |/  / |   __|  | |  |  \n");
    printf("  |  |__|  |__|  |  /__|  |__|  |_|  |  \n");
    printf("  |_____|_____|__|_____|_____|_______|\n\n");
    printf("========================================\n");
    pause();
}


void cadastraCliente(void) {
    system ("cls || clear");
    Cliente* dados;
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-  C A D A S T R A R    C L I E N T E  -\n");
    printf("========================================\n");
    dados = (Cliente*) malloc(sizeof(Cliente));
    printf("\nInforme o CPF do cliente: ");
    scanf(" %11[^\n]", dados->cpf);
    printf("Informe o nome do cliente: ");
    scanf(" %80[^\n]", dados->nome);
    printf("Informe a data de nascimento do cliente (dd/mm/aaaa): ");
    scanf(" %10[^\n]", dados->nasc);
    printf("Informe o endereço do cliente: ");
    scanf(" %120[^\n]", dados->end);
    printf("Informe o telefone do cliente: ");
    scanf(" %20[^\n]", dados->fone);
    getchar();
    printf("Informe o sexo do cliente (M/F): ");
    scanf("%c", &dados->sexo);
    dados->status = '1';
    printf("\n");
    printf("========================================\n\n");
    exibeCliente(dados);
    printf("========================================\n");
    gravaCliente(dados);
    printf("\nDados do cliente gravado com sucesso!\n");
    pause();
}


void exibeCliente(Cliente* dados) {
    printf("CPF: %s\n", dados->cpf);
    printf("NOME: %s\n", dados->nome);
    printf("NASCIMENTO: %s\n", dados->nasc);
    printf("ENDEREÇO: %s\n", dados->end);
    printf("TELEFONE: %s\n", dados->fone);
    printf("SEXO: %c\n", dados->sexo);
    printf("STATUS: %c\n", dados->status);
    printf("\n");
}


void gravaCliente(Cliente* dados) {
    FILE* fp;
    fp = fopen("clientes.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(dados, sizeof(Cliente), 1, fp);
    fclose(fp);
}


void telaFim(void) {
    system ("cls || clear");
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-           P R O G R A M A            -\n");
    printf("-          E N C E R R A D O           -\n");
    printf("-                                      -\n");
    printf("-             .--=   =--.              -\n");
    printf("-            / |  \\./  | \\             -\n");
    printf("-           (__|   :   |__)            -\n");
    printf("-              |   :   |               -\n");
    printf("-              |   :   |               -\n");
    printf("-              |___:___|               -\n");
    printf("-                                      -\n");
    printf("-   Obrigado por usar nosso sistema!   -\n");
    printf("========================================\n");
}


char menuCliente(void) {
    system ("cls || clear");
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-       M E N U    C L I E N T E       -\n");
    printf("-                                      -\n");
    printf("-        1 - Cadastrar Cliente         -\n");
    printf("-        2 - Pesquisar Cliente         -\n");
    printf("-        3 - Atualizar Cliente         -\n");
    printf("-        4 - Excluir Cliente           -\n");
    printf("-        5 - Listar Clientes           -\n");
    printf("-        0 - Voltar                    -\n");
    printf("========================================\n");
    char opcao;
    printf("\nEscolha uma opção: ");
    scanf("%c", &opcao);
    return opcao;
}


char menuRoupaFantasia(void) {
    system ("cls || clear");
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-                M E N U               -\n");
    printf("-     R O U P A / F A N T A S I A      -\n");
    printf("-                                      -\n");
    printf("-     1 - Cadastrar Roupa/Fantasia     -\n");
    printf("-     2 - Pesquisar Roupa/Fantasia     -\n");
    printf("-     3 - Atualizar Roupa/Fantasia     -\n");
    printf("-     4 - Excluir Roupa/Fantasia       -\n");
    printf("-     5 - Listar Roupa/Fantasia        -\n");
    printf("-     0 - Voltar                       -\n");
    printf("========================================\n");
    char opcao;
    printf("\nEscolha uma opção: ");
    scanf("%c", &opcao);
    return opcao;
}




void pesquisaCliente(void) {
    system ("cls || clear");
    FILE* fp;
    Cliente* dados;
    int achou;
    char pesquisado[81];
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-  P E S Q U I S A R    C L I E N T E  -\n");
    printf("========================================\n");
    printf("Informe o nome do cliente a ser pesquisado: ");
    scanf(" %80[^\n]", pesquisado);
    dados = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(dados, sizeof(Cliente), 1, fp))) {
    if ((strcmp(dados->nome, pesquisado) == 0) && (dados->status == '1')) {
        achou = 1;
    }
    }
    fclose(fp);
    if (achou) {
        printf("\n");
        printf("========================================\n\n");
        exibeCliente(dados);
        printf("========================================\n");
    } else {
        printf("\nO cliente %s não foi encontrado...\n", pesquisado);
    }
    free(dados);
    pause();
}


void atualizaCliente(void) {
    system ("cls || clear");
    FILE* fp;
    Cliente* dados;
    int achou;
    char resp;
    char pesquisado[80];
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-  A T U A L I Z A R    C L I E N T E  -\n");
    printf("========================================\n");
    printf("Informe o nome do cliente a ser pesquisado: ");
    scanf(" %80[^\n]", pesquisado);
    dados = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(dados, sizeof(Cliente), 1, fp))) {
    if ((strcmp(dados->nome, pesquisado) == 0) && (dados->status == '1')) {
        achou = 1;
    }
    }
    if (achou) {
        printf("\n");
        printf("========================================\n\n");
        exibeCliente(dados);
        printf("========================================\n");
        getchar();
        printf("Deseja realmente atualizar este cliente (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
        printf("\nInforme o CPF do cliente: ");
        scanf(" %11[^\n]", dados->cpf);
        printf("Informe o nome do cliente: ");
        scanf(" %80[^\n]", dados->nome);
        printf("Informe a data de nascimento do cliente (dd/mm/aaaa): ");
        scanf(" %10[^\n]", dados->nasc);
        printf("Informe o endereço do cliente: ");
        scanf(" %120[^\n]", dados->end);
        printf("Informe o telefone do cliente: ");
        scanf(" %20[^\n]", dados->fone);
        getchar();
        printf("Informe o sexo do cliente (M/F): ");
        scanf("%c", &dados->sexo);
        dados->status = '1';
        fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
        fwrite(dados, sizeof(Cliente), 1, fp);
        printf("\nCliente atualizado com sucesso!\n");
        } else {
        printf("\nOk, os dados não foram alterados!\n");
        }
    } else {
        printf("\nO cliente %s não foi encontrado!\n", pesquisado);
    }
    free(dados);
    fclose(fp);
    pause();
}


void excluiCliente(void) {
    system ("cls || clear");
    FILE* fp;
    Cliente* dados;
    int achou;
    char resp;
    char pesquisado[80];
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-    E X C L U I R    C L I E N T E    -\n");
    printf("========================================\n");
    printf("Informe o nome do cliente a ser excluído: ");
    scanf(" %80[^\n]", pesquisado);
    dados = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(dados, sizeof(Cliente), 1, fp))) {
    if ((strcmp(dados->nome, pesquisado) == 0) && (dados->status == '1')) {
        achou = 1;
    }
    }
    if (achou) {
        printf("\n");
        printf("========================================\n\n");
        exibeCliente(dados);
        printf("========================================\n");
        getchar();
        printf("Deseja realmente excluir este cliente (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            dados->status = '0';
            fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
            fwrite(dados, sizeof(Cliente), 1, fp);
            printf("\nCliente excluído com sucesso!\n");
        } else {
        printf("\nOk, o cliente não foi excluído!\n");
        }
    } else {
        printf("\nO cliente %s não foi encontrado!\n", pesquisado);
    }
    free(dados);
    fclose(fp);
    pause();
}


void listaClientes(void) {
    system ("cls || clear");
    FILE* fp;
    Cliente* dados;
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-    L I S T A R    C L I E N T E S    -\n");
    printf("========================================\n");
    dados = (Cliente*) malloc(sizeof(Cliente));
    while(fread(dados, sizeof(Cliente), 1, fp)) {
        if (dados->status == '1') {
            printf("========================================\n\n");
            exibeCliente(dados);
        }
    }
    fclose(fp);
    free(dados);
    pause();
}


void cadastraRoupaFantasia(void) {
    system ("cls || clear");
    Vestuario* vestes;
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-          C A D A S T R A R           -\n");
    printf("-     R O U P A / F A N T A S I A      -\n");
    printf("========================================\n");
    vestes = (Vestuario*) malloc(sizeof(Vestuario));
    printf("\nInforme o código da roupa/fantasia: ");
    scanf("%d", &vestes->cod);
    printf("Informe a descrição da roupa/fantasia: ");
    scanf(" %50[^\n]", vestes->descricao);
    printf("Informe o tamanho da roupa/fantasia\nPP, P, M, G, GG, XGG\n2, 4, 6, 8, 10, 12, 14, 16\n34, 36, 38, 40, 42, 44, 46, 48: ");
    scanf(" %4[^\n]", vestes->tam);
    printf("Informe o valor do aluguel da roupa/fantasia: ");
    scanf("%f", &vestes->preco);
    getchar();
    vestes->status = '1';
    printf("\n");
    printf("========================================\n\n");
    exibeRoupaFantasia(vestes);
    printf("========================================\n");
    gravaRoupaFantasia(vestes);
    printf("\nDados da roupa/Fantasia gravado com sucesso!\n");
    pause();
    
}


void exibeRoupaFantasia(Vestuario* vestes) {
    printf("CÓDIGO: %d\n", vestes->cod);
    printf("DESCRIÇÃO: %s\n", vestes->descricao);
    printf("TAMANHO: %s\n", vestes->tam);
    printf("VALOR: R$ %.2f\n", vestes->preco);
    printf("STATUS: %c\n", vestes->status);
    printf("\n");
}


void gravaRoupaFantasia(Vestuario* vestes) {
    FILE* fp;
    fp = fopen("vestuario.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(vestes, sizeof(Vestuario), 1, fp);
    fclose(fp);
}


void pesquisaRoupaFantasia(void) {
    system ("cls || clear");
    FILE* fp;
    Vestuario* vestes;
    int achou;
    int pesquisado;
    fp = fopen("vestuario.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-          P E S Q U I S A R           -\n");
    printf("-     R O U P A / F A N T A S I A      -\n");
    printf("========================================\n");
    printf("Informe o código da roupa/fantasia a ser pesquisada: ");
    scanf("%d", &pesquisado);
    vestes = (Vestuario*) malloc(sizeof(Vestuario));
    achou = 0;
    while((!achou) && (fread(vestes, sizeof(Vestuario), 1, fp))) {
    if ((vestes->cod == pesquisado) && (vestes->status == '1')) {
        achou = 1;
    }
    }
    fclose(fp);
    if (achou) {
        printf("\n");
        printf("========================================\n\n");
        exibeRoupaFantasia(vestes);
        printf("========================================\n");
    } else {
        printf("\nA roupa/fantasia não foi encontrada!\n");
    }
    free(vestes);
    pause();
    
}


void atualizaRoupaFantasia(void) {
    system ("cls || clear");
    FILE* fp;
    Vestuario* vestes;
    int achou;
    char resp;
    int pesquisado;
    fp = fopen("vestuario.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-          A T U A L I Z A R           -\n");
    printf("-     R O U P A / F A N T A S I A      -\n");
    printf("========================================\n");
    printf("Informe o código da roupa/fantasia a ser atualisada: ");
    scanf("%d", &pesquisado);
    vestes = (Vestuario*) malloc(sizeof(Vestuario));
    achou = 0;
    while((!achou) && (fread(vestes, sizeof(Vestuario), 1, fp))) {
    if ((vestes->cod == pesquisado) && (vestes->status == '1')) {
        achou = 1;
    }
    }
    if (achou) {
        printf("\n");
        printf("========================================\n\n");
        exibeRoupaFantasia(vestes);
        printf("========================================\n");
        getchar();
        printf("Deseja realmente atualizar esta roupa/fantasia (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            printf("\nInforme o código da roupa/fantasia: ");
            scanf("%d", &vestes->cod);
            printf("Informe a descrição da roupa/fantasia: ");
            scanf(" %50[^\n]", vestes->descricao);
            printf("Informe o tamanho da roupa/fantasia\nPP, P, M, G, GG, XGG\n2, 4, 6, 8, 10, 12, 14, 16\n34, 36, 38, 40, 42, 44, 46, 48: ");
            scanf(" %4[^\n]", vestes->tam);
            printf("Informe o valor do aluguel da roupa/fantasia: ");
            scanf("%f", &vestes->preco);
            getchar();
            vestes->status = '1';
            fseek(fp, (-1)*sizeof(Vestuario), SEEK_CUR);
            fwrite(vestes, sizeof(Vestuario), 1, fp);
            printf("\nRoupa/fantasia atualizada com sucesso!\n");
        } else {
            printf("\nOk, os dados não foram alterados!\n");
        }
    } else {
        printf("\nA roupa/fantasia não foi encontrada!\n");
    }
    free(vestes);
    fclose(fp);
    pause();
    
}


void excluiRoupaFantasia(void) {
    system ("cls || clear");
    FILE* fp;
    Vestuario* vestes;
    int achou;
    char resp;
    int pesquisado;
    fp = fopen("vestuario.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-            E X C L U I R             -\n");
    printf("-     R O U P A / F A N T A S I A      -\n");
    printf("========================================\n");
    printf("Informe o código da roupa/fantasia a ser atualisada: ");
    scanf("%d", &pesquisado);
    vestes = (Vestuario*) malloc(sizeof(Vestuario));
    achou = 0;
    while((!achou) && (fread(vestes, sizeof(Vestuario), 1, fp))) {
    if ((vestes->cod == pesquisado) && (vestes->status == '1')) {
        achou = 1;
    }
    }
    if (achou) {
        printf("\n");
        printf("========================================\n\n");
        exibeRoupaFantasia(vestes);
        printf("========================================\n");
        getchar();
        printf("Deseja realmente excluir esta roupa/fantasia (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            vestes->status = '0';
            fseek(fp, (-1)*sizeof(Vestuario), SEEK_CUR);
            fwrite(vestes, sizeof(Vestuario), 1, fp);
            printf("\nRoupa/fantasia excluída com sucesso!\n");
        } else {
        printf("\nOk, a roupa/fantasia não foi excluída!\n");
        }
    } else {
        printf("\nA roupa/fantasia não foi encontrada!\n");
    }
    free(vestes);
    fclose(fp);
    pause();
    
}


void listaRoupaFantasia(void) {
    system ("cls || clear");
    FILE* fp;
    Vestuario* vestes;
    fp = fopen("vestuario.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("--   LOCADORA DE ROUPAS E FANTASIAS   --\n");
    printf("========================================\n");
    printf("-             L I S T A R              -\n");
    printf("-     R O U P A / F A N T A S I A      -\n");
    printf("========================================\n");
    vestes = (Vestuario*) malloc(sizeof(Vestuario));
    while(fread(vestes, sizeof(Vestuario), 1, fp)) {
        if (vestes->status == '1') {
            printf("========================================\n\n");
            exibeRoupaFantasia(vestes);
        }
    }
    free(vestes);
    fclose(fp);
    pause();
    
}


void pause(void) {
    char resp;
    printf("\nDigite qualquer LETRA ou NÚMERO...");
    printf("\nE tecle ENTER para continuar... ");
    scanf(" %c", &resp);
    limpaBuffer();
}


void limpaBuffer(void) {
    char b;
    while ((b = getchar()) != '\n' && b != EOF);
}