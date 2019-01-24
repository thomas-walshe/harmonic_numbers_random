#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 50 //number of elements
#define NUM_TESTS 1000

int rand_lim(int limit);
void fill_array(int random_array[N]);
void print_array(int random_array[N]);
int number_changes(int random_array[N]);

/** Very basic comments in this project,
but for a given N, it will compute the expected
number of changes of the Z parameter (See assignment)
**/

int main(void){
  srand(time(NULL)); //Initiate random number generator
  int random_array[N]; //Array of length N for random numbers

  int changes = 0; //Counter for number of changes of Z
  int change_array[N] = {0}; //Storing the number of changes
  for(int i = 0; i < NUM_TESTS; i++){
    fill_array(random_array); //Fill with random numbers
    changes = number_changes(random_array); 
    change_array[changes - 1]++;
  }

  double expected = 0;
  for(int i = 0; i < N; i++){
    expected += (double)(change_array[i] * (i + 1));
  }
  expected /= (double)NUM_TESTS;
  print_array(change_array);
  printf("Expected: %f\n", expected);
  return 0;
}


int rand_lim(int limit) {
/* return a random number between 0 and limit inclusive.
 */

    int divisor = RAND_MAX/(limit+1);
    int retval;

    do { 
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}


void fill_array(int random_array[N]){
  /** Fills the random_array with integers 
      from 1 to N, uniformly **/
  for(int i = 0; i < N; i++){
    random_array[i] = 0;
  }
  
  int random_int = 0;
  int new_int_flag = 0;
  for(int index = 0; index < N; index++){
    random_int = 0;
    new_int_flag = 0;
    while(!random_int || !new_int_flag){
      new_int_flag = 1;
      random_int = rand_lim(N);
      for(int i = 0; i < index; i++){
	if(random_array[i] == random_int){
	  new_int_flag = 0;
	}
      }
      random_array[index] = random_int;
    }
  }
}


void print_array(int random_array[N]){
  for(int i = 0; i < N; i++){
    printf("%d ", random_array[i]);
  }
  printf("\n");
}


int number_changes(int random_array[N]){
  int z = random_array[0];
  int changes = 1;
  for(int i = 1; i < N; i++){
    if(random_array[i] < z){
      z = random_array[i];
      changes++;
    }
  }
  return changes;
}
