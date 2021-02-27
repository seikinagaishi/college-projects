#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#include <windows.h>
#include "listaprojeto.h"

int main(){
    setlocale(LC_ALL, "");
    List *li;
    int x, escolha, codcli, i=0;
    char nome[30], r, r2;
    cli cl;

    //Criando a Lista
    li=criacao();

    //Carregando o arquivo contato.bin
    FILE *f;
    f=fopen("contato.bin", "rb");
    if(f!=NULL)
        carregar(li);
    fclose(f);

    //Rotina do Menu
    do{

        //Evitar a introdu��o de uma op��o inv�lida
        do{
            system("cls");
            printf("Menu\n\n");
            printf("1 - Inser��o de novo contato\n2 - Edi��o de Contato\n3 - Exibir Lista\n4 - Pesquisar por C�digo\n5 - Pesquisar por Nome\n6 - Remover contato\n7 - Sobre\n8 - Sair\n\nOp��o: ");
            scanf("%d", &escolha);
            if(escolha<1 || escolha>8){
                printf("\nDigite um n�mero v�lido!\n\n");
                system("pause");
            }
        } while(escolha<1 || escolha>8);
        system("cls");


        switch(escolha){

        case 1:
            //Inser��o de um Novo Contato
            cl=dadoscl(); //Coleta Dados
            x=verif(li, cl.cod); //Verifica algum contato j� possui o mesmo c�digo

            if(x){
                x=inserir(li, cl);
                if(x){
                    printf("Contato inserido com sucesso!\n\n");
                }
                else{
                    printf("N�o foi poss�vel inserir o contato.\n\n");
                }
            }else{
                system("cls");
                printf("J� existe um contato com este c�digo!\n\n");
            }
        break;

        case 2:
            //Edi��o

            printf("Digite o c�digo do contato a ser editado: ");
            scanf("%d", &codcli);

            x=consultacod(li, codcli, &cl);
            if(x){
                printf("-----------------------------");
                printf("\nC�digo: %d", cl.cod);
                printf("\nNome: %s", cl.nome);
                printf("\nEmpresa: %s", cl.emp);
                printf("\nDepartamento: %s", cl.dept);        //Demonstra as informa��es para facilitar a edi��o
                printf("\nTelefone: %s", cl.tel);
                printf("\nCelular: %s", cl.cel);
                printf("\nE-mail: %s", cl.email);
                printf("\n-----------------------------\n\n");

                cl=editarcl(codcli); //Cadastro de Novos Dados

                do{
                    printf("\nTem certeza que deseja editar este contato? (S/N)\n");
                    fflush(stdin);
                    scanf("%c", &r);
                    r=toupper(r);
                    if(r!='S' && r!='N'){
                        printf("Op��o Inv�lida!\n");
                    }
                } while(r!='S' && r!='N');
                //Possibilidade do usu�rio cancelar a edi��o
                if(r=='S'){
                    system("cls");
                    remover(li, codcli);
                    x=inserir(li, cl);
                    if(x){
                        printf("Contato editado com sucesso!\n\n");
                    }else{
                        printf("N�o foi poss�vel editar o contato.\n\n");
                    }
                }
            } else
                printf("Contato %d n�o encontrado!\n\n", codcli);
        break;

        case 3:
            //Exibi��o Total
            exibir(li);
        break;

        case 4:
            //Busca por C�digo
            printf("Digite o c�digo a ser buscado: ");
            scanf("%d", &codcli);

            x=consultacod(li, codcli, &cl);
            if(x){
                printf("\nC�digo: %d", cl.cod);
                printf("\nNome: %s", cl.nome);
                printf("\nEmpresa: %s", cl.emp);
                printf("\nDepartamento: %s", cl.dept);
                printf("\nTelefone: %s", cl.tel);
                printf("\nCelular: %s", cl.cel);
                printf("\nE-mail: %s\n\n", cl.email);
            } else
                printf("\nContato %d n�o localizado!\n\n", codcli);
        break;

        case 5:
            //Busca por Nome
            fflush(stdin);
            printf("Digite o nome a ser buscado: ");
            fgets(nome,30,stdin);
            nome[strlen(nome) - 1] = '\0';
            consultanome(li, nome);
        break;

        case 6:
            //Remo��o
            do{
                printf("Digite o c�digo do contato a ser removido: ");
                scanf("%d", &codcli);

                x=consultacod(li, codcli, &cl);
                if(x){
                    do{
                        printf("Tem certeza que deseja remover o contato %s? (S/N)\n", cl.nome);
                        fflush(stdin);
                        scanf("%c", &r);
                        r=toupper(r);
                        if(r!='S' && r!='N'){
                            printf("Op��o Inv�lida!\n");
                        }
                    } while(r!='S' && r!='N');
                    system("cls");
                }else{
                    codcli=NULL; //Impossibilitar a remo��o caso o usu�rio cancele a opera��o
                    break;
                }
            } while(r!='S');

            x=remover(li, codcli);
            if(x){
                printf("Contato removido com sucesso!\n\n");
            }else{
                printf("N�o foi poss�vel remover o contato.\n\n");
            }
        break;

        case 7:
            //Informa��es sobre a proposta do trabalho
            printf("Projeto de Estrutura de Dados I\n\n");
            printf("Professor: \tAnt�nio\nTema:\t\tLista Ligada de Contatos\nCurso: \t\tAn�lise e Desenvolvimento de Sistemas\nTurma: \t\t2� ADS\n\n");
            printf("Integrantes:\nAndr� Seiki Nagaishi\nKahu� Aquino\n\nNenhum direito reservado.\n\n");
        break;

        case 8:
            //Sa�da e Salvamento dos Dados
            tamsave(li);
            printf("Salvando dados...");
            Sleep(750);
            system("cls");
            printf("Dados Salvos!\n\n");

        break;
        }
    system("pause");
    fflush(stdin);
    } while(escolha!=8);

    return 0;
}
