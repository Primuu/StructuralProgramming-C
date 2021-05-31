#include <stdio.h>
#include <stdlib.h>

struct element
{
    int i;
    struct element * next;
};


struct element* utworz()
{
    struct element * temp = malloc(sizeof(struct element));
    temp->next = NULL;
    return temp;
};


void wyswietlListeZGlowa(struct element * Lista)
{
    struct element*temp=Lista->next;
    if(temp==NULL)
    {
        printf("Lista jest pusta\n");
    }
    while(temp!=NULL)
    {
        printf("%d\n",temp->i);
        temp=temp->next;
    }
    printf("----\n");
}


void dodajk(struct element*Lista, int a)
{
    struct element * wsk = Lista;
    while(wsk->next != NULL)
    {
        wsk = wsk->next;
    }
    wsk->next = malloc(sizeof(struct element));
    wsk = wsk->next;
    wsk->i = a;
    wsk->next = NULL;

};


void usunw2 (struct element * Lista, struct element * elem)
{
    struct element * wsk = elem->next;
    elem->next = wsk->next;
    free(wsk);
}


int main()
{
    struct element* Lista = utworz();
    dodajk(Lista,2);
    dodajk(Lista,4);
    dodajk(Lista,-8);
    dodajk(Lista,-22);

    wyswietlListeZGlowa(Lista);

    usunw2(Lista, Lista);

    wyswietlListeZGlowa(Lista);

    return 0;
}
