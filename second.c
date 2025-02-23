#include <stdio.h>
#include <stdlib.h>

void freeMatrix(int **matrix, int r){
   for(int i = 0; i < r; i++){
      free(matrix[i]);  //free each row
   }
   free(matrix);  //free row pointers
}

int main(int argc, char** argv){
   if(argc < 2) { //checks if there are 2 arguments!
      fprintf(stderr,"./first {text file}"); //prints messages to stderr. Primarily for error messages
      exit(1); //exits the program with a return code 1.
   }
   
   FILE *file = fopen(argv[1], "r"); //opening file
   if(file == NULL){ //if fopen fails to open the file, it returns NULL
      fprintf(stderr,"%s failed to open\n",argv[1]);
      exit(1); //exits your program
   }
   int row, col;

   int f1 = fscanf(file, "%d %d", &row, &col);
   if (f1 != 2) return 0;
   //printf("%d %d", row, col);
   
   // Allocate memory for row pointers
   int **arr = malloc(row*sizeof(int *));
   int **rot = malloc(row*sizeof(int *));

   // Allocate memory for each row
   for(int i = 0; i < row; i++){
      arr[i] = malloc(col*sizeof(int));
      rot[i] = malloc(col*sizeof(int));
   }
   //rewind(file);
   //fscanf(file, "%d %d", &row, &col);
   for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
         int f2 = fscanf(file, "%d", &arr[i][j]);
         if(f2 != 1) return 0;
         //printf("%d", arr[i][j]);
         //arr[i][j] = fscanf(file, "%d"); // Assign values
         rot[j][col-1-i] = arr[i][j];
      }
   }
   fclose(file);
   
//////////////////////////////////
   //print rotated array
   for(int a = 0; a < row; a++){
      for(int b = 0; b < col; b++){
         printf("%d\t", rot[a][b]);
      }
      printf("\n");
   }
   
   freeMatrix(arr, row);  //free matrices
   freeMatrix(rot, row);
   
}
