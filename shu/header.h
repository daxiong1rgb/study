
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stack>
#define MAXSIZE 255
using namespace std;
typedef struct
{

    char name[MAXSIZE];
}ElementType;
typedef struct cbtree
{
    ElementType data;
    struct cbtree *firstchilld;
    struct cbtree *nextsibling;
}CbTree;
int  createcbtree(CbTree*node);
void initcbtree(CbTree*tree);
void testcbtree();
void preordercbtree(CbTree*node);

void initcbtree(CbTree*tree)
{
    tree->firstchilld=NULL;
    tree->nextsibling=NULL;

}

int createcbtree(CbTree*node)
{
    char inputname  [MAXSIZE];
     gets(inputname);
      if(strcmp(inputname,"00")==0)
      {
          return 0;
       }



      strcpy(node->data.name,inputname);
      node->firstchilld=(CbTree*)malloc(sizeof(CbTree));
       node->nextsibling=(CbTree*)malloc(sizeof(CbTree));
      printf("请输入长子节点: ");
       if(createcbtree(node->firstchilld)==0)
       {
           free(node->firstchilld);
           node->firstchilld=NULL;

       }
        printf("请输入兄弟节点: ");
        if(createcbtree(node->nextsibling)==0)
        {
            free(node->nextsibling);
            node->nextsibling=NULL;

        }
        return 1;

}
void qianxu(CbTree*node)//前序遍历（
{

        if(node!=NULL){
          printf("%s  ",node->data.name);
           CbTree*p=node->firstchilld;
         qianxu(p);
           while(p)
           {
               p=p->nextsibling;
               qianxu(p);
           }
        }
}
void houxu(CbTree *node){



    if(node!=NULL){


            houxu(node->firstchilld);
            printf("%s ",node->data.name);
            houxu(node->nextsibling);



    }
}
void fdqianxu(CbTree *node){
  stack <CbTree *>S;
    while (node != NULL ||!S.empty()) {
        while (node != NULL) {
           printf("%s ",node->data.name);
          S.push(node);
            node = node->firstchilld;
        }
        if (!S.empty()) {
            node = S.top();
            S.pop();
            node=node->nextsibling;

        }

    }
}
void fdhouxu(CbTree *node){
     stack <CbTree *>S;
    while (node != NULL ||!S.empty()) {
        while (node != NULL) {

          S.push(node);
            node = node->firstchilld;
        }
        if (!S.empty()) {
            node = S.top();
              printf("%s ",node->data.name);
            S.pop();
        if(node->nextsibling!=NULL)
            node = node->nextsibling;
            else
            {
                node=S.top();
                  printf("%s ",node->data.name);
                S.pop();
                node=node->nextsibling;
            }
        }
    }




}
void Destorytree(CbTree *node){//摧毁树

        if(node!=NULL){
                CbTree*p=node->firstchilld;
         free(node);

         Destorytree(p);
           while(p)
           {
               p=p->nextsibling;
               Destorytree(p);
           }
        }


}
void Cleartree(CbTree *node){//清空树
    CbTree *s=node->firstchilld;
    Destorytree(s);
     strcpy(node->data.name,NULL);

     node->firstchilld=NULL;
    node->nextsibling=NULL;

}
bool Treeempty(CbTree *node){//判断是否是空树
    if(node->data.name==NULL&&node->firstchilld==NULL&&node->nextsibling==NULL)
        return true;
    else
        return false;

}
int Treedeep(CbTree *node){//返回树的深度
    int max=0;
    int i=0;

      stack <CbTree *>S;
    while (node != NULL ||!S.empty()) {
        while (node != NULL) {

          S.push(node);
          i++;
            node = node->firstchilld;
            if(max<=i)
                max=i;
        }
        if (!S.empty()) {
            node = S.top();

            S.pop();
            i--;
             if(max<=i)
                max=i;

        if(node->nextsibling!=NULL)
            node = node->nextsibling;
            else
            {
                node=S.top();

                S.pop();
                i--;
                 if(max<=i)
                max=i;
                node=node->nextsibling;
            }
        }
    }
    return max;



}

int ftree(CbTree *node,CbTree *node1){//判断node1节点是否属于树node
     stack <CbTree *>S;

     int i=0;
    while (node != NULL ||!S.empty()) {
        while (node != NULL) {
           if(node==node1)
           {


            i=1;
            break;
           }
          S.push(node);
            node = node->firstchilld;
        }

         if (!S.empty()) {
            node = S.top();
            S.pop();
            node=node->nextsibling;

        }
        if(i==1)
            break;
        }
         return i;

    }




bool Assign(CbTree *node,CbTree *node1,ElementType a){//为树node的node1节点赋值
    if(!Treeempty(node)&&ftree(node,node1)==1){
        node->data=a;




        return true;



    }
    else
        return false;


}
int getdu(CbTree *node){
    int i=0;
    CbTree *s =node->firstchilld;
    while(s!=NULL){
        s=s->nextsibling;
        i++;
    }
    return i;


}
bool insetchild(CbTree *node,CbTree *node1,int i,CbTree *node2 ){
    if(!Treeempty(node)&&ftree(node,node1)==1&&getdu(node1)>=i&&i>=1){
            if(i!=1){
            CbTree *s=node1->firstchilld;
            int j=1;
    while(j<i-1){
        s=s->nextsibling;
        j++;
    }
    s->nextsibling=node2;
    node2->nextsibling=s->nextsibling->nextsibling;

    }
    else{
        CbTree *s=node1->firstchilld;
        node1->firstchilld=node2;
        node2->nextsibling=s;

    }
    return true;


    }
    else
        return false;



}
bool Deletetree(CbTree *node,CbTree *node1,int i){
    if(!Treeempty(node)&&ftree(node,node1)==1&&getdu(node1)>=i&&i>=1){
        if(i!=1){

            CbTree *s=node1->firstchilld;
             int j=1;
    while(j<i-1){
        s=s->nextsibling;
        j++;
    }
    s->nextsibling=s->nextsibling->nextsibling;
    Destorytree(s->nextsibling);



        }
        else{

            node1->firstchilld=node1->firstchilld->nextsibling;
            Destorytree(node1->firstchilld);
        }
        return true;


    }
    else
        return false;



}








