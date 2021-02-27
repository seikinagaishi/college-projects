#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

double conversor();

double menu(double matriz[30][2], char nome[], int qtd){
    int choice, i;
    double res;
    if(qtd>0)
        printf("Número de conversões já realizadas: %d\n\n", qtd);
    do{
        printf(" _________MENU_________ \n");
        printf("|                      |\n");
        printf("|1 - Sobre o programa  |\n");
        printf("|2 - Realizar conversão|\n");
        printf("|3 - Descrição         |\n");
        printf("|4 - Sair              |\n");
        printf("|______________________|\n\n");
        scanf("%d", &choice);
        system("cls");
        switch(choice){
            case 1: printf(" ______________SOBRE O PROGRAMA______________\n");
                    printf("|                                            |\n");
                    printf("|                Integrantes                 |\n");
                    printf("|                                            |\n");
                    printf("|André Seiki Nagaishi                        |\n");
                    printf("|Gabriel Santos Sá                           |\n");
                    printf("|                                            |\n");
                    printf("|Instituto Federal de São Paulo - Guarulhos  |\n");
                    printf("|Curso: Análise e Desenvolvimento de Sistemas|\n");
                    printf("|Disciplina: Algoritmos e Programação        |\n");
                    printf("|Turma: B                                    |\n");
                    printf("|                                            |\n");
                    printf("|      Copyright © 2019 Seiki e Gabriel      |\n");
                    printf("|____________________________________________|\n\n");
                    printf(" _______________Passo a Passo________________\n");
                    printf("|                                            |\n");
                    printf("|Escolha uma das opções do menu.             |\n");
                    printf("|Todas as opções são intuitivas.             |\n");
                    printf("|                                            |\n");
                    printf("|Na opção 2 o programa realiza a conversão.  |\n");
                    printf("|Lá, o usuário deve:                         |\n");
                    printf("|-Escolher o parâmetro inicial.              |\n");
                    printf("|-Escolher o parâmetro do produto final.     |\n");
                    printf("|-Fornecer o valor a ser transformado.       |\n");
                    printf("|-Decidir continuar no programa ou sair.     |\n");
                    printf("|                                            |\n");
                    printf("|Esse processo repetirá até atingir o limite |\n");
                    printf("|de 30 conversões ou o usuário decidir sair. |\n");
                    printf("|                                            |\n");
                    printf("|Ao fim será apresentado todas as conversões.|\n");
                    printf("|                                            |\n");
                    printf("|OBS: O programa trabalha com muitas casas   |\n");
                    printf("|após a vírgula por conta de conterem valores|\n");
                    printf("|baixíssimos.                                |\n");
                    printf("|____________________________________________|\n\n");
                    return 0;
                    break;
            case 2: res=conversor();
                    return res;
                    break;
            case 3: printf("Breve histórico do tempo:\n\n");
                    printf("A noção de tempo é uma das coisas fundamentais para a humanidade e isso não é algo atual, uma vez que esse é\num conhecimento de séculos a.C. Desde a era paleolítica, os seres humanos observavam o tempo através dos\ncorpos celestes e mudanças climáticas da natureza, conhecimento que posteriormente se tornou a divisão das\nquatro estações do ano.\n\nCaçadores tiravam proveito para entender o comportamento dos animais, fazendeiros\natentavam-se aos períodos de colheita e assim foi surgindo esse conhecimento.\n\nPosteriormente, povos começam a estudar mais aprofundadamente esse assunto, levando a criação de diferentes\nformas de cálculo desde ossumérios até o período atual, passando por relógios de areia até chegar aos\nmodernos relógios atômicos e a padronização universal do Sistema Internacional de Unidades.");
                    printf("\n\nA conversão do tempo já é algo natural, uma vez que existe uma escala de tempo.");
                    printf("\n\nFonte: https://www.infoescola.com/historia/a-origem-da-contagem-do-tempo/");
                    return 0;
                    break;
            case 4: printf("Muito obrigado por utilizar o conversor!\n\n");
                    printf("RELATÓRIO DAS CONVERSÕES FEITAS POR %s:\n\n", nome);
                    for(i=0;i<30;i++){
                        if(matriz[i][0]!=0 && matriz[i][1]!=0)
                            printf("Resultado da Conversão %.f: %.20f\n", matriz[i][0], matriz[i][1]);
                    }
                    exit(0);
        }
    } while(choice<1 || choice>4);
}

void escolhas(int tipo, int tipo2){
    char string[15], string2[15];
    switch(tipo){
        case 1: strcpy(string,"dia");
                break;
        case 2: strcpy(string,"hora");
                break;
        case 3: strcpy(string,"minuto");
                break;
        case 4: strcpy(string,"segundo");
                break;
        case 5: strcpy(string,"milissegundo");
                break;
        case 6: strcpy(string,"microsegundo");
                break;
        case 7: strcpy(string,"nanosegundo");
                break;
    }
    switch(tipo2){
        case 1: strcpy(string2,"dia");
                break;
        case 2: strcpy(string2,"hora");
                break;
        case 3: strcpy(string2,"minuto");
                break;
        case 4: strcpy(string2,"segundo");
                break;
        case 5: strcpy(string2,"milissegundo");
                break;
        case 6: strcpy(string2,"microsegundo");
                break;
        case 7: strcpy(string2,"nanosegundo");
                break;
    }
    printf("\nConversão escolhida de %s para %s.\n\n", string, string2);
}

void explanation(int op){
    switch(op){
        case 1: printf("DIA: Medida de tempo universal adotada pelos babilônios, que inventaram o primeiro relógio da humanidade,\no relógio do sol. Não possuía a precisão atual porém o dia e a noite eram divididos em 12 partes cada,\ntotalizando 24. O dia também é caracterizado pelo período de rotação do planeta Terra.\n\n");
                break;
        case 2: printf("HORA: Medida de tempo universal desenvolvida pelos babilônios e aprimorada conforme os períodos da humanidade\naté chegar na versão atual.\n\n");
                break;
        case 3: printf("MINUTO: Medida de tempo universal existente desde a época dos babilônios, que trabalhavam com sistemas numéricos\nduodecimal e sexagesimal (baseados nos números 12 e 60), dividindo a hora em 60 partes.\nPosteriormente é reajustada conforme os avanços tecnológicos.\n\n");
                break;
        case 4: printf("SEGUNDO: Medida de tempo universal existente desde a época dos babilônios, sendo até 1967 a divisão do minuto\nem 60 partes. Após essa data, o Sistema Internacional de Unidades definiu sua duração baseado\nna radiação do átomo césio 133.\n\n");
                break;
        case 5: printf("MILISSEGUNDO: Medida de tempo universal que representa a fração de um segundo por mil partes. Prefixo\nestabelecido pelo Sistema Internacional de Unidades.\n\n");
                break;
        case 6: printf("MICROSEGUNDO: Medida de tempo universal que representa a fração de um segundo por um milhão de partes.\nPrefixo estabelecido pelo Sistema Internacional de Unidades.\n\n");
                break;
        case 7: printf("NANOSEGUNDO: Medida de tempo universal que representa a fração de um segundo por um bilhão de partes\n(Recebe o nome de nano por ser denotado 10^(-9)). Prefixo estabelecido pelo Sistema Internacional de Unidades.\n\n");
                break;
    }
}

double operation(int a, int b, int val){
    double res, valor;
    valor=val;
    switch(a){
        case 1: switch(b){
            case 1: printf("d = d\n\n");
                    res=valor;
                    printf("d = %.5f", res);
                    break;
            case 2: printf("h = 24 * d\n\n");
                    printf("h = 24 * %.2f\n", valor);
                    res=valor*24;
                    printf("h = %.5f", res);
                    break;
            case 3: printf("min = 1440 * d\n\n");
                    printf("min = 1440 * %.2f\n", valor);
                    res=valor*1440;
                    printf("min = %.5f", res);
                    break;
            case 4: printf("s = 86400 * d\n\n");
                    printf("s = 86400 * %.2f\n", valor);
                    res=valor*86400;
                    printf("s = %.5f", res);
                    break;
            case 5: printf("ms = 86400000 * d\n\n");
                    printf("ms = 86400000 * %.2f\n", valor);
                    res=valor*86400000;
                    printf("ms = %.5f", res);
                    break;
            case 6: printf("µs = 86400000000 * d\n\n");
                    printf("µs = 86400000000 * %.2f\n", valor);
                    res=valor*86400000000;
                    printf("µs = %.5f", res);
                    break;
            case 7: printf("ns = 86400000000000 * d\n\n");
                    printf("ns = 86400000000000 * %.2f\n", valor);
                    res=valor*86400000000000;
                    printf("ns = %.5f", res);
                    break;
        }
                break;
        case 2: switch(b){
            case 1: printf("d = h/24\n\n");
                    printf("d = %.2f/24\n", valor);
                    res=valor/24;
                    printf("d = %.5f", res);
                    break;
            case 2: printf("h = h\n\n");
                    res=valor;
                    printf("h = %.5f", res);
                    break;
            case 3: printf("min = h * 60\n\n");
                    printf("min = %.2f * 60\n", valor);
                    res=valor*60;
                    printf("min = %.5f", res);
                    break;
            case 4: printf("s = h * 3600\n\n");
                    printf("s = %.2f * 3600\n", valor);
                    res=valor*3600;
                    printf("s = %.5f", res);
                    break;
            case 5: printf("ms = h * 3600000\n\n");
                    printf("ms = %.2f * 3600000\n", valor);
                    res=valor*3600000;
                    printf("ms = %.5f", res);
                    break;
            case 6: printf("µs = h * 3600000000\n\n");
                    printf("µs = %.2f * 3600000000\n", valor);
                    res=valor*3600000000;
                    printf("µs = %.5f", res);
                    break;
            case 7: printf("ns = h * 3600000000000\n\n");
                    printf("ns = %.2f * 3600000000000\n", valor);
                    res=valor*3600000000000;
                    printf("ns = %.5f", res);
                    break;
        }
                break;
        case 3: switch(b){
            case 1: printf("d = min/1440\n\n");
                    printf("d = %.2f/1440\n", valor);
                    res=valor/1440;
                    printf("d = %.5f", res);
                    break;
            case 2: printf("h = min/60\n\n");
                    printf("h = %.2f/60\n", valor);
                    res=valor/60;
                    printf("h = %.5f", res);
                    break;
            case 3: printf("min = min\n\n");
                    res=valor;
                    printf("min = %.5f", res);
                    break;
            case 4: printf("s = min * 60\n\n");
                    printf("s = %.2f * 60\n", valor);
                    res=valor*60;
                    printf("s = %.5f", res);
                    break;
            case 5: printf("ms = min * 60000\n\n");
                    printf("ms = %.2f * 60000\n", valor);
                    res=valor*60000;
                    printf("ms = %.5f", res);
                    break;
            case 6: printf("µs = min * 60000000\n\n");
                    printf("µs = %.2f * 60000000\n", valor);
                    res=valor*60000000;
                    printf("µs = %.5f", res);
                    break;
            case 7: printf("ns = min * 60000000000\n\n");
                    printf("ns = %.2f * 60000000000\n", valor);
                    res=valor*60000000000;
                    printf("ns = %.5f", res);
                    break;
        }
                break;
        case 4: switch(b){
            case 1: printf("d = s/86400\n\n");
                    printf("d = %.2f/86400\n", valor);
                    res=valor/86400;
                    printf("d = %.5f", res);
                    break;
            case 2: printf("h = s/3600\n\n");
                    printf("h = %.2f/3600\n", valor);
                    res=valor/3600;
                    printf("h = %.5f", res);
                    break;
            case 3: printf("min = s/60\n\n");
                    printf("min = %.2f/60\n", valor);
                    res=valor/60;
                    printf("min = %.5f", res);
                    break;
            case 4: printf("s = s\n\n");
                    res=valor;
                    printf("s = %.5f", res);
                    break;
            case 5: printf("ms = s * 1000\n\n");
                    printf("ms = %.2f * 1000\n", valor);
                    res=valor*1000;
                    printf("ms = %.5f", res);
                    break;
            case 6: printf("µs = s * 1000000\n\n");
                    printf("µs = %.2f * 1000000\n", valor);
                    res=valor*1000000;
                    printf("µs = %.5f", res);
                    break;
            case 7: printf("ns = s * 1000000000\n\n");
                    printf("ns = %.2f * 1000000000\n", valor);
                    res=valor*1000000000;
                    printf("ns = %.5f", res);
                    break;
        }
                break;
        case 5: switch(b){
            case 1: printf("d = ms/86400000\n\n");
                    printf("d = %.2f/86400000\n", valor);
                    res=valor/86400000;
                    printf("d = %.10f", res);
                    break;
            case 2: printf("h = ms/3600000\n\n");
                    printf("h = %.2f/3600000\n", valor);
                    res=valor/3600000;
                    printf("h = %.10f", res);
                    break;
            case 3: printf("min = ms/60000\n\n");
                    printf("min = %.2f/60000\n", valor);
                    res=valor/60000;
                    printf("min = %.10f", res);
                    break;
            case 4: printf("s = ms/1000\n\n");
                    printf("s = %.2f/1000\n", valor);
                    res=valor/1000;
                    printf("s = %.10f", res);
                    break;
            case 5: printf("ms = ms\n\n");
                    res=valor;
                    printf("ms = %.10f", res);
                    break;
            case 6: printf("µs = ms * 1000\n\n");
                    printf("µs = %.2f * 1000\n", valor);
                    res=valor*1000;
                    printf("µs = %.10f", res);
                    break;
            case 7: printf("ns = ms * 1000000\n\n");
                    printf("ns = %.2f * 1000000\n", valor);
                    res=valor*1000000;
                    printf("ns = %.10f", res);
                    break;
        }
                break;
        case 6: switch(b){
            case 1: printf("d = µs/86400000000\n\n");
                    printf("d = %.2f/86400000000\n", valor);
                    res=valor/86400000000;
                    printf("d = %.15f", res);
                    break;
            case 2: printf("h = µs/3600000000\n\n");
                    printf("h = %.2f/3600000000\n", valor);
                    res=valor/3600000000;
                    printf("h = %.15f", res);
                    break;
            case 3: printf("min = µs/60000000\n\n");
                    printf("min = %.2f/60000000\n", valor);
                    res=valor/60000000;
                    printf("min = %.15f", res);
                    break;
            case 4: printf("s = µs/1000000\n\n");
                    printf("s = %.2f/1000000\n", valor);
                    res=valor/1000000;
                    printf("s = %.15f", res);
                    break;
            case 5: printf("ms = µs/1000\n\n");
                    printf("ms = %.2f/1000\n", valor);
                    res=valor/1000;
                    printf("ms = %.15f", res);
                    break;
            case 6: printf("µs = µs\n\n");
                    res=valor;
                    printf("µs = %.15f", res);
                    break;
            case 7: printf("ns = µs * 1000\n\n");
                    printf("ns = %.2f * 1000\n", valor);
                    res=valor*1000;
                    printf("ns = %.15f", res);
                    break;
        }
                break;
        case 7: switch(b){
            case 1: printf("d = ns/86400000000000\n\n");
                    printf("d = %.2f/86400000000000\n", valor);
                    res=valor/86400000000000;
                    printf("d = %.20f", res);
                    break;
            case 2: printf("h = ns/3600000000000\n\n");
                    printf("h = %.2f/3600000000000\n", valor);
                    res=valor/3600000000000;
                    printf("h = %.20f", res);
                    break;
            case 3: printf("min = ns/60000000000\n\n");
                    printf("min = %.2f/60000000000\n", valor);
                    res=valor/60000000000;
                    printf("min = %.20f", res);
                    break;
            case 4: printf("s = ns/1000000000\n\n");
                    printf("s = %.2f/1000000000\n", valor);
                    res=valor/1000000000;
                    printf("s = %.20f", res);
                    break;
            case 5: printf("ms = ns/1000000\n\n");
                    printf("ms = %.2f/1000000\n", valor);
                    res=valor/1000000;
                    printf("ms = %.20f", res);
                    break;
            case 6: printf("µs = ns/1000\n\n");
                    printf("µs = %.2f/1000\n", valor);
                    res=valor/1000;
                    printf("µs = %.20f", res);
                    break;
            case 7: printf("ns = ns\n\n");
                    res=valor;
                    printf("ns = %.20f", res);
                    break;
        }
    }
    return res;
}

double conversor(){
    double res;
    int de, para, valor;
    printf("SISTEMA DE CONVERSÃO DE MEDIDAS - TEMPO\n\n");
    printf("Converter de:\n\n");
    de=options();
    printf("\nPARA:\n");
    para=options();
    do{
        printf("\nValor: ");
        scanf("%d", &valor);
        if(valor<=0)
            printf("Tempo inválido!\n");
    }while(valor<=0);
    escolhas(de, para);
    explanation(de);
    explanation(para);
    printf("FÓRMULA DA CONVERSÃO:\n");
    res=operation(de, para, valor);
    return res;
}

int options(){
    int option;
    do{
        printf("1 - Dia (d)\n");
        printf("2 - Hora (h)\n");
        printf("3 - Minuto (min)\n");
        printf("4 - Segundo (s)\n");
        printf("5 - Milissegundo (ms)\n");
        printf("6 - Microsegundo (µs)\n");
        printf("7 - Nanosegundo (ns)\n\n");
        printf("Opção: ");
        scanf("%d", &option);
        if(option<1 || option>7){
            printf("\nOpção inválida!\n\n");
            fflush(stdin);
        }
    } while(option<1 || option>7);
    return option;
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    double res, matriz[30][2]={0}, replay=1;
    int i, j, cont=0, vetor[30];
    char nome[30];
    for(i=0;i<30;i++){
        vetor[i]=i;
    }
    printf("Bem vindo ao Projeto de APO, o Conversor de Tempo.\n");
    printf("Para começar digite seu nome: ");
    gets(nome);
    printf("\n");
    do {
        res=menu(matriz, nome, vetor[cont]);
        if(res!=0){
            matriz[cont][0]=replay;
            matriz[cont][1]=res;
            replay++;
            cont++;
        }
        printf("\n\nDigite qualquer tecla para retornar.\n");
        getchar();
        getchar();
        system("cls");
    } while(cont<30);
    system("cls");
    if(replay>30)
        printf("Limite estourado! (30 Conversões)\n");
    printf("RELATÓRIO DAS CONVERSÕES FEITAS POR %s:\n\n", nome);
    for(i=0;i<30;i++){
        if(matriz[i][0]!=0 && matriz[i][1]!=0)
            printf("Resultado da Conversão %.f: %.20f\n", matriz[i][0], matriz[i][1]);
    }
    return 0;
}
