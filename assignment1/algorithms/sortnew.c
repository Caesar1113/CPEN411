#include "sortnew.h"

void sortnew(unsigned long long int *arr, long long int size){
	//Add your function calls here
	quickSort(arr,0,size-1);
	return;
}
// +++++++++++++++++++ Add your additional function definitions below ++++++++++++++++++++++++//



// function to swap elements
void swap1(unsigned long long int *first, unsigned long long int *second)
{
	unsigned long long int tempreg = *first;
	*first = *second;
	*second = tempreg;
	return;
}

// function to find the partition position
int partition(unsigned long long int array[], unsigned long long int low, unsigned long long int high) {
  

  int pivot = array[high];
  

  int i = (low - 1);


  for (unsigned long long  j = low; j < high; j++) {
    if (array[j] <= pivot) {
        

      i++;
      

      swap(&array[i], &array[j]);
    }
  }

  
  swap1(&array[i + 1], &array[high]);
  

  return (i + 1);
}

void quickSort(unsigned long long int array[], unsigned long long int low, unsigned long long int high) {
  if (low < high) {
    

    unsigned long long int pi = partition(array, low, high);
    

    quickSort(array, low, pi - 1);
    

    quickSort(array, pi + 1, high);
  }
  return;
}

