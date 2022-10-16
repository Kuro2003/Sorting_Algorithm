#include "my_Function.h"
int main()
{
    int data[5] = { 2500, 10000, 25000, 100000, 250000 };

    for (int k = 0; k <= 3; k++)
    {
        fstream timeFile;

        switch (k)
        {
        case 0:
            timeFile.open("Datak0.csv", ios::out);
            break;
        case 1:
            timeFile.open("Datak1.csv", ios::out);
            break;
        case 2:
            timeFile.open("Datak2.csv", ios::out);
            break;
        case 3:
            timeFile.open("Datak3.csv", ios::out);
            break;
        default:
            break;
        }

        timeFile << "," << "Selection Sort" << ","
            << "Insertion Sort" << ","
            << "Bubble Sort" << ","
            << "Shell Sort" << ","
            << "Heap Sort" << ","
            << "Merge Sort" << ","
            << "Quick Sort" << ","
            << "Radix Sort"<< "\n";

        for (int i = 0; i < 5; i++)
        {
            timeFile << data[i] << ",";

            for (int j = 1; j <= 8; j++)
            {

                int* arr = NULL;
                arr = new int[data[i]];

                GenerateData(arr, data[i], k);

                clock_t start = clock();
                init_and_run_Algorithm(j, arr, data[i]);
                clock_t end = clock();

                double result = (double)(end - start);

                timeFile << result / CLOCKS_PER_SEC;

                if (j != 8)
                    timeFile << ",";
                else
                    continue;

                delete[] arr;
            }

            timeFile << "\n";
        }
    }

	return 0;
}