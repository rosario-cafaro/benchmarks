using System;
using System.IO;

namespace Test1
{
    class Sort
    {
        private static void Quick_Sort(int[] arr, int left, int right)
        {
            if (left < right)
            {
                int pivot = Partition(arr, left, right);

                if (pivot > 1)
                {
                    Quick_Sort(arr, left, pivot - 1);
                }
                if (pivot + 1 < right)
                {
                    Quick_Sort(arr, pivot + 1, right);
                }
            }

        }

        private static int Partition(int[] arr, int left, int right)
        {
            int pivot = arr[left];
            while (true)
            {

                while (arr[left] < pivot)
                {
                    left++;
                }

                while (arr[right] > pivot)
                {
                    right--;
                }

                if (left < right)
                {
                    if (arr[left] == arr[right]) return right;

                    int temp = arr[left];
                    arr[left] = arr[right];
                    arr[right] = temp;


                }
                else
                {
                    return right;
                }
            }
        }
        static void Main()
        {
            var reader = new StreamReader(File.OpenRead("../../data/10k_integers.txt"));
            int[] integers = new int[10000];
            int i = 0;
            while (!reader.EndOfStream)
            {
                var row = int.Parse(reader.ReadLine());
                integers[i] = row;
                i++;
            }

            Quick_Sort(integers, 0, integers.Length - 1);

            // foreach (var integer in integers)
            // {
            //     Console.WriteLine(integer);
            // }
            Console.WriteLine("First element: {0}\nLast element: {1}\n", integers[0], integers[integers.Length - 1]);
        }
    }
}