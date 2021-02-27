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
        printf("N�mero de convers�es j� realizadas: %d\n\n", qtd);
    do{
        printf(" _________MENU_________ \n");
        printf("|                      |\n");
        printf("|1 - Sobre o programa  |\n");
        printf("|2 - Realizar convers�o|\n");
        printf("|3 - Descri��o         |\n");
        printf("|4 - Sair              |\n");
        printf("|______________________|\n\n");
        scanf("%d", &choice);
        system("cls");
        switch(choice){
            case 1: printf(" ______________SOBRE O PROGRAMA______________\n");
                    printf("|                                            |\n");
                    printf("|                Integrantes                 |\n");
                    printf("|                                            |\n");
                    printf("|Andr� Seiki Nagaishi                        |\n");
                    printf("|Gabriel Santos S�                           |\n");
                    printf("|                                            |\n");
                    printf("|Instituto Federal de S�o Paulo - Guarulhos  |\n");
                    printf("|Curso: An�lise e Desenvolvimento de Sistemas|\n");
                    printf("|Disciplina: Algoritmos e Programa��o        |\n");
                    printf("|Turma: B                                    |\n");
                    printf("|                                            |\n");
                    printf("|      Copyright � 2019 Seiki e Gabriel      |\n");
                    printf("|____________________________________________|\n\n");
                    printf(" _______________Passo a Passo________________\n");
                    printf("|                                            |\n");
                    printf("|Escolha uma das op��es do menu.             |\n");
                    printf("|Todas as op��es s�o intuitivas.             |\n");
                    printf("|                                            |\n");
                    printf("|Na op��o 2 o programa realiza a convers�o.  |\n");
                    printf("|L�, o usu�rio deve:                         |\n");
                    printf("|-Escolher o par�metro inicial.              |\n");
                    printf("|-Escolher o par�metro do produto final.     |\n");
                    printf("|-Fornecer o valor a ser transformado.       |\n");
                    printf("|-Decidir continuar no programa ou sair.     |\n");
                    printf("|                                            |\n");
                    printf("|Esse processo repetir� at� atingir o limite |\n");
                    printf("|de 30 convers�es ou o usu�rio decidir sair. |\n");
                    printf("|                                            |\n");
                    printf("|Ao fim ser� apresentado todas as convers�es.|\n");
                    printf("|                                            |\n");
                    printf("|OBS: O programa trabalha com muitas casas   |\n");
                    printf("|ap�s a v�rgula por conta de conterem valores|\n");
                    printf("|baix�ssimos.                                |\n");
                    printf("|____________________________________________|\n\n");
                    return 0;
                    break;
            case 2: res=conversor();
                    return res;
                    break;
            case 3: printf("Breve hist�rico do tempo:\n\n");
                    printf("A no��o de tempo � uma das coisas fundamentais para a humanidade e isso n�o � algo atual, uma vez que esse �\num conhecimento de s�culos a.C. Desde a era paleol�tica, os seres humanos observavam o tempo atrav�s dos\ncorpos celestes e mudan�as clim�ticas da natureza, conhecimento que posteriormente se tornou a divis�o das\nquatro esta��es do ano.\n\nCa�adores tiravam proveito para entender o comportamento dos animais, fazendeiros\natentavam-se aos per�odos de colheita e assim foi surgindo esse conhecimento.\n\nPosteriormente, povos come�am a estudar mais aprofundadamente esse assunto, levando a cria��o de diferentes\nformas de c�lculo desde ossum�rios at� o per�odo atual, passando por rel�gios de areia at� chegar aos\nmodernos rel�gios at�micos e a padroniza��o universal do Sistema Internacional de Unidades.");
                    printf("\n\nA convers�o do tempo j� � algo natural, uma vez que existe uma escala de tempo.");
                    printf("\n\nFonte: https://www.infoescola.com/historia/a-origem-da-contagem-do-tempo/");
                    return 0;
                    break;
            case 4: printf("Muito obrigado por utilizar o conversor!\n\n");
                    printf("RELAT�RIO DAS CONVERS�ES FEITAS POR %s:\n\n", nome);
                    for(i=0;i<30;i++){
                        if(matriz[i][0]!=0 && matriz[i][1]!=0)
                            printf("Resultado da Convers�o %.f: %.20f\n", matriz[i][0], matriz[i][1]);
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
    printf("\nConvers�o escolhida de %s para %s.\n\n", string, string2);
}

void explanation(int op){
    switch(op){
        case 1: printf("DIA: Medida de tempo universal adotada pelos babil�nios, que inventaram o primeiro rel�gio da humanidade,\no rel�gio do sol. N�o possu�a a precis�o atual por�m o dia e a noite eram divididos em 12 partes cada,\ntotalizando 24. O dia tamb�m � caracterizado pelo per�odo de rota��o do planeta Terra.\n\n");
                break;
        case 2: printf("HORA: Medida de tempo universal desenvolvida pelos babil�nios e aprimorada conforme os per�odos da humanidade\nat� chegar na vers�o atual.\n\n");
                break;
        case 3: printf("MINUTO: Medida de tempo universal existente desde a �poca dos babil�nios, que trabalhavam com sistemas num�ricos\nduodecimal e sexagesimal (baseados nos n�meros 12 e 60), dividindo a hora em 60 partes.\nPosteriormente � reajustada conforme os avan�os tecnol�gicos.\n\n");
                break;
        case 4: printf("SEGUNDO: Medida de tempo universal existente desde a �poca dos babil�nios, sendo at� 1967 a divis�o do minuto\nem 60 partes. Ap�s essa data, o Sistema Internacional de Unidades definiu sua dura��o baseado\nna radia��o do �tomo c�sio 133.\n\n");
                break;
        case 5: printf("MILISSEGUNDO: Medida de tempo universal que representa a fra��o de um segundo por mil partes. Prefixo\nestabelecido pelo Sistema Internacional de Unidades.\n\n");
                break;
        case 6: printf("MICROSEGUNDO: Medida de tempo universal que representa a fra��o de um segundo por um milh�o de partes.\nPrefixo estabelecido pelo Sistema Internacional de Unidades.\n\n");
                break;
        case 7: printf("NANOSEGUNDO: Medida de tempo universal que representa a fra��o de um segundo por um bilh�o de partes\n(Recebe o nome de nano por ser denotado 10^(-9)). Prefixo estabelecido pelo Sistema Internacional de Unidades.\n\n");
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
            case 6: printf("�s = 86400000000 * d\n\n");
                    printf("�s = 86400000000 * %.2f\n", valor);
                    res=valor*86400000000;
                    printf("�s = %.5f", res);
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
            case 6: printf("�s = h * 3600000000\n\n");
                    printf("�s = %.2f * 3600000000\n", valor);
                    res=valor*3600000000;
                    printf("�s = %.5f", res);
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
            case 6: printf("�s = min * 60000000\n\n");
                    printf("�s = %.2f * 60000000\n", valor);
                    res=valor*60000000;
                    printf("�s = %.5f", res);
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
            case 6: printf("�s = s * 1000000\n\n");
                    printf("�s = %.2f * 1000000\n", valor);
                    res=valor*1000000;
                    printf("�s = %.5f", res);
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
            case 6: printf("�s = ms * 1000\n\n");
                    printf("�s = %.2f * 1000\n", valor);
                    res=valor*1000;
                    printf("�s = %.10f", res);
                    break;
            case 7: printf("ns = ms * 1000000\n\n");
                    printf("ns = %.2f * 1000000\n", valor);
                    res=valor*1000000;
                    printf("ns = %.10f", res);
                    break;
        }
                break;
        case 6: switch(b){
            case 1: printf("d = �s/86400000000\n\n");
                    printf("d = %.2f/86400000000\n", valor);
                    res=valor/86400000000;
                    printf("d = %.15f", res);
                    break;
            case 2: printf("h = �s/3600000000\n\n");
                    printf("h = %.2f/3600000000\n", valor);
                    res=valor/3600000000;
                    printf("h = %.15f", res);
                    break;
            case 3: printf("min = �s/60000000\n\n");
                    printf("min = %.2f/60000000\n", valor);
                    res=valor/60000000;
                    printf("min = %.15f", res);
                    break;
            case 4: printf("s = �s/1000000\n\n");
                    printf("s = %.2f/1000000\n", valor);
                    res=valor/1000000;
                    printf("s = %.15f", res);
                    break;
            case 5: printf("ms = �s/1000\n\n");
                    printf("ms = %.2f/1000\n", valor);
                    res=valor/1000;
                    printf("ms = %.15f", res);
                    break;
            case 6: printf("�s = �s\n\n");
                    res=valor;
                    printf("�s = %.15f", res);
                    break;
            case 7: printf("ns = �s * 1000\n\n");
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
            case 6: printf("�s = ns/1000\n\n");
                    printf("�s = %.2f/1000\n", valor);
                    res=valor/1000;
                    printf("�s = %.20f", res);
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
    printf("SISTEMA DE CONVERS�O DE MEDIDAS - TEMPO\n\n");
    printf("Converter de:\n\n");
    de=options();
    printf("\nPARA:\n");
    para=options();
    do{
        printf("\nValor: ");
        scanf("%d", &valor);
        if(valor<=0)
            printf("Tempo inv�lido!\n");
    }while(valor<=0);
    escolhas(de, para);
    explanation(de);
    explanation(para);
    printf("F�RMULA DA CONVERS�O:\n");
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
        printf("6 - Microsegundo (�s)\n");
        printf("7 - Nanosegundo (ns)\n\n");
        printf("Op��o: ");
        scanf("%d", &option);
        if(option<1 || option>7){
            printf("\nOp��o inv�lida!\n\n");
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
    printf("Para come�ar digite seu nome: ");
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
        printf("Limite estourado! (30 Convers�es)\n");
    printf("RELAT�RIO DAS CONVERS�ES FEITAS POR %s:\n\n", nome);
    for(i=0;i<30;i++){
        if(matriz[i][0]!=0 && matriz[i][1]!=0)
            printf("Resultado da Convers�o %.f: %.20f\n", matriz[i][0], matriz[i][1]);
    }
    return 0;
}
