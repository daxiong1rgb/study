#include <iostream>
#include "header.h"








int main()
{
    CbTree*tree;
    tree=(CbTree*)malloc(sizeof(CbTree));
     if(tree!=NULL)
     {
          initcbtree(tree);
        printf("请输入根节点的数据:\n");
         createcbtree(tree);
         printf("先根递归遍历的结果为:\n");
        qianxu(tree);
         printf("\n");
         printf("后根递归遍历结果:\n");
         houxu(tree);
         printf("\n");
         printf("非递归前根遍历结果:\n");
         fdqianxu(tree);
         printf("\n");
           printf("非递归后根遍历结果:\n");
         fdhouxu(tree);


     }

    return 0;
}
