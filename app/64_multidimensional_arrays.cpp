/*
 * Video #64: Multidimensional Arrays
 */

#include <iostream>

int main() {
  // Start by heap allocating an array
  int* arr = new int[50];

  // Heap allocate a 2D array
  int** arr_2d = new int*[50];

  // Allocate each element (itself a 1D array) of the 2D array.
  for (int i = 0; i < 50; i++) {
    arr_2d[i] = new int[50];
  }

  // In order to delete a multidimensional array, we have to delete each
  // individual array of integers followed by deleting the array of pointers
  for (int i = 0; i < 50; i++) {
    delete[] arr_2d[i];
  }
  delete[] arr_2d;

  // Heap allocate a 3D array (and array of 2D arrays, e.g. images)
  int rows = 1024;
  int cols = 2048;
  int n_images = 100;
  int*** arr_3d = new int**[n_images];
  for (int img_idx = 0; img_idx < n_images; img_idx++) {
    // For each image allocate an array of pointers equal to the number of rows
    arr_3d[img_idx] = new int*[rows];
    for (int row = 0; row < rows; row++) {
      // For each row, allocate an array equal to the number of columns
      arr_3d[img_idx][row] = new int[cols];
      
      // Could also do
      // int** img_ptr = arr_3d[img_idx];
      // img_ptr[row] = new int[cols];
    }
  }

  // Access a single pixel in one of the images
  int img_num = 50;
  int row_num = 1023;
  int col_num = 1024;
  int pixel_value = arr_3d[img_num][row_num][col_num];

  // Delete the 3D array (did I do this correctly?)
  for (int img_idx = 0; img_idx < n_images; img_idx++) {
    for (int row = 0; row < rows; row++) {
      delete[] arr_3d[img_idx][row];
    }
    delete[] arr_3d[img_idx];
  }
  delete[] arr_3d;

  std::cin.get();
}