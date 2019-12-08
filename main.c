// Esse programa é uma Locadora de Roupas e Fantasias
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include <regex.h>


# define RE_TEL "[0-9]{2}-([0-9]{8}|[0-9]{9})"
//# define RE_CPF "^[0-9]{3}\\.[0-9]{3}\\.[0-9]{3}\\-[0-9]{2}$"


typedef struct cliente Cliente;
typedef struct vestuario Vestuario;
typedef struct locacao Locacao;


struct cliente {
    char cpf[12];
    char nome[81];
    char nasc[11];
    char rua[71];
    char num[7];
    char bairro[71];
    char cidade[41];
    char uf[3];
    char fone[13];
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


struct locacao {
    int codLocacao;
    char cpf[12];
    char nome[81];
    int codRoupaFantasia;
    char descricao[51];
    char tam[5];
    char dataEmprestimo[12];
    char dataPreviaDevolucao[12];
    char dataDevolucao[12];
    float preco;
    float multa;
    float valorTotal;
    char status;
};


char menuPrincipal(void);
char menuCliente(void);
char menuRoupaFantasia(void);
char atualizaClienteDados(void);
char atualizaRoupaFantasiaDados(void);
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
void gravaLocacao(Locacao*);
void locarRoupaFantasia(void);
void exibeLocacao(Locacao*);
void listaLocacao(void);
void telaMenuLocacao(void);
char menuLocacao(void);
void iniciar(void);
int validaCPF(char *cpf);
int verificaCPF(char procurado[12]);
int validaData(char *data);
int validaFone(char tel[15]);  
void excluiLocacao(void);
void pesquisaLocacao(void);


int main(void) {
    iniciar();
    return 0;
}


void iniciar(void) {
    telaInicio();
    char opcao;
    opcao = menuPrincipal();
    while (opcao != '0') {
        switch (opcao) {
            case '1':
                telaMenuCliente();
                break;
            case '2':
                telaMenuRoupaFantasia();
                break;
            case '3':
                telaMenuLocacao();              
                break;
            case '4':
                sobre();               
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
}


void telaMenuCliente(void) {
    limpaBuffer();
    char opcao;
    opcao = menuCliente();
    while (opcao != '0') {
        switch (opcao) {
            case '1':
                cadastraCliente();
                break;
            case '2':
                pesquisaCliente();
                break;
            case '3':
                atualizaCliente();
                break;
            case '4':
                excluiCliente();
                break;
            case '5':
                listaClientes();
                break;
            default:
                limpaBuffer();
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
            case '1':
                cadastraRoupaFantasia(); 
                break;
            case '2':
                pesquisaRoupaFantasia();
                break;
            case '3':
                atualizaRoupaFantasia();
                break;
            case '4':
                excluiRoupaFantasia();
                break;
            case '5':
                listaRoupaFantasia();
                break;
            default:
                limpaBuffer();
                printf("\nEscolha uma opção válida!\n");
                pause();
                break;
        }
        opcao = menuRoupaFantasia();
    }
}



void telaMenuLocacao(void) {
    limpaBuffer();
    char opcao;
    opcao = menuLocacao();
    while (opcao != '0') {
        switch (opcao) {
            case '1':
                locarRoupaFantasia(); 
                break;
            case '2':
                pesquisaLocacao();
                break;
            /*case '3':
                atualizaLocacao();
                break;*/
            case '4':
                excluiLocacao();
                break;
            case '5':
                listaLocacao();
                break;
            default:
                limpaBuffer();
                printf("\nEscolha uma opção válida!\n");
                pause();
                break;
        }
        opcao = menuLocacao();
    }
}



void telaInicio(void) {
    //system ("cls || clear"); 
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
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
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-     M E N U    P R I N C I P A L     -\n");
    printf("-                                      -\n");
    printf("-          1 - Cliente                 -\n");
    printf("-          2 - Roupa/Fantasia          -\n");
    printf("-          3 - Locação                 -\n");
    printf("-          4 - Sobre                   -\n");
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
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
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


void telaFim(void) {
    system ("cls || clear");
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
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
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
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
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
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


char atualizaClienteDados(void) {
    system ("cls || clear");
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-  A T U A L I Z A R    C L I E N T E  -\n");
    printf("-                                      -\n");
    printf("-            1 - Nome                  -\n");
    printf("-            2 - Nascimento            -\n");
    printf("-            3 - Rua                   -\n");
    printf("-            4 - Número                -\n");
    printf("-            5 - Bairro                -\n");
    printf("-            6 - Cidade                -\n");
    printf("-            7 - UF                    -\n");
    printf("-            8 - Telefone              -\n");
    printf("-            9 - Sexo                  -\n");
    printf("-            0 - Voltar                -\n");
    printf("========================================\n");
    char opcao;
    printf("\nEscolha uma opção: ");
    scanf("%c", &opcao);
    return opcao;
}


char atualizaRoupaFantasiaDados(void) {
    system ("cls || clear");
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-          A T U A L I Z A R           -\n");
    printf("-     R O U P A / F A N T A S I A      -\n");
    printf("-                                      -\n");
    printf("-            1 - Código                -\n");
    printf("-            2 - Descrição             -\n");
    printf("-            3 - Tamanho               -\n");
    printf("-            4 - Valor                 -\n");
    printf("-            0 - Voltar                -\n");
    printf("========================================\n");
    char opcao;
    printf("\nEscolha uma opção: ");
    scanf("%c", &opcao);
    return opcao;
}


char menuLocacao(void) {
    system ("cls || clear");
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-       M E N U    L O C A Ç Ã O       -\n");
    printf("-                                      -\n");
    printf("-        1 - Fazer Locação             -\n");
    printf("-        2 - Pesquisar Locação         -\n");
    printf("-        3 - Atualizar Locação         -\n");
    printf("-        4 - Excluir Locação           -\n");
    printf("-        5 - Listar Locação            -\n");
    printf("-        0 - Voltar                    -\n");
    printf("========================================\n");
    char opcao;
    printf("\nEscolha uma opção: ");
    scanf("%c", &opcao);
    return opcao;
}


void cadastraCliente(void) {
    system ("cls || clear");
    Cliente* dados;
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-  C A D A S T R A R    C L I E N T E  -\n");
    printf("========================================\n");
    dados = (Cliente*) malloc(sizeof(Cliente));
    printf("\nInforme o CPF do cliente: ");
    scanf(" %11[^\n]", dados->cpf);
    while (validaCPF(dados->cpf) == 0) {
        printf("\nInsira um CPF válido: ");
        scanf(" %11[^\n]", dados->cpf);
    }
    while (verificaCPF(dados->cpf) == 0) {
        printf("\nCPF já está cadastrado!");
        printf("\nInsira um outro CPF: ");
        scanf(" %11[^\n]", dados->cpf);
    }
    printf("Informe o nome do cliente: ");
    scanf(" %80[^\n]", dados->nome);
    printf("Informe a data de nascimento do cliente (dd/mm/aaaa): ");
    scanf(" %10[^\n]", dados->nasc);
    while (validaData(dados->nasc) == 0) {
        printf("Insira uma data válida: ");
        scanf(" %10[^\n]", dados->nasc);
    }
    printf("Informe o endereço do cliente:\n");
    printf("Rua: ");
    scanf(" %70[^\n]", dados->rua);
    printf("Número: ");
    scanf(" %6[^\n]", dados->num);    
    printf("Bairro: ");
    scanf(" %70[^\n]", dados->bairro);  
    printf("Cidade: ");
    scanf(" %40[^\n]", dados->cidade);
    printf("UF: ");
    scanf(" %2[^\n]", dados->uf);
    printf("Informe o telefone do cliente (Ex: 01-234567890): ");
    scanf(" %12[^\n]", dados->fone);
    while (validaFone(dados->fone) == 0) {
        printf("Insira um Telefone válido: ");
        scanf(" %12[^\n]", dados->fone);
    }
    getchar();
    printf("Informe o sexo do cliente (M/F): ");
    scanf("%c", &dados->sexo);
    dados->status = '1';
    limpaBuffer();
    printf("\n");
    printf("========================================\n\n");
    exibeCliente(dados);
    printf("========================================\n");
    gravaCliente(dados);
    printf("\nDados do cliente gravado com sucesso!\n");
    pause();
}


void exibeCliente(Cliente* dados) {
    printf("CPF: %c%c%c.%c%c%c.%c%c%c-%c%c\n", dados->cpf[0], dados->cpf[1], dados->cpf[2], dados->cpf[3], dados->cpf[4], dados->cpf[5], dados->cpf[6], dados->cpf[7], dados->cpf[8], dados->cpf[9], dados->cpf[10]);
    printf("NOME: %s\n", dados->nome);
    printf("NASCIMENTO: %s\n", dados->nasc);
    printf("ENDEREÇO: %s, %s, %s, %s, %s\n", dados->rua, dados->num, dados->bairro, dados->cidade, dados->uf);
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


void pesquisaCliente(void) {
    system ("cls || clear");
    FILE* fp;
    Cliente* dados;
    int achou;
    char pesquisado[12];
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-  P E S Q U I S A R    C L I E N T E  -\n");
    printf("========================================\n");
    dados = (Cliente*) malloc(sizeof(Cliente));
    printf("Informe o CPF do cliente a ser pesquisado: ");
    scanf(" %11[^\n]", pesquisado);
    while (validaCPF(pesquisado) == 0) {
        printf("\nInsira um CPF válido: ");
        scanf(" %11[^\n]", pesquisado);
    }
    achou = 0;
    while((!achou) && (fread(dados, sizeof(Cliente), 1, fp))) {
        if ((strcmp(dados->cpf, pesquisado) == 0) && (dados->status == '1')) {
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
        printf("\nO cliente não foi encontrado!\n");
    }
    free(dados);
    limpaBuffer();
    pause();
}


void atualizaCliente(void) {
    system ("cls || clear");
    FILE* fp;
    Cliente* dados;
    int achou;
    char resp, opcao;
    char pesquisado[12];
    fp = fopen("clientes.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-  A T U A L I Z A R    C L I E N T E  -\n");
    printf("========================================\n");
    printf("Informe o CPF do cliente a ser pesquisado: ");
    scanf(" %11[^\n]", pesquisado);
    while (validaCPF(pesquisado) == 0) {
        printf("\nInsira um CPF válido: ");
        scanf(" %11[^\n]", pesquisado);
    }
    dados = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(dados, sizeof(Cliente), 1, fp))) {
        if ((strcmp(dados->cpf, pesquisado) == 0) && (dados->status == '1')) {
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
            limpaBuffer();
            opcao = atualizaClienteDados();
            while (opcao != '0') {
                switch (opcao) {
                    case '1':
                        printf("Informe o nome do cliente: ");
                        scanf(" %80[^\n]", dados->nome);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(dados, sizeof(Cliente), 1, fp);
                        printf("Nome do cliente atualizado com sucesso!\n");
                        break;
                    case '2':
                        printf("Informe a data de nascimento do cliente (dia/mes/aaaa): ");
                        scanf(" %10[^\n]", dados->nasc);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(dados, sizeof(Cliente), 1, fp);
                        printf("Data de nascimento atualizada com sucesso!\n");
                        break;
                    case '3':
                        printf("Rua: ");
                        scanf(" %70[^\n]", dados->rua);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(dados, sizeof(Cliente), 1, fp);
                        printf("Rua atualizada com sucesso!\n");
                        break;
                    case '4':
                        printf("Número: ");
                        scanf(" %6[^\n]", dados->num);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(dados, sizeof(Cliente), 1, fp);
                        printf("Número atualizado com sucesso!\n");
                        break;
                    case '5':
                        printf("Bairro: ");
                        scanf(" %70[^\n]", dados->bairro);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(dados, sizeof(Cliente), 1, fp);
                        printf("Bairro atualizado com sucesso!\n");
                        break;
                    case '6':
                        printf("Cidade: ");
                        scanf(" %40[^\n]", dados->cidade);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(dados, sizeof(Cliente), 1, fp);
                        printf("Cidade atualizada com sucesso!\n");
                        break;
                    case '7':
                        printf("UF: ");
                        scanf(" %2[^\n]", dados->uf);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(dados, sizeof(Cliente), 1, fp);
                        printf("UF atualizado com sucesso!\n");
                        break;
                    case '8':
                        printf("Informe o telefone do cliente (Ex: 01-234567890): ");
                        scanf(" %12[^\n]", dados->fone);
                        while (validaFone(dados->fone) == 0) {
                            printf("Insira um Telefone válido: ");
                            scanf(" %12[^\n]", dados->fone);
                        }
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(dados, sizeof(Cliente), 1, fp);
                        printf("Telefone atualizado com sucesso!\n");
                        break;
                    case '9':
                        getchar();
                        printf("Informe o sexo do cliente (M/F): ");
                        scanf("%c", &dados->sexo);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Cliente), SEEK_CUR);
                        fwrite(dados, sizeof(Cliente), 1, fp);
                        printf("Sexo do cliente atualizado com sucesso!\n");
                        break;
                    default:
                        printf("\nEscolha uma opção válida!\n");
                        break;
                }
                limpaBuffer();
                pause();
                opcao = atualizaClienteDados();
            }
            limpaBuffer();
        } else {
            printf("\nOk, os dados não foram alterados!\n");
            limpaBuffer();
            pause();
        }
    } else {
        printf("\nO cliente %s não foi encontrado!\n", pesquisado);
        limpaBuffer();
        pause();
    }
    free(dados);
    fclose(fp);
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
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-    E X C L U I R    C L I E N T E    -\n");
    printf("========================================\n");
    printf("Informe o CPF do cliente a ser excluído: ");
    scanf(" %11[^\n]", pesquisado);
    while (validaCPF(pesquisado) == 0) {
        printf("\nInsira um CPF válido: ");
        scanf(" %11[^\n]", pesquisado);
    }
    dados = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(dados, sizeof(Cliente), 1, fp))) {
        if ((strcmp(dados->cpf, pesquisado) == 0) && (dados->status == '1')) {
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
    limpaBuffer();
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
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-    L I S T A R    C L I E N T E S    -\n");
    printf("========================================\n");
    dados = (Cliente*) malloc(sizeof(Cliente));
    while(fread(dados, sizeof(Cliente), 1, fp)) {
        if (dados->status == '1') {
            printf("\n");
            exibeCliente(dados);
            printf("========================================\n");
        }
    }
    fclose(fp);
    free(dados);
    limpaBuffer();
    pause();
}


void cadastraRoupaFantasia(void) {
    system ("cls || clear");
    Vestuario* vestes;
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-          C A D A S T R A R           -\n");
    printf("-     R O U P A / F A N T A S I A      -\n");
    printf("========================================\n");
    vestes = (Vestuario*) malloc(sizeof(Vestuario));
    printf("\nInforme o código da roupa/fantasia: ");
    scanf("%d", &vestes->cod);
    printf("Informe a descrição da roupa/fantasia: ");
    scanf(" %50[^\n]", vestes->descricao);
    printf("Informe o tamanho da roupa/fantasia\n|PP| P| M| G|GG|XGG|\n| 2| 4| 6| 8|10|12|14|16|\n|34|36|38|40|42|44|46|48|: ");
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
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
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
    limpaBuffer();
    pause();
}


void atualizaRoupaFantasia(void) {
    system ("cls || clear");
    FILE* fp;
    Vestuario* vestes;
    int achou;
    char resp, opcao;
    int pesquisado;
    fp = fopen("vestuario.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
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
            limpaBuffer();
            opcao = atualizaRoupaFantasiaDados();
            while (opcao != '0') {
                switch (opcao) {
                    case '1':
                        printf("\nInforme o código da roupa/fantasia: ");
                        scanf("%d", &vestes->cod);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Vestuario), SEEK_CUR);
                        fwrite(vestes, sizeof(Vestuario), 1, fp);
                        printf("Código da roupa/fantasia atualizado com sucesso!\n");
                        break;
                    case '2':
                        printf("Informe a descrição da roupa/fantasia: ");
                        scanf(" %50[^\n]", vestes->descricao);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Vestuario), SEEK_CUR);
                        fwrite(vestes, sizeof(Vestuario), 1, fp);
                        printf("Descrição da roupa/fantasia atualizada com sucesso!\n");
                        break;
                    case '3':
                        printf("Informe o tamanho da roupa/fantasia\n|PP| P| M| G|GG|XGG|\n| 2| 4| 6| 8|10|12|14|16|\n|34|36|38|40|42|44|46|48|: ");
                        scanf(" %4[^\n]", vestes->tam);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Vestuario), SEEK_CUR);
                        fwrite(vestes, sizeof(Vestuario), 1, fp);
                        printf("Tamanho da roupa/fantasia atualizado com sucesso!\n");
                        break;
                    case '4':
                        printf("Informe o valor do aluguel da roupa/fantasia: ");
                        scanf("%f", &vestes->preco);
                        printf("\n");
                        fseek(fp, (-1)*sizeof(Vestuario), SEEK_CUR);
                        fwrite(vestes, sizeof(Vestuario), 1, fp);
                        printf("Valor do aluguel da roupa/fantasia atualizado com sucesso!\n");
                        break;
                    default:
                        printf("\nEscolha uma opção válida!\n");
                        break;
                }
                limpaBuffer();
                pause();
                opcao = atualizaRoupaFantasiaDados();
            }
            limpaBuffer();
        } else {
            printf("\nOk, os dados não foram alterados!\n");
            limpaBuffer();
            pause();
        }
    } else {
        printf("\nA roupa/fantasia não foi encontrada!\n");
        limpaBuffer();
        pause();
    }
    free(vestes);
    fclose(fp);
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
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-            E X C L U I R             -\n");
    printf("-     R O U P A / F A N T A S I A      -\n");
    printf("========================================\n");
    printf("Informe o código da roupa/fantasia a ser excluída: ");
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
    limpaBuffer();
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
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-             L I S T A R              -\n");
    printf("-     R O U P A / F A N T A S I A      -\n");
    printf("========================================\n");
    vestes = (Vestuario*) malloc(sizeof(Vestuario));
    while(fread(vestes, sizeof(Vestuario), 1, fp)) {
        if (vestes->status == '1') {
            printf("\n");
            exibeRoupaFantasia(vestes);
            printf("========================================\n");
        }
    }
    free(vestes);
    fclose(fp);
    limpaBuffer();
    pause();
}


void locarRoupaFantasia (void) {
    system ("cls || clear");
    FILE* fp1;
    FILE* fp2;
    Locacao* locar;
    Vestuario* vestes;
    Cliente* dados;
    char pesquisado[12];
    int codPesquisado;
    int achou1 = 0, achou2 = 0;
    fp1 = fopen("clientes.dat", "rb");
    fp2 = fopen("vestuario.dat", "rb");

    if ((fp1 == NULL) || (fp2 == NULL)) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-              L O C A R               -\n");
    printf("-     R O U P A / F A N T A S I A      -\n");
    printf("========================================\n");
    locar = (Locacao*) malloc(sizeof(Locacao));
    dados = (Cliente*) malloc(sizeof(Cliente));
    vestes = (Vestuario*) malloc(sizeof(Vestuario));
    printf("\nInforme o CPF do cliente: ");
    scanf(" %11[^\n]", pesquisado);
    while (validaCPF(pesquisado) == 0) {
        printf("Insira um CPF válido: ");
        scanf(" %11[^\n]", pesquisado);
    }
    while ((!achou1) && (fread(dados, sizeof(Cliente), 1, fp1))) {
        if((strcmp(dados->cpf, pesquisado) == 0) && (dados->status == '1')) {
            achou1 = 1;
        }
    }
    if (achou1) {
        printf("Insira o código da roupa/fantasia a ser alugada: ");
        scanf("%d", &codPesquisado);
        while((!achou2) && (fread(vestes, sizeof(Vestuario), 1, fp2))) {
            if ((vestes->cod == codPesquisado) && (vestes->status == '1')) {
                achou2 = 1;
            }
        }
        if (achou2) {
            printf("\nInforme o código da locação: ");
            scanf("%d", &locar->codLocacao);
            strcpy(locar->cpf, dados->cpf);
            strcpy(locar->nome, dados->nome);
            locar->codRoupaFantasia = vestes->cod;
            strcpy(locar->descricao, vestes->descricao);
            strcpy(locar->tam, vestes->tam);
            printf("\nInsira data de empréstimo da roupa/fantasia: ");
            scanf(" %10[^\n]", locar->dataEmprestimo);
            while (validaData(locar->dataEmprestimo) == 0) {
                printf("Insira uma data válida: ");
                scanf(" %10[^\n]", locar->dataEmprestimo);
            }
            printf("\nInsira data prevista para devolução do empréstimo da roupa/fantasia: ");
            scanf(" %10[^\n]", locar->dataPreviaDevolucao);
            while (validaData(locar->dataPreviaDevolucao) == 0) {
                printf("Insira uma data válida: ");
                scanf(" %10[^\n]", locar->dataPreviaDevolucao);
            }
            //locar->dataDevolucao = 
            locar->preco = vestes->preco;
            locar->status = '1';
            printf("\n");
            printf("========================================\n\n");
            exibeLocacao(locar);
            printf("========================================\n\n");
            gravaLocacao(locar);
            printf("Locação realizada com sucesso!\n");
        }
        else {
            printf("\nA roupa/fantasia não foi encontrada!\n");
        }
    }
    else {
        printf("\nCliente não foi encontrado!\n");
    }
    fclose(fp1);
    fclose(fp2);
    free(locar);
    free(vestes);
    free(dados);
    limpaBuffer();
    pause();
}



void pesquisaLocacao(void) {
    system ("cls || clear");
    FILE* fp;
    Locacao* locar;
    int achou;
    int pesquisado;
    fp = fopen("locacao.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-          P E S Q U I S A R           -\n");
    printf("-            L O C A Ç Ã O             -\n");
    printf("========================================\n");
    printf("Informe o código da locação a ser pesquisada: ");
    scanf("%d", &pesquisado);
    locar = (Locacao*) malloc(sizeof(Locacao));
    achou = 0;
    while((!achou) && (fread(locar, sizeof(Locacao), 1, fp))) {
        if ((locar->codLocacao == pesquisado) && (locar->status == '1')) {
            achou = 1;
        }
    }
    fclose(fp);
    if (achou) {
        printf("\n");
        printf("========================================\n\n");
        exibeLocacao(locar);
        printf("========================================\n");
    } else {
        printf("\nA roupa/fantasia não foi encontrada!\n");
    }
    free(locar);
    limpaBuffer();
    pause();
}


void listaLocacao(void) {
    system ("cls || clear");
    FILE* fp;
    Locacao* locar;
    fp = fopen("locacao.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-     L I S T A R    L O C A Ç Ã O     -\n");
    printf("========================================\n");
    locar = (Locacao*) malloc(sizeof(Locacao));
    while(fread(locar, sizeof(Locacao), 1, fp)) {
        if (locar->status == '1') {
            printf("\n");
            exibeLocacao(locar);
            printf("========================================\n");
        }
    }
    fclose(fp);
    free(locar);
    limpaBuffer();
    pause();
}


void excluiLocacao(void) {
    system ("cls || clear");
    FILE* fp;
    Locacao* locar;
    int achou;
    char resp;
    int pesquisado;
    fp = fopen("locacao.dat", "r+b");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    printf("\n");
    printf("========================================\n");
    printf("---  LOCADORA DE ROUPAS E FANTASIAS  ---\n");
    printf("========================================\n");
    printf("-    E X C L U I R    L O C A Ç Ã O    -\n");
    printf("========================================\n");
    printf("Informe o código de locação a ser excluído: ");
    scanf("%d", &pesquisado);
    locar = (Locacao*) malloc(sizeof(Locacao));
    achou = 0;
    while((!achou) && (fread(locar, sizeof(Locacao), 1, fp))) {
        if ((locar->codLocacao == pesquisado) && (locar->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        printf("\n");
        printf("========================================\n\n");
        exibeLocacao(locar);
        printf("========================================\n");
        getchar();
        printf("Deseja realmente excluir esta locação (s/n)? ");
        scanf("%c", &resp);
        if (resp == 's' || resp == 'S') {
            locar->status = '0';
            fseek(fp, (-1)*sizeof(Locacao), SEEK_CUR);
            fwrite(locar, sizeof(Locacao), 1, fp);
            printf("\nLocação excluída com sucesso!\n");
        } else {
        printf("\nOk, a locação não foi excluído!\n");
        }
    } else {
        printf("\nLocação não foi encontrado!\n");
    }
    free(locar);
    fclose(fp);
    limpaBuffer();
    pause();
}


void exibeLocacao(Locacao* locar) {
    printf("COD LOCAÇÃO: %d\n", locar->codLocacao);
    printf("NOME DO CLIENTE: %s\n", locar->nome);
    printf("CPF DO CLIENTE: %c%c%c.%c%c%c.%c%c%c-%c%c\n", locar->cpf[0], locar->cpf[1], locar->cpf[2], locar->cpf[3], locar->cpf[4], locar->cpf[5], locar->cpf[6], locar->cpf[7], locar->cpf[8], locar->cpf[9], locar->cpf[10]);
    printf("COD ROUPA/FANTASIA: %d\n", locar->codRoupaFantasia);
    printf("DESCRIÇÃO: %s\n", locar->descricao);
    printf("TAMANHO: %s\n", locar->tam);
    printf("DATA DE EMPRÉSTIMO: %s\n", locar->dataEmprestimo);
    printf("DATA PREVISTA PARA DEVOLUÇÃO DO EMPRÉSTIMO: %s\n", locar->dataPreviaDevolucao);
    printf("DATA DE DEVOLUÇAO: %s\n", locar->dataDevolucao);
    printf("VALOR DE LOCAÇÃO: R$ %.2f\n", locar->preco);
    printf("MULTA POR ATRASO: R$ %.2f\n", locar->multa);
    printf("VALOR TOTAL À PAGAR: R$ %.2f\n", locar->valorTotal);
    printf("STATUS: %c\n", locar->status);
    printf("\n");
}


void gravaLocacao(Locacao* locar) {
    FILE* fp;
    fp = fopen("locacao.dat", "ab");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    fwrite(locar, sizeof(Locacao), 1, fp);
    fclose(fp);
}


void pause(void) {
    printf("\nTecle ENTER para continuar... "); 
    limpaBuffer();
}


void limpaBuffer(void) {
    char b;
    while ((b = getchar()) != '\n'  && b != EOF);
}


int validaFone(char tel[15]) { 
    regex_t reg;
    if((strlen(tel)) > 15) {
        return 0;
    } else {
        if(regcomp(&reg, RE_TEL, REG_EXTENDED|REG_NOSUB) != 0) {
            return 0;
        } else {
            if((regexec(&reg, tel, 0, (regmatch_t*)NULL, 0)) == 0) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}


int validaCPF(char *cpf) {
    //https://gist.github.com/eduardoedson/8f991b6d234a9ebdcbe3
    int i, j, digito1 = 0, digito2 = 0;
    if (strlen(cpf) != 11) {
        return 0;
    }
    else if ((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0)) {
        return 0; ///se o CPF tiver todos os números iguais ele é inválido.
    }
    else {
        ///digito 1---------------------------------------------------
        for (i = 0, j = 10; i < strlen(cpf)-2; i++, j--) {///multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;
        }
        digito1 %= 11;
        if (digito1 < 2) {
            digito1 = 0;
        }
        else {
            digito1 = 11 - digito1;
        }
        if ((cpf[9]-48) != digito1) {
            return 0; ///se o digito 1 não for o mesmo que o da validação CPF é inválido
        }
        else { ///digito 2--------------------------------------------------
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--) ///multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
        }
        digito2 %= 11;
        if (digito2 < 2) {
            digito2 = 0;
        }
        else {
            digito2 = 11 - digito2;
        }
        if ((cpf[10]-48) != digito2) {
            return 0; ///se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}


int verificaCPF(char procurado[12]) {
    FILE* fp;
    Cliente* dados;
    int achou;
    fp = fopen("clientes.dat", "rb");
    if (fp == NULL) {
        printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
        printf("Não é possível continuar o programa...\n");
        exit(1);
    }
    dados = (Cliente*) malloc(sizeof(Cliente));
    achou = 0;
    while((!achou) && (fread(dados, sizeof(Cliente), 1, fp))) {
        if ((strcmp(dados->cpf, procurado) == 0) && (dados->status == '1')) {
            achou = 1;
        }
    }
    if (achou) {
        return 0;
    }
    else {
        return 1;
    }
    fclose(fp);
    free(dados);
}


int validaData(char *data) {
    int dia, mes, ano;
    dia = ((data[0]-48)*10) + (data[1]-48);
    mes = ((data[3]-48)*10) + (data[4]-48);
    ano = ((data[6]-48)*1000) + ((data[7]-48)*100) + ((data[8]-48)*10) + (data[9]-48);
    //verifica se os numeros sao validos
    if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) {
        if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) { //verifica se o ano e bissexto
            return 1;
        }
        if (dia <= 28 && mes == 2) {//verifica o mes de feveireiro
            return 1;
        }
        if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) {//verifica os meses de 30 dias
            return 1;
        }
        if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) {//verifica os meses de 31 dias
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}