#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	int *a, *b, *c, n1, n2, n, ch, i, pos, val, j, k, temp, flag;
	printf("\n1.Create\n2.Display\n3.Count\n4.Reverse of the List\n5.Index of an element\n6.Indexed element");
	printf("\n7.Insert\n8.Delete\n9.Merge\n10.Split\n11.Sort\n12.Search");

	do
	{
		printf("\nEnter your choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		// Create
		case 1:
			printf("\nEnter the size of the array: ");
			scanf("%d", &n);
			a = (int *)malloc(n * sizeof(int));
			printf("\nEnter array elements : ");
			for (i = 0; i < n; i++)
			{
				scanf("%d", a + i);
			}
			break;
		// Display
		case 2:
			printf("\nThe List is : ");
			for (i = 0; i < n; i++)
			{
				printf("%d \t", *(a + i));
			}

			break;
		// Count Array Length
		case 3:
			printf("\nArray Length : %d", n);
			break;
		// Reverse the Array
		case 4:
			i = 0;
			j = n - 1;
			while (i < j)
			{
				temp = *(a + i);
				*(a + i) = *(a + j);
				*(a + j) = temp;
				i++;
				j--;
			}
			break;
		// Searching
		case 5:
			printf("\nEnter value to be searched : ");
			scanf("%d", &val);
			flag = 0;
			for (i = 0; i < n; i++)
			{
				if (*(a + i) == val)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				printf("\nIndex of %d is %d", val, i);
			else
				printf("\nElement is not Found.......");

			break;
		// Print Indexed Value
		case 6:
			printf("\nEnter the Index value : ");
			scanf("%d", &val);
			if (val >= 0 && val < n)
				printf("\nElement at index %d is %d", val, *(a + val));
			else
				printf("\nError !out of index......");

			break;
		// New Value Insertion
		case 7:
			n++;
			a = (int *)realloc(a, n * sizeof(int));
			printf("\nEnter position and value : ");
			scanf("%d %d ", &pos, &val);
			for (i = n - 1; i >= pos; i--)
			{
				*(a + i + 1) = *(a + i);
			}
			*(a + pos) = val;
			break;
		// Delete a value
		case 8:
			printf("\nEnter position whose element to be deleted : ");
			scanf("%d", &pos);
			for (i = pos; i < n; i++)
			{
				*(a + i) = *(a + i + 1);
			}
			n--;
			a = (int *)realloc(a, n * sizeof(int));
			break;
		// Merge Two Array
		case 9:
			printf("\nEnter the 2nd Array size : ");
			scanf("%d", &n1);
			b = (int *)malloc(n1 * sizeof(int));
			printf("\nEnter the Array elements : ");
			for (i = 0; i < n1; i++)
			{
				scanf("%d", b + i);
			}
			a = (int *)realloc(a, n1* sizeof(int));
			for (i = 0; i < n1; i++)
			{
				*(a + n + i) = *(b + i);
			}
			// Update the array size
			n = n + n1;
			// print the 3rd array
			printf("\nThe Mreged array is : ");
			for (i = 0; i < n; i++)
				printf("%d\t", *(a + i));

			break;
		// Split Array
		case 10:
			if (n % 2 == 0)
			{
				n1 = n / 2;
				n2 = n / 2;
			}
			else
			{
				n1 = n / 2 + 1;
				n2 = n - n1;
			}
			b = (int *)malloc(n1 * sizeof(int));
			c = (int *)malloc(n2 * sizeof(int));
			// 1st Half
			for (i = 0; i < n1; i++)
			{
				*(b + i) = *(a + i);
			}
			// 2nd Half
			k = 0;
			for (j = i; j < n; j++)
			{
				*(c + k) = *(a + j);
				k++;
			}
			// print the 1st half
			printf("\nThe 1st Half is : ");
			for (i = 0; i < n1; i++)
			{
				printf("%d\t", *(b + i));
			}

			// print the 2nd Half
			for (i = 0; i < n2; i++)
			{
				printf("%d\t", *(c + i));
			}
			break;
		// Sorting
		case 11:
			for (i = 0; i < n - 1; i++)
			{
				for (j = 0; j < n - i - 1; j++)
				{
					if (*(a + j) > *(a + j + 1))
					{
						temp = *(a + j);
						*(a + j) = *(a + j + 1);
						*(a + j + 1) = temp;
					}
				}
			}
			break;
		// Searching
		case 12:
			printf("\nEnter the value to be searchwed : ");
			scanf("%d", &val);
			flag = 0;
			for (i = 0; i < n; i++)
			{
				if (*(a + i) == val)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				printf("\nIndex of %d is %d", val, i);
			else
				printf("\nElement is not found....");
		}
	} while (ch >= 1 && ch <= 12);

	// getch();
}
