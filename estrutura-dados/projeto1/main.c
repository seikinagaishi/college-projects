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

        //Evitar a introdução de uma opção inválida
        do{
            system("cls");
            printf("Menu\n\n");
            printf("1 - Inserção de novo contato\n2 - Edição de Contato\n3 - Exibir Lista\n4 - Pesquisar por Código\n5 - Pesquisar por Nome\n6 - Remover contato\n7 - Sobre\n8 - Sair\n\nOpção: ");
            scanf("%d", &escolha);
            if(escolha<1 || escolha>8){
                printf("\nDigite um número válido!\n\n");
                system("pause");
            }
        } while(escolha<1 || escolha>8);
        system("cls");


        switch(escolha){

        case 1:
            //Inserção de um Novo Contato
            cl=dadoscl(); //Coleta Dados
            x=verif(li, cl.cod); //Verifica algum contato já possui o mesmo código

            if(x){
                x=inserir(li, cl);
                if(x){
                    printf("Contato inserido com sucesso!\n\n");
                }
                else{
                    printf("Não foi possível inserir o contato.\n\n");
                }
            }else{
                system("cls");
                printf("Já existe um contato com este código!\n\n");
            }
        break;

        case 2:
            //Edição

            printf("Digite o código do contato a ser editado: ");
            scanf("%d", &codcli);

            x=consultacod(li, codcli, &cl);
            if(x){
                printf("-----------------------------");
                printf("\nCódigo: %d", cl.cod);
                printf("\nNome: %s", cl.nome);
                printf("\nEmpresa: %s", cl.emp);
                printf("\nDepartamento: %s", cl.dept);        //Demonstra as informações para facilitar a edição
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
                        printf("Opção Inválida!\n");
                    }
                } while(r!='S' && r!='N');
                //Possibilidade do usuário cancelar a edição
                if(r=='S'){
                    system("cls");
                    remover(li, codcli);
                    x=inserir(li, cl);
                    if(x){
                        printf("Contato editado com sucesso!\n\n");
                    }else{
                        printf("Não foi possível editar o contato.\n\n");
                    }
                }
            } else
                printf("Contato %d não encontrado!\n\n", codcli);
        break;

        case 3:
            //Exibição Total
            exibir(li);
        break;

        case 4:
            //Busca por Código
            printf("Digite o código a ser buscado: ");
            scanf("%d", &codcli);

            x=consultacod(li, codcli, &cl);
            if(x){
                printf("\nCódigo: %d", cl.cod);
                printf("\nNome: %s", cl.nome);
                printf("\nEmpresa: %s", cl.emp);
                printf("\nDepartamento: %s", cl.dept);
                printf("\nTelefone: %s", cl.tel);
                printf("\nCelular: %s", cl.cel);
                printf("\nE-mail: %s\n\n", cl.email);
            } else
                printf("\nContato %d não localizado!\n\n", codcli);
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
            //Remoção
            do{
                printf("Digite o código do contato a ser removido: ");
                scanf("%d", &codcli);

                x=consultacod(li, codcli, &cl);
                if(x){
                    do{
                        printf("Tem certeza que deseja remover o contato %s? (S/N)\n", cl.nome);
                        fflush(stdin);
                        scanf("%c", &r);
                        r=toupper(r);
                        if(r!='S' && r!='N'){
                            printf("Opção Inválida!\n");
                        }
                    } while(r!='S' && r!='N');
                    system("cls");
                }else{
                    codcli=NULL; //Impossibilitar a remoção caso o usuário cancele a operação
                    break;
                }
            } while(r!='S');

            x=remover(li, codcli);
            if(x){
                printf("Contato removido com sucesso!\n\n");
            }else{
                printf("Não foi possível remover o contato.\n\n");
            }
        break;

        case 7:
            //Informações sobre a proposta do trabalho
            printf("Projeto de Estrutura de Dados I\n\n");
            printf("Professor: \tAntônio\nTema:\t\tLista Ligada de Contatos\nCurso: \t\tAnálise e Desenvolvimento de Sistemas\nTurma: \t\t2º ADS\n\n");
            printf("Integrantes:\nAndré Seiki Nagaishi\nKahuã Aquino\n\nNenhum direito reservado.\n\n");
        break;

        case 8:
            //Saída e Salvamento dos Dados
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
