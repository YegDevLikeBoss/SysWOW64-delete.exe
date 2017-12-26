
#include <locale.h>
#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200
#define MIN -100

int inp[1000];

int arrio();
int separator(int mm);
int glbio();
int dumb(int arg, int mn, int mx);

int nn;

void quickSort(int *numbers, int left, int right)
{
  int pivot; 
  int l_hold = left; 
  int r_hold = right; 
  pivot = numbers[left];
  while (left < right)
   {
    while ((numbers[right] >= pivot) && (left < right))
      right--; 
    if (left != right) 
    {
      numbers[left] = numbers[right]; 
      left++; 
    }
    while ((numbers[left] <= pivot) && (left < right))
      left++; 
    if (left != right) 
    {
      numbers[right] = numbers[left]; 
      right--;
    }
  }
  numbers[left] = pivot;
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot)
    quickSort(numbers, left, pivot - 1);
  if (right > pivot)
    quickSort(numbers, pivot + 1, right);
}

int main()
{
	setlocale(LC_ALL, "ru_RU");
	printf("??????????????");
	
    /* Entering array size */
    int size=-41;
    printf("Enter size of array, lower than 200: ");
	size = dumb(size, 1, 200);  

    /* Filling the array */
    int array[size];
	for (nn=0;nn<size;nn++)
	{
		array[nn]=-1000099;
	}
    printf("If you want to automatically filling array, type 1\nIf you want to fill array yourself, type 2\n");
    int answer=-41;
	answer = dumb(answer, 0, 3); 
	 
    int i;
    switch(answer)
    {
    case 1:
        srand(time(NULL));
        printf("Array elements are assigned values:\n");
        for(i = 0; i < size; i++)
            printf("array[%2.1d] = %d\n", i, array[i] = rand() % (MAX - MIN + 1) + MIN);
        break;
    case 2:
        printf("Enter value for elements\n");
		i=0;
		
		
        while(i < size)
        {
			int yeah=-41;
            printf("array[%d] = ", i);
			yeah = dumb(yeah, 1, 200); 
			array[i]=yeah;
			i++;
        }
        break;
    }

    /* Deleting the repeating elements */
    printf("Deleting the repeating elements\n");
    for(i = 0; i < size - 1; i++)
    {
        int j;
        for(j = i+1; j < size; j++)
        {
            if(array[i] == array[j])
            {
                int n;
                for(n = j; n < size - 1; n++)
                    array[n] = array[n+1];
                size--;
            }
        }
    }

    /* Sorting */
    printf("Creating newarray and copy elements from array\n");
    int newarray[size];
    for(i = 0; i < size; i++)
        newarray[i] = array[i];

    /* With bubble*/
    for(i = 0; i < size-1; i++)
    {
        int j;
        for(j = i+1; j < size; j++)
            if(array[j] < array[i])
            {
                int a = array[i];
                array[i] = array[j];
                array[j] = a;
            }
    }

    printf("The result of sorting with bubble method:\n");
    for(i = 0; i < size; i++)
        printf("array[%d] = %d\n", i, array[i]);

    /* Quick sort */
    quickSort(newarray, 0, size-1);

    printf("The result of sorting with quick sorting:\n");
    for(i = 0; i < size; i++)
        printf("array[%d] = %d\n", i, newarray[i]);

    /* Max and min */
    int n=-1, m=-1;
    printf("Enter Maximum and Minimum:\nMax: ");
	n=dumb(n, 1, size);
    printf("Min: ");
	m=dumb(m, 1, size);

    printf("The %d maximum is %d\n", n, array[size-n]);
    printf("The %d minimum is %d\n", m, array[m-1]);

    printf("End of program!\n");
    return 0; }

int arrio()
{
    int i=0, k=0, iMem=0;
    while(k==0)
    {
        inp[i] = getchar();
        if (inp[i]=='\n')
        {
            inp[i]='\0';
            k=1;
        }
        i++;
    }
    iMem=i;
    return iMem;
}
int separator(int mm)
{
    int i=0, modi, result=0, powr=1, neg=1;

        if ((inp[0]>='0'&&inp[0]<='9')||(inp[0]=='-'))
        {
            for (i=mm-2;i>=0;i--)
            {
				if ('-'==inp[i])
				{
					neg*=-1;
					printf("neg%d", neg);
					continue;
				}
                modi=inp[i];
                if (modi>='0'&&modi<='9')
                {
                    modi-='0';
                    modi*=powr;
					powr*=10;
                    result+=modi;
                }
                else
                {
                    return 0;
                }
            }
			result*=neg;
            return result;
        }
        else return 0;
}	
int glbio()
{
    int tryer, test;
    test=arrio();
    tryer=separator(test);
    return tryer;
}
int dumb(int arg, int mn, int mx)
{
	while (!((arg>mn)&&(arg<mx)))
	{
        arg=glbio();
        if (!((arg>mn)&&(arg<mx)))
            printf("Don't cheat. Enter valid value. :-[\n");
	}
	return arg;
}