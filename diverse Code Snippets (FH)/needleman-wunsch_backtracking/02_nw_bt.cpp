#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

using vector2d = vector<vector<int>>;

enum Directions
{
  Up,
  Left,
  Diagonal
};

void print(vector2d matrix)
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

void printDirections(vector2d matrix)
{
  // cout << setfill(' ');

  for (vector<int> row : matrix)
  {
    for (int value : row)
    {
      char c = value == Directions::Up
                   ? 'U'
               : value == Directions::Left
                   ? 'L'
                   : 'D';

      cout << c << " ";
    }
    cout << endl;
  }
}

void initialize(vector2d &matrix, uint rows, uint columns, int gapScore = 0)
{
  for (size_t r = 0; r <= rows; r++)
  {
    vector<int> row;

    for (size_t c = 0; c <= columns; c++)
    {
      int value = 0;

      // Erste Zeile
      if (r == 0 && gapScore != 0)
      {
        value = c * gapScore;
      }

      // Erste Spalte
      if (c == 0 && gapScore != 0)
      {
        value = r * gapScore;
      }

      row.push_back(value);
    }

    matrix.push_back(row);
  }
}

void initializeDirections(vector2d &matrix, uint rows, uint columns)
{
  for (size_t r = 0; r <= rows; r++)
  {
    vector<int> row;

    for (size_t c = 0; c <= columns; c++)
    {
      int value = 0; // Directions::Diagonal;

      // Erste Zeile
      if (r == 0)
      {
        value = Directions::Left;
      }

      // Erste Spalte
      if (c == 0)
      {
        value = Directions::Up;
      }

      row.push_back(value);
    }

    matrix.push_back(row);
  }
}

int main()
{
  // Äußerer Vector sind Zeilen, innen die Spalten
  vector2d matrix;

  vector2d directions;

  // Incoming variables
  string s1 = "GCATGCU"; //"GCATGC"; // Spalten
  string s2 = "GATTACA"; //"GATTA";  // Zeilen

  int gapScore = -1;
  int mismatchScore = -1;
  int matchScore = 1;

  uint rows = s2.length(), columns = s1.length();

  initialize(matrix, rows, columns, gapScore);
  initializeDirections(directions, rows, columns);

  for (size_t r = 1; r <= rows; r++)
  {
    for (size_t c = 1; c <= columns; c++)
    {
      // Wir sind an einer stelle in der matrix und wollen die scores berechnen ....

      int up = matrix[r - 1][c] + gapScore;
      int left = matrix[r][c - 1] + gapScore;

      bool isMatch = s1[c - 1] == s2[r - 1];
      int diag = matrix[r - 1][c - 1] + (isMatch ? matchScore : mismatchScore);

      // Max rausfinden
      int maximum = max(up, max(left, diag)); // max(up, left, diag)
      matrix[r][c] = maximum;

      // if (maximum == up)
      // {
      //   directions[r][c] = Directions::Up;
      // }
      // else if (maximum == left)
      // {
      //   directions[r][c] = Directions::Left;
      // }
      // else
      // {
      //   directions[r][c] = Directions::Diagonal;
      // }

      // Ternärer Operator verschachtelt
      directions[r][c] = maximum == up
                             ? Directions::Up
                             : (maximum == left
                                    ? Directions::Left
                                    : Directions::Diagonal);
    }
  }

  print(matrix);

  cout << "Der score ist " << matrix[rows][columns] << endl;

  printDirections(directions);

  string aligned1 = "", aligned2 = "";

  int c = columns;
  int r = rows;
  while (r > 0 && c > 0)
  {
    int direction = directions[r][c];

    if (direction == Directions::Left)
    {
      // Ausgabe Seq1 + Gap aus Seq2
      aligned1 = s1[c - 1] + aligned1;
      aligned2 = "-" + aligned2;

      c--;
    }
    else if (direction == Directions::Up)
    {
      // Ausgabe Seq2 + Gap aus Seq1
      aligned1 = "-" + aligned1;
      aligned2 = s2[r - 1] + aligned2;

      r--;
    }
    else
    {
      // Ausgabe beide
      aligned1 = s1[c - 1] + aligned1;
      aligned2 = s2[r - 1] + aligned2;

      c--;
      r--;
    }
  }

  print(directions);

  cout << "S1: " << s1 << endl;
  cout << "S2: " << s2 << endl;
  cout << "A1: " << aligned1 << endl;
  cout << "A2: " << aligned2 << endl;

  return 0;
}