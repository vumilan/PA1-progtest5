#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

long long int GCD ( long long int a, long long int b ){
  if (b != 0)
    return GCD(b, a%b);
  else
    return a;
}

long long int LCM ( long long int a, long long int b ){
  return a / GCD(a,b)*b;
}

int main ( void ){

  int count = 0;
  int alloc_count = 2000;
  char charIn;
  int intIn;
  int from, to;
  int was_in_array;
  long long int lcm;

  int *array = NULL;

  printf("Pocty pruhu:\n");

  if ( scanf(" %c", &charIn) != 1 || charIn != '{' ){
    if (getchar()!= EOF)
		  printf("Nespravny vstup.\n");
		return 0;
	}

  while ( 1 ) {
    if ( scanf(" %d", &intIn) != 1 || intIn < 1){
      if (getchar()!= EOF)
  		  printf("Nespravny vstup.\n");
  		return 0;
  	}
    ++count;
    if ( count == 1 ){
      array = (int *)realloc(array, alloc_count*sizeof(int));
    }
    else if ( count % alloc_count == 0 ){
      array = (int *)realloc(array, (count+alloc_count)*sizeof(int));
    }

    array[count-1] = intIn;

    if ( scanf(" %c", &charIn) != 1 ){
      if (getchar()!= EOF)
        printf("Nespravny vstup.\n");
      free(array);
      return 0;
  	}
    if ( charIn != ',' && charIn != '}' ){
      if (getchar()!= EOF)
        printf("Nespravny vstup.\n");
      free(array);
      return 0;
    }
    if ( charIn == '}' ){
      break;
    }
  }

  printf("Trasy:\n");
  while ( 1 ){
    if ( scanf("%d", &from) != 1 ){
      if (getchar()!= EOF)
        printf("Nespravny vstup.\n");
      free(array);
      return 0;
    }
    if ( scanf("%d", &to) != 1 || from >= to || to > count || from > count){
      printf("Nespravny vstup.\n");
      free(array);
      return 0;
    }

    if ( count != 1 ){
      lcm = array[from];
      for ( int i = from; i < to - 1; ++i ){
        for ( int j = from; j < i + 1; ++j ){
          if (array[i+1] == array[j]){
            was_in_array = 1;
            break;
          }
        }
        if ( was_in_array == 1 ){
          was_in_array = 0;
          continue;
        }
        else
          lcm = LCM(lcm, array[i+1]);
      }
      printf("Vozidel: %lld\n", lcm);
    }
    else{
      printf("Vozidel: %d\n", array[0]);
    }

  }
  free(array);
  return 0;
}
