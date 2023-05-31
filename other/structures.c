//
// Created by user on 31.05.2023.


typedef struct node {
    int data;
    struct node *next;
}Node;

Node *Add( Node *Top, int d ){
    Node *newel = (Node*)malloc(sizeof (Node)) ;
    newel->data = d;
    newel->next = Top;
    return newel;
}
void Show( Node *Top ) {
    while (Top) {
        if (Top->next) printf("*3d", Top->data);
        else printf("43d\n", Top->data);
        Top = Top->next;
    }
}

int Delete( Node **Top ){
        int d;
    if ((*Top)!=NULL){
        d = (*Top) ->data;
        Node *temp = *Top;
        *Top = (*Top)->next;
        free(temp) ;
    }else {
        printf("Error!!");
        d = 1;}
return d;
}
Node *Add_Q( Node *Top, int d) {
    Node *newel = (Node*) malloc(sizeof( Node));
    newel->data = d;
    newel->next = NULL;
    if (Top==NULL) return newel;
        Node *temp = Top;
    while (temp->next)
        temp = temp->next;
    temp->next = newel;
    return Top;
}
void bfs(){

};