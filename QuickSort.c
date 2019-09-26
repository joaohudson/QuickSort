#include <stdio.h>

#define SWAP(a,b) {int aux; aux = (a); (a) = (b); (b) = aux; }

static void PrintArray(int ar[], int size)
{
  for(int i = 0; i < size; i++)
  {
    printf("\n[%d] = %d", i, ar[i]);
  }
}

static int Partition(int ar[], int low, int high)
{
  int pivot = ar[high];
  int i = low - 1;

  for(int j = low; j < high; j++)
  {
    if(ar[j] <= pivot)
    {
      i++;
      SWAP(ar[i], ar[j])
    }
  }

  SWAP(ar[i + 1], ar[high])

  return i + 1;
}

void QuickSort(int ar[], int begin, int end)
{
  int flag;
  if(begin < end)
  {
    flag = Partition(ar, begin, end);
    QuickSort(ar, begin, flag - 1);
    QuickSort(ar, flag + 1, end);
  }
}

int main(void)
{
  int ar[] = {2, 55, -90, 15, 37, -98};

  QuickSort(ar, 0, 5);

  PrintArray(ar, 6);

  return 0;
}