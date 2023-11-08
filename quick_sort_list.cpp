#include<iostream>
using namespace std;
class List
{
public:
    int data;
    List *next;
};
void part(List *head,List *F,List *FU)
{
    int pivot = F->data;
    List *i = F->next;
    List *j = FU;
    do
    {
        while(i!= NULL && !(pivot<i->data))
        {
            i = i->next;
        }
    }while(F != FU);
}
void quick_sort(List *head,List *F,List *FU)
{
    if(F != FU)
    {
        List *temp = part(head,F,FU);
    }
}
int main()
{
    List *head = NULL;
    List *F = new List[sizeof(List)];
    List *S = new List[sizeof(List)];
    List *T = new List[sizeof(List)];
    List *FU = new List[sizeof(List)];

    head = F;

    F->data = 80;
    F->next = S;

    S->data = 100;
    S->next = T;

    T->data = 30;
    T->next = FU;

    FU->data = 40;
    FU->next = NULL;
    return 0;
}