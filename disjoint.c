#include<stdio.h>
#include <stdbool.h>

void get_universal(int [], int);
void get_set(int [],int [], int, int);
bool check_data(int [], int, int);
void bitString(int [], int [], int[], int, int);
void disp_bit(int [], int);
void set_union(int [], int [], int [], int);
void set_intersection(int [], int [],int [],int);
void set_difference(int [], int[], int[], int);

int main(){
  printf("\n\n\t-------------------------------------\n\n\tDefine Universal set, Set A and Set B\n\n\t-------------------------------------");
  int u[100], a[100], b[100], set_size, setA_size=0, setB_size=0, bit_stringA[100], bit_stringB[100];
  while(1){
    printf("\n\nEnter the size of Universal set(<100): ");
    scanf("%d", &set_size);
    if(set_size<=0 || set_size>100)
      continue;
    get_universal(u, set_size);
    break;
  }
  while(1){
    printf("\nEnter the size of Set A(<100): ");
    scanf("%d", &setA_size);
    if(setA_size<=0 || setA_size>set_size)
      continue;
    get_set(u, a, set_size, setA_size);
    break;
  }
  while(1){
    printf("\nEnter the size of Set B(<100): ");
    scanf("%d", &setB_size);
    if(setB_size<=0 || setB_size>set_size)
      continue;
    get_set(u, b, set_size, setB_size);
    break;
  }

  printf("\n\n\t--------------------------------------\n\n\tGenerate bitString for Set A and Set B\n\n\t--------------------------------------");
  bitString(u, a, bit_stringA, set_size, setA_size);
  bitString(u, b, bit_stringB, set_size, setB_size);
  printf("\nBitString A: ");
  disp_bit(bit_stringA, set_size);
  printf("\nBitString B: ");
  disp_bit(bit_stringB, set_size);

  printf("\n\n\n\t------------------\n\n\tSet A union Set B\n\n\t------------------");
  set_union(u, bit_stringA, bit_stringB, set_size);

  printf("\n\n\n\t--------------------------\n\n\tSet A intersection Set B\n\n\t--------------------------");
  set_intersection(u, bit_stringA, bit_stringB, set_size);

  printf("\n\n\n\t--------------------------\n\n\tSet A difference Set B\n\n\t-------------------------");
  set_difference(u, bit_stringA, bit_stringB, set_size);

  printf("\n\n\n\t--------------------------\n\n\tSet B difference Set A\n\n\t-------------------------");
  set_difference(u, bit_stringB, bit_stringA, set_size);

  printf("\n\n\n");
}

void get_universal(int set[],int size){
  int data;
  for(int i=0; i<size; i++){
    if(i>0){
      printf("Enter element %d: ", (i+1));
      scanf("%d", &data);
      if(!check_data(set, data, i))
        set[i] = data;
      else{
        i--;
        printf("\n\tDuplicate element found in set!!\n");
        continue;
      }
    }
    else{
      printf("Enter element %d: ", (i+1));
      scanf("%d", &set[i]);
    }
  }
}

void get_set(int u[], int set[],int size, int set_size){
  int data;
  for(int i=0; i<set_size; i++){
    printf("Enter element %d: ", (i+1));
    scanf("%d", &data);
    if(!(check_data(set, data, i)) && check_data(u, data, size))
      set[i] = data;
    else{
      i--;
      printf("\n\tInvalid element found in Set!!!\n");
      continue;
    }
  }
}
