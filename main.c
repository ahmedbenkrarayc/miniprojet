#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int nlivre = 100;
    int counter = 0;
    char titles[50][nlivre];
    char authors[50][nlivre];
    float prices[nlivre];
    int quantities[nlivre];

    int choix = 0;
    char titlefind[50];
    int totallv = 0;

    do{
        int found = 0;
        int newquantity = 0;

        printf("------------ Welcome to main menu --------------\n\n");
        printf("0- Exit\n");
        printf("1- Ajouter un livre au stock\n");
        printf("2- Afficher tous les livres disponibles\n");
        printf("3- Rechercher un livre par son titre\n");
        printf("4- Mettre à jour la quantité d'un livre\n");
        printf("5- Supprimer un livre du stock\n");
        printf("6- Afficher le nombre total de livres en stock\n\n");

        printf("Enter votre choix :\n-");
        scanf("%d", &choix);

        switch(choix){
            case 1:

                printf("Entrer le titre : ");
                scanf("%s", titles[counter]);
                printf("Entrer le author : ");
                scanf("%s", authors[counter]);
                printf("Entrer le price : ");
                scanf("%f", &prices[counter]);
                printf("Entrer le quantity : ");
                scanf("%d", &quantities[counter]);


                printf("livre ajoute avec success\n");
                counter++;
                break;

            case 2:
                if(counter > 0){
                    for(int i=0; i<counter; i++){
                        printf("title : %s | author : %s | price : %.2f | quantity : %d\n", titles[i], authors[i], prices[i], quantities[i]);
                    }
                }else{
                    printf("la liste des livres est vide !");
                }
                break;
            case 3:
                printf("Entrer le title de livre : \n-");
                scanf("%s", titlefind);
                for(int i=0; i<counter; i++){
                    if(strcmp(titles[i], titlefind) == 0){
                        printf("title : %s | author : %s | price : %.2f | quantity : %d\n", titles[i], authors[i], prices[i], quantities[i]);
                        found = 1;
                        break;
                    }
                }
                if(found == 0){
                    printf("le livre est introuvable !\n");
                }
                found = 0;
                break;
            case 4:
                printf("Entrer le title de livre a modifier : \n-");
                scanf("%s", titlefind);
                for(int i=0; i<counter; i++){
                    if(strcmp(titles[i], titlefind) == 0){
                        printf("Entrer la nouvelle quantite : \n-");
                        scanf("%d", &newquantity);

                        quantities[i] = newquantity;
                        found = 1;
                        break;
                    }
                }
                if(found == 0){
                    printf("le livre est introuvable !\n");
                }
                found = 0;
                break;
            case 5:
                printf("Entrer le title de livre a supprimer  : \n-");
                scanf("%s", titlefind);
                for(int i=0; i<counter; i++){
                    if(strcmp(titles[i], titlefind) == 0){
                        for(int j=i; j<counter; j++){
                            strcpy(titles[j],titles[j+1]);
                            strcpy(authors[j],authors[j+1]);
                            prices[j] = prices[j+1];
                            quantities[j] = quantities[j+1];
                        }
                        found = 1;
                        counter--;
                        printf("le livre a ete supprimer avec success !\n");
                        break;
                    }
                }
                if(found == 0){
                    printf("le livre est introuvable !\n");
                }
                found = 0;
                break;
            case 6:

                for(int i=0; i<counter; i++){
                        totallv += quantities[i];
                }

                printf("le nombre total de livres en stock est : %d\n", totallv);
                break;
            default:
                if(choix != 0){
                    printf("choisir un valid nombre !\n");
                }
        }
        system("pause");
        system("cls");
    }while(choix != 0);
    return 0;
}
