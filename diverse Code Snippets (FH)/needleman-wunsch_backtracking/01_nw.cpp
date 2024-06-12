#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

void print(vector<vector<int>> matrix)
{
  cout << setfill(' ');

  for (vector<int> row : matrix)
  {
    for (int value : row)
    {
      cout << setw(3) << value << " ";
    }
    cout << endl;
  }
}

void initialize(vector<vector<int>> &matrix, uint rows, uint columns, int gapScore)
{
  for (size_t r = 0; r <= rows; r++)
  {
    vector<int> row;

    for (size_t c = 0; c <= columns; c++)
    {
      int value = 0;

      // Erste Zeile
      if (r == 0)
      {
        value = c * gapScore;
      }

      // Erste Spalte
      if (c == 0)
      {
        value = r * gapScore;
      }

      row.push_back(value);
    }

    matrix.push_back(row);
  }
}

int main()
{
  // Äußerer Vector sind Zeilen, innen die Spalten
  vector<vector<int>> matrix;

  // Incoming variables
  string s1 = "GCATGC"; // Spalten
  string s2 = "GATTA";  // Zeilen

  int gapScore = -1;
  int mismatchScore = -1;
  int matchScore = 1;


  uint rows = s2.length(), columns = s1.length();

  initialize(matrix, rows, columns, gapScore);

  for (size_t r = 1; r <= rows; r++)
  {
    for (size_t c = 1; c <= columns; c++)
    {
      // Wir sind an einer stelle in der matrix und wollen die scores berechnen ....      
      
      int oben = matrix[r - 1][c] + gapScore;
      int links = matrix[r][c - 1] + gapScore;

      bool isMatch = s1[c - 1] == s2[r - 1];
      int diag = matrix[r - 1][c - 1] + (isMatch ? matchScore : mismatchScore);

      // Max rausfinden
      int maximum = max(oben, max(links, diag)); // max(oben, links, diag)

      matrix[r][c] = maximum;
    }
  }

  print(matrix);

  cout << "Der score ist " << matrix[rows][columns];

  return 0;
}