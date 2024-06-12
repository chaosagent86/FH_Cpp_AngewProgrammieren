#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

// Umbenennung (alias), damit wir nicht immer vector<vector<int>> schreiben müssen
using vector2d = vector<vector<int>>;

enum Directions
{
  Up = 1,
  Left = 2,
  Diagonal = 4
};

// 1  0001   - Up
// 2  0010   - Left
// 3  0011   - Up + Left
// 4  0100   - Diagonal
// 5  0101   - Up + D
// 6  0110   - L + D
// 7  0111   - U + L + D

void traceback(vector2d &matrix, vector2d &directions, int r, int c, string s1, string s2, string aligned1, string aligned2);

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

  // Incoming variables ... sollten in Command-Line-Arguments ausgelagert werden
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

      int maximum = max(up, max(left, diag)); // max(up, left, diag)
      matrix[r][c] = maximum;

      // IFs getrennt, weil alle 3 IFs zutreffend sein könnten
      if (maximum == up)
      {
        directions[r][c] |= Directions::Up;
        // |= ... bitweise ver-oder-ung
      }

      if (maximum == left)
      {
        directions[r][c] |= Directions::Left;
      }

      if (maximum == diag)
      {
        directions[r][c] |= Directions::Diagonal;
      }

      // directions[r][c] = maximum == up
      //                        ? Directions::Up
      //                        : (maximum == left
      //                               ? Directions::Left
      //                               : Directions::Diagonal);
    }
  }

  print(matrix);

  cout << "Der score ist " << matrix[rows][columns] << endl;

  print(directions);
  traceback(matrix, directions, rows, columns, s1, s2, "", "");

  return 0;
}

void traceback(vector2d &matrix, vector2d &directions, int r, int c, string s1, string s2, string aligned1, string aligned2)
{
  if (r <= 0 || c <= 0) // Gegenteil von: r > 0 && c > 0
  {
    cout << "A1: " << aligned1 << endl;
    cout << "A2: " << aligned2 << endl;

    return;
  }
  int direction = directions[r][c];

  if ((direction & Directions::Left) == Directions::Left)
  {
    // Ausgabe Seq1 + Gap aus Seq2
    // Strings kopieren, sonst würden die bereits angepassten Strings im nächsten IF weiterverwendet werden
    string xaligned1 = s1[c - 1] + aligned1;
    string xaligned2 = "-" + aligned2;

    traceback(matrix, directions, r, c - 1, s1, s2, xaligned1, xaligned2);
  }

  if ((direction & Directions::Up) == Directions::Up)
  {
    // Ausgabe Seq2 + Gap aus Seq1
    string xaligned1 = "-" + aligned1;
    string xaligned2 = s2[r - 1] + aligned2;

    traceback(matrix, directions, r - 1, c, s1, s2, xaligned1, xaligned2);
  }

  if ((direction & Directions::Diagonal) == Directions::Diagonal)
  {
    // Ausgabe beide
    string xaligned1 = s1[c - 1] + aligned1;
    string xaligned2 = s2[r - 1] + aligned2;

    traceback(matrix, directions, r - 1, c - 1, s1, s2, xaligned1, xaligned2);
  }
}