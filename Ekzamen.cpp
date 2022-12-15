#include<iostream>
#include<ctime>
#include<iomanip>

using namespace std;

const int cols = 2;
const int rows = 15;

void Sort(int arr[rows][cols])
{
    for (unsigned i = 0; i < rows; i++) {
        for (unsigned j = 0; j < cols - 1; j++) {
            for (unsigned k = 0; k < cols - j - 1; k++) {
                if (arr[i][k] > arr[i][k + 1]) {
                    int tmp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = tmp;
                }
            }
        }
    }
}
int main()
{
  srand(time(NULL));
  
  const int rows = 15;
  const int cols = 2;
  int arr[rows][cols];

  cout << "Масив: " << endl;

  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      arr[i][j] = rand() % 20;
      cout << setw(4) << arr[i][j];
    }
    cout << endl;
  }

  int k = (arr[0][0] + arr[0][1]) + (arr[1][0] + arr[1][1]);
  int index1 = 0;
  int index2 = 0;


  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < cols; ++j)
    {
      if (k > (arr[i][0] + arr[i][1]) + (arr[i + 1][0] + arr[i + 1][i]))
      {
        k = (arr[i][0] + arr[i][1]) + (arr[i + 1][0] + arr[i + 1][i]);
        index1 = i;
        index2 = i + 1;
      }
    }
  }
  cout << "Номера  двох  сусідніх рядків, сума елементів в яких мінімальна: " << index1 << " " << index2 << endl;
  
  cout << endl;

  cout << "Сортована матриця;" << endl;
  Sort(arr);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(4) << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}