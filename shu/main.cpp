#include <iostream>
#include "header.h"








int main()
{
    CbTree*tree;
    tree=(CbTree*)malloc(sizeof(CbTree));
     if(tree!=NULL)
     {
          initcbtree(tree);
        printf("��������ڵ������:\n");
         createcbtree(tree);
         printf("�ȸ��ݹ�����Ľ��Ϊ:\n");
        qianxu(tree);
         printf("\n");
         printf("����ݹ�������:\n");
         houxu(tree);
         printf("\n");
         printf("�ǵݹ�ǰ���������:\n");
         fdqianxu(tree);
         printf("\n");
           printf("�ǵݹ����������:\n");
         fdhouxu(tree);


     }

    return 0;
}
