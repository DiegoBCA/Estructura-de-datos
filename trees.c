#include <stdio.h>

int main(){
 int tree[23] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

  //niveles del arbol
    tree[0]=1;
  //nivel 1
    tree[1] = 2; // D 
    tree[2] = 3; // I 

  //nivel 2
    tree[3] = 4; // B
    tree[4] = 5; // F 
    tree[5] = 6; // H 
    tree[6] = 7; // J 

  //nivel 3
    tree[7] = 8; // A 
    tree[8] = 9; // C 
    // tree[9] is -1 (Left child of F is NULL)
    tree[10] = 10; // E 
  
    printf("arbol:\n");
    for (int i = 0; i < 23; i++) {
        printf("tree[%d] = %d\n", i, tree[i]);
    }

    return 0;
}
